#include <iostream>
#include <iomanip>
using namespace std;


/* 기초 1번
int main() {
	char grade = 'X';
	int score;
	cout << "Enter your score: ";
	cin >> score;

	if (0 <= score && score <= 100) {
		if (score >= 90)
			grade = 'A';
		else if (score >= 80)
			grade = 'B';
		else if (score >= 70)
			grade = 'C';
		else if (score >= 60)
			grade = 'D';
		else
			grade = 'F';
		cout << "Your grade is " << grade << endl;
	}
	else {
		cout << "The score (" << score << ") is invalid" << endl;
	}

	return 0;
}
*/

/* 기초 2번
int main() {
	int num = 1;
	int count = 1;
	cout.imbue(locale(""));
	while (count <= 20) {
		num = pow(2, count);
		cout << count << '\t' << setw(10) << num << endl;
		count++;
	}

	return 0;
}
*/

/* 기초 3번
int main() {
	int column = 1, row = 1;
	while (row <= 10) {
		while (column <= 10) {
			int num;
			num = (row == column ? 1 : 0);
			cout << setw(4) << num;
			column++;
		}
		cout << endl;
		column = 1;
		row++;
	}

	return 0;
}
*/

/* 기초 4-1번
int main() {
	int num;

	while (true) {
		cout << "Enter the number (0, 10]: ";
		cin >> num;
		if (num > 0 && num <= 10)
			break;
	}
	cout << "Success!" << endl;

	return 0;
}
*/

/* 기초 4-2번
int main() {
	int num;
	do {
		cout << "Enter the number (0, 10]: ";
		cin >> num;
	} while (!(num > 0 && num <= 10));
	cout << "Success!" << endl;

	return 0;
}
*/

/* 기초 5번
int main() {
	int n, m;
	cout << "Enter n for n x m matrix: ";
	cin >> n;
	cout << "Enter m for n x m matrix: ";
	cin >> m;

	for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= m; col++) {
			cout << setw(4) << row * col;
		}
		cout << endl;
	}

	return 0;
}
*/

/* 기초 6초
int main() {
	char key;
	cout << "Enter a key (p or q): ";
	cin >> key;
	switch (key) {
	case 'p':
	case 'P':
		cout << "Pause" << endl;
		break;
	case 'q':
	case 'Q':
		cout << "Quit" << endl;
		break;
	default:
		cout << "Default" << endl;
	}

	return 0;
}
*/

/* 응용 1번
int main() {
	int input;

	for (int i = 1; i <= 5; i++) {
		cout << i << "번째 정수 : ";
		cin >> input;
		if (input % 2 == 0)
			cout << input << "은(는) 짝수입니다." << endl;
		else
			cout << input << "은(는) 홀수입니다." << endl;
	}

	return 0;
}
*/

/* 응용 2번
int main() {
	int input;
	int sum = 0;
	cout << "number : ";
	cin >> input;

	for (int i = 1; i <= input; i++)
		sum += i;

	cout << "Sum of 1 to " << input << " = " << sum;

	return 0;
}
*/

/* 응용 3번
int main() {
	int input;
	int sum = 0;
	cout << "number : ";
	cin >> input;

	for (int i = 1; i <= input; i++) {
		if (i % 2 == 0 || i % 3 == 0)
			continue;
		sum += i;
	}
	cout << "sum : " << sum;

	return 0;
}
*/

/* 응용 4번
int main() {
	int input;
	while (true) {
		cout << "단 수를 입력하세요: ";
		cin >> input;
		if (input == -1) {
			cout << "종료합니다.";
			break;
		}
		else if (1 <= input && input < 10) {
			for (int i = 1; i < 10; i++)
				cout << input << '*' << i << " = " << input * i << endl;
			cout << endl;
		}
		else
			cout << "1부터 9까지의 정수를 입력해주세요." << endl << endl;
	}

	return 0;
}
*/

/* 응용 5번
int gcd(int x, int y) {
	int r = x % y;
	if (r == 0)
		return y;
	return gcd(y, r);
}

int main() {
	int x, y;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;

	int print = gcd(x, y);
	cout << "gcd(" << x << "," << y << ") = " << print;

	return 0;
}
*/