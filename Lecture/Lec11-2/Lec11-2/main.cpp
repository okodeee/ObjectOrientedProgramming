#include <iostream>
using namespace std;

class Point {
private:
	int x;
	int y;
	static int numCreatedObj;
	int* ary;
public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {
		numCreatedObj++;
		// file open
		// 동적 할당
		ary = new int[5];
	}
	// 소멸자
	~Point() {
		cout << x << ", " << y << " is destructed.." << endl;
		// file close
		// 할당 해제
		delete[] ary;
	}
	void setXY(int _x, int _y) { x = _x; y = _y; }
	int getX() const { return x; } //const method: 맴버 변수가 바뀌지 않음
	int getY() const { return y; }
	static int getNumCreatedObject() { return numCreatedObj; }
	// Point class는 operator<< 함수를 친구로 여긴다:
	friend ostream& operator<<(ostream& cout, const Point& pt);
	friend class SpyPoint;
	// A->B를 친구로 여겼음 (B는 A의 private 멤버 변수 사용 가능)
	// 역은 성립하지 않는다 (A는 B의 private 멤버 변수 가용 불가능)
};

// static 멤버 변수 초기화
int Point::numCreatedObj = 0;

// 객체의 입력 type이 const이면 내부에서 const method만 사용가능
ostream& operator<<(ostream& cout, const Point& pt) {
	cout << pt.x << ", " << pt.y;
	return cout;
}

class SpyPoint {
public:
	void hack_all_info(const Point& pt) {
		cout << "Hacked by SpyPoint" << endl;
		cout << "x: " << pt.x << endl;
		cout << "x: " << pt.y << endl;
		cout << "numCreatedObj: " << pt.getNumCreatedObject() << endl << endl;
	}
	~SpyPoint() {
		cout << "SpyPoint is destructed" << endl;
	}
};

int main() {
	Point pt1(10, 20), pt2(30, 40);
	cout << pt1 << endl;
	cout << "numCreatedObj: " << pt1.getNumCreatedObject() << endl;

	Point* pPt = new Point[5];
	cout << "numCreatedObj: " << pPt[2].getNumCreatedObject() << endl;
	delete[] pPt;

	SpyPoint spy;
	spy.hack_all_info(pt1);
	spy.hack_all_info(pt2);

	return 0;
}