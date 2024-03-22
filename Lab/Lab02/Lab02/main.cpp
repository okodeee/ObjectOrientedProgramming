#include <iostream>
using namespace std;


/* 기초 1번
int main() {
	int x, y;
	x = 10;
	y = 20;
	cout << x << endl;
	cout << y << endl;
}
*/

/* 기초 2번
int main() {
	unsigned short siX; // (int) 생략 가능
	unsigned iX;
	long liX;
	long long lliX;
	cout << "sizeof(siX):" << sizeof(siX) << endl;
	cout << "sizeof(iX):" << sizeof(iX) << endl;
	cout << "sizeof(liX):" << sizeof(liX) << endl;
	cout << "sizeof(lliX):" << sizeof(lliX) << endl;
}
*/

/* 기초 3번
int main() {
	cout << "(7 == 5):" << (7 == 5) << endl;
	cout << "(7 >= 5):" << (7 >= 5) << endl;
	cout << "(7 != 5):" << (7 != 5) << endl;
	cout << "(7 <= 5):" << (7 <= 5) << endl;
	cout << "(7 >= 5 ? 100 : -100): " << (7 >= 5 ? 100 : -100) << endl;
}
*/

/* 기초 4번
int main() {
	const float PI = 3.14;
	char ch1 = 65;
	char ch2 = ch1 + 32;
	cout << PI << endl;
	cout << ch1 << endl;
	cout << ch2 << endl;
}
*/

/* 기초 5번
int main() {
	int x, y, sum, mult;
	float div;
	cin >> x >> y;
	sum = x + y;
	mult = x * y;
	div = float(x) / y;
	cout << x << '\t' << y << endl;
	cout << "x + y = " << sum << endl;
	cout << "x * y = " << mult << endl;
	cout << "x / y = " << div << endl;
}
*/

/* 응용 1번
int main() {
	cout << "My name is 정윤지" << endl;
}
*/

/* 응용 2번
int main() {
	int A, B;
	cout << "Please enter two integer values: ";
	cin >> A >> B;
	cout << A << " + " << B << " = " << A + B << endl;
	cout << A << " - " << B << " = " << A - B << endl;
	cout << A << " * " << B << " = " << A * B << endl;
	cout << A << " / " << B << " = " << float(A) / B << endl;
	cout << A << " % " << B << " = " << A % B << endl;
}
*/

/* 응용 3번
int main() {
	int i1 = 2, i2 = 5, i3 = -3;
	double d1 = 2.0, d2 = 5.0, d3 = -0.5;

	cout << i1 + (i2 * i3) << endl;
	cout << i1 * (i2 + i3) << endl;
	cout << float(i1) / (i2 + i3) << endl;
	cout << float(i1) / i2 + i3 << endl;
	cout << 3 + 4 + float(5) / 3 << endl;
	cout << (3 + 4 + 5) / float(3) << endl;
	cout << d1 + (d2 * d3) << endl;
	cout << d1 + d2 * d3 << endl;
	cout << d1 / d2 - d3 << endl;
	cout << d1 / (d2 - d3) << endl;
	cout << d1 + d2 + d3 / 3 << endl;
	cout << (d1 + d2 + d3) / 3 << endl;
}
*/

/*  응용 4번
int main() {
	int A, B;
	cout << "Please enter two integer values:" << endl;
	cout << "A : ";
	cin >> A;
	cout << "B : ";
	cin >> B;
	cout << "value of A is : " << B << endl;
	cout << "value of B is : " << A << endl;
}
*/

/* 응용 5번
int main() {
	int Fah, Cel;
	cout << "Please enter Fahrenheit value: ";
	cin >> Fah;
	Cel = float(5) / 9 * (Fah - 32);
	cout << "Celsius value is " << Cel;
}
*/