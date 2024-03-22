#pragma once
#include <iostream>
#include <string>
using namespace std;


class Text {
private:
	string text;
public:
	Text(string _t);
	virtual string get();
	virtual void append(string _extra);
};

