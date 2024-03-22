#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
using Matrix = vector<vector<string>>;

// 참고1: 각 함수별로 점수를 책정. 함수가 정확히 기술된 경우에 10점, 그렇지 않으면 0점 
// 참고2: 로그인시 관리자의 ID: admin, 비밀번호 :0000 
// 요구사항1: 첨부된 실행파일(MidtermProjectCoupang.exe)을 동작시켜 동일한 동작이 수행되도록 코딩할 것
// 요구사항2: file의 정보가 추가/삭제되더라도(예를들어 회원 추가) 일반적으로 동작할 수 있도록 코딩할 것 (현재 제공된 파일에 대해서만 동작하면 관련 함수 모두 감점)
// 요구사항3: (주석을 제외하고) 아래 이미 작성된코드를 삭제하시 말고, 그 코드를 활용해서 작성할 것
// 요구사항4: 아래에 define된 symol을 사용하여 가독성을 높일 것(예를 들어, info_client[0] 대신 info_client[CLIENT_ID]을 사용, info_item[1] 대신 info_client[ITEM_NAME]을 사용)
#define CLIENT_ID 0
#define CLIENT_PW 1
#define CLIENT_REGION 2
#define CLIENT_ORDER_LIST 3

#define ITEM_ID 0
#define ITEM_NAME 1
#define ITEM_PRICE 2
#define ITEM_QUANTITY 3


void admin_start(Matrix& info_client, Matrix& info_item);
void get_id_pw(string& id, string& pw);
string get_command_admin();
void client_start(Matrix& info_client, Matrix& info_item); // 추가점수 (최대 15점)

bool client_login(const Matrix& info_client, string id, string pw, int& client_index);
string get_command_client();
bool identify_password(const Matrix& info_client, int client_index);
void change_password(Matrix& info_client, int client_index);
void change_region(Matrix& info_client, int client_index);
void membership_withdrawal(Matrix& info_client, int client_index);
void order_item(Matrix& info_client, Matrix& info_item, int client_index);

void read_info(Matrix& info_client, Matrix& info_item, string filename_client, string filename_item);  //10점
void write_info(const Matrix& info_client, const Matrix& info_item, string filename_client, string filename_item); //10점

void print_all(const Matrix& info_client); //10점
void print_each(const Matrix& info_client, int index); //10점
int search_client_by_id(const Matrix& info_client, string& id); //10점
void add_client(Matrix& info_client); //10점
void delete_client(Matrix& info_client);// 10점

vector<string> extract_regions(const Matrix& info_client); //10점
void print_items_by_region(const Matrix& info_client, const Matrix& info_item); // 10점
int search_item_by_id(const Matrix& info_item, string& id); // 10점
void add_item(Matrix& info_item); //10점
void delete_item(Matrix& info_item); //10점

int main() {
	string command;
	Matrix info_client(4), info_item(4); //info_client는 회원정보, info_item은 물품정보를 저장
	read_info(info_client, info_item, "clients.txt", "items.txt");

	while (true) {
		cout << "1. 관리자 로그인" << endl;
		cout << "2. 회원 로그인" << endl;
		cout << "0. 저장 및 종료" << endl;
		cout << ">>";
		cin >> command;
		if (command == "1")
			admin_start(info_client, info_item);
		else if (command == "2")
			client_start(info_client, info_item);
		else if (command == "0")
			break;
		else
			cout << "잘못 입력하였습니다." << endl;
	}

	write_info(info_client, info_item, "clients.txt", "items.txt");

	return 0;
}


void get_id_pw(string& id, string& pw) {
	cout << "ID를 입력하세요>>";
	cin >> id;
	cout << "암호를 입력하세요>>";
	cin >> pw;
}


string get_command_admin() {
	string command;
	cout << "1. 모든 회원정보 출력" << endl;
	cout << "2. 회원 검색         " << endl;
	cout << "3. 회원 추가         " << endl;
	cout << "4. 회원 삭제         " << endl;
	cout << "---------------------" << endl;
	cout << "5. 모든 물품정보 출력" << endl;
	cout << "6. 배송지별 물품 출력" << endl;
	cout << "7. 물품 검색         " << endl;
	cout << "8. 물품 추가         " << endl;
	cout << "9. 물품 삭제         " << endl;
	cout << "---------------------" << endl;
	cout << "0. 종료              " << endl;
	cout << ">>";
	cin >> command;
	return command;
}


