#pragma once
#include <iostream>
#include <string>
using namespace std;


class Text {
protected:
	string text;
public:
	Text(string _t);
	virtual string get() const;
	virtual void append(string _extra) = 0;
};