#include <iostream>
using namespace std;
// (//) 1 line 주석 comment, 프로그램 실행 시 무시되는 부분
/* 여러 줄 주석 */
// ctrl + F5 : build


int main() {
	cout << "(7 == 5): " << (7 == 5) << endl;
	cout << "(7 >= 5): " << (7 >= 5) << endl;

	cout << "(7 > 5 ? 100 : -100): " << (7 > 5 ? 100 : -100) << endl;
	//조건식 ? 참일때 값 : 거짓일때 값

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

//	cout << ++x << endl; //전위증가 연산자: x를 1 증가시킨다음 line 실행
	cout << x++ << endl; //후위증가 연산자: line을 실행한 다음 x를 1증가
	cout << x << endl; //왼쪽에서 오른쪽으로 --> ++가 먼저나오면 1증가
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
	char ch1 = 'A'; //초기화
	char ch2 = 66 + 32;

	cout << ch1 << endl;
	cout << ch2 << endl;
}
*/

/*
// short, long, unsigned를 쓰면, int는 생략 가능
int main() {
	unsigned short siX;
	unsigned iX;
	unsigned long liX;
	unsigned long long lliX;

	cout << sizeof(siX) << endl; //size of() 변수의 byte크기를 리턴
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
	cout << x << endl; //cout 변수를 화면에 출력
	cout << y << endl; //endl 줄바꿈(개행) 문자
}
*/