void admin_start(Matrix& info_client, Matrix& info_item) {
	string id, pw, command;
	get_id_pw(id, pw);
	if (id == "admin" && pw == "0000") {
		cout << "로그인 완료." << endl << endl;
		while (true) {
			command = get_command_admin();
			if (command == "1")		 print_all(info_client);
			else if (command == "2") search_client_by_id(info_client, id);
			else if (command == "3") add_client(info_client);
			else if (command == "4") delete_client(info_client);
			else if (command == "5") print_all(info_item);
			else if (command == "6") print_items_by_region(info_client, info_item);
			else if (command == "7") search_item_by_id(info_item, id);
			else if (command == "8") add_item(info_item);
			else if (command == "9") delete_item(info_item);
			else if (command == "0") break;
			else                     cout << "잘못 입력하였습니다." << endl << endl;
		}
	}
	else {
		cout << "ID 또는 암호가 잘못되었습니다." << endl << endl;
	}
}

void read_info(Matrix& info_client, Matrix& info_item, string filename_client, string filename_item) {
	/* 기능: filename_client와 filename_item의 내용을 info_client와 info_item에 저장할 것
	   요구사항1: 파일이 제대로 열리지 않는 경우 "파일이 존재하지 않습니다"를 화면에 출력하고 exit(100)을 이용하여 프로그램 강제종료
	   요구사항2: 파일 읽기를 마친 후 반드시 닫을것
	   참고: info_client와 info_item에 속한 각 vector element의 첫 번째 element는 실제 회원(또는 물품)정보가 아닌 아래의 label을 가짐: 
	         - info_client:     ID  Password    Region       Order_Item_ID
	         - info_item:	    ID            ItemName     Price  Quantity
	 */

	ifstream fin;
	string str;
	fin.open(filename_client);
	if (!fin) {
		cout << "파일이 존재하지 않습니다";
		exit(100);
	}
	while (true) {
		fin >> str;
		if (fin.eof() == true)
			break;
		info_client[CLIENT_ID].push_back(str);
		fin >> str;
		info_client[CLIENT_PW].push_back(str);
		fin >> str;
		info_client[CLIENT_REGION].push_back(str);
		fin >> str;
		info_client[CLIENT_ORDER_LIST].push_back(str);
	}
	fin.close();

	fin.open(filename_item);
	if (!fin) {
		cout << "파일이 존재하지 않습니다";
		exit(100);
	}
	while (true) {
		fin >> str;
		if (fin.eof() == true)
			break;
		info_item[ITEM_ID].push_back(str);
		fin >> str;
		info_item[ITEM_NAME].push_back(str);
		fin >> str;
		info_item[ITEM_PRICE].push_back(str);
		fin >> str;
		info_item[ITEM_QUANTITY].push_back(str);
	}
	fin.close();

	cout << "파일 읽기 완료." << endl << endl;
}


void write_info(const Matrix& info_client, const Matrix& info_item, string filename_client, string filename_item) {
	/* 기능: info_client와 info_item의 내용을 filename_client와 filename_item에 저장할 것
	  요구사항1: 파일 쓰기를 마친 후 반드시 닫을것
	*/

	ofstream fout;
	fout.open(filename_client);
	for (int index = 0; index < info_client[CLIENT_ID].size(); index++) {
		fout << setw(10) << info_client[CLIENT_ID][index];
		fout << setw(10) << info_client[CLIENT_PW][index];
		fout << setw(10) << info_client[CLIENT_REGION][index];
		fout << setw(20) << info_client[CLIENT_ORDER_LIST][index];
		fout << endl;
	}
	fout.close();

	fout.open(filename_item);
	for (int index = 0; index < info_item[ITEM_ID].size(); index++) {
		fout << setw(10) << info_item[ITEM_ID][index];
		fout << setw(20) << info_item[ITEM_NAME][index];
		fout << setw(10) << info_item[ITEM_PRICE][index];
		fout << setw(10) << info_item[ITEM_QUANTITY][index];
		fout << endl;
	}
	fout.close();

	cout << "저장완료 - 프로그램을 종료합니다." << endl;
}


