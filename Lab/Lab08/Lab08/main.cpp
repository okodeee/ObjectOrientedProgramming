#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

/* 기초 1번
//int &x = a; int &y = b; pass by reference
//int *x = &a; int *y = &b; pass by address
void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main() {
	int a = 10, b = 20;
	cout << a << ", " << b << endl;
	swap(&a, &b);
	cout << a << ", " << b << endl;

	return 0;
}*//* 기초 2번int sum(int x, int y) { return x + y; }
int mult(int x, int y) { return x * y; }
// 함수 func의 포인터와 파라미터 x, y를 받아와서 함수 func의 실행값을 리턴해주는 함수
int evaluate(int(*func)(int, int), int x, int y)
{
	return func(x, y);
}
int main() {
	int(*func)(int, int);
	func = &sum; // sum 함수 주소값 대입
	cout << func(10, 20) << endl;
	func = &mult; // mult 함수 주소값 대입
	cout << func(10, 20) << endl;
	cout << evaluate(&sum, 100, 200) << endl;
	cout << evaluate(&mult, 100, 200) << endl;

	return 0;
}
*/

/* 기초 3번
void print(const vector<int>& v) {
	for (unsigned i = 0; i < v.size(); i++)
		cout << v[i] << "\t";
	cout << endl;
}

int main() {
	// 인덱스         0   1   2
	vector<int> vec{ 10, 20, 30 };
	print(vec);

	vec[0] = 100; // vector 인덱스 0번에 직접 대입
	vec.at(1) = 200; // vector의 at() 함수 이용
	print(vec);

	vec.push_back(400); // vector의 push_back() 함수 이용
	print(vec);

	vec.pop_back(); // vector의 pop_back() 함수 이용
	print(vec);

	cout << endl;
	// 범위기반 for문을 이용한 vector 원소값 바꾸기 (슬라이드 p.26 참고)
	for (int& elem : vec) {
		cout << "enter an element of vector v: ";
		cin >> elem;
	}

	cout << endl << "[ vector v ]" << endl;
	// 범위기반 for문을 이용한 화면 출력하기 (슬라이드 p.26 참고)
	for (int elem : vec)
		cout << elem << "\t";
	cout << endl;

	return 0;
}
*/

/* 기초 4번
bool is_prime(int num) {
	if (num < 2)
		return false;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) // num을 i로 나눈 나머지가 0이면 false 리턴
			return false;
	}
	return true;
}

vector<int> primes(int lower, int upper) {
	vector<int> v;
	for (int i = lower; i <= upper; i++) {
		if (is_prime(i)) // 소수이면(is_prime이 참이면) 뒤에 push
			v.push_back(i);
	}
	return v;
}

int main() {
	int lower = 10, upper = 100;
	vector<int> vec = primes(lower, upper); // 벡터 vec 선언 및 primes로 대입
	for (int elem : vec)
		cout << elem << setw(5);
	cout << endl;

	return 0;
}*//* 응용 1번void square(int* px) { *px *= *px; }int main() {
	int n;
	cout << "input> ";	cin >> n;	square(&n);	cout << "제곱값> " << n;	return 0;}*//* 응용 2번void changevalue(string* str) {
	string input;
	cout << "input> ";
	cin >> input;
	*str = input;
}

int main() {
	string str = "This is default value";
	cout << "기본값 출력> " << str << endl;
	changevalue(&str);
	cout << "변환된 값 출력> " << str << endl;

	return 0;
}
*/

/* 응용 3번
void reverse(vector<int>& v) {
	int temp;
	for (int i = 0; i < 5; i++) {
		temp = v[i];
		v[i] = v[9 - i];
		v[9 - i] = temp;
	}
}

void print(const vector<int>& v) {
	for (int elem : v)
		cout << ' ' << elem;
	cout << endl;
}

int main() {
	vector<int> vec(10);
	for (int i = 0; i < vec.size(); i++)
		vec[i] = i + 1;

	cout << "기본 Vector 값:" << endl;
	print(vec);

	reverse(vec);

	cout << "함수 실행 후  Vector 값:" << endl;
	print(vec);

	return 0;
}
*/

/* 응용 4번
int inputGrade(float grade) {
	cin >> grade;
	if ((grade - (int)grade) != 0.0 || grade < 0 || grade > 100) {
		cout << "invalid input!!!" << endl;
		exit(EXIT_FAILURE);
	}
	else
		return (int)grade;
}
int* topGrade(const vector<int>& grade) {
	int top;
	if (grade[0] > grade[1])
		top = grade[0];
	else
		top = grade[1];

	if (grade[2] > top)
		top = grade[2];

	return &top;
}

int main() {
	vector<int> grades;
	float _grade = 0;
	for (int i = 0; i < 3; i++) {
		cout << "Input " << i << "-th grade(0~100):";
		int grade = inputGrade(_grade);
		grades.push_back(grade);
	}
	int output = *topGrade(grades);
	cout << "Top Grade: " << output;

	return 0;
}
*/