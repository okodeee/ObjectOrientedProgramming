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
		// ���� �Ҵ�
		ary = new int[5];
	}
	// �Ҹ���
	~Point() {
		cout << x << ", " << y << " is destructed.." << endl;
		// file close
		// �Ҵ� ����
		delete[] ary;
	}
	void setXY(int _x, int _y) { x = _x; y = _y; }
	int getX() const { return x; } //const method: �ɹ� ������ �ٲ��� ����
	int getY() const { return y; }
	static int getNumCreatedObject() { return numCreatedObj; }
	// Point class�� operator<< �Լ��� ģ���� �����:
	friend ostream& operator<<(ostream& cout, const Point& pt);
	friend class SpyPoint;
	// A->B�� ģ���� ������ (B�� A�� private ��� ���� ��� ����)
	// ���� �������� �ʴ´� (A�� B�� private ��� ���� ���� �Ұ���)
};

// static ��� ���� �ʱ�ȭ
int Point::numCreatedObj = 0;

// ��ü�� �Է� type�� const�̸� ���ο��� const method�� ��밡��
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