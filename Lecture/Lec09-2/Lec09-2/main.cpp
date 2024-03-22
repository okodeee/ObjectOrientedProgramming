#include <iostream>
#include <iomanip>
using namespace std;


// 문자열(const char* s = "oop")
// s = {'o', 'o', 'p', '\0'}

bool find_char(const char* s, char ch) {
	while (*s != '\0') {
		if (*s == ch)
			return true;
		s++;
	}
	return false;
}

int main() {
	const char* phrase = "This is a phrase";
	// 'A': 65
	// 'a': 97 (+32)

	cout << phrase << endl;

	for (char ch = 'a'; ch <= 'z'; ch++) {
		cout << ch << " is ";
		if (!find_char(phrase, ch))
			cout << "NOT";
		cout << " in (" << phrase << ")" << endl;
		// a is in (this is a phrase)
		// b is NOT in (this is a phrase)
	}

	return 0;
}


/*
void print(int** m, int nRow, int nCol) {
	for (int row = 0; row < nRow; row++) {
		for (int col = 0; col < nCol; col++)
			cout << setw(4) << m[row][col];
		cout << endl;
	}
}

int main() {
//	vector<vector<int>> m(2, vector<int>(3));
	int matrix[2][3]; // 2x3 matrix

	int nRow = 2, nCol = 3;
	int** matrix2 = new int*[nRow];
	for (int row = 0; row < nRow; row++)
		matrix2[row] = new int[nCol];

	matrix2[0][0] = 1; matrix2[0][1] = 2; matrix2[0][2] = 3;
	matrix2[1][0] = 4; matrix2[1][1] = 5; matrix2[1][2] = 6;

	print(matrix2, nRow, nCol);

	for (int row = 0; row < nRow; row++)
		delete[] matrix2[row];
	delete[] matrix2;

	return 0;
}
*/

/*
// 정적 배열(static array): 프로그램 동작중(run-time) 크기가 고정
// 동적 배열(dynamic array): 프로그램이 동작중 할당/해제 가능
//   - keywords: new (할당), delete[] (할당 해제)

void get_data(int* begin, int* end) {
	for (int* curr = begin; curr != end; curr++)
		cin >> *curr;
}

void print(int* begin, int* end) {
	for (int* curr = begin; curr != end; curr++)
		cout << setw(4) << *curr;
	cout << endl;
}

int main() {
	const int size = 3;
	int list[size] = { 10, 20, 30 }; //정적 배열

	int length;
	cin >> length;
	int* list2 = new int[length]; //동적 배열 선언

	int* begin = list2;
	int* end = list2 + length;

	get_data(begin, end);
	print(begin, end);

	delete[] list2;

	return 0;
}
*/