void print_each(const Matrix& info, int index) {
	/* 기능: 해당 index에 해당하는 info_item(또는 info_client)의 정보를 화면에 출력
	   요구사항: setw(15)를 이용하여 각 element간 간격을 맞출 것
	*/

	for (int i = 0; i < 4; i++) {
		cout << setw(15) << info[i][index];
	}
	cout << endl;
}


void print_all(const Matrix& info) {
	/* 기능: info_item(또는 info_client)의 정보를 화면에 출력
	   요구사항1: 각 item(또는 client)는 반드시 print_each()함수를 사용해서 화면에 출력
	*/
	
	for (int index = 0; index < info[0].size(); index++) {
		print_each(info, index);
	}
	cout << endl;
}


vector<string> extract_regions(const Matrix& info_client) {
	/* 기능: 회원의 거주 지역을 중복을 허용하지 않고 vector에 element로 저장한 다음 해당 vector를 반환
	   예: 회원의 지역이 (서울, 서울, 부산, 부산 부산, 대전) 일 경우 --> (서울, 부산, 대전) 으로 중복을 제거
	       이때 지역의 출력 순서는 상관없음(정렬되지 않아도 됨)
	*/

	vector<string> regions;
	int overlap;
	
	for (int index = 1; index < info_client[CLIENT_REGION].size(); index++) {
		overlap = 0;
		for (int i = 1; i < index; i++) {
			if (info_client[CLIENT_REGION][index] == info_client[CLIENT_REGION][i])
				overlap++;
		}
		if (overlap == 0)
			regions.push_back(info_client[CLIENT_REGION][index]);
	}
	return regions;
}


void print_items_by_region(const Matrix& info_client, const Matrix& info_item) {
	/* 기능: 쿠팡맨의 배송을 위해 지역별로 주문한 물품들의 정보를 화면에 출력할 것
	   요구사항: 아래 regions를 반드시 사용할 것
	   참고: 한 지역에 복수 물품 ID가 출력될 수 있으며, 정렬되지 않아도 됨(예를 들어, 서울: F04,C01,F04,) 
	*/

	vector<string> regions = extract_regions(info_client);
	
	for (int i = 0; i < regions.size(); i++) {
		cout << setw(15) << regions[i] << ": ";
		for (int index = 1; index < info_client[CLIENT_REGION].size(); index++) {
			if (regions[i] == info_client[CLIENT_REGION][index])
				cout << info_client[CLIENT_ORDER_LIST][index] << ",";
		}
		cout << endl;
	}
	cout << endl;
}


int search_item_by_id(const Matrix& info_item, string& id) {
	/* 기능: ID를 키보드로부터 입력받아 info_item에서 해당 id와 동일한 id를 찾은경우 label과 item의 세부 정보를 화면에 출력하고 vector의 해당 index를 반환
	         만약 동일한 id를 찾지 못하면 -1을 반환
	*/

	cout << "ID를 입력하세요>>";
	cin >> id;
	
	for (int index = 1; index < info_item[ITEM_ID].size(); index++) {
		if (info_item[ITEM_ID][index] == id) {
			print_each(info_item, 0);
			print_each(info_item, index);
			cout << endl;
			return index;
		}
	}
	cout << endl;
	return -1;
}


int search_client_by_id(const Matrix& info_client, string& id) {
	/* 기능: ID를 키보드로부터 입력받아 info_client에서 해당 id와 동일한 id를 찾은경우 label과 client의 세부 정보를 화면에 출력하고 vector의 해당 index를 반환
	         만약 동일한 id를 찾지 못하면 -1을 반환
	*/

	cout << "ID를 입력하세요>>";
	cin >> id;
	
	for (int index = 1; index < info_client[CLIENT_ID].size(); index++) {
		if (info_client[CLIENT_ID][index] == id) {
			print_each(info_client, 0);
			print_each(info_client, index);
			cout << endl;
			return index;
		}
	}
	cout << endl;
	return -1;
}


