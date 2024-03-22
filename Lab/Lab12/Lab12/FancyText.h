#pragma once
#include <iostream>
#include <string>
#include "Text.h"
using namespace std;


class FancyText : public Text {
private:
	string left_brac;
	string right_brac;
	string connector;
public:
	FancyText(string _t, string _lb, string _rb, string _con);
	string get() override;
	void append(string _extra) override;
};
