#include <iostream>
using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	void setXY(int _x, int _y) {
		this->x = _x;
		this->y = _y;
	}
	int getX() const { return this->x; } //const method 내부에 맴버 변수 변수값이 바뀌지 않음
	int getY() const { return this->y; }

	// this: 객체 자기자신의 시작 주소값을 저장하고 있는 포인터
	Point operator+(const Point& pt) {
		Point result(this->x + pt.getX(), this->y + pt.getY());
	}
};

// 객체 pass by ref.: const로 설정할 경우 const method만 함수안에서 사용 가능
void print(const Point& pt) {
	cout << pt.getX() << ", " << pt.getY() << endl;
}

//			operator+(좌측피연산자, 우측피연산자)
//Point operator+(const Point& pt1, const Point& pt2) {
//	Point result(pt1.getX() + pt2.getX(), pt1.getY() + pt2.getY());
//	return result;
//}

// cout << pt -> operator<<(cout, pt)
ostream& operator<<(ostream& cout, Point pt) {
	cout << pt.getX() << ", " << pt.getY();
	return cout;
}

int main() {
	Point pt1(1, 2);
	print(pt1);

	// 포인터
	Point* pPt1 = &pt1;
	cout << (*pPt1).getX() << ", " << (*pPt1).getY() << endl;
	cout << pPt1->getX() << ", " << pPt1->getY() << endl;
	cout << endl;

	// 동적 할당
	Point* pPt2 = new Point(10, 20);
	cout << pPt2->getX() << ", " << pPt2->getY() << endl;
	delete pPt2;
	cout << endl;

	// 연산자 오버로딩(operator overloading)
	Point pt3(10, 20), pt4(30, 40);
	Point pt5 = pt3 + pt4; // pt5 = operator+(pt3, pt4)
	cout << pt3 << endl; // operator<<(cout, pt3)
	cout << pt4 << endl;
	cout << pt5 << endl;

	return 0;
}