void add_client(Matrix& info_client) {
	/* 기능: id를 키보드로 부터 입력받아, 해당 id를 가진 고객이 info_client에 이미 존재하면 "동일한 ID가 존재합니다"를 화면에 출력
	         그렇지 않으면 추가로 비밀번호와 지역을 입력으로 받아 vector들의 가장 마지막 부분에 추가(이때, info_client[CLIENT_ORDER_LIST]에는 "N/A" 문자열을 추가) 
       요구사항: search_client_by_id()를 사용해서 id가 존재하는지 찾을 것
	*/

	string input;

	if (search_client_by_id(info_client, input) > 0)
		cout << "동일한 ID가 존재합니다." << endl << endl;
	else {
		info_client[CLIENT_ID].push_back(input);
		cout << "비밀번호를 입력하세요>>";
		cin >> input;
		info_client[CLIENT_PW].push_back(input);
		cout << "지역을 입력하세요>>";
		cin >> input;
		info_client[CLIENT_REGION].push_back(input);
		info_client[CLIENT_ORDER_LIST].push_back("N/A");
		cout << "추가 완료." << endl << endl;
	}
}


void delete_client(Matrix& info_client) {
	/* 기능: id를 키보드로 부터 입력받아, 해당 id를 가진 고객이 info_client에 이미 존재하지 않으면 "ID가 존재하지 않습니다"를 화면에 출력
	         존재할 경우 해당 고객정보를 vector에서 삭제할 것
			 (힌트: 제거해야 할 element의 index가 i라면, [i+1]번째 element를 [i]번째 element로 복사하고, 이를 마지막 element까지 반복 후 pop_back()사용) 
	요구사항: search_client_by_id()를 사용해서 id가 존재하는지 찾을 것
	*/

	string input;
	
	int index = search_client_by_id(info_client, input);
	if (index == -1)
		cout << "ID가 존재하지 않습니다." << endl << endl;
	else {
		for (int i = 0; i < 4; i++) {
			for (int j = index + 1; j < info_client[i].size(); j++) {
				info_client[i][j - 1] = info_client[i][j];
			}
			info_client[i].pop_back();
		}
		cout << "삭제되었습니다." << endl << endl;
	}
}


void add_item(Matrix& info_item) {
	/* 기능: id를 키보드로 부터 입력받아, 해당 id를 가진 고객이 info_item에 이미 존재하면 "동일한 ID가 존재합니다"를 화면에 출력
	         그렇지 않으면 추가로 상품명과 수량을 입력으로 받아 vector들의 가장 마지막 부분에 추가(상품명, 수량등 숫자도 모두 string문자열로 처리할 것)
			 요구사항: search_client_by_id()를 사용해서 id가 존재하는지 찾을 것
	*/

	string input;
	
	if (search_item_by_id(info_item, input) > 0)
		cout << "동일한 ID가 존재합니다." << endl << endl;
	else {
		info_item[CLIENT_ID].push_back(input);
		cout << "상품명을 입력하세요>>";
		cin >> input;
		info_item[ITEM_NAME].push_back(input);
		cout << "가격을 입력하세요>>";
		cin >> input;
		info_item[ITEM_PRICE].push_back(input);
		cout << "수량을 입력하세요>>";
		cin >> input;
		info_item[ITEM_QUANTITY].push_back(input);
		cout << "추가 완료." << endl << endl;
	}
}


void delete_item(Matrix& info_item) {
	/* 기능: id를 키보드로 부터 입력받아, 해당 id를 가진 물품이 info_client에 이미 존재하지 않으면 "ID가 존재하지 않습니다"를 화면에 출력
	         존재할 경우, 해당 물품정보를 vector에서 삭제할 것
	         (힌트: 제거해야 할 element의 index가 i라면, [i+1]번째 element를 [i]번째 element로 복사하고, 이를 마지막 element까지 반복 후 pop_back()사용)
	요구사항: search_item_by_id()를 사용해서 id가 존재하는지 찾을 것
	*/

	string input;
	
	int index = search_item_by_id(info_item, input);
	if (index == -1)
		cout << "ID가 존재하지 않습니다." << endl << endl;
	else {
		for (int i = 0; i < 4; i++) {
			for (int j = index + 1; j < info_item[i].size(); j++) {
				info_item[i][j - 1] = info_item[i][j];
			}
			info_item[i].pop_back();
		}
		cout << "삭제되었습니다." << endl << endl;
	}
}



