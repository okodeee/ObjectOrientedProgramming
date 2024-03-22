#include <iostream>
using namespace std;

int sum(int a, int b) { return a + b; }
int mult(int a, int b) { return a * b; }
int evaluate(int(*f)(int, int), int a, int b) {
	return f(a, b);
}

int main() {
	int(*func)(int, int); //함수 포인터

	func = &sum;
	cout << func(10, 20) << endl;

	func = &mult;
	cout << func(10, 20) << endl;

	cout << evaluate(&sum, 10, 20) << endl;
	cout << evaluate(&mult, 10, 20) << endl;

	return 0;
}



/*
// pass by value: int  a =  x; int  b =  y;
// pass by ref. : int& a =  x; int& b =  y;
// pass by addr.: int* a = &x; int* b = &y;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int x = 10, y = 20;

	cout << x << '\t' << y << endl;
	swap(&x, &y); //swap(x, y) smart compiler
	cout << x << '\t' << y << endl;

	return 0;
}
*/

/*
// &x: x의 주소값을 반환
// int* px: (int*)
//    ->포인터형 변수(주소값을 저장하는 변수)
// *px: px에 저장된 주소값으로 jump

int main() {
	int x = 10;
	int* px = &x; //px라는 포인트형 변수에 x의 주소값을 할당

	cout << &x << '\t' << x << endl;
	cout << px << '\t' << *px << endl;
	cout << &px << endl;

	return 0;
}
*/