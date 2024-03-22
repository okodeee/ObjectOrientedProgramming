#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

// 1) class name {};
// 2) private:, public:
// 3) private: member data
// 4) public: member function - 생성자, get(), set(), print()...
// 5) 생성자(constructor) - 객체 선언시 자동으로 1회 호출 - member data를 호출
//       - 리턴 타입 없음, 생성자의 이름은 class 이름과 동일
//       - 만약 생성자를 만들지 않으면, dafault 생성자(Account(){})가 자동으로 생성
//       - 만약 생성자를 만들면, default 생성자가 자동 생성되지 않음
//       - initialization list: 멤버 변수를 초기화하는 부분 - 예외처리 부분과 구분
// 6) (optional): method를 선언과 정의 구분

class Account {
private:
	string name;
	string id;
	double balance;
public:
	//initialization list
	Account(string _name = "xxx", string _id = "0000", double _bal = 0.0);
	void deposit(int _amt);
	bool withdraw(double _amt);
	void print();
};


Account::Account(string _name, string _id, double _bal)
	: name(_name), id(_id), balance(_bal) {
	if (balance < 0) {
		cout << "Error: negative balance" << endl;
		balance = 0;
	}
}

void Account::deposit(int _amt) {
	balance += _amt;
}

bool Account::withdraw(double _amt) {
	double temp = balance - _amt;
	if (temp < 0)
		return false;
	else {
		balance = temp;
		return true;
	}
}

void Account::print() {
	cout << setw(10) << name
		<< setw(10) << id
		<< setw(10) << balance << endl;
}

int main() {
	Account ac1("홍길동", "1002", 5000), ac2;
	ac1.print();
	ac2.print();

	ac1.deposit(10000);
	ac1.print();

	if (ac1.withdraw(20000))
		cout << "출금 성공." << endl;
	else
		cout << "출금 실패." << endl;
	ac1.print();

	if (ac1.withdraw(15000))
		cout << "출금 성공." << endl;
	else
		cout << "출금 실패." << endl;
	ac1.print();

	vector<Account> vec(10);
	for (auto& elem : vec)
		elem.print();

	return 0;
}