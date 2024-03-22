#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <random>
using namespace std;
using Matrix = vector<vector<int>>;

/* 기초 1번
void print(int* begin, int* end) {
	for (int* curr = begin; curr < end; curr++)
		cout << setw(4) << *curr;

	//int* curr = begin;
	//while (curr != end) {
	//	cout << setw(4) << *curr;
	//	curr++;
	//}
	cout << endl;
}

int main() {
	int list[3] = { 10, 20, 30 };
	cout << (list + 0) << '\t' << *(list + 0) << endl;
	cout << (list + 1) << '\t' << *(list + 1) << endl;
	cout << (list + 2) << '\t' << *(list + 2) << endl;

	int *begin = list;
	int* end = list + 3;
	print(begin, end);

	return 0;
}
*/

/* 기초 2번
void print(const Matrix& mat) {
	//for (unsigned row = 0; row < mat.size(); row++) {
	//	for (unsigned col = 0; col < mat[row].size(); col++) {
	//		mat.at(row).at(col);
	//		cout << setw(4) << mat[row][col];
	//	}
	//	cout << endl;
	//}
	//for (unsigned row = 0; row < mat.size(); row++) {
	//	for (unsigned col = 0; col < mat[row].size(); col++) {
	//		cout << setw(4) << col;
	//	}
	//	cout << endl;
	//}
	//vector<int> row = mat[0];
	//	   auto row = mat[0];

	for (auto row : mat) {
		for (auto elem : row) {
			cout << setw(4) << elem;
		}
		cout << endl;
	}
}

int main() {
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
int main() {
	const int size = 3;
	int list[size] = { 10, 20, 30 };

	int length = 3;
	cin >> length;
	int* list2 = new int[length];
// double* list2 = new double[length]

	int* begin = list2;
	int* end = list2 + length;

	for (int* curr = begin; curr != end; curr++)
		cin >> *curr;

	for (int* curr = begin; curr != end; curr++)
		cout << *curr << '\t';

	delete[] list2;

	return 0;
}
*/

/* 기초 5번
void print(int** m, int nRow, int nCol) {
	for (int row = 0; row < nRow; row++) {
		for (int col = 0; col < nCol; col++) {
			cout << m[row][col] << '\t';
		}
		cout << endl;
	}
}

int main() {
	int nRow = 2, nCol = 2;
	int** matrix2;
	matrix2 = new int*[nRow];
	for (int i = 0; i < nRow; i++)
		matrix2[i] = new int[nCol];

	matrix2[0][0] = 1; matrix2[0][1] = 2;
	matrix2[1][0] = 3; matrix2[1][1] = 4;

	print(matrix2, nRow, nCol);


	for (int i = 0; i < nRow; i++)
		delete[] matrix2[i];

	delete[] matrix2;

	return 0;
}
*/

/* 기초 6번
bool found_char(const char* s, char ch) {
	while (*s != '\0') {
		if (*s == ch)
			return true;
		s++;
	}
	return false;
}

int main() {

	const char* phrase = "this is a phrase";

	for (char ch = 'a'; ch <= 'z'; ch++) {
		cout << ch << " is ";
		if (!found_char(phrase, ch))
			cout << "NOT";
		cout << " in (" << phrase << ")" << endl;
	}

	return 0;
}
*/