void client_start(Matrix& info_client, Matrix& info_item) {
	/* 기능: 아래의 기능들을 구현할 경우 가산점 (기능의 난이도 및 갯수에 따라) 추가
	(적절히 난이도가 높은)재미있는 기능을 제안해도됨
	기능의 예: 로그인 및 password 변경, 주문한 물품 정보 조회(ID를 이용해서 각 물품의 정보를 화면에 출력) 물품 주문, 물품 수취 확인 등
	요구사항: 각 기능들은 함수로 구현할 것
	요구사항: 각 기능들에 대한 예외처리는 완벽해야 함(예를 들어, '물품 주문' 시 수량이 없는 물품을 주문하면 "수량이 부족합니다"를 화면에 출력하고 주문이 취소되어야 함)
	*/

	string id, pw, command;
	int client_index;
	get_id_pw(id, pw);
	if (client_login(info_client, id, pw, client_index)) {
		cout << "로그인 완료." << endl << endl;
		while (true) {
			command = get_command_client();
			if (command == "1")		 change_password(info_client, client_index);
			else if (command == "2") change_region(info_client, client_index);
			else if (command == "3") {
				membership_withdrawal(info_client, client_index);
				break;
			}
			else if (command == "4") order_item(info_client, info_item, client_index);
			else if (command == "0") break;
			else                     cout << "잘못 입력하였습니다." << endl << endl;
		}
	}
	else {
		cout << "ID 또는 암호가 잘못되었습니다." << endl << endl;
	}
}


bool client_login(const Matrix& info_client, string id, string pw, int& client_index) {
	for (int index = 1; index < info_client[CLIENT_ID].size(); index++) {
		if (info_client[CLIENT_ID][index] == id && info_client[CLIENT_PW][index] == pw) {
			client_index = index;
			return client_index;
		}
	}
	return 0;
}


string get_command_client() {
	string command;
	cout << "1. 암호 변경         " << endl;
	cout << "2. 지역 변경         " << endl;
	cout << "3. 회원탈퇴          " << endl;
	cout << "---------------------" << endl;
	cout << "4. 주문하기          " << endl;
	cout << "---------------------" << endl;
	cout << "0. 종료              " << endl;
	cout << ">>";
	cin >> command;
	return command;
}


bool identify_password(const Matrix& info_client, int client_index) {
	string pw;
	cout << "본인확인을 위해 암호를 입력하세요>>";
	cin >> pw;
	if (info_client[CLIENT_PW][client_index] == pw)
		return 1;
	cout << "암호가 잘못되었습니다." << endl << endl;
	return 0;
}


void change_password(Matrix& info_client, int client_index) {
	if (identify_password(info_client, client_index)) {
		string input;
		cout << "새로운 암호를 입력하세요>>";
		cin >> input;
		info_client[CLIENT_PW][client_index] = input;
		cout << "변경 완료." << endl << endl;
	}
}


void change_region(Matrix& info_client, int client_index) {
	if (identify_password(info_client, client_index)) {
		string input;
		cout << "새로운 지역을 입력하세요>>";
		cin >> input;
		info_client[CLIENT_REGION][client_index] = input;
		cout << "변경 완료." << endl << endl;
	}
}


void membership_withdrawal(Matrix& info_client, int client_index) {
	if (identify_password(info_client, client_index)) {
		for (int i = 0; i < 4; i++) {
			for (int j = client_index + 1; j < info_client[i].size(); j++) {
				info_client[i][j - 1] = info_client[i][j];
			}
			info_client[i].pop_back();
		}
		cout << "탈퇴 완료." << endl << endl;
	}
}


void order_item(Matrix& info_client, Matrix& info_item, int client_index) {
	int num;
	print_each(info_item, 0);
	for (int index = 1; index < info_item[ITEM_NAME].size(); index++) {
		cout << index << ". ";
		print_each(info_item, index);
	}
	cout << "주문할 상품의 번호를 입력하세요(없으면 0)>>";
	cin >> num;
	if (num == 0) {}
	else if (0 < num && num < info_item[ITEM_NAME].size()) {
		if (info_item[ITEM_QUANTITY][num] == "0")
			cout << "품절되었습니다." << endl << endl;
		else {
			info_item[ITEM_QUANTITY][num] = to_string(atoi(info_item[ITEM_QUANTITY][num].c_str()) - 1);
			info_client[CLIENT_ORDER_LIST][client_index] += "," + info_item[ITEM_ID][num];
			print_each(info_client, 0);
			print_each(info_client, client_index);
			cout << "주문 완료." << endl << endl;
		}
	}
	else
		cout << "잘못된 주문입니다." << endl << endl;
}