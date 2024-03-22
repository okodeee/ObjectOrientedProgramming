#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

/* 1¹ø
class Complex {
	double re, im;
public:
	Complex(double r, double i) { re = r; im = i; }
	Complex() { re = 0; im = 0; }

	double getRE() { return re; }
	double getIM() { return im; }

	Complex operator+ (Complex a) {
		Complex result(this->re + a.getRE(), this->im + a.getIM());
		return result;
	}
	Complex operator+ (double b) {
		Complex result(this->re + b, this->im);
		return result;
	}

	Complex operator- (Complex a) {
		Complex result(this->re - a.getRE(), this->im - a.getIM());
		return result;
	}
	Complex operator- (double b) {
		Complex result(this->re - b, this->im);
		return result;
	}

	void print() {
		cout << re << " + i" << im << endl;
	}
};

int main()
{
	Complex a(.3, 8.4), b(4.5, 5.2), c(2.0, 7.7);
	Complex sum, dif;
	sum = a + b + 3.0;
	cout << "a + b + 3.0 = ";
	sum.print();

	dif = a - b - 2.0;
	cout << "a - b - 2.0 = ";
	dif.print();

	sum = a + b + 5 - c - 8;
	cout << "a + b + 5 - c - 8 = ";
	sum.print();
	return 0;
}
*/

/* 2¹ø
class VectorList {
	vector<double*> vItem;
	vector<int> vLength;
public:
	~VectorList() {}
	void append(double* _pArray, int _length) {
		vItem.push_back(_pArray);
		vLength.push_back(_length);
	}
	int findVector(double* _pArray, int _length) {
		for (int i = 0; i < vItem.size(); i++) {
			if (vLength[i] == _length) {
				for (int j = 0; j < _length; j++) {
					if (_pArray + j != vItem[i] + j) {
						return -1;
						break;
					}
					return i;
				}
				return -1;
			}
		}
	}
	void print_single_vector(int idx) {
		if (idx < 0 || idx >= vItem.size())
			cout << "[Wrong index]";
		else {
			cout << idx << "-th vector:";
			for (int i = 0; i < vLength[idx]; i++)
				cout << setw(10) << *(vItem[idx] + i);
		}
		cout << endl;
	}
	void print_all_vectors() {
		for (int i = 0; i < vItem.size(); i++)
			print_single_vector(i);
	}
};
int main() {
	VectorList vectorList;
	double* pTemp = new double[3]{ 1.1, 2.2, 3.3 };
	vectorList.append(pTemp, 3);

	pTemp = new double[5]{ 10.1, 10.2, 10.3, 10.4, 10.5 };
	vectorList.append(pTemp, 5);

	pTemp = new double[2]{ 4.5, 5.5 };
	vectorList.append(pTemp, 2);

	vectorList.print_single_vector(-1);
	vectorList.print_single_vector(0);
	cout << endl;

	vectorList.print_all_vectors();
	cout << endl;

	double* pTemp1 = new double[2]{ 4.5, 5.5 };
	double* pTemp2 = new double[4]{ 1.1, 2.2, 5.5, 4.4 };

	cout << "Index of vector{4.5, 5.5} :" << vectorList.findVector(pTemp1, 2) << endl;
	cout << "Index of vector{1.1, 2.2, 5.5, 4.4} :" << vectorList.findVector(pTemp2, 4) << endl;

	delete[] pTemp;
	delete[] pTemp1;
	delete[] pTemp2;

	return 0;
}
*/