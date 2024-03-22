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
	//  - 특징1: lambda 함수는 각 element에 대해 수행, return type 없음(void)
	//  - 특징2: 외부 변수를 for_each에 사용할 때, closure를 사용
	for_each(begin(v1), end(v1), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	for_each(begin(v1), end(v1), [](int& elem) {elem++; });
	for_each(begin(v1), end(v1), [](int elem) {cout << elem << '\t'; });

	int a = 10;
	for_each(begin(v1), end(v1), [a](int& elem) {elem *= a; });
	for_each(begin(v1), end(v1), [](int elem) {cout << elem << '\t'; });
	cout << endl << endl;

	vector<int> v2(5);
	// copy(): src의 element를 dst로 복사
	// copy(src_iter_begin, src_iter_end, dst_iter_begin)
	// v1: { 20, 30, 40, 50 }
	// v2: { 0, 0, 0, 0, 0 }
	copy(begin(v1), end(v1), begin(v2));
	for_each(begin(v2), end(v2), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	// transform(): src의 element를 *변환해서* dst로 복사 (for_each + copy)
	// transform(src_iter_begin, src_iter_end, dst_iter_begin, lambda)
	//   - 특징: lambda의 return type이 존재(for_each의 lambda는 return type이 없음)
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