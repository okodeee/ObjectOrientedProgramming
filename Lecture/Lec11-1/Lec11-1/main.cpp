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
	int getX() const { return this->x; } //const method ���ο� �ɹ� ���� �������� �ٲ��� ����
	int getY() const { return this->y; }

	// this: ��ü �ڱ��ڽ��� ���� �ּҰ��� �����ϰ� �ִ� ������
	Point operator+(const Point& pt) {
		Point result(this->x + pt.getX(), this->y + pt.getY());
	}
};

// ��ü pass by ref.: const�� ������ ��� const method�� �Լ��ȿ��� ��� ����
void print(const Point& pt) {
	cout << pt.getX() << ", " << pt.getY() << endl;
}

//			operator+(�����ǿ�����, �����ǿ�����)
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

	// ������
	Point* pPt1 = &pt1;
	cout << (*pPt1).getX() << ", " << (*pPt1).getY() << endl;
	cout << pPt1->getX() << ", " << pPt1->getY() << endl;
	cout << endl;

	// ���� �Ҵ�
	Point* pPt2 = new Point(10, 20);
	cout << pPt2->getX() << ", " << pPt2->getY() << endl;
	delete pPt2;
	cout << endl;

	// ������ �����ε�(operator overloading)
	Point pt3(10, 20), pt4(30, 40);
	Point pt5 = pt3 + pt4; // pt5 = operator+(pt3, pt4)
	cout << pt3 << endl; // operator<<(cout, pt3)
	cout << pt4 << endl;
	cout << pt5 << endl;

	return 0;
}