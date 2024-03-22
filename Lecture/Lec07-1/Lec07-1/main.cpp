#include <iostream>
#include <string>
#include <fstream> //ifstream, ofstream
using namespace std;

//				     | ifstream	   | ofstream
//-------------------+-------------+-----------
// char              | fin.get(c)  | fout.put(c)
// word(����/�ٹٲ�) | fin >> s    | fout << s
// line(�ٹٲ�)      | getline(s)  | fout << s
// ��������: 1. fout/fin ��� �� �ݵ�� ����: open() ��: close()
//           2. fin ���: ���� open ���� �Ǵ� EOF�� ��� fin == false
//                (!fin == true)

int main() {
	ofstream fout;
	fout.open("example.txt"); //�����
//	fout.open("example.txt", ios::app); //append: �̾��
	string s = "Object oriented programming";
	fout << s << endl;
	fout << "Linear algebra" << endl;
	fout << "Random process" << endl;

	char c = 3;
	fout.put('1');
	fout.put('2');
	fout.put(c);
	fout.put('\n'); //endl:�ٹٲ�

	fout.close();


	ifstream fin;
	fin.open("example.txt");

	if (!fin) {
		cout << "File not found" << endl;
		exit(100);
	}


	//get: �ϳ��� ����(char)
	while (true) {
		fin.get(c);
		if (!fin)
			break;
		cout << c;
	}

	// �ϳ��� line�� �о s�� ����
//	while (getline(fin, s)) {
//		cout << s << endl;
//	}

	// fin >> :�ϳ��� word�� ���� (endl �Ǵ� ���鹮�ڷ� ����)
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
	s.clear(); //���ڿ��� ���� s = "";
	cout << "s: " << s << endl;
	cout << s.empty() << endl << endl;

	s = "Good";
	s += "-bye"; //s = s + "-bye" s <- "Good-bye"
	// Good-bye
	// 01234567 :index (zero-based indexing)
	cout << "s: " << s << endl;
	cout << s[4] << ", " << s.at(4) << endl;

	cout << s.substr(5, 2) << endl;
	cout << s.substr(5, 3) << endl << endl; //(���� index, ������ ���ڿ��� ����)

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
	cout << (s == "good-bye-od") << endl; //case-sensitive: ��ҹ��ڸ� �ٸ� ���ڷ� ���
	
	return 0;
}
*/