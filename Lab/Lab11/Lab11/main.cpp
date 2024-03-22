#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* 기초 1번
class Point {
private:
	int x;
	int y;
	static int numCreatedObjects;
public:
	Point() : x(0), y(0) {
		numCreatedObjects++;
	}

	// int _x 와 int _y를 입력으로 받는 생성자
	Point(int _x, int _y) : x(_x), y(_y) {
		numCreatedObjects++;
	}

	~Point() {
		cout << "Destructed..." << endl;
	}

	void setXY(int _x, int _y) {
		//this-> 사용한 초기화
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

	//operator overloading(연산자 오버로딩)
	Point& operator=(Point& pt) {
		return pt;
	}

	static int getNumCreatedObject() { return numCreatedObjects; }
	friend void print(const Point& pt);
	friend ostream& operator<<(ostream& cout, Point& pt);
	friend class SpyPoint;
};

//static 맴버 변수 초기화 (numCreatedObjects)
int Point::numCreatedObjects = 0;

//객체 call by reference시: const로 함수 입력시 const method만 함수에서 사용가능
// const: 객체 내부의 member data가 상수(변하지 않는다)
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
	//다음과 같이 출력 되도록 hack_all_info함수 구현
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

	// 포인터
	Point* pPt1 = &pt1;
	// pPt1의 값을 통해 getX, getY를 호출하여 출력
	cout << "pt1 : ";
	cout << (*pPt1).getX() << ", " << (*pPt1).getY() << endl;
	// pPt1를 통해 호출 getX, getY를 호출하여 출력
	cout << "pt1 : ";
	cout << pPt1->getX() << ", " << pPt1->getY() << endl;

	cout << endl;

	//동적으로 Point* pPt2할당하여 10,20넣은 뒤 ->사용하여 출력(pt1 출력 참고)
	Point* pPt2 = new Point(10, 20);
	cout << "pt2 : ";
	cout << *pPt2 << endl;
	cout << endl;

	//pPt1, pPt2의 메모리 해제
	delete pPt2;

	cout << "pt1 NumCreatedObject : ";
	cout << pt1.getNumCreatedObject() << endl;

	// 연산자 오버로딩
	//pt4 = pt2, pt3값 더하기
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

	// ptAry 메모리 해제
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

/* 응용 1번
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

	cout << "첫번째 좌표(x1, y1)를 입력하세요 : ";
	cin >> x1 >> y1;

	cout << "두번째 좌표(x2, y2)를 입력하세요 : ";
	cin >> x2 >> y2;

	pP1 = new Point(x1, y1);
	pP2 = new Point(x2, y2);
	pP3 = new Point();

	*pP3 = (*pP1 - *pP2) * (*pP1 - *pP2);

	cout << "두 좌표 사이의 길이는 " << root(*pP3) << "입니다." << endl;

	return 0;
}
*/

/* 응용 2번
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
	cout << "학번: " << a.id;
	cout << ", 이름: " << a.name;
	cout << ", 잔액: " << a.balance;
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
		Account("장윤호", "2014", 10000),
		Account("김유민", "2019", 0),
		Account("박진배", "2013", 5000),
	};

	while (true) {
		string remit, receive;
		cout << "돈을 보낼 학생의 학번을 입력하세요: ";
		cin >> remit;
		if (remit == "종료") {
			cout << "종료합니다." << endl;
			cout << acnt[0] << endl;
			cout << acnt[1] << endl;
			cout << acnt[2] << endl;
			break;
		}
		cout << "돈을 받을 학생의 학번을 입력하세요: ";
		cin >> receive;

		int remit_acnum = acnum(remit);
		int receive_acnum = acnum(receive);
		if (remit_acnum == -1 || receive_acnum == -1)
			cout << "보내는 학생 혹은 받은 학생의 학번이 존재하지 않습니다.다시 입력해주세요." << endl;
		else if (remit_acnum == receive_acnum)
			cout << "보내는 학생과 받을 학생이 동일합니다." << endl;
		else if (acnt[remit_acnum].getBalance() == 0)
			cout << "보내는 학생의 잔액이 부족합니다." << endl;
		else {
			acnt[receive_acnum] + acnt[remit_acnum];
			acnt[remit_acnum] - acnt[receive_acnum];
			cout << "보낸 학생의 잔액 => ";
			cout << acnt[remit_acnum] << endl;
			cout << "받은 학생의 잔액 => ";
			cout << acnt[receive_acnum] << endl;
		}
	}
}
*/

/* 응용 3번
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
	cout << "총 학생 수 입력: ";
	cin >> num;

	Account* acAry = new Account[num];
	for (int i = 0; i < num; i++) {
		cout << i + 1 << "번째 학생 계좌 입력 : ";
		cout << "학번 : ";
		cin >> _id;
		acAry[i].setID(_id);
		cout << "\n이름 : ";
		cin >> _name;
		acAry[i].setName(_name);
		cout << "\n잔액 : ";
		cin >> _balance;
		acAry[i].setBalance(_balance);
		cout << "=========================" << endl << endl;
	}
	delete[] acAry;
	cout << "회수된 금액 : " << Account::sum << endl;
	return 0;
}
*/