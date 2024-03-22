#include <iostream>
#include <vector>
using namespace std;

// private, protected, public
// protected: 상속을 위해서 존재하는 특수 type (Base class에서는 private으로 동작)


//  Base type | Inheritance type | Derived type
//  private   |     상관없음     | 접근불가(base class의 method를 통해서 접근)
//  protected |     상관없음     | private (클래스 내부에서 사용가능)
//  public    | private/protected| private
//  public    |      public      | public (클래스 내부/외부에서 사용가능)

class Base {
public: // Base type
	void print_base() { cout << "print_base()" << endl; }
	virtual void print() { cout << "Base::print()" << endl; }
};

class Derived : public Base { // Inheritance type
public:
	void print_derived() { 
		cout << "print_derived()" << endl;
		Base::print_base();
	}
	void print() override { cout << "Derived::print()" << endl; }
};

int main() {
	Base base;
	Derived derived;
	base.print_base();
	derived.print_derived();
	derived.print_base();
	cout << endl;

	// 함수 오버라이딩(overriding): base class의 method를 derived class에서 재정의(입력, 이름, 출력 모두 동일)
	// - 함수 오버로딩: 같은 이름을 가진 함수(입/출력은 다를 수 있음) 여러개 정의, 상속이랑 무관
	// 정적 바인딩(static binding): compile시 객체가 어떤 method를 호출할지를 미리 지정
	base.print();
	derived.print();
	cout << endl;

	// 동적 바인딩(dynamic binding): run-time시 호출할 method들이 상황에 따라 가변
	// - pointer: Base class의 pointer에 derived class의 주소값을 할당
	// - 핵심 키워드: virtual, override
	// - 다형성을 구현: single interface(base class의 pointer)로
	//                  다양한 entitied(derived class 객체)를 사용 가능
	Base* pBase = &derived;
	pBase->print();
	pBase = &base;
	pBase->print();

	// 다형성 응용 예시
	//               {  0x00,           0x10,     0x20,    0x30
	vector<Base*> vec{ new Base, new Derived, new Base };
	pBase = new Derived;
	vec.push_back(pBase);

	for (auto elem : vec)
		elem->print();

	for (auto elem : vec)
		delete elem;

	return 0;
}