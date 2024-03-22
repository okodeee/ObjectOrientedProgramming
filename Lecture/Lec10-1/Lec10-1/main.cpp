#include <iostream>
using namespace std;

// class ����� ��
// 1) class name{ };
// 2) private:, public: ���� ����
// 3) member data ����� in private:
// 4) method      ����� in public:
// 5) �ʱ�ȭ �Լ�(constructor, ������)
//   - ������ �̸��� class �̸��� ����
//   - ���� ���� �����ڸ� ������ ������, default ������(Point(){}) �� �ڵ����� ����
//   - ���� ���� �����ڸ� �����, default ������ �ڵ� ���� �ȵ�

class Point {
private: // �ܺ�(main)���� ���� �Ұ���, member data
	int x;
	int y;
public:  // �ܺ�(main)���� ���� ����, member function (method)
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