#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;
using Matrix = vector<vector<int>>;


/* 기초 1번
// 배열의 경우 주소값(시작주소, 끝주소)을 전달
void print(int* begin, int* end) {
	for (int* curr = begin; curr != end; curr++) //수업시간에 배운 주소값을 기준으로 for문 작성
		cout << setw(4) << *curr;

	// while문 구현 부분 - 수업시간에 배운 주소값을 기준으로 while문 작성
	// int* curr = begin;
	// while (curr != end) {
	// cout << setw(4) << *curr;
	// curr++;
	// }
	cout << endl;
}

// (+, -) for pointer: 주소값을 증가/감소 (다음 변수 위치)
int main() {
	int list[3] = { 10, 20, 30 };
	cout << (list + 0) << '\t' << *(list + 0) << endl;
	cout << (list + 1) << '\t' << *(list + 1) << endl;
	cout << (list + 2) << '\t' << *(list + 2) << endl;

	int *begin = list;
	int* end = list + 3;
	print(begin, end);

	return 0;
}*//* 기초 2번void print(const Matrix& mat) {
	// vector index를 이용한 for 문 작성
//	for (unsigned row = 0; row < mat.size(); row++) {
//		for (unsigned col = 0; col < mat[row].size(); col++) {
//			//mat.at(row).at(col);
//			cout << setw(4) << mat[row][col];
//		}
//		cout << endl;
//	}

	// vector 원소를 이용한 for 문 작성
//	for (const vector<int>& row : mat) {
//		for (int col : row) {
//			cout << setw(4) << col;
//		}
//		cout << endl;
//	}

	//유추 가능한 경우, 자료형 부분을 auto로 치환가능
	// vector<int> row = mat[0];
	//  ==    auto row = mat[0];
	// auto와 벡터 원소를 이용하여 for문 구현
	for (const auto& row : mat) {
		for (auto col : row) {
			cout << setw(4) << col;
		}
		cout << endl;
	}
}

int main() {
	// 2 x 3 matrix
	// vector<vector<int>> mat(2, vector < int>(3) );
	Matrix mat{ { 1, 2, 3 },
	{ 4, 5, 6 } };

	mat[0][0] = 1;
	mat[0][1] = 2;
	mat[0][2] = 3;
	mat[1][0] = 4;
	mat[1][1] = 5;
	mat[1][2] = 6;

	print(mat);

	return 0;
}
*/

/* 기초 3번
bool is_prime(int n) {
	if (n < 2)
		return false;
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;
	return true;
}

vector<int> primes(int low, int high) {
	vector<int> result;
	for (int i = low; i <= high; i++)
		if (is_prime(i) == true)
			result.push_back(i);
	return result;
}

void print(const vector<int>& v) {
	for (int elem : v)
		cout << setw(4) << elem;
	cout << endl;
}

int main() {
	int low, high;
	cin >> low >> high;
	vector<int> vec = primes(low, high);
	print(vec);

	return 0;
}
*/

/* 기초 4번
//정적 배열(static array):프로그램 실행중 크기가 고정되어 변경 불가
//동적 배열(dynamic array): 프로그램 실행중(run time) 할당/해제가 가능
int main() {
	const int size = 3;
	int list[size] = { 10, 20, 30 };

	int length = 3;
	cin >> length; // 키보드로부터 배열의 크기를 입력받음
	int* list2 = new int[length]; //동적 배열 선언
	// double* list2 = new double[length]

	int* begin = list2;
	int* end = list2 + length;

	for (int* curr = begin; curr != end; curr++)
			cin >> *curr;

	for (int* curr = begin; curr != end; curr++)
		cout << *curr << '\t';
	cout << endl;

	delete[] list2; //할당 해제

	return 0;
}
*/

/* 기초 5번
void print(int** m, int nRow, int nCol) {
	for (int row = 0; row < nRow; row++) { //2중 for문과 index를 이용하여 배열 원소 출력 - 구분자 : '\t'
		for (int col = 0; col < nCol; col++)
			cout << m[row][col] << '\t';
		cout << endl;
	}
}

int main() {
	int nRow = 2, nCol = 2;
	int** matrix2;
	matrix2 = new int*[nRow]; // 동적배열 선언(행기준)
	for (int i = 0; i < nRow; i++)
		matrix2[i] = new int[nCol]; // 동적배열 선언(열기준)

	matrix2[0][0] = 1; matrix2[0][1] = 2;
	matrix2[1][0] = 3; matrix2[1][1] = 4;

	print(matrix2, nRow, nCol);

	for (int i = 0; i < nRow; i++)
		delete[] matrix2[i];

	delete[] matrix2;

	return 0;
}*//* 기초 6번bool found_char(const char* s, char ch) {
	while (*s != '\0') { // s와 ch 만으로 (s,s+1, ...)에 ch가 있는지 true/false return
		if (*s == ch)
			return true;
		s++;
	}
	return false;
}
int main() {
	//                    012345(6)
	const char* phrase = "phrase";// ch[]
	                            // phrase(\0)==NULL
	for (char ch = 'a'; ch <= 'z'; ch++) { // 'a' == 65, 'z' == 97
		cout << ch << " is ";
		if (!found_char(phrase, ch))
			cout << "NOT";
		cout << " in (" << phrase << ")" << endl;
	}

	return 0;
}
*/


int** generate(int nRow, int nCol) {
	 if (nRow == 0 || nCol == 0) {
		 cout << "행렬을 생성할 수 없습니다.";
		 exit(100);
	 }

	 int** mat = new int*[nRow];
	 for (int i = 0; i < nRow; i++)
		 mat[i] = new int[nCol];

	 for (int i = 0; i < nRow; i++) {
		 for (int j = 0; j < nCol; j++)
			 mat[i][j] = rand() % 19 - 9;
	 }

	 return mat;
}

void print(int** mat, int nRow, int nCol) {
	for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCol; j++)
			cout << setw(5) << mat[i][j];
		cout << endl;
	}
}

int** mult(const int**& mat1, const int**& mat2, int nCol1, int nRow2) {
	if (nCol1 != nRow2) {
		cout << "두 행렬을 곱할 수 없습니다.";
		exit(100);
	}

}

int main() {
	int nRowA, nColA, nRowB, nColB;

	cout << "A의 행, 열의 크기를 입력해주세요 : ";
	cin >> nRowA >> nColA;
	cout << "B의 행, 열의 크기를 입력해주세요 : ";
	cin >> nRowB >> nColB;

	int** matA = generate(nRowA, nColA);
	int** matB = generate(nRowB, nColB);

	cout << "A 행렬 :" << endl;
	print(matA, nRowA, nColA);
	cout << "B 행렬 :" << endl;
	print(matB, nRowB, nColB);



	return 0;
}