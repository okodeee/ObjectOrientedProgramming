#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* ���� 1��
class Point {
private:
	int x;
	int y;
	static int numCreatedObjects;
public:
	Point() : x(0), y(0) {
		numCreatedObjects++;
	}

	// int _x �� int _y�� �Է����� �޴� ������
	Point(int _x, int _y) : x(_x), y(_y) {
		numCreatedObjects++;
	}

	~Point() {
		cout << "Destructed..." << endl;
	}

	void setXY(int _x, int _y) {
		//this-> ����� �ʱ�ȭ
		this->x = _x;
		this->y = _y;
	}

	int getX() const { return x; }
	int getY() const { return y; }

	// *this + pt2 ->
	Point operator+(Point& pt2) {
		Point result(this->x + pt2.getX(), this->y + pt2.getY());
		return result;
	}

	//operator overloading(������ �����ε�)
	Point& operator=(Point& pt) {
		return pt;
	}

	static int getNumCreatedObject() { return numCreatedObjects; }
	friend void print(const Point& pt);
	friend ostream& operator<<(ostream& cout, Point& pt);
	friend class SpyPoint;
};

//static �ɹ� ���� �ʱ�ȭ (numCreatedObjects)
int Point::numCreatedObjects = 0;

//��ü call by reference��: const�� �Լ� �Է½� const method�� �Լ����� ��밡��
// const: ��ü ������ member data�� ���(������ �ʴ´�)
void print(const Point& pt) {
	cout << pt.x << ", " << pt.y << endl;
}

//Point operator+(Point& pt1, Point& pt2){
// Point result(pt1.getX() + pt2.get(X), pt1.getY() + pt2.getY());
// return result;
//}

ostream& operator<<(ostream& cout, Point& pt) {
	cout << pt.x << ", " << pt.y;
	return cout;
}

class SpyPoint {
public:
	//������ ���� ��� �ǵ��� hack_all_info�Լ� ����
	//Hacked by SpyPoint
	//x: 40
	//y: 60
	//numCreatedObj.: 10

	void hack_all_info(const Point& pt) {
		cout << "Hacked by SpyPoint" << endl;
		cout << "x: " << pt.x << endl;
		cout << "y: " << pt.y << endl;
		cout << "numCreatedObj.: " << pt.getNumCreatedObject() << endl;
	}
};

int main() {
	Point pt1(1, 2);
	cout << "pt1 : ";
	print(pt1);
	cout << endl;

	// ������
	Point* pPt1 = &pt1;
	// pPt1�� ���� ���� getX, getY�� ȣ���Ͽ� ���
	cout << "pt1 : ";
	cout << (*pPt1).getX() << ", " << (*pPt1).getY() << endl;
	// pPt1�� ���� ȣ�� getX, getY�� ȣ���Ͽ� ���
	cout << "pt1 : ";
	cout << pPt1->getX() << ", " << pPt1->getY() << endl;

	cout << endl;

	//�������� Point* pPt2�Ҵ��Ͽ� 10,20���� �� ->����Ͽ� ���(pt1 ��� ����)
	Point* pPt2 = new Point(10, 20);
	cout << "pt2 : ";
	cout << *pPt2 << endl;
	cout << endl;

	//pPt1, pPt2�� �޸� ����
	delete pPt2;

	cout << "pt1 NumCreatedObject : ";
	cout << pt1.getNumCreatedObject() << endl;

	// ������ �����ε�
	//pt4 = pt2, pt3�� ���ϱ�
	Point pt2(10, 20), pt3(30, 40), pt4(40, 60);
	cout << "pt2 : ";
	cout << pt2 << endl;
	cout << "pt3 : ";
	cout << pt3 << endl;
	cout << "pt4 : ";
	cout << pt4 << endl;

	cout << "pt1 NumCreatedObject : ";
	cout << pt1.getNumCreatedObject() << endl << endl;

	// object array
	Point* ptAry = new Point[5];
	cout << "pt2 NumCreatedObject : ";
	cout << pt2.getNumCreatedObject() << endl;
	cout << endl;

	// ptAry �޸� ����
	delete[] ptAry;

	cout << endl;

	// friend class
	SpyPoint spy;
	cout << "pt1 info" << endl;
	spy.hack_all_info(pt1);
	cout << endl;
	cout << "pt4 info" << endl;
	spy.hack_all_info(pt4);
	cout << endl;

	return 0;
}
*/

