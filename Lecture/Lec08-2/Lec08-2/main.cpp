#include <iostream>
#include <vector>
using namespace std;

// &: 객체는 pass by reference로 보낼 것(효율성)
// const: 함수안에서 객체 data가 바뀌지 않을 때

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
	
	// int& elem = vec[0] -> for문의 body 실행
	// int& elem = vec[1] -> for문의 body 실행
	// int& elem = vec[2] -> for문의 body 실행
	for (int& elem : vec)
		cin >> elem;

	// int elem = vec[0] -> for문의 body 실행
	// int elem = vec[1] -> for문의 body 실행
	// int elem = vec[2] -> for문의 body 실행
	for (int elem : vec)
		cout << elem << '\t';
	cout << endl;

	cout << "sum: " << sum(vec) << endl;

	return 0;
}