#include <iostream>
#include <iomanip> //setw(n): �� ������ nĭ�� �Ҵ�, ������ ����
using namespace std; //std::�� �����ϰڴ�


int main() {
	int row = 1, col = 1;
	int n;
	cin >> n;
	while (row <= n) {
		while (col <= n) {
			int val = row * col;
			cout << setw(4) << val;
			col++;
		}
		cout << endl;
		row++;
		col = 1;
	}

	return 0;
}


/*
int main() {
	int sum = 0, n;
	int i = 2;
	cin >> n;
	cout.imbue(locale("");) //3�ڸ� ���ڸ��� (,)ǥ��
	while (i <= n) {
		sum += i;
		cout << setw(4) << i << setw(12) << sum << endl;
		i += 2;
	}

	return 0;
}
*/

/*
// if, else-if, else ������ ��ȣ �� ���ǵ��� Ž��,
//  true������ ������ block�� ���� �� ��ü ���ǹ��� Ż��
//  1) if: ó���� ��ġ, �ܵ����� ���
//  2) else: ���� ���ǹ��� ��� ������ ��� �ڵ����� ����(default)
//  3) block�� ������ �ϳ��� ��� �߰�ȣ{ } ���� ����

int main() {
	int score;
	char grade = NULL; //''
	cout << "Enter the score [0-100]: ";
	cin >> score;

	if (score >= 0 && score <= 100) {
		if (score >= 90)
			grade = 'A';
		else if (score >= 80)
			grade = 'B';
		else if (score >= 70)
			grade = 'C';
		else
			grade = 'F';
	}
	else {
		cout << "Invalid score" << endl;
	}
	
	cout << "Grade is " << grade << endl;

	return 0;
}
*/

/*
int main() {
	bool a = false;
	bool b = (10 <= 5);
	bool c = 0;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	return 0;
}
*/