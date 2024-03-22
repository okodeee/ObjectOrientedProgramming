#include <iostream>
#include <string>
#include <vector>
#include "CText.h"
#include "CFancyText.h"
#include "CFixedText.h"
using namespace std;


int main() {
	vector<Text*> vec{ new FixedText, new FancyText("Fancy", "<", ">", "*") };
	Text* pText;
	pText = new FixedText;
	vec.push_back(pText);

	for (auto elem : vec) {
		elem->append("A");
		cout << elem->get() << endl;
	}

	for (auto elem : vec)
		delete elem;

	return 0;
}