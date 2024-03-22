#include <iostream>
using namespace std;

// class 만드는 법
// 1) class name{ };
// 2) private:, public: 영역 분할
// 3) member data 만들기 in private:
// 4) method      만들기 in public:
// 5) 초기화 함수(constructor, 생성자)
//   - 생성자 이름은 class 이름과 동일
//   - 만약 내가 생성자를 만들지 않으면, default 생상자(Point(){}) 가 자동으로 생성
//   - 만약 내가 생성자를 만들면, default 생성자 자동 생성 안됨

class Point {
private: // 외부(main)에서 접근 불가능, member data
	int x;
	int y;
public:  // 외부(main)에서 접근 가능, member function (method)
	Point(int _x, int _y) {
		x = _x;
		y = _y;
	}
	Point() {}
	int getX() { return x; }
	int getY() { return y; }
	void setXY(int _x, int _y) {
		x = _x;
		y = _y;
	}
	void print() {
		cout << "(" << x << ", " << y << ")" << endl;
	}
};

int main() {
	Point pt1, pt2(10, 20);
	pt1.setXY(1, 2);
	cout << pt1.getX() << endl;
	cout << pt1.getY() << endl;

	pt1.print();
	pt2.print();

	return 0;
}