#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
using Matrix = vector<vector<int>>;

/*
int sum(int* list, int size) {
	int result = 0;
	for (int i = 0; i < size; i++)
		result += list[i];
	return result;
}

void print(int* begin, int* end) {
	for (int* curr = begin; curr != end; curr++)
		cout << *curr << '\t';
	cout << endl;

//	int* curr = begin;
//	while (curr != end) {
//		cout << *curr << '\t';
//		curr++;
//	}
//	cout << endl;
}

// pointer + 1: 배열의 다음 element값으로 update
// list 그 자체는 배열의 시작주소값을 저장
int main() {
	int list[] = { 10, 20, 30 };
//	cout << sum(list, 3) << endl;

	cout << (list + 0) << '\t' << *(list + 0) << endl; // list[0]
	cout << (list + 1) << '\t' << *(list + 1) << endl; // list[1]
	cout << (list + 2) << '\t' << *(list + 2) << endl; // list[2]

	int* begin = list;
	int* end = list + 3;
	print(begin, end);

	return 0;
}
*/

/*
void print(const Matrix& m) {
//	for (unsigned row = 0; row < m.size(); row++) {
//		for (unsigned col = 0; col < m[row].size(); col++) {
//			cout << setw(4) << m[row][col];
//		}
//		cout << endl;
//	}

	// auto: 선언시 data type을 대체할 수 있음
	for (const auto& row : m) {
		for (auto elem : row) { //row (vector<int>)s
			cout << setw(4) << elem;
		}
		cout << endl;
	}
}

int main() {
	// 2 x 3 matrix
//	Matrix mat(2, vector<int>(3));
	Matrix mat{ {1, 2, 3},
				{4, 5, 6} };

	mat[0][0] = 1; mat[0][1] = 2; mat[0][2] = 3;
	mat[1][0] = 2; mat[1][1] = 3; mat[1][2] = 4;

	print(mat);

	return 0;
}
*/