#include <iostream>
#include <iomanip>
using namespace std;

// switch��: if-else���� ���������� ������ ���� ������ case�� ����
//  - if-else�� ��: �������� �� ����
//  - case�� �ڿ��� break;
//  - default: ��� case�� ������ ��� ����(else)
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
// while: ���ǽ�->block->���ǽ�
// do{}while();: block->���ǽ�->block
// for(�ʱ�ȭ; �ݺ�����; ������Ʈ){block}
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
			continue; //�Ʒ� �κ��� �������� �ʰ� while�� ù �ٷ� ���ư�
//			break; //�ݺ��� Ż��
		sum += input;
		cout << "Sum: " << sum << endl;
	}

	return 0;
}
*/