#include <iostream>
#include <cmath>
using namespace std;


void applePrice(int a = 1000); //default augment�� ���� �κп����� �ۼ�

int main() {
	applePrice();
	applePrice(2000);
	applePrice();
	applePrice();
	applePrice();

	return 0;
}

void applePrice(int a) {
	cout << "Price of apple: " << a << endl;
}

/*
int main() {
	double value = 5;
	cout << sqrt(value) << endl; //������
	cout << exp(value) << endl; //e^5
	cout << log(value) << endl; //ln(5)
	cout << cos(value) << endl;
	return 0;
}
*/

/*
//����
int sum(int a, int b);
int subt(int a, int b);
int mult(int a, int b);
float divi(int a, int b);
int get_data();

int main() {
	int x, y;
	x = get_data();
	y = get_data();
	cout << "x = " << x << ", y = " << y << endl;
	cout << "x + y = " << sum(x, y) << endl;
	cout << "x - y = " << subt(x, y) << endl;
	cout << "x * y = " << mult(x, y) << endl;
	cout << "x / y = " << divi(x, y) << endl;

	return 0;
}

// ����
int sum(int a, int b) {
	return a + b;
}

int subt(int a, int b) {
	return a - b;
}

int mult(int a, int b) {
	return a * b;
}

float divi(int a, int b) {
	return 1.0*a / b; // float = float(??)int ����ȯ
}

int get_data() {
	int a;
	cout << "Enter a number: ";
	cin >> a; //Ű����κ��� ���� �Է¹޾� a�� 
	return a;
}
*/

/*
// 1. ���� (declare)
int square(int a); // ����(prototype)

int main() {
	int x; //����
	x = 5; //�ʱ�ȭ
	cout << square(x) << endl; // 3. ȣ��(call)
}

// 2. ���� (define, ����)
int square(int a) {
	return a * a;
}
*/