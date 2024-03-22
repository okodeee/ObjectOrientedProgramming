#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

/* ���� 1��
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
}*//* ���� 2��int sum(int x, int y) { return x + y; }
int mult(int x, int y) { return x * y; }
// �Լ� func�� �����Ϳ� �Ķ���� x, y�� �޾ƿͼ� �Լ� func�� ���ప�� �������ִ� �Լ�
int evaluate(int(*func)(int, int), int x, int y)
{
	return func(x, y);
}
int main() {
	int(*func)(int, int);
	func = &sum; // sum �Լ� �ּҰ� ����
	cout << func(10, 20) << endl;
	func = &mult; // mult �Լ� �ּҰ� ����
	cout << func(10, 20) << endl;
	cout << evaluate(&sum, 100, 200) << endl;
	cout << evaluate(&mult, 100, 200) << endl;

	return 0;
}
*/

/* ���� 3��
void print(const vector<int>& v) {
	for (unsigned i = 0; i < v.size(); i++)
		cout << v[i] << "\t";
	cout << endl;
}

int main() {
	// �ε���         0   1   2
	vector<int> vec{ 10, 20, 30 };
	print(vec);

	vec[0] = 100; // vector �ε��� 0���� ���� ����
	vec.at(1) = 200; // vector�� at() �Լ� �̿�
	print(vec);

	vec.push_back(400); // vector�� push_back() �Լ� �̿�
	print(vec);

	vec.pop_back(); // vector�� pop_back() �Լ� �̿�
	print(vec);

	cout << endl;
	// ������� for���� �̿��� vector ���Ұ� �ٲٱ� (�����̵� p.26 ����)
	for (int& elem : vec) {
		cout << "enter an element of vector v: ";
		cin >> elem;
	}

	cout << endl << "[ vector v ]" << endl;
	// ������� for���� �̿��� ȭ�� ����ϱ� (�����̵� p.26 ����)
	for (int elem : vec)
		cout << elem << "\t";
	cout << endl;

	return 0;
}
*/

/* ���� 4��
bool is_prime(int num) {
	if (num < 2)
		return false;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) // num�� i�� ���� �������� 0�̸� false ����
			return false;
	}
	return true;
}

vector<int> primes(int lower, int upper) {
	vector<int> v;
	for (int i = lower; i <= upper; i++) {
		if (is_prime(i)) // �Ҽ��̸�(is_prime�� ���̸�) �ڿ� push
			v.push_back(i);
	}
	return v;
}

int main() {
	int lower = 10, upper = 100;
	vector<int> vec = primes(lower, upper); // ���� vec ���� �� primes�� ����
	for (int elem : vec)
		cout << elem << setw(5);
	cout << endl;

	return 0;
}*//* ���� 1��void square(int* px) { *px *= *px; }int main() {
	int n;
	cout << "input> ";	cin >> n;	square(&n);	cout << "������> " << n;	return 0;}*//* ���� 2��void changevalue(string* str) {
	string input;
	cout << "input> ";
	cin >> input;
	*str = input;
}

int main() {
	string str = "This is default value";
	cout << "�⺻�� ���> " << str << endl;
	changevalue(&str);
	cout << "��ȯ�� �� ���> " << str << endl;

	return 0;
}
*/

/* ���� 3��
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

	cout << "�⺻ Vector ��:" << endl;
	print(vec);

	reverse(vec);

	cout << "�Լ� ���� ��  Vector ��:" << endl;
	print(vec);

	return 0;
}
*/

/* ���� 4��
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