/* ���� 1��
class Point {
private:
	int x;
	int y;
public:
	Point() : x(0), y(0) {}
	Point(int _x, int _y) : x(_x), y(_y) {}

	void setPoint(int _x, int _y) { this->x = _x; this->y = _y; }

	Point operator-(Point& pt) {
		Point result(this->x - pt.x, this->y - pt.y);
		return result;
	}
	Point operator*(const Point& pt) {
		Point result(this->x * pt.x, this->y * pt.y);
		return result;
	}
	Point operator=(const Point& pt) {
		Point result(this->x = pt.x, this->y = pt.y);
		return result;
	}
	friend double root(Point& pt);
};

double root(Point& pt) {
	double result = sqrt(pt.x + pt.y);
	return result;
}

int main() {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	Point* pP1, * pP2, * pP3;

	cout << "ù��° ��ǥ(x1, y1)�� �Է��ϼ��� : ";
	cin >> x1 >> y1;

	cout << "�ι�° ��ǥ(x2, y2)�� �Է��ϼ��� : ";
	cin >> x2 >> y2;

	pP1 = new Point(x1, y1);
	pP2 = new Point(x2, y2);
	pP3 = new Point();

	*pP3 = (*pP1 - *pP2) * (*pP1 - *pP2);

	cout << "�� ��ǥ ������ ���̴� " << root(*pP3) << "�Դϴ�." << endl;

	return 0;
}
*/

/* ���� 2��
class Account {
private:
	string name;
	string id;
	int balance;
public:
	Account(string _name, string _id, int _balance)
		: name(_name), id(_id), balance(_balance) {}

	int getBalance() { return balance; }

	void operator+(const Account& a) { this->balance += a.balance; }
	void operator-(const Account& a) { this->balance = 0; }

	friend ostream& operator<<(ostream& cout, const Account& a);
};

ostream& operator<<(ostream& cout, const Account& a) {
	cout << "�й�: " << a.id;
	cout << ", �̸�: " << a.name;
	cout << ", �ܾ�: " << a.balance;
	return cout;
}

int acnum(string id) {
	if (id == "2014")
		return 0;
	else if (id == "2019")
		return 1;
	else if (id == "2013")
		return 2;
	return -1;
}

int main() {
	Account acnt[3] = {
		Account("����ȣ", "2014", 10000),
		Account("������", "2019", 0),
		Account("������", "2013", 5000),
	};

	while (true) {
		string remit, receive;
		cout << "���� ���� �л��� �й��� �Է��ϼ���: ";
		cin >> remit;
		if (remit == "����") {
			cout << "�����մϴ�." << endl;
			cout << acnt[0] << endl;
			cout << acnt[1] << endl;
			cout << acnt[2] << endl;
			break;
		}
		cout << "���� ���� �л��� �й��� �Է��ϼ���: ";
		cin >> receive;

		int remit_acnum = acnum(remit);
		int receive_acnum = acnum(receive);
		if (remit_acnum == -1 || receive_acnum == -1)
			cout << "������ �л� Ȥ�� ���� �л��� �й��� �������� �ʽ��ϴ�.�ٽ� �Է����ּ���." << endl;
		else if (remit_acnum == receive_acnum)
			cout << "������ �л��� ���� �л��� �����մϴ�." << endl;
		else if (acnt[remit_acnum].getBalance() == 0)
			cout << "������ �л��� �ܾ��� �����մϴ�." << endl;
		else {
			acnt[receive_acnum] + acnt[remit_acnum];
			acnt[remit_acnum] - acnt[receive_acnum];
			cout << "���� �л��� �ܾ� => ";
			cout << acnt[remit_acnum] << endl;
			cout << "���� �л��� �ܾ� => ";
			cout << acnt[receive_acnum] << endl;
		}
	}
}
*/

/* ���� 3��
class Account {
private:
	string id;
	string name;
	int balance;

public:
	Account() : id(""), name(""), balance(0) {}
	~Account() {
		sum += this->balance;
	}

	void setID(string _id) { this->id = _id; }
	void setName(string _name) { this->name = _name; }
	void setBalance(int _balance) { this->balance = _balance; }

	static int sum;
};

int Account::sum = 0;

int main() {
	string _id, _name;
	int _balance;
	int num;
	cout << "�� �л� �� �Է�: ";
	cin >> num;

	Account* acAry = new Account[num];
	for (int i = 0; i < num; i++) {
		cout << i + 1 << "��° �л� ���� �Է� : ";
		cout << "�й� : ";
		cin >> _id;
		acAry[i].setID(_id);
		cout << "\n�̸� : ";
		cin >> _name;
		acAry[i].setName(_name);
		cout << "\n�ܾ� : ";
		cin >> _balance;
		acAry[i].setBalance(_balance);
		cout << "=========================" << endl << endl;
	}
	delete[] acAry;
	cout << "ȸ���� �ݾ� : " << Account::sum << endl;
	return 0;
}
*/