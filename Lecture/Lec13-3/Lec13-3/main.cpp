#include <iostream>
#include <functional>
#include <algorithm> // for_each, copy, transform
#include <vector>
using namespace std;

int main() {
	vector<int> v1{ 1, 2, 3, 4 };
	for (int elem : v1)
		cout << elem << '\t';
	cout << endl;

	// for_each(iter_begin, iter_end, lambda)
	//  - Ư¡1: lambda �Լ��� �� element�� ���� ����, return type ����(void)
	//  - Ư¡2: �ܺ� ������ for_each�� ����� ��, closure�� ���
	for_each(begin(v1), end(v1), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	for_each(begin(v1), end(v1), [](int& elem) {elem++; });
	for_each(begin(v1), end(v1), [](int elem) {cout << elem << '\t'; });

	int a = 10;
	for_each(begin(v1), end(v1), [a](int& elem) {elem *= a; });
	for_each(begin(v1), end(v1), [](int elem) {cout << elem << '\t'; });
	cout << endl << endl;

	vector<int> v2(5);
	// copy(): src�� element�� dst�� ����
	// copy(src_iter_begin, src_iter_end, dst_iter_begin)
	// v1: { 20, 30, 40, 50 }
	// v2: { 0, 0, 0, 0, 0 }
	copy(begin(v1), end(v1), begin(v2));
	for_each(begin(v2), end(v2), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	// transform(): src�� element�� *��ȯ�ؼ�* dst�� ���� (for_each + copy)
	// transform(src_iter_begin, src_iter_end, dst_iter_begin, lambda)
	//   - Ư¡: lambda�� return type�� ����(for_each�� lambda�� return type�� ����)
	transform(begin(v1), end(v1), begin(v2), [](int elem) { return elem * elem; });
	for_each(begin(v2), end(v2), [](int elem) { cout << elem << '\t'; });
	cout << endl << endl;

	return 0;
}

/*
int evaluate(function<int(int, int)> f, int x, int y) {
	return f(x, y);
}

int main() {
	int a = 10, b = 20;

	cout << evaluate([&a](int x, int y) {a = 100; return a + x + y; }, 2, 3) << endl;
	cout << a << endl;

	return 0;
}
*/