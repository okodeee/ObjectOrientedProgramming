#include <iostream>
#include <string> //string��ü ���
#include <fstream> //ifstream ofstream
#include <iomanip> // setw
#include <cstdlib>
using namespace std;

/* ���� 1��
int main() {
	string s1 = "mouse";
	cout << s1 << endl;
	cout << s1.length() << ", " << s1.size() << endl << endl; //s1�� length, size ���
	
	cout << s1.empty() << endl;
	s1.clear();// s1 = "";
	cout << s1.empty() << endl;

	s1 = "Good";
	s1 = s1 + "-bye";
	// Good-bye (string)
	// 01234567 (index)
	cout << s1 << endl;
	cout << s1[4] << ", " << s1.at(4) << endl; // �ΰ��� ������� index 4 �� ���
	cout <<  (s1 == "Good-bye") << endl; // s1�� Good-bye �� (bool �� ���)
	cout << (s1 == "good-bye") << endl; // s1�� good-bye �� (bool �� ���)
	cout << (s1 >= "z") << endl << endl; // s1�� ��z������ ũ�ų� ������ �� (bool �� ���)
	
	cout << s1.substr(5, 3) << endl; // s1�� index 5���� 3���� ���
	cout << s1.substr(2, 2) << endl; // s1�� index 2���� 2���� ���
	cout << s1.find("od") << endl; // od ��ġ ���
	cout << s1.find("od", 5) << endl;
	int od_index = s1.find("od");
	cout << s1.find("od", od_index + 2);
	cout << (s1.find("korea") == string::npos) << endl;

	return 0;
}
*/

/* ���� 2��
int main() {
	ofstream fout; // processor->file ����
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
	
	while (getline(fin, s1)) { // line by line���� example.txt���� �о�ͼ� ���
		cout << s1 << endl;
	}
	
	
	//�ѹ��� ������� �ʱ� ������ �ּ�ó�� �س���
	while (1) { // ���� ������ example.txt���� �о�ͼ� ���
		fin >> s1;
		if (!fin)
			break;
		cout << s1 << endl;
	}
	
	fin.close();

	return 0;
}
*/

/* ���� 3��
int main() {
	double d1 = 1.23456789;

	cout << d1 << endl;

	cout.width(10);
	cout.precision(3);
	cout << d1 << endl;

	char ch1;
	char ch2;

	// ch1, ch2 : enter �� z��. ( space + z )
	cin >> ch1;
	cout << "(" << ch1 << ")" << endl;

	cin.ignore(); // enter�� ���� cin���� ���� �ʵ��� ����

	cin.unsetf(ios::skipws);
	cin >> ch2;
	cout << "(" << ch2 << ")" << endl;

	return 0;
}
*/

/* ���� 4��
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
	//�ݺ�: ��� �л��� �а� ������ ������
		//getStu �Լ� = ch7STUFL.DAT���� ���� �б�: id, exam1, exam2, exam3
		//calcAvgGrade �Լ� = ���,grade ���: exam1, exam2, exam3 -> avg, grade
		//writeStu �Լ� = grade.txt ����: id, avg, grade

	ifstream fin("ch7STUFL.DAT"); // ���� ����Ʈ���� �ٿ�ε� ����
	ofstream fout("grade.txt");
	int id, exam1, exam2, exam3, avg;
	char grade;

	while (getStu(fin, id, exam1, exam2, exam3)) { // getStu�Լ� ���
		calcAvgGrade(exam1, exam2, exam3, avg, grade); // calcAvgGrade�Լ� ���
		writeStu(fout, id, avg, grade); // writeStu�Լ� ���
	}

	fin.close();
	fout.close();

	cout << "end";

	return 0;
}
*/

/* ���� 1��
int main() {
	string address, city, area, street, building;

	cout << "�� : ";
	cin >> city;
	cout << "�� : ";
	cin >> area;
	cout << "�� : ";
	cin >> street;
	cout << "�ǹ��� : ";
	cin >> building;
	cout << endl;

	address = city + area + street + building;
	cout << "�� �ּ� : " << address;

	return 0;
}
*/

/* ���� 2��
int main() {
	string data = "���,���α׷���,����,����ǹٺ�,���뿪,õ���ǻ��,�����,��ü����";
	string key, word;
	int cursor = 0, comma;

	cout << "Ű���� : ";
	cin >> key;
	cout << "�˻���� : ";

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

/* ���� 3��
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

/* ���� 4��
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

/* ���� 5��
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