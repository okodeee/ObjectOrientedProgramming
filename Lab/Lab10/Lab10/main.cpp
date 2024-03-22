#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 기초 1번
class Point {
private:
	int x;
	int y;

public:
	Point() {}
	Point(int _x, int _y) {
		x = _x;
		y = _y;
	}

	void setXY(int _x, int _y) {
		x = _x;
		y = _y;
	}

	int getX() { return x; }
	int getY() { return y; }

	void print() {
		cout << x << ", " << y << endl;
	}
};

int main() {
	Point pt1(1, 2), pt2(3, 4);
	pt1.setXY(10, 20);
	pt1.print();
	pt2.print();

	cout << pt1.getX() << endl;
	cout << pt2.getY() << endl;
	return 0;
}
*/

/* 기초 2번
class Account {
//private: //멤버변수
	string name;
	string id;
	double balance;
public: // 멤버함수(method)
	Account() {
		name = "";
		id = "";
		balance = 0.0;
	}
	Account(string _name, string _id) {
		name = _name;
		id = _id;
		balance = 0.0;
	}
	Account(string _name, string _id, double _balance) {
		name = _name;
		id = _id;
		balance = _balance;
		if (balance < 0)
			balance = 0.0;
	}
	void deposit(double _amt) { balance += _amt; }
	bool withdraw(double _amt) {
		if (balance - _amt < 0)
			return false;
		balance -= _amt;
		return true;
	}
	void print() {
		cout << name << ", " << id << ", " << balance << endl << endl;
	}
};

int main() {
	Account ac1("배성호", "1002", 5000);
	Account ac2;
	ac2.print();
	ac1.print();

	int depo;
	cout << "예금할 금액을 입력하세요 : ";
	cin >> depo;
	ac1.deposit(depo);
	ac1.print();

	int wdrw;
	cout << "출금할 금액을 입력하세요 : ";
	cin >> wdrw;
	if (!ac1.withdraw(wdrw))
		cout << "잔액이 부족합니다." << endl;
	ac1.print();
	return 0;
}
*/

/* 응용 1번
class CStudent {
private:
	int number;
	string name;
	string major;
public:
	CStudent()
		: number(2018000000), name("홍길동"), major("컴퓨터공학과") {}
	CStudent(int _number, string _name, string _major)
		: number(_number), name(_name), major(_major) {}

	void setNumber(int _number) { number = _number; }
	void setName(string _name) { name = _name; }
	void setMajor(string _major) { major = _major; }

	int	getNumber() { return number; }
	string getName() { return name; }
	string getMajor() { return major; }

	void Display() {
	cout << "학번 :" << number << endl;
	cout << "이름 :" << name << endl;
	cout << "전공 :" << major << endl << endl;
	}
};

int main() {
	CStudent s1;
	s1.Display();

	CStudent s2(1999000000, "공지철", "연극영화과");
	s2.Display();

	s1.setNumber(2006000000);
	s1.setName("민경훈");
	s1.setMajor("포스트모던");
	cout << "학번 :" << s1.getNumber() << endl;
	cout << "이름 :" << s1.getName() << endl;
	cout << "전공 :" << s1.getMajor() << endl;

	return 0;
}
*/

/* 응용 2번
class CStudent {
private:
	int number;
	string name;
	string major;
public:
	CStudent()
		: number(2018000000), name("홍길동"), major("컴퓨터공학과") {}
	CStudent(int _number, string _name, string _major)
		: number(_number), name(_name), major(_major) {}

	void setNumber(int _number) { number = _number; }
	void setName(string _name) { name = _name; }
	void setMajor(string _major) { major = _major; }

	int	getNumber() { return number; }
	string getName() { return name; }
	string getMajor() { return major; }

	void Display() {
		cout << "학번 :" << number << endl;
		cout << "이름 :" << name << endl;
		cout << "전공 :" << major << endl << endl;
	}
};

int main() {
	CStudent s[3];
	int inputNumber;
	string inputName, inputMajor;
	int length = 0;

	while (1) {
		if (length == 3) {
			cout << "----모든입력이 완료되었습니다----\n1학생정보\n";
			s[0].Display();
			cout << "2학생정보" << endl;
			s[1].Display();
			cout << "3학생정보" << endl;
			s[2].Display();
			break;
		}
		cout << length + 1 << " 번째 학생 입력" << endl;
		cout << "학번 : ";
		cin >> inputNumber;
		cout << "이름 : ";
		cin >> inputName;
		cout << "전공 : ";
		cin >> inputMajor;
		int dup = 0;
		for (int i = 0; i < length; i++) {
			if (s[i].getNumber() == inputNumber) {
				dup++;
				break;
			}
		}
		if (dup == 0) {
			s[length].setNumber(inputNumber);
			s[length].setName(inputName);
			s[length].setMajor(inputMajor);
			cout << "※입력 완료";
			length++;
		}
		else
			cout << "※중복된 학번이 존재합니다";
		cout << endl << endl;
	}
}
*/

/* 응용 3번
class Student {
private:
	string name;
	int id;
	string depart;
	vector<string> subjects;
	vector<char> grades;
public:
	Student()
		: name("default"), id(0), depart("depart") {}
	Student(string _name, int _id, string _depart)
		: name(_name), id(_id), depart(_depart) {}

	void setName(string _name) { name = _name; }
	void setID(int _id) { id = _id; }
	void setDpt(string _depart) { depart = _depart; }

	void print() {
		cout << name << " " << id << " " << depart << endl;
	}
	void addGrade(string _subject, char _grade) {
		subjects.push_back(_subject);
		grades.push_back(_grade);
	}
	void printGrades() {
		for (int i = 0; i < subjects.size(); i++) {
			cout << subjects[i] << " " << grades[i] << endl;
		}
		cout << "GPA : " << getGPA();
	}
	float getGPA() {
		float sum = 0;
		for (char elem : grades) {
			if (elem == 'A')
				sum += 4;
			else if (elem == 'B')
				sum += 3;
			else if (elem = 'C')
				sum += 2;
			else if (elem = 'D')
				sum += 1;
		}
		return sum / grades.size();
	}
	void getYear(int year) {
		int gap = year * 1000000 - id;
		if (gap >= 3000000)
			cout << "About to graduate(5학년)";
		else if (gap >= 2000000)
			cout << "Senior(4학년)";
		else if (gap >= 1000000)
			cout << "Junior(3학년)";
		else if (gap >= 0)
			cout << "Sophomore(2학년)";
		else
			cout << "Freshmen(1학년)";
		cout << endl;
	}
};

int main() {
	Student Harry("Harry", 2017310973, "CS");
	Harry.print();
	Harry.getYear(2019);
	Harry.addGrade("programming", 'A');
	Harry.addGrade("Basic Circuit", 'B');
	Harry.printGrades();
	cout << "\n\n";

	Student Ron;
	Ron.print();
	cout << "\n";
	Ron.setName("Ron");
	Ron.setID(2014103959);
	Ron.setDpt("EE");
	Ron.print();
	Ron.getYear(2019);
	Ron.addGrade("Computer Architecture", 'B');
	Ron.addGrade("Maching Learning", 'B');
	Ron.addGrade("Computer Vision", 'C');
	Ron.printGrades();
	cout << "\n\n";

	return 0;
}
*/