#include <iostream>
using namespace std;
// (//) 1 line �ּ� comment, ���α׷� ���� �� ���õǴ� �κ�
/* ���� �� �ּ� */
// ctrl + F5 : build


int main() {
	cout << "(7 == 5): " << (7 == 5) << endl;
	cout << "(7 >= 5): " << (7 >= 5) << endl;

	cout << "(7 > 5 ? 100 : -100): " << (7 > 5 ? 100 : -100) << endl;
	//���ǽ� ? ���϶� �� : �����϶� ��

	//x = 2 * 3 * 4 + 5;
	//x = 6 * 4 + 5;
	//x = 24 + 5;
	//x = 29;
}

/*
int main() {
	int x = 10, y = 20;
	x += y;
	x *= y;
	x = 20;

//	cout << ++x << endl; //�������� ������: x�� 1 ������Ų���� line ����
	cout << x++ << endl; //�������� ������: line�� ������ ���� x�� 1����
	cout << x << endl; //���ʿ��� ���������� --> ++�� ���������� 1����
}
*/

/*
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

/*
int main() {
	const double PI = 3.14;

	//ASCII Code: A = 65
	char ch1 = 'A'; //�ʱ�ȭ
	char ch2 = 66 + 32;

	cout << ch1 << endl;
	cout << ch2 << endl;
}
*/

/*
// short, long, unsigned�� ����, int�� ���� ����
int main() {
	unsigned short siX;
	unsigned iX;
	unsigned long liX;
	unsigned long long lliX;

	cout << sizeof(siX) << endl; //size of() ������ byteũ�⸦ ����
	cout << sizeof(iX) << endl;
	cout << sizeof(liX) << endl;
	cout << sizeof(lliX) << endl;
}
*/

/*
int main() {
	int x, y;
	x = 10;
	y = 20;
	cout << x << endl; //cout ������ ȭ�鿡 ���
	cout << y << endl; //endl �ٹٲ�(����) ����
}
*/