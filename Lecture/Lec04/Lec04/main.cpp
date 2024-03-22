#include <iostream>
using namespace std;

// pass by value: �Լ� �Է� ���ڿ� ���縦 ���� ���� ����
// pass by reference: �Լ� �Է� ���ڿ� ������ ���� ���� ����(����ȭ)
// - �Լ��� �پ��� ������ ����� �� �ְ� ���ش�

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int x = 10, y = 1000;
	cout << x << '\t' << y << endl;
	swap(x, y);
	cout << x << '\t' << y << endl;

	return 0;
}


/*
// alising: x�� r�� ����ȭ (r�� x�� reference variable)
int main() {
	int x = 10;
	int& r = x;
	cout << x << '\t' << r << endl; // x = 10, r = 10
	x = 10000;
	cout << x << '\t' << r << endl; // x = 1000, r = 1000

	return 0;
}
*/

/*
// ����Լ�: �Լ��� �Լ� �ڱ��ڽ��� ��ȯ�� ���
// - 2���� ���� ����: base/termination condition
int factorial(int n) {
	// termination condition
	if (n == 0)
		return 1;

	// base condition
	return n * factorial(n - 1);
}

int main() {
	cout << factorial(5) << endl;
	return 0;
}
*/

/*
// global variable: �Լ� �ܺο��� ����, �������� ��밡��(���� ����)
// -���ǻ���: global, local variable�� �������� �浹�� �켱����: local > global
int gX;

void print() {
	gX = 1000;
	cout << "gX in print(): " << gX << endl; // gX = 1000
}

int main() {
	int gX; //local variable
	gX = 10;
	cout << gX << endl; // gX = 10
	print();
	cout << gX << endl; // gX = 10

	return 0;
}
*/

/*
// local variable: �Լ� �ȿ��� ����, ����- �Լ��� ����Ǹ� �����
void increase(int x) {
	x++;
	cout << "x in increase(): " << x << endl;
}

int main() {
	int x = 10;
	cout << x << endl; // x = 10
	increase(x);
	cout << x << endl; // x = 10

	return 0;
}
*/

/*
void print(int n = 10) {
	cout << "print(): " << n << endl;
}

int main() {
	print();
	print();
	print();
	print(11);

	return 0;
}
*/