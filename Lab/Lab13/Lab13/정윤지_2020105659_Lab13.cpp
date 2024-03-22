#include <iostream>
#include <vector>
#include <list>
using namespace std;

/* 기초 1번
template<class T, class U>
bool less_than(T a, U b) { return a < b; }

template<class T>
T sum(const vector<T>& v) {
	T sum = 0;
	for (T elem : v)
		sum += elem;
	return sum;
}

int main() {
	cout << less_than(2, 3) << endl;
	cout << less_than(2.1, 2.9) << endl;
	cout << less_than(2, 2.5) << endl;

	vector<int> v1{ 1, 2, 3, 4 };
	vector<double> v2{ 10.1, 20.2, 30.3, 40.4 };
	cout << sum(v1) << endl;
	cout << sum(v2) << endl;

	return 0;
}
*/

/* 기초 2번
template<class T>
class Point {
private:
	T x;
	T y;
public:
	Point(T _x, T _y);
	void setXY(T _x, T _y);
	T getX();
	T getY();
	void print();
};

template<class T>
Point<T>::Point(T _x, T _y) : x(_x), y(_y) {}

template<class T>
void Point<T>::setXY(T _x, T _y) {
	x = _x;
	y = _y;
}

template<class T>
T Point<T>::getX() { return x; }

template<class T>
T Point<T>::getY() { return y; }

template<class T>
void Point<T>::print() {
	cout << x << '\t' << y << endl;
}

int main() {
	Point<int> pt(1, 2);
	Point<double> pt2(1.1, 2.2);
	pt.print();
	pt2.print();
}
*/

/* 기초 3번
int main() {
	list<int> myList{ 1, 2, 3, 4 };
	char command;
	int inputVal;
	bool finished = false;
	while(!finished) {
		cout << "I)nput, P)rint, L)ength, E)mpty, Q)uit>>";
		cin >> command;

		switch (command) {
		case 'I':
		case 'i':
			cin >> inputVal;
			myList.push_back(inputVal);
			break;
		case 'P':
		case 'p':
			for (int elem : myList)
				cout << elem << '\t';
			cout << endl;
			break;
		case 'L':
		case 'l':
			cout << "Number of items: " << myList.size() << endl;
			break;
		case 'E':
		case 'e':
			myList.clear();
			break;
		case 'Q':
		case 'q':
			finished = true;
			cout << "Exit the program" << endl;
			break;
		default:
			cout << "Wrong command" << endl;
			break;
		}
	}

	return 0;
}
*/

/* 기초 4번
int main() {
	int ary[] = { 1, 2, 3, 4 };
	int* pBegin, *pEnd;
	pBegin = ary;
	pEnd = ary + 4;
	for (int* pIter = pBegin; pIter != pEnd; pIter++)
		cout << *pIter << "\t";
	cout << endl;

	vector<int> v{ 10, 20, 30, 40 };
	auto iter_begin = begin(v);
	auto iter_end = end(v);
	for (auto iter = iter_begin; iter != iter_end; iter++)
		cout << *iter << "\t";
	cout << endl;

	return 0;
}
*/

/* 기초 5번
template<class Iter>
void print(const Iter& iter_begin, const Iter& iter_end) {
	for (Iter iter = iter_begin; iter != iter_end; iter++)
		cout << *iter << "\t";
	cout << endl;
}

template<class Iter>
void print_reverse(const Iter& iter_begin, const Iter& iter_end) {
	Iter iter = iter_end;
	iter--;
	while (iter != iter_begin) {
		cout << *iter << "\t";
		iter--;
	}
	cout << *iter;
	cout << endl;
}

int main() {

	vector<int> v{ 1, 2, 3, 4 };
	list<double> l{ 1.1, 2.2, 3.3 };
	int ary[] = { 100, 200, 300, 400 };

	print(begin(v), end(v));
	print(begin(l), end(l));
	print(begin(ary), end(ary));

	print_reverse(begin(v), end(v));
	print_reverse(begin(l), end(l));
	print_reverse(begin(ary), end(ary));

	return 0;
}
*/

/* 응용 1번
template <typename T>
class CList
{
public:
	CList();
	~CList();

	bool IsEmpty();
	bool IsFull();

	void Add(T data);
	void Delete(T data);
	void Print();

private:
	T m_Array[5];
	int m_Length;
};

template <typename T>
CList<T>::CList() : m_Array(), m_Length() {
}

template <typename T>
CList<T>::~CList() {
}

template <typename T>
bool CList<T>::IsEmpty() {
	if (m_Length == 0) return 1;
	else return 0;
}

template <typename T>
bool CList<T>::IsFull() {
	if (m_Length == 5) return 1;
	else return 0;
}

template <typename T>
void CList<T>::Add(T data) {
	if (IsFull() == 0) {   // 가득 차지 않으면
		int check = 0;
		for (int i = 0; i < m_Length + 1; i++) {
			if (m_Array[m_Length] == data) {
				check = 1;
				break;
			}
		}
		if (check == 0) {      //중복이 아니면
			m_Array[m_Length] = data;
			sort(m_Array, m_Array + 5);
		}
		else cout << "중복된 데이터가 존재합니다." << endl;
	}
	else cout << "List is full." << endl;   // 가득 찼으면
}

template <typename T>
void CList<T>::Delete(T data) {
	if (IsEmpty() == 0) {   // 비어 있지 않으면
		for (int i = 0; i < m_Length + 1; i++) {
			if (m_Array[i] == data) {
				for (int j = i; j < m_Length + 1; j++) {
					m_Array[j] = m_Array[j + 1];
				}
			}
		}

	}
	else cout << "List is empty." << endl;
}

template <typename T>
void CList<T>::Print() {
	cout << "*Current List" << endl;
	for (int i = 0; i < m_Length + 1; i++) {
		cout << m_Array[i] << " " << endl;
	}
}

int command()
{
	int num;

	cout << "\n\t---- menu ----" << endl;
	cout << "\t1. 리스트 추가" << endl;
	cout << "\t2. 리스트 삭제" << endl;
	cout << "\t3. 리스트 출력" << endl;
	cout << "\t4. 프로그램 종료" << endl;
	cout << "\n\t입력 --> ";
	cin >> num;
	return num;
}

int main()
{
	CList<int> list;
	int input;
	int com;
	while (1)
	{
		com = command();
		switch (com)
		{
		case 1:
			cout << "\n추가할 데이터 : ";
			cin >> input;
			list.Add(input);
			break;
		case 2:
			cout << "\n삭제할 데이터 : ";
			cin >> input;
			list.Delete(input);
			break;
		case 3:
			list.Print();
			break;
		case 4:
			cout << "\n\t프로그램을 종료합니다\n";
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}
*/