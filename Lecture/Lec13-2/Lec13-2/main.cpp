#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <functional>
using namespace std;

// []  : closure
// [a] : 변수 a를 pass by value로 lambda 함수 내부로 전달
// [&a]: 별수 a를 pass by reference로 lambda 함수 내부에 전달
// [=] : 모든 외부변수를 pass by value로 전달
// [&] : 모든 외부변수를 pass by reference로 전달
// - 사용시 주의할점: 함수에 입력으로 lambda 함수를 사용할 경우 반드시 입력 type을 function으로

int evaluate2(function<int(int, int)> f, int x, int y) {
	return f(x, y);
}

int main() {
	int a = 10, b = 20;

	[&](int x) {
		cout << "x = " << x << endl;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		a = 1000;
	}(10);
	cout << "main::a = " << a << endl;

	cout << evaluate2([a](int x, int y) {return a + x + y; }, 2, 3) << endl;

	return 0;
}

/*
int sum(int x, int y) { return x + y; }
int mult(int x, int y) { return x * y; }
int evaluate(int(*f)(int, int), int x, int y) {
	return f(x, y);
}

int main() {
	cout << evaluate(&sum, 2, 3) << endl;
	cout << evaluate(&mult, 2, 3) << endl;

	// lambda 함수: 이름없이 일회용으로 사용되는 함수
	//  - form: [](입력변수)->리턴타임 {본문}
	// ex) sum(): [](int x, int y)->int { return x + y; }
	cout << evaluate([](int x, int y)->int { return x + y; }, 20, 30) << endl;

	// simplified lambda 함수: [](입력변수) {본문}
	// mult(): [](int x, int y) { return x * y; }
	cout << evaluate([](int x, int y) { return x * y; }, 20, 30) << endl;

	// lambda 함수 생성-호출을 동시에
	[](int x, int y) {cout << x << ", " << y << endl; } (20, 30);

	// lambda 함수로 local function 만들기
	auto f = [](int x, int y) {return x - y; };
	cout << f(1000, 2000) << endl;

	return 0;
}
*/

/*
template <class Iter>
void print(Iter iter_begin, Iter iter_end) {
	Iter iter = iter_begin;
	while (iter != iter_end) {
		cout << *iter << '\t';
		iter++;
	}
	cout << endl;
}

template <class Iter, typename T>
int count_value(Iter iter_begin, Iter iter_end, T key_value) {
	int count = 0;
	for (Iter iter = iter_begin; iter != iter_end; iter++)
		if (*iter == key_value) count++;

	return count;
}

int main() {
	vector<int> v{ 1, 2, 3, 1, 2, 2 };
	list<double> l{ 1.1, 2.2, 3.3, 1.1, 1.1 };
	string sAry[] = { "Apple", "Bear", "Cearrot", "Apple", "Apple" };

	print(begin(v), end(v));
	print(begin(l), end(l));
	print(begin(sAry), end(sAry));

	cout << count_value(begin(v), end(v), 2) << endl;
	cout << count_value(begin(l), end(l), 2.2) << endl;
	cout << count_value(begin(sAry), end(sAry), "Apple") << endl;

	struct Point {
		int x;
		int y;
		bool operator==(const Point& pt) {
			return (this->x == pt.x) && (this->y == pt.y);
		}
	};
	//             pts[0],pts[1],pts[2]
	Point pts[] = { {1,2}, {3,4}, {5,6} };
	cout << count_value(begin(pts), end(pts), Point{ 1,2 }) << endl;

	return 0;
}
*/