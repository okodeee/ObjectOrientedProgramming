#pragma once
#include <iostream>
#include <string>
#include "Text.h"
using namespace std;


class FixedText : public Text {
public:
	FixedText();
	void append(string _extra) override;
};
