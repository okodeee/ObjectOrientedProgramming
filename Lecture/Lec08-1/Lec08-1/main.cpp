#include <iostream>
using namespace std;

int sum(int a, int b) { return a + b; }
int mult(int a, int b) { return a * b; }
int evaluate(int(*f)(int, int), int a, int b) {
	return f(a, b);
}

int main() {
	int(*func)(int, int); //�Լ� ������

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
// &x: x�� �ּҰ��� ��ȯ
// int* px: (int*)
//    ->�������� ����(�ּҰ��� �����ϴ� ����)
// *px: px�� ����� �ּҰ����� jump

int main() {
	int x = 10;
	int* px = &x; //px��� ����Ʈ�� ������ x�� �ּҰ��� �Ҵ�

	cout << &x << '\t' << x << endl;
	cout << px << '\t' << *px << endl;
	cout << &px << endl;

	return 0;
}
*/