/* 응용 1번
Matrix init_mat(int row, int col) {

	if (row <= 0 || col <= 0) {
		cout << endl << "행렬을 생성할 수 없습니다.";
		exit(100);
	}
	Matrix mat(row);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			mat[i].push_back( rand() % 19 - 9 );
		}
	}
	return mat;
}

void print_mat(const Matrix& mat) {
	
	for (vector<int> row : mat) {
		for (int elem : row) {
			cout << setw(4) << elem;
		}
		cout << endl;
	}
}

Matrix mult_mat(const Matrix& mat1, const Matrix& mat2) {

	if (mat1[0].size() != mat2.size()) {
		cout << endl << "두 행렬을 곱할 수 없습니다.";
		exit(100);
	}

	int sum = 0;
	Matrix result(mat1.size());

	for (int i = 0; i < mat1.size(); i++) {
		for (int j = 0; j < mat2[0].size(); j++) {
			for (int k = 0; k < mat1[0].size(); k++) {
				for (int l = 0; l < mat2.size(); l++) {
					if (k == l) {
						sum += mat1[i][k] * mat2[l][j];
					}
				}
			}
			result[i].push_back(sum);
			sum = 0;
		}
	}
	return result;
}

int main() {

	int A_row, A_col, B_row, B_col;
	cout << "A의 행, 열의 크기를 입력해주세요 : ";
	cin >> A_row >> A_col;
	cout << "B의 행, 열의 크기를 입력해주세요 : ";
	cin >> B_row >> B_col;

	Matrix A_mat = init_mat(A_row, A_col);
	Matrix B_mat = init_mat(B_row, B_col);
	cout << endl << "A 행렬 : " << endl;
	print_mat(A_mat);
	cout << endl << "B 행렬 : " << endl;
	print_mat(B_mat);

	Matrix AB_mat = mult_mat(A_mat, B_mat);
	cout << endl << "AB 곱행렬 : " << endl;
	print_mat(AB_mat);

	return 0;
}
*/

/* 응용 2번
int* make_arr(int n) {
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = 2 * i + 1;
	}
	return a;
}

void print_arr(int* a, int n) {
	cout << "\nOdd Number Array:" << endl;
	while (n) {
		cout << *a << " ";
		a++;
		n--;
	}
	cout << endl;
}

int sum_arr(int* a, int n) {
	int s = 0;
	for (int i = 0; i < n; i++)
		s += a[i];
	return s;
}

int main() {
	int n;
	cout << "Enter a number: ";
	cin >> n;

	int* arr = make_arr(n);
	print_arr(arr, n);

	int sum = sum_arr(arr, n);
	cout << "\nSum of the array: " << sum << endl;

	delete[] arr;
	return 0;
}
*/

/* 응용 3번
int* make_arr(int n, int len) {
	
	int* a = new int[len];

	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<> dist(1, n);

	for (int i = 0; i < len; i++) {
		a[i] = dist(rng);
	}
	return a;
}

void print_arr(int* a, int len) {
	cout << "Size of random array: " << len << endl;
	cout << "[ Array ]" << endl;
	for (int i = 0; i < len; i++)
		cout << a[i] << " ";
	cout << endl;
}

bool find_dup(int* a, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (a[i] == a[j])
				return true;
		}
	}
	return false;
}

int main() {

	while (true) {
		int n;
		cout << "Please enter a number: ";
		cin >> n;

		if (n < 2) {
			cout << "Wrong number!!!";
			break;
		}
		
		int len = n / 2;

		int* arr = make_arr(n, len);
		print_arr(arr, len);

		cout << "Duplicates ";
		if (!find_dup(arr, len))
			cout << "not ";
		cout << "found." << endl << endl;

		delete[] arr;
	}
	return 0;
}
*/

/* 응용 4번
int** buildTable(int n) {
	int** table = new int*[n];
	for (int row = 0; row < n; row++) {
		table[row] = new int[n];
	}
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			table[row][col] = 0;
		}
	}
	return table;
}

void make_identity_matrix(int** table, int n) {
	for (int i = 0; i < n; i++) {
		table[i][i] = 1;
	}
}

void printTable(int** table, int n) {
	cout << "Output:" << endl;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			cout << setw(5) << table[row][col];
		}
		cout << endl;
	}
}

int main() {
	int n = 0;
	cout << "N을 입력하시오: ";
	cin >> n;
	if (n < 1) {
		cout << "\n행렬을 생성할 수 없습니다.\n" << endl;
		exit(EXIT_FAILURE);
	}

	int** table = buildTable(n);
	make_identity_matrix(table, n);
	printTable(table, n);

	for (int i = 0; i < n; i++)
		delete[] table[i];
	delete[] table;

	return 0;
}
*/