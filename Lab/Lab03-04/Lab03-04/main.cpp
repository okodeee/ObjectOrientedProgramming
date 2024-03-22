#include <iostream>
#include <cmath>
using namespace std;


/* 기초 1번
int square(int a);

int main() {
	int x;
	x = 5;
	cout << square(5) << endl;
}

int square(int a) { return a * a; }
*/

/* 기초 2번
int get_num();
int myadd(int x, int y);
int mysub(int x, int y);
int mymul(int x, int y);
float mydiv(int x, int y);

int main() {
	int x, y;
	x = get_num();
	y = get_num();
	cout << "x = " << x << ", y = " << y << endl;
	cout << "x + y = " << myadd(x, y) << endl;
	cout << "x - y = " << mysub(x, y) << endl;
	cout << "x * y = " << mymul(x, y) << endl;
	cout << "x / y = " << mydiv(x, y) << endl;

	return 0;
}

int get_num() {
	int num;
	cout << "Enter a number: ";
	cin >> num;
	return num;
}
int myadd(int x, int y) {
	return x + y;}
int mysub(int x, int y) {
	return x - y;}
int mymul(int x, int y) {
	return x * y;}
float mydiv(int x, int y) {
	return float(x) / y;}
*/

/* 기초 3번
int main() {
	double value;
	value = 5;
	cout << sqrt(value) << endl;
	cout << exp(value) << endl;
	cout << log(value) << endl;
	cout << cos(value) << endl;

	return 0;
}
*/

/* 기초 4번
void applePrice(int a = 1000) {
	cout << "Price of an apple is " << a << endl;
}

int main() {
	applePrice(1500);
	applePrice(500);
	applePrice();
	applePrice();

	return 0;
}
*/

/* 응용 1번
int get_num();
int myadd(int x, int y);
int mysub(int x, int y);
int mymul(int x, int y);
float mydiv(int x, int y);

int addmul(int x, int y, int z);
float muldiv(int x, int y, int z);
int addmuladd(int x, int y, int z);
float subdivsub(int x, int y, int z);

int main() {
	int x, y, z;
	x = get_num();
	y = get_num();
	z = get_num();
	cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
	cout << "(x + y) * z = " << addmul(x, y, z) << endl;
	cout << "(x * y) / z = " << muldiv(x, y, z) << endl;
	cout << "(x + y) * (y + z) = " << addmuladd(x, y, z) << endl;
	cout << "(x - y) / (y - z) = " << subdivsub(x, y, z) << endl;
}

int get_num() {
	int num;
	cout << "Enter a number: ";
	cin >> num;
	return num;
}
int myadd(int x, int y) {
	return x + y;}
int mysub(int x, int y) {
	return x - y;}
int mymul(int x, int y) {
	return x * y;}
float mydiv(int x, int y) {
	return float(x) / y;}

int addmul(int x, int y, int z) {
	return mymul(myadd(x, y), z);
}
float muldiv(int x, int y, int z) {
	return mydiv(mymul(x, y), z);
}
int addmuladd(int x, int y, int z) {
	return mymul(myadd(x, y), myadd(y, z));
}
float subdivsub(int x, int y, int z) {
	return mydiv(mysub(x, y), mysub(y, z));
}
*/

/* 응용 2번
void print_DOB(int year = 1900, int month = 1, int day = 1) {
	cout << "생년월일은 " << year << "년 " << month << "월 " << day << "일입니다." << endl;
}

int main() {
	int year, month, day;
	print_DOB();
	cout << "year 입력 : ";
	cin >> year;
	cout << "month 입력 : ";
	cin >> month;
	cout << "day 입력 : ";
	cin >> day;
	print_DOB(year, month, day);
}
*/

/* 응용 3번
int main() {
	double x, y;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	cout << "Rounding up number of " << x << ": " << ceil(x) << endl;
	cout << "Rounding down number of " << x << ": " << floor(x) << endl;
	cout << "Rounding number of " << x << ": " << round(x) << endl;
	cout << "Maximum number between " << x << " and " << y << ": " << fmax(x, y) << endl;
	cout << y << "-th root of " << x << ": " << pow(x, 1/y) << endl;
	cout << "|" << x << " - " << y << "| = " << abs(x - y) << endl;
}
*/

/* 응용 4번
void swap_call_by_value(int x, int y);
void swap_call_by_reference(int& x, int& y);
void get_data(int& x, int& y);

int main() {
	int x, y;
	get_data(x, y);
	cout << endl;

	cout << "swap_call_by_value 함수 사용 전" << endl
		<< "x = " << x << ", y = " << y << endl;
	swap_call_by_value(x, y);
	cout << "swap_call_by_value 함수 사용 후" << endl
		<< "x = " << x << ", y = " << y << endl;
	cout << endl;

	cout << "swap_call_by_reference 함수 사용 전" << endl
		<< "x = " << x << ", y = " << y << endl;
	swap_call_by_reference(x, y);
	cout << "swap_call_by_reference 함수 사용 후" << endl
		<< "x = " << x << ", y = " << y << endl;

	return 0;
}

void swap_call_by_value(int x, int y) {
	swap(x, y);
}

void swap_call_by_reference(int& x, int& y) {
	swap(x, y);
}

void get_data(int& x, int& y) {
	cout << "x 입력 : ";
	cin >> x;
	cout << "y 입력 : ";
	cin >> y;
}
*/