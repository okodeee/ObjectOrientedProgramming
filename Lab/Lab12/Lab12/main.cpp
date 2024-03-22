#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

/* 기초 1번
class Base {
protected: //Base type
	void print_base() { cout << "Base" << endl; }
};

// Base type  |  상속 type   | Derived type
// private    |  상관없음    | 접근 불가 (Base함수로 접근)
// protected  |  상관없음    | private
// public     | private/protected | private
// public     | public       | public

class Derived : private Base {
public:
	void print_derived() {
		print_base();
		cout << "Derived" << endl;
	}
};

int main() {
	Base base;
	Derived derived;

	derived.print_derived();

	return 0;
}
*/

/* 기초 2번
// 함수 오버로딩: int    sum(int x, int y),
//                double sum(double x, double y)
//                float  sum(float x, float y, float z)
// 함수 오버라이딩 (상속의 특수한 경우 사용)
//void Text::append(string _extra)
//void Fancy::append(string _extra)

class Text {
private:
	string text;
public:
	Text(string _t) : text(_t) {}
	virtual string get() { return text; }
	virtual void append(string _extra) { text += _extra; }
};

class FancyText : public Text {
private:
	string left_brac;
	string right_brac;
	string connector;
public:
	FancyText(string _t, string _lb, string _rb, string _con) :
		Text::Text(_t), left_brac(_lb), right_brac(_rb), connector(_con) {}
	string get() override { return left_brac + Text::get() + right_brac; }
	void append(string _extra) override { Text::append(connector + _extra); }
};

class FixedText : public Text {
public:
	FixedText() : Text::Text("FIXED") {}
	void append(string _extra) override {}
};

int main() {
	Text t1("Plain");
	t1.append("A");
	cout << t1.get() << endl;

	FancyText t2("Fancy", "<<", ">>", "***");
	t2.append("A");
	cout << t2.get() << endl;

	FixedText t3;
	t3.append("A");
	cout << t3.get() << endl;
	t1 = t2;

	return 0;
}
*/

/* 응용 1번
class Polygon {
public:
	Polygon() {}
	Polygon(int point, float length) : mPoint(point), mLength(length) {}
	~Polygon() {}
	virtual void calcPerimeter() { cout << "Perimeter: empty" << endl; }
	virtual void calcArea() { cout << "Area: empty" << endl; }
protected:
	int mPoint;
	double mLength;
};

class Rectangle : public Polygon {
public:
	Rectangle() {}
	Rectangle(int point, float length) : Polygon(point, length) {}
	~Rectangle() {}
	void calcPerimeter() override { cout << "Perimeter: " << mPoint * mLength << endl; }
	void calcArea() override { cout << "Area: " << mLength * mLength << endl; }
};

int main() {
	Polygon pol;
	Rectangle rec(4, 10);

	cout << "--- Polygon class ---" << endl;
	pol.calcPerimeter();
	pol.calcArea();
	cout << "--- Rectangle class ---" << endl;
	rec.calcPerimeter();
	rec.calcArea();

	return 0;
}
*/

/* 응용 2번
class Polygon {
public:
	Polygon() {}
	Polygon(int point, float length) : mPoint(point), mLength(length) {}
	~Polygon() {}
	virtual void calcPerimeter() { cout << "Perimeter: empty" << endl; }
	virtual void calcArea() { cout << "Area: empty" << endl; }
protected:
	int mPoint;
	double mLength;
};

class Rectangle : public Polygon {
public:
	Rectangle() {}
	Rectangle(int point, float length) : Polygon(point, length) {}
	~Rectangle() {}
	void calcPerimeter() override { cout << "Perimeter: " << mPoint * mLength << endl; }
	void calcArea() override { cout << "Area: " << mLength * mLength << endl; }
};

class Triangle : public Polygon {
public:
	Triangle() {}
	Triangle(int point, float length) : Polygon(point, length) {}
	~Triangle() {}
	void calcPerimeter() override { cout << "Perimeter: " << mPoint*mLength << endl; }
	void calcArea() override { cout << "Area: " << mLength * mLength * sqrt(3) / 4 << endl; }
};

class Circle : public Polygon {
public:
	Circle() {}
	Circle(int point, float length) : Polygon(point, length) {}
	~Circle() {}
	void calcPerimeter() override { cout << "Perimeter: " << 3.14 * 2 * mLength << endl; }
	void calcArea() override { cout << "Area: " << mLength * mLength*3.14 << endl; }
};

int main() {
	Triangle tri(3, 10);
	Rectangle rec(4, 10);
	Circle cir(0, 5);
	cout << "--- Triangle class ---" << endl;
	tri.calcPerimeter();
	tri.calcArea();
	cout << "--- Rectangle class ---" << endl;
	rec.calcPerimeter();
	rec.calcArea();
	cout << "--- Circle class ---" << endl;
	cir.calcPerimeter();
	cir.calcArea();

	return 0;
}
*/

/* 응용 3번
class Train {
public:
	Train() { mPeople = 0; }
	Train(int people) { mPeople = people; }
	~Train() {}
	virtual int station(int takeOff, int takeOn) {
		return mPeople - takeOff + takeOn;
	}
protected:
	int mPeople;
};
class Ktx : public Train {
public:
	Ktx() : Train() {}
	Ktx(int people) : Train(people) {}
	~Ktx() {}
	int station(int takeOff, int takeOn) {
		mPeople -= takeOff;
		mPeople += takeOn;
		return mPeople;
	}
	int getPeople() { return mPeople; }
};

int main()
{
	Ktx k;
	int takeoff;
	int takeon;
	int high = 0;

	for (int i = 1; i < 6; i++) {
		cout << i << "번역: ";
		cin >> takeoff >> takeon;
		k.station(takeoff, takeon);
		if (k.getPeople() < 0) {
			cout << "정원미달입니다" << endl;
			exit(100);
		}
		else if (k.getPeople() > 300) {
			cout << "정원초과입니다" << endl;
			exit(100);
		}
		if (k.getPeople() > high)
			high = k.getPeople();
	}
	cout << "가장 많은 사람이 탑승했을 때의 사람 수: " << high << endl;
	
	return 0;
}
*/

/* 응용 4번
class Avengers {
public:
	Avengers() {
		name = "";
		attack_point = 0;
		defense_point = 0;
		health = 0;
	}
	~Avengers() {}
	virtual void set(string _name, int _attack, int _defense, int _health) {}
	virtual int attack() { return 0; }
	virtual void defense(int _attack_point) {}
	virtual void print_info() {}
protected:
	string name;
	int attack_point;
	int defense_point;
	int health;
};

class Character : public Avengers {
public:
	void set(string _name, int _attack, int _defense, int _health) override {
		name = _name;
		attack_point = _attack;
		defense_point = _defense;
		health = _health;
	}
	int attack() override { return 0; }
	void defense(int _attack_point) override {
		health -= (_attack_point - defense_point);
		if (health < 0)
			health = 0;
	}
	void print_info() override {
		cout << "Name: " << name << endl;
		cout << "Attack_Point: " << attack_point << endl;
		cout << "Defense_Point: " << defense_point << endl;
		cout << "Health: " << health << endl;
	}
	int get_attack() { return attack_point; }
	int get_health() { return health; }
};

int main() {
	Character my_char;
	Character enemy_char;
	string my_name;
	unsigned ran;

	cout << "Choose your character(IronMan, CaptainAmerica, Thor): ";
	cin >> my_name;
	if (my_name == "IronMan")
		my_char.set("IronMan", 70, 40, 100);
	else if (my_name == "CaptainAmerica")
		my_char.set("CaptainAmerica", 60, 50, 100);
	else
		my_char.set("Thor", 80, 30, 100);

	ran = rand() % 3;
	if (ran == 0)
		enemy_char.set("IronMan", 70, 40, 100);
	else if (ran == 1)
		enemy_char.set("CaptainAmerica", 60, 50, 100);
	else
		enemy_char.set("Thor", 80, 30, 100);

	cout << "--My Character--" << endl;
	my_char.print_info();
	cout << "--Enemy Character--" << endl;
	enemy_char.print_info();
	cout << endl;

	cout << endl << "--Battle--" << endl;
	cout << "My Life: " << my_char.get_health() << "\t"
		<< "Enemy Life:" << enemy_char.get_health() << endl;

	while (1) {
		enemy_char.defense(my_char.get_attack());
		cout << "My Life: " << my_char.get_health() << "\t"
			<< "Enemy Life:" << enemy_char.get_health() << endl;
		if (enemy_char.get_health() == 0) {
			cout << "You Win!" << endl;
			break;
		}
		my_char.defense(enemy_char.get_attack());
		cout << "My Life: " << my_char.get_health() << "\t"
			<< "Enemy Life:" << enemy_char.get_health() << endl;
		if (my_char.get_health() == 0) {
			cout << "You Lose!" << endl;
			break;
		}
	}

	return 0;
}
*/