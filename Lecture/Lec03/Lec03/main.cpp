#include <iostream>
#include <cmath>
using namespace std;


void applePrice(int a = 1000); //default augment는 선언 부분에서만 작성

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
	cout << sqrt(value) << endl; //제곱근
	cout << exp(value) << endl; //e^5
	cout << log(value) << endl; //ln(5)
	cout << cos(value) << endl;
	return 0;
}
*/

/*
//선언
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

// 정의
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
	return 1.0*a / b; // float = float(??)int 형변환
}

int get_data() {
	int a;
	cout << "Enter a number: ";
	cin >> a; //키보드로부터 값을 입력받아 a로 
	return a;
}
*/

/*
// 1. 선언 (declare)
int square(int a); // 원형(prototype)

int main() {
	int x; //선언
	x = 5; //초기화
	cout << square(x) << endl; // 3. 호출(call)
}

// 2. 정의 (define, 구형)
int square(int a) {
	return a * a;
}
*/