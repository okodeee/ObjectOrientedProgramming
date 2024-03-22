#include <iostream>
#include <iomanip> //setw(n): 한 변수당 n칸을 할당, 오른쪽 정렬
using namespace std; //std::를 생략하겠다


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
	cout.imbue(locale("");) //3자리 숫자마다 (,)표시
	while (i <= n) {
		sum += i;
		cout << setw(4) << i << setw(12) << sum << endl;
		i += 2;
	}

	return 0;
}
*/

/*
// if, else-if, else 순서로 괄호 안 조건들을 탐색,
//  true조건을 가지는 block을 수행 후 전체 조건문을 탈출
//  1) if: 처음에 위치, 단독으로 사용
//  2) else: 상위 조건문이 모두 거짓일 경우 자동으로 수행(default)
//  3) block안 문장이 하나일 경우 중괄호{ } 생략 가능

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