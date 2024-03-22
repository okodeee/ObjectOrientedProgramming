#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

bool readStu(ifstream& fin, int& id, int& score1, int& score2, int& score3) {
	//fin >>: �ϳ��� word ���ڿ��� �б�(����, �ٹٲ޹���)
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
	// �ݺ�: ��� �л������� ���� ������
		// 1) �л����� ch7STUFL.DAT�κ��� 1�پ� �д´�(ID, score1, score2, score3)
		// 2) score1, score2, score3�� �̿��ؼ� ��հ�, grade�� �����Ѵ�
		// 3) ���Ͽ� ID, avg, grade�� �����Ѵ�
	ifstream fin("ch7STUFL.DAT");
	ofstream fout("grade.txt");

	//����ó��
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
		if (!fin)//������ ������ �� ������ fin==false (fin.eof() )
			break;
		cout << ch << endl;
	}

	fin.close();

	return 0;
}
*/