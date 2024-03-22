#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

bool readStu(ifstream& fin, int& id, int& score1, int& score2, int& score3) {
	//fin >>: 하나의 word 문자열을 읽기(공백, 줄바꿈문자)
	fin >> id >> score1 >> score2 >> score3;
	if (!fin)
		return false;
	else
		return true;
}

void calcGrade(int score1, int score2, int score3, int& avg, char& grade) {
	avg = (score1 + score2 + score3) / 3;
	if (avg >= 90)
		grade = 'A';
	else if (avg >= 80)
		grade = 'B';
	else if (avg >= 70)
		grade = 'C';
	else if (avg >= 60)
		grade = 'D';
	else
		grade = 'F';
}

void writeStu(ofstream& fout, int id, int avg, char grade) {
	fout.fill('0');
	fout << setw(4) << id;
	fout.fill(' ');
	fout << setw(3) << avg;
	fout << setw(2) << grade;
}


int main() {
	// pseudo-code
	// 반복: 모든 학생정보를 읽을 때까지
		// 1) 학생정보 ch7STUFL.DAT로부터 1줄씩 읽는다(ID, score1, score2, score3)
		// 2) score1, score2, score3를 이용해서 평균값, grade를 산출한다
		// 3) 파일에 ID, avg, grade를 저장한다
	ifstream fin("ch7STUFL.DAT");
	ofstream fout("grade.txt");

	//예외처리
	if (!fin || !fout) {
		cout << "Error: file open failed" << endl;
		exit(100);
	}

	int id, score1, score2, score3, avg;
	char grade;

	while (readStu(fin, id, score1, score2, score3)) {
		calcGrade(score1, score2, score3, avg, grade);
		writeStu(fout, id, avg, grade);
	}
	
	cout << "End grading";

	fin.close();
	fout.close;

	return 0;
}


/*
int main() {
	double a = 12.345;

	cout << a << endl;

	cout.width(15); //setw(15)
	cout.precision(4);
	cout.fill('-');
	cout << a << endl;

	char ch;
	cin.unsetf(ios::skipws); //ws: white space
	cin >> ch;
	cout << '(' << ch << ')' << endl;

	cin.setf(ios::skipws);
	cin >> ch;
	cout << '(' << ch << ')' << endl;


	return 0;
}
*/

/*
int main() {
	char ch;
	ofstream fout;
	fout.open("char.txt");
	while (true) {
		cin >> ch;
		if (ch == 'q')
			break;
		fout.put(ch);
	}

	fout.close();

	ifstream fin;
	fin.open("Char.txt");

	if (!fin) {
		cout << "file not found" << endl;
		exit(100);
	}

	while (true) {
		fin.get(ch);
		if (!fin)//파일의 끝까지 다 읽으면 fin==false (fin.eof() )
			break;
		cout << ch << endl;
	}

	fin.close();

	return 0;
}
*/