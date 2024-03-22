#include <iostream>
#include <string> //string객체 사용
#include <fstream> //ifstream ofstream
#include <iomanip> // setw
#include <cstdlib>
using namespace std;

/* 기초 1번
int main() {
	string s1 = "mouse";
	cout << s1 << endl;
	cout << s1.length() << ", " << s1.size() << endl << endl; //s1의 length, size 출력
	
	cout << s1.empty() << endl;
	s1.clear();// s1 = "";
	cout << s1.empty() << endl;

	s1 = "Good";
	s1 = s1 + "-bye";
	// Good-bye (string)
	// 01234567 (index)
	cout << s1 << endl;
	cout << s1[4] << ", " << s1.at(4) << endl; // 두가지 방법으로 index 4 값 출력
	cout <<  (s1 == "Good-bye") << endl; // s1과 Good-bye 비교 (bool 값 출력)
	cout << (s1 == "good-bye") << endl; // s1과 good-bye 비교 (bool 값 출력)
	cout << (s1 >= "z") << endl << endl; // s1이 “z”보다 크거나 같은지 비교 (bool 값 출력)
	
	cout << s1.substr(5, 3) << endl; // s1의 index 5부터 3글자 출력
	cout << s1.substr(2, 2) << endl; // s1의 index 2부터 2글자 출력
	cout << s1.find("od") << endl; // od 위치 출력
	cout << s1.find("od", 5) << endl;
	int od_index = s1.find("od");
	cout << s1.find("od", od_index + 2);
	cout << (s1.find("korea") == string::npos) << endl;

	return 0;
}
*/

/* 기초 2번
int main() {
	ofstream fout; // processor->file 저장
	fout.open("example.txt");

	string s2 = "Objective Oriented Programming";
	fout << s2 << endl;
	fout << "Random Variables" << endl;
	fout << "Linear Algebra" << endl;

	fout.close();

	ifstream fin;
	string s1;
	fin.open("example.txt");
	if (!fin) {
		cout << "Error, no such file exists" << endl;
		exit(100);
	}
	
	while (getline(fin, s1)) { // line by line으로 example.txt에서 읽어와서 출력
		cout << s1 << endl;
	}
	
	
	//한번에 실행되지 않기 때문에 주석처리 해놓음
	while (1) { // 띄어쓰기 단위로 example.txt에서 읽어와서 출력
		fin >> s1;
		if (!fin)
			break;
		cout << s1 << endl;
	}
	
	fin.close();

	return 0;
}
*/

/* 기초 3번
int main() {
	double d1 = 1.23456789;

	cout << d1 << endl;

	cout.width(10);
	cout.precision(3);
	cout << d1 << endl;

	char ch1;
	char ch2;

	// ch1, ch2 : enter “ z”. ( space + z )
	cin >> ch1;
	cout << "(" << ch1 << ")" << endl;

	cin.ignore(); // enter가 다음 cin으로 들어가지 않도록 해줌

	cin.unsetf(ios::skipws);
	cin >> ch2;
	cout << "(" << ch2 << ")" << endl;

	return 0;
}
*/

/* 기초 4번
bool getStu(ifstream& fin, int& id, int& exam1, int& exam2, int& exam3) {
	fin >> id >> exam1 >> exam2 >> exam3;
	if (!fin)
		return false;
	return true;
}

void calcAvgGrade(int exam1, int exam2, int exam3, int& avg, char& grade) {
	avg = (exam1 + exam2 + exam3) / 3;
	if (avg >= 90)
		grade = 'A';
	else if (avg >= 80)
		grade = 'B';
	else
		grade = 'F';
}

void writeStu(ofstream& fout, int id, int avg, char grade) {
	fout.fill('0');
	fout << setw(4) << id;
	fout.fill(' ');
	fout << setw(4) << avg;
	fout << setw(4) << grade << endl;
}

int main() {
	//반복: 모든 학생을 읽고 저장할 때까지
		//getStu 함수 = ch7STUFL.DAT에서 파일 읽기: id, exam1, exam2, exam3
		//calcAvgGrade 함수 = 평균,grade 계산: exam1, exam2, exam3 -> avg, grade
		//writeStu 함수 = grade.txt 저장: id, avg, grade

	ifstream fin("ch7STUFL.DAT"); // 강의 사이트에서 다운로드 가능
	ofstream fout("grade.txt");
	int id, exam1, exam2, exam3, avg;
	char grade;

	while (getStu(fin, id, exam1, exam2, exam3)) { // getStu함수 사용
		calcAvgGrade(exam1, exam2, exam3, avg, grade); // calcAvgGrade함수 사용
		writeStu(fout, id, avg, grade); // writeStu함수 사용
	}

	fin.close();
	fout.close();

	cout << "end";

	return 0;
}
*/

/* 응용 1번
int main() {
	string address, city, area, street, building;

	cout << "시 : ";
	cin >> city;
	cout << "구 : ";
	cin >> area;
	cout << "로 : ";
	cin >> street;
	cout << "건물명 : ";
	cin >> building;
	cout << endl;

	address = city + area + street + building;
	cout << "집 주소 : " << address;

	return 0;
}
*/

/* 응용 2번
int main() {
	string data = "사랑,프로그래밍,의자,사랑의바보,영통역,천년의사랑,냉장고,객체지향";
	string key, word;
	int cursor = 0, comma;

	cout << "키워드 : ";
	cin >> key;
	cout << "검색결과 : ";

	while (true) {
		comma = data.find(',', cursor);
		word = data.substr(cursor, comma - cursor);
		if (word.find(key) != string::npos)
			cout << word << "  ";
		cursor += word.size() + 1;
		if (cursor >= data.size())
			break;
	}

	return 0;
}
*/

/* 응용 3번
int main() {
	ofstream fout("temp.txt");
	int temp;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			temp = rand() % 101;
			fout << temp << ' ';
		}
		fout << endl;
	}

	return 0;
}
*/

/* 응용 4번
int main() {
	string s;
	ofstream fout("combine.txt");
	ifstream fin;
	fin.open("text1.txt");
	while (getline(fin, s)) {
		fout << s << endl;
	}

	fin.close();
	fout << endl;

	fin.open("text2.txt");
	while (getline(fin, s)) {
		fout << s << endl;
	}

	fin.close();

	fout.close();

	return 0;
}
*/

/* 응용 5번
int main() {
	char ch;
	int count=0, length;
	cout << "length = ";
	cin >> length;
	ifstream fin("original.txt");
	ofstream fout("output.txt");
	while (fin) {
		fin.get(ch);
		if (!fin)
			break;
		else if (ch == '\n')
			continue;
		fout.put(ch);
		count++;
		if (count == length) {
			fout << endl;
			count = 0;
		}
	}

	fin.close();
	fout.close();

	return 0;
}
*/