#pragma once
#include "Imagelib.h"
#include "CTensor.h"

#define MEAN_INIT 0
#define LOAD_INIT 1

// Layer�� tensor�� ��/������� ������, Ư�� operation�� �����ϴ� Convolutional Neural Netowork�� �⺻ ���� ����


class Layer {
protected:
	int fK; // kernel size in K*K kernel
	int fC_in; // number of channels
	int fC_out; //number of filters
	string name;
public:
	Layer(string _name, int _fK, int _fC_in, int _fC_out) : name(_name), fK(_fK), fC_in(_fC_in), fC_out(_fC_out) {}
	virtual ~Layer() {}; //����Ҹ��� (����: https://wonjayk.tistory.com/243)
	virtual Tensor3D* forward(const Tensor3D* input) = 0;
	//	virtual bool backward() = 0;
	virtual void print() const = 0;
	virtual void get_info(string& _name, int& _fK, int& _fC_in, int& _fC_out) const = 0;
};


class Layer_ReLU : public Layer {
public:
	Layer_ReLU(string _name, int _fK, int _fC_in, int _fC_out)
		: Layer::Layer(_name, _fK, _fC_in, _fC_out)
	{
		// (������ ��)
		// ����1: Base class�� �����ڸ� ȣ���Ͽ� �ɹ� ������ �ʱ�ȭ �� ��(�ݵ�� initialization list�� ����� ��)
	}
	~Layer_ReLU() {}
	Tensor3D* forward(const Tensor3D* input) override {
		// (������ ��)
		// ����1: input tensor�� ���� �� element x�� ����̸� �״�� ����, �����̸� 0���� output tensor�� �����Ұ�    
		// ����2: �̶�, output tensor�� �����Ҵ��Ͽ� �ּҰ��� ��ȯ�� ��
		// �Լ�1: Tensor3D�� �ɹ��Լ��� get_info(), get_elem(), set_elem()�� ������ Ȱ���� ��

		int nH, nW, nC;
		input->get_info(nH, nW, nC);
		Tensor3D* output = new Tensor3D(nH, nW, nC);
		double elem;

		for (int y = 0; y < nH; y++) {
			for (int x = 0; x < nW; x++) {
				for (int c = 0; c < nC; c++) {
					elem = input->get_elem(y, x, c);
					if (elem <= 0)
						output->set_elem(y, x, c, 0);
					else
						output->set_elem(y, x, c, elem);
				}
			}
		}

		cout << name << " is finished" << endl;
		return output;
	};
	void get_info(string& _name, int& _fK, int& _fC_in, int& _fC_out) const override {
		// (������ ��)
		// ����: Tensor3D�� get_info()�� ���������� �ɹ� �������� pass by reference�� �ܺο� ����

		_name = name;
		_fK = fK;
		_fC_in = fC_in;
		_fC_out = fC_out;
	}
	void print() const override {
		// (������ ��)
		// ����: Tensor3D�� print()�� ���������� ������ ũ�⸦ ȭ�鿡 ���

		cout << name << ":  " << fK << "*" << fK << "*" << fC_in << "*" << fC_out << endl;
	}
};



class Layer_Conv : public Layer {
private:
	string filename_weight;
	string filename_bias;
	double**** weight_tensor; // fK x fK x _fC_in x _fC_out ũ�⸦ ������ 4���� �迭
	double*  bias_tensor;     // _fC_out ũ�⸦ ������ 1���� �迭 (bias�� �� filter�� 1�� ����) 
public:
	Layer_Conv(string _name, int _fK, int _fC_in, int _fC_out, int init_type, string _filename_weight = "", string _filename_bias = "")
		: Layer::Layer(_name, _fK, _fC_in, _fC_out), filename_weight(_filename_weight), filename_bias(_filename_bias)
	{
		// (������ ��)
		// ����1: initialization list�� base class�� �����ڸ� �̿��Ͽ� �ɹ� ������ �ʱ�ȭ �� ��
		// ����2: filename_weight�� filename_bias�� LOAD_INIT ����� ��� �ش� ���Ϸκ��� ����ġ/���̾�� �ҷ���
		// ����3: init() �Լ��� init_type�� �Է����� �޾� ����ġ�� �ʱ�ȭ �� 
		// �Լ�1: dmatrix4D()�� dmatrix1D()�� ����Ͽ� 1����, 4���� �迭�� ���� �Ҵ��� ��

		init(init_type);
	}
	void init(int init_type) {
		// (������ ��)
		// ����1: init_type (MEAN_INIT �Ǵ� LOAD_INIT)�� ���� ����ġ�� �ٸ� ������� �ʱ�ȭ ��
		// ����2: MEAN_INIT�� ��� ���ʹ� ��հ��� �����ϴ� ���Ͱ� �� (��, ��� ����ġ ���� ������ ũ��(fK*fK*fC_in)�� ������ ������ (�̶� bias�� ��� 0���� ����)
		// ����3: LOAD_INIT�� ��� filename_weight, filename_bias�� �̸��� ������ ������ ���� �о� ����ġ�� ����(�ʱ�ȭ) ��  
		// �Լ�1: dmatrix4D()�� dmatrix1D()�� ����Ͽ� 1����, 4���� �迭�� ���� �Ҵ��� ��
		
		weight_tensor = dmatrix4D(fK, fK, fC_in, fC_out);
		bias_tensor = dmatrix1D(fC_out);

		if (init_type == MEAN_INIT) {
			for (int y = 0; y < fK; y++) {
				for (int x = 0; x < fK; x++) {
					for (int c = 0; c < fC_in; c++) {
						for (int n = 0; n < fC_out; n++)
							weight_tensor[y][x][c][n] = 1.0 / (fK*fK*fC_in);
					}
				}
			}

			for (int k = 0; k < fC_out; k++)
				bias_tensor[k] = 0;
		}
		else if (init_type == LOAD_INIT) {
			ifstream fin1(filename_weight);
			double weight;
			for (int n = 0; n < fC_out; n++) {
				for (int c = 0; c < fC_in; c++) {
					for (int x = 0; x < fK; x++) {
						for (int y = 0; y < fK; y++) {
							fin1 >> weight;
							weight_tensor[y][x][c][n] = weight;
						}
					}
				}
			}

			fin1.close();

			ifstream fin2(filename_bias);
			double bias;
			for (int i = 0; i < fC_out; i++) {
				fin2 >> bias;
				bias_tensor[i] = bias;
			}

			fin2.close();
		}
	}
	~Layer_Conv() override {
		// (������ ��)
		// ����1: weight_tensor�� bias_tensor�� ���� �Ҵ� ������ ��
		// �Լ�1: free_dmatrix4D(), free_dmatrix1D() �Լ��� ���

		free_dmatrix4D(weight_tensor, fK, fK, fC_in, fC_out);
		free_dmatrix1D(bias_tensor, fC_out);
	}
	Tensor3D* forward(const Tensor3D* input) override {
		// (������ ��)
		// ����1: ������� (�� ��ġ���� y = WX + b)�� ����
		// ����2: output (Tensor3D type)�� ���� ���� �Ҵ��ϰ� ������ �Ϸ�� ���� pointer�� ��ȯ 

		int nH, nW, fC_in;
		input->get_info(nH, nW, fC_in);
		Tensor3D* output = new Tensor3D(nH, nW, fC_out);
		double sum = 0.0;

		int offset = (fK - 1) / 2;
		for (int f = 0; f < fC_out; f++) {
			for (int h = offset; h < nH - offset; h++) {
				for (int w = offset; w < nW - offset; w++) {
					for (int c = 0; c < fC_in; c++) {
						for (int ph = 0; ph < fK; ph++) {
							for (int pw = 0; pw < fK; pw++) {
								sum += input->get_elem(ph + h - offset, pw + w - offset, c) * weight_tensor[ph][pw][c][f];
							}
						}
					}
					output->set_elem(h, w, f, sum);
					sum = 0;
				}
			}
		}

		cout  << name << " is finished" << endl;
		return output;
	};
	void get_info(string& _name, int& _fK, int& _fC_in, int& _fC_out) const override {
		// (������ ��)
		// ����: Layer_ReLU�� ����

		_name = name;
		_fK = fK;
		_fC_in = fC_in;
		_fC_out = fC_out;
	}
	void print() const override {
		// (������ ��)
		// ����: Layer_ReLU�� ����

		cout << name << ":  " << fK << "*" << fK << "*" << fC_in << "*" << fC_out << endl;
	}
};



