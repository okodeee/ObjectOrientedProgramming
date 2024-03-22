#include <iostream>
#include <string>
#include <fstream> //ifstream, ofstream
using namespace std;

//				     | ifstream	   | ofstream
//-------------------+-------------+-----------
// char              | fin.get(c)  | fout.put(c)
// word(공백/줄바꿈) | fin >> s    | fout << s
// line(줄바꿈)      | getline(s)  | fout << s
// 주의할점: 1. fout/fin 사용 시 반드시 시작: open() 끝: close()
//           2. fin 용법: 파일 open 실패 또는 EOF일 경우 fin == false
//                (!fin == true)

int main() {
	ofstream fout;
	fout.open("example.txt"); //덮어쓰기
//	fout.open("example.txt", ios::app); //append: 이어쓰기
	string s = "Object oriented programming";
	fout << s << endl;
	fout << "Linear algebra" << endl;
	fout << "Random process" << endl;

	char c = 3;
	fout.put('1');
	fout.put('2');
	fout.put(c);
	fout.put('\n'); //endl:줄바꿈

	fout.close();


	ifstream fin;
	fin.open("example.txt");

	if (!fin) {
		cout << "File not found" << endl;
		exit(100);
	}


	//get: 하나의 문자(char)
	while (true) {
		fin.get(c);
		if (!fin)
			break;
		cout << c;
	}

	// 하나의 line씩 읽어서 s에 저장
//	while (getline(fin, s)) {
//		cout << s << endl;
//	}

	// fin >> :하나의 word를 읽음 (endl 또는 공백문자로 구분)
//	while (true) {
//		fin >> s;
//		if (!fin) //End Of File
//			break;
//		cout << s << endl;
//	}


	fin.close();

	return 0;
}


/*
int main() {
	string s = "fred";
	cout << "s: " << s << endl;
	cout << s.size() << endl << endl;

	cout << "s: " << s << endl;
	cout << s.empty() << endl;
	s.clear(); //빈문자열로 만듦 s = "";
	cout << "s: " << s << endl;
	cout << s.empty() << endl << endl;

	s = "Good";
	s += "-bye"; //s = s + "-bye" s <- "Good-bye"
	// Good-bye
	// 01234567 :index (zero-based indexing)
	cout << "s: " << s << endl;
	cout << s[4] << ", " << s.at(4) << endl;

	cout << s.substr(5, 2) << endl;
	cout << s.substr(5, 3) << endl << endl; //(시작 index, 추출할 문자열의 길이)

	cout << s.find("od") << endl;
	cout << s.find("od", 5) << ", " << string::npos << endl;
	cout << (s.find("od, 5") == string::npos) << endl;

	s += "-od";
	// Good-bye-od
	// 012345678910
	string key = "od";
	cout << "s: " << s << endl;
	int index = s.find(key);
	cout << index << endl;
	cout << s.find("od", index + key.size()) << endl;
	cout << (s == "good-bye-od") << endl; //case-sensitive: 대소문자를 다른 문자로 취급
	
	return 0;
}
*/