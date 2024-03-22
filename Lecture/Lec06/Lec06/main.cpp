#include <iostream>
#include <iomanip>
using namespace std;

// switch문: if-else문과 유사하지만 변수의 값과 동일한 case를 실행
//  - if-else와 비교: 가독성이 더 좋다
//  - case문 뒤에는 break;
//  - default: 모든 case가 거짓일 경우 수행(else)
int main() {
	char input;
	cin >> input;

	switch (input) {
	case 'P':
	case 'p':
		cout << "Pause" << endl;
		break;
	case 'Q':
	case 'q':
		cout << "Quit" << endl;
		break;
	default:
		cout << "Default" << endl;
	}

	return 0;
}

/*
// while: 조건식->block->조건식
// do{}while();: block->조건식->block
// for(초기화; 반복조건; 업데이트){block}
int main() {
	int size;
	cout << "Enter a size: ";
	cin >> size;

	for (int row = 1; row <= size; row++) {
		for (int col = 1; col <= size; col++) {
//			int val = row * col;
//			int val = (row > col ? row : col);
			int val = 0;
			if (row == col)
				val = 1;
			cout << setw(4) << val;
		}
		cout << endl;
	}

	return 0;
}
*/

/*
int main() {
	int sum = 0;

	for (int i = 1; i <= 100; i++)
		sum += i;

	cout << sum << endl;

	return 0;
}
*/

/*
int main() {
	int input;
	do {
		cout << "Enter a number [0, 10]: ";
		cin >> input;
	} while (input >= 0 && input <= 10);
	cout << "Output: " << input << endl;

	return 0;
}
*/

/*
int main() {
	int sum = 0;
	int input;
	while (true) {
		cout << "Enter a number: ";
		cin >> input;
		if (input < 0)
			continue; //아랫 부분을 실행하지 않고 while문 첫 줄로 돌아감
//			break; //반복문 탈출
		sum += input;
		cout << "Sum: " << sum << endl;
	}

	return 0;
}
*/