#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;
using Matrix = vector<vector<int>>;


/* ���� 1��
// �迭�� ��� �ּҰ�(�����ּ�, ���ּ�)�� ����
void print(int* begin, int* end) {
	for (int* curr = begin; curr != end; curr++) //�����ð��� ��� �ּҰ��� �������� for�� �ۼ�
		cout << setw(4) << *curr;

	// while�� ���� �κ� - �����ð��� ��� �ּҰ��� �������� while�� �ۼ�
	// int* curr = begin;
	// while (curr != end) {
	// cout << setw(4) << *curr;
	// curr++;
	// }
	cout << endl;
}

// (+, -) for pointer: �ּҰ��� ����/���� (���� ���� ��ġ)
int main() {
	int list[3] = { 10, 20, 30 };
	cout << (list + 0) << '\t' << *(list + 0) << endl;
	cout << (list + 1) << '\t' << *(list + 1) << endl;
	cout << (list + 2) << '\t' << *(list + 2) << endl;

	int *begin = list;
	int* end = list + 3;
	print(begin, end);

	return 0;
}*//* ���� 2��void print(const Matrix& mat) {
	// vector index�� �̿��� for �� �ۼ�
//	for (unsigned row = 0; row < mat.size(); row++) {
//		for (unsigned col = 0; col < mat[row].size(); col++) {
//			//mat.at(row).at(col);
//			cout << setw(4) << mat[row][col];
//		}
//		cout << endl;
//	}

	// vector ���Ҹ� �̿��� for �� �ۼ�
//	for (const vector<int>& row : mat) {
//		for (int col : row) {
//			cout << setw(4) << col;
//		}
//		cout << endl;
//	}

	//���� ������ ���, �ڷ��� �κ��� auto�� ġȯ����
	// vector<int> row = mat[0];
	//  ==    auto row = mat[0];
	// auto�� ���� ���Ҹ� �̿��Ͽ� for�� ����
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

/* ���� 3��
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

/* ���� 4��
//���� �迭(static array):���α׷� ������ ũ�Ⱑ �����Ǿ� ���� �Ұ�
//���� �迭(dynamic array): ���α׷� ������(run time) �Ҵ�/������ ����
int main() {
	const int size = 3;
	int list[size] = { 10, 20, 30 };

	int length = 3;
	cin >> length; // Ű����κ��� �迭�� ũ�⸦ �Է¹���
	int* list2 = new int[length]; //���� �迭 ����
	// double* list2 = new double[length]

	int* begin = list2;
	int* end = list2 + length;

	for (int* curr = begin; curr != end; curr++)
			cin >> *curr;

	for (int* curr = begin; curr != end; curr++)
		cout << *curr << '\t';
	cout << endl;

	delete[] list2; //�Ҵ� ����

	return 0;
}
*/

/* ���� 5��
void print(int** m, int nRow, int nCol) {
	for (int row = 0; row < nRow; row++) { //2�� for���� index�� �̿��Ͽ� �迭 ���� ��� - ������ : '\t'
		for (int col = 0; col < nCol; col++)
			cout << m[row][col] << '\t';
		cout << endl;
	}
}

int main() {
	int nRow = 2, nCol = 2;
	int** matrix2;
	matrix2 = new int*[nRow]; // �����迭 ����(�����)
	for (int i = 0; i < nRow; i++)
		matrix2[i] = new int[nCol]; // �����迭 ����(������)

	matrix2[0][0] = 1; matrix2[0][1] = 2;
	matrix2[1][0] = 3; matrix2[1][1] = 4;

	print(matrix2, nRow, nCol);

	for (int i = 0; i < nRow; i++)
		delete[] matrix2[i];

	delete[] matrix2;

	return 0;
}*//* ���� 6��bool found_char(const char* s, char ch) {
	while (*s != '\0') { // s�� ch ������ (s,s+1, ...)�� ch�� �ִ��� true/false return
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
		 cout << "����� ������ �� �����ϴ�.";
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
		cout << "�� ����� ���� �� �����ϴ�.";
		exit(100);
	}

}

int main() {
	int nRowA, nColA, nRowB, nColB;

	cout << "A�� ��, ���� ũ�⸦ �Է����ּ��� : ";
	cin >> nRowA >> nColA;
	cout << "B�� ��, ���� ũ�⸦ �Է����ּ��� : ";
	cin >> nRowB >> nColB;

	int** matA = generate(nRowA, nColA);
	int** matB = generate(nRowB, nColB);

	cout << "A ��� :" << endl;
	print(matA, nRowA, nColA);
	cout << "B ��� :" << endl;
	print(matB, nRowB, nColB);



	return 0;
}