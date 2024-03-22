#include <iostream>
#include <vector>
using namespace std;

// &: ��ü�� pass by reference�� ���� ��(ȿ����)
// const: �Լ��ȿ��� ��ü data�� �ٲ��� ���� ��

void print(const vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++)
		cout << vec.at(i) << '\t';
	cout << endl;
}

int sum(const vector<int>& vec) {
	int result = 0;
	for (int elem : vec)
		result += elem;
}

int main() {
	//        index:  0,  1,  2,  3
	vector<int> vec{ 10, 20, 30, 40 };
	print(vec);
	
	vec[0] = 100;
	vec.at(1) = 200;
	print(vec);

	vec.push_back(50);
	print(vec);
	vec.pop_back();
	print(vec);
	
	// int& elem = vec[0] -> for���� body ����
	// int& elem = vec[1] -> for���� body ����
	// int& elem = vec[2] -> for���� body ����
	for (int& elem : vec)
		cin >> elem;

	// int elem = vec[0] -> for���� body ����
	// int elem = vec[1] -> for���� body ����
	// int elem = vec[2] -> for���� body ����
	for (int elem : vec)
		cout << elem << '\t';
	cout << endl;

	cout << "sum: " << sum(vec) << endl;

	return 0;
}