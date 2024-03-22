#include <iostream>
#include <vector>
#include <string>
using namespace std;

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
	FancyText(string _t, string _lb, string _rb, string _con)
		: Text::Text(_t), left_brac(_lb), right_brac(_rb), connector(_con) {}
	string get() override { return left_brac + Text::get() + right_brac; }
	void append(string _extra) override {
		Text::append(connector + _extra);
	}
};

class FixedText : public Text {
public:
	FixedText() : Text::Text("FIXED") {}
	void append(string _extra) override {
		// NOOP
	}
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
	cout << endl;

	vector<Text*> v{ new Text("Plain"), new FancyText("Fancy1", "<", ">", "-"), new FixedText };
	Text* pText;
	pText = new FancyText("Fancy2", "[", "]", "*");
	v.push_back(pText);
	pText = new FixedText;
	v.push_back(pText);

	for (auto elem : v)
		elem->append("A");

	for (unsigned i = 0; i < v.size(); i++)
		cout << i << " : " << v.at(i)->get() << endl;

	for (auto elem : v)
		delete elem;

	return 0;
}

/*
// �߻�Ŭ����(abstract class)
// - ���� ���� �Լ��� ��� �ϳ� ������ �ִ� Ŭ����
// - ��üȭ(instantiation)�� �� ����
// - base class�� pointer��, ���������� single interface�� ����
class Cursor {
public:
	virtual void draw() = 0; //���� ���� �Լ�(pure virtual function)
	                         // - �ڽ�Ŭ�������� �ݵ�� �����ε� �ؾ���
};

class Round : public Cursor {
public:
	void draw() override { cout << "Round::draw()" << endl; }
};

class Rectangle : public Cursor {
public:
	void draw() override { cout << "Rectangle::draw()" << endl; }
};

int main() {
	// ���� ���ε�
//	Cursor cursor;
	Round round;
	Rectangle rectangle;
//	cursor.draw();
	round.draw();
	rectangle.draw();
	cout << endl;

	// ���� ���ε�(dynamic binding): run-time�� ȣ���� method���� ��Ȳ�� �°� ����
	// - base class�� pointer�� derived class�� �ּҰ��� �Ҵ�
	// - �ٽ� Ű����: virtual, override
	// - ������: single interface(base class�� pointer)�� �پ��� entities(derived class ��ü) ���
	Cursor* pCur;
//	pCur = &cursor;
//	pCur->draw();
	pCur = &round;
	pCur->draw();
	pCur = &rectangle;
	pCur->draw();
	cout << endl;

	vector<Cursor*> vec{ new Round, new Rectangle, new Round };

	for (auto elem : vec)
		elem->draw();

	for (auto elem : vec)
		delete elem;

	return 0;
}
*/