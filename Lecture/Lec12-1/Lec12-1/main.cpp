#include <iostream>
#include <vector>
using namespace std;

// private, protected, public
// protected: ����� ���ؼ� �����ϴ� Ư�� type (Base class������ private���� ����)


//  Base type | Inheritance type | Derived type
//  private   |     �������     | ���ٺҰ�(base class�� method�� ���ؼ� ����)
//  protected |     �������     | private (Ŭ���� ���ο��� ��밡��)
//  public    | private/protected| private
//  public    |      public      | public (Ŭ���� ����/�ܺο��� ��밡��)

class Base {
public: // Base type
	void print_base() { cout << "print_base()" << endl; }
	virtual void print() { cout << "Base::print()" << endl; }
};

class Derived : public Base { // Inheritance type
public:
	void print_derived() { 
		cout << "print_derived()" << endl;
		Base::print_base();
	}
	void print() override { cout << "Derived::print()" << endl; }
};

int main() {
	Base base;
	Derived derived;
	base.print_base();
	derived.print_derived();
	derived.print_base();
	cout << endl;

	// �Լ� �������̵�(overriding): base class�� method�� derived class���� ������(�Է�, �̸�, ��� ��� ����)
	// - �Լ� �����ε�: ���� �̸��� ���� �Լ�(��/����� �ٸ� �� ����) ������ ����, ����̶� ����
	// ���� ���ε�(static binding): compile�� ��ü�� � method�� ȣ�������� �̸� ����
	base.print();
	derived.print();
	cout << endl;

	// ���� ���ε�(dynamic binding): run-time�� ȣ���� method���� ��Ȳ�� ���� ����
	// - pointer: Base class�� pointer�� derived class�� �ּҰ��� �Ҵ�
	// - �ٽ� Ű����: virtual, override
	// - �������� ����: single interface(base class�� pointer)��
	//                  �پ��� entitied(derived class ��ü)�� ��� ����
	Base* pBase = &derived;
	pBase->print();
	pBase = &base;
	pBase->print();

	// ������ ���� ����
	//               {  0x00,           0x10,     0x20,    0x30
	vector<Base*> vec{ new Base, new Derived, new Base };
	pBase = new Derived;
	vec.push_back(pBase);

	for (auto elem : vec)
		elem->print();

	for (auto elem : vec)
		delete elem;

	return 0;
}