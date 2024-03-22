#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
using Matrix = vector<vector<string>>;

// ����1: �� �Լ����� ������ å��. �Լ��� ��Ȯ�� ����� ��쿡 10��, �׷��� ������ 0�� 
// ����2: �α��ν� �������� ID: admin, ��й�ȣ :0000 
// �䱸����1: ÷�ε� ��������(MidtermProjectCoupang.exe)�� ���۽��� ������ ������ ����ǵ��� �ڵ��� ��
// �䱸����2: file�� ������ �߰�/�����Ǵ���(������� ȸ�� �߰�) �Ϲ������� ������ �� �ֵ��� �ڵ��� �� (���� ������ ���Ͽ� ���ؼ��� �����ϸ� ���� �Լ� ��� ����)
// �䱸����3: (�ּ��� �����ϰ�) �Ʒ� �̹� �ۼ����ڵ带 �����Ͻ� ����, �� �ڵ带 Ȱ���ؼ� �ۼ��� ��
// �䱸����4: �Ʒ��� define�� symol�� ����Ͽ� �������� ���� ��(���� ���, info_client[0] ��� info_client[CLIENT_ID]�� ���, info_item[1] ��� info_client[ITEM_NAME]�� ���)
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
void client_start(Matrix& info_client, Matrix& info_item); // �߰����� (�ִ� 15��)

bool client_login(const Matrix& info_client, string id, string pw, int& client_index);
string get_command_client();
bool identify_password(const Matrix& info_client, int client_index);
void change_password(Matrix& info_client, int client_index);
void change_region(Matrix& info_client, int client_index);
void membership_withdrawal(Matrix& info_client, int client_index);
void order_item(Matrix& info_client, Matrix& info_item, int client_index);

void read_info(Matrix& info_client, Matrix& info_item, string filename_client, string filename_item);  //10��
void write_info(const Matrix& info_client, const Matrix& info_item, string filename_client, string filename_item); //10��

void print_all(const Matrix& info_client); //10��
void print_each(const Matrix& info_client, int index); //10��
int search_client_by_id(const Matrix& info_client, string& id); //10��
void add_client(Matrix& info_client); //10��
void delete_client(Matrix& info_client);// 10��

vector<string> extract_regions(const Matrix& info_client); //10��
void print_items_by_region(const Matrix& info_client, const Matrix& info_item); // 10��
int search_item_by_id(const Matrix& info_item, string& id); // 10��
void add_item(Matrix& info_item); //10��
void delete_item(Matrix& info_item); //10��

int main() {
	string command;
	Matrix info_client(4), info_item(4); //info_client�� ȸ������, info_item�� ��ǰ������ ����
	read_info(info_client, info_item, "clients.txt", "items.txt");

	while (true) {
		cout << "1. ������ �α���" << endl;
		cout << "2. ȸ�� �α���" << endl;
		cout << "0. ���� �� ����" << endl;
		cout << ">>";
		cin >> command;
		if (command == "1")
			admin_start(info_client, info_item);
		else if (command == "2")
			client_start(info_client, info_item);
		else if (command == "0")
			break;
		else
			cout << "�߸� �Է��Ͽ����ϴ�." << endl;
	}

	write_info(info_client, info_item, "clients.txt", "items.txt");

	return 0;
}


void get_id_pw(string& id, string& pw) {
	cout << "ID�� �Է��ϼ���>>";
	cin >> id;
	cout << "��ȣ�� �Է��ϼ���>>";
	cin >> pw;
}


string get_command_admin() {
	string command;
	cout << "1. ��� ȸ������ ���" << endl;
	cout << "2. ȸ�� �˻�         " << endl;
	cout << "3. ȸ�� �߰�         " << endl;
	cout << "4. ȸ�� ����         " << endl;
	cout << "---------------------" << endl;
	cout << "5. ��� ��ǰ���� ���" << endl;
	cout << "6. ������� ��ǰ ���" << endl;
	cout << "7. ��ǰ �˻�         " << endl;
	cout << "8. ��ǰ �߰�         " << endl;
	cout << "9. ��ǰ ����         " << endl;
	cout << "---------------------" << endl;
	cout << "0. ����              " << endl;
	cout << ">>";
	cin >> command;
	return command;
}


void admin_start(Matrix& info_client, Matrix& info_item) {
	string id, pw, command;
	get_id_pw(id, pw);
	if (id == "admin" && pw == "0000") {
		cout << "�α��� �Ϸ�." << endl << endl;
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
			else                     cout << "�߸� �Է��Ͽ����ϴ�." << endl << endl;
		}
	}
	else {
		cout << "ID �Ǵ� ��ȣ�� �߸��Ǿ����ϴ�." << endl << endl;
	}
}

void read_info(Matrix& info_client, Matrix& info_item, string filename_client, string filename_item) {
	/* ���: filename_client�� filename_item�� ������ info_client�� info_item�� ������ ��
	   �䱸����1: ������ ����� ������ �ʴ� ��� "������ �������� �ʽ��ϴ�"�� ȭ�鿡 ����ϰ� exit(100)�� �̿��Ͽ� ���α׷� ��������
	   �䱸����2: ���� �б⸦ ��ģ �� �ݵ�� ������
	   ����: info_client�� info_item�� ���� �� vector element�� ù ��° element�� ���� ȸ��(�Ǵ� ��ǰ)������ �ƴ� �Ʒ��� label�� ����: 
	         - info_client:     ID  Password    Region       Order_Item_ID
	         - info_item:	    ID            ItemName     Price  Quantity
	 */

	ifstream fin;
	string str;
	fin.open(filename_client);
	if (!fin) {
		cout << "������ �������� �ʽ��ϴ�";
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
		cout << "������ �������� �ʽ��ϴ�";
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

	cout << "���� �б� �Ϸ�." << endl << endl;
}


void write_info(const Matrix& info_client, const Matrix& info_item, string filename_client, string filename_item) {
	/* ���: info_client�� info_item�� ������ filename_client�� filename_item�� ������ ��
	  �䱸����1: ���� ���⸦ ��ģ �� �ݵ�� ������
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

	cout << "����Ϸ� - ���α׷��� �����մϴ�." << endl;
}


void print_each(const Matrix& info, int index) {
	/* ���: �ش� index�� �ش��ϴ� info_item(�Ǵ� info_client)�� ������ ȭ�鿡 ���
	   �䱸����: setw(15)�� �̿��Ͽ� �� element�� ������ ���� ��
	*/

	for (int i = 0; i < 4; i++) {
		cout << setw(15) << info[i][index];
	}
	cout << endl;
}


void print_all(const Matrix& info) {
	/* ���: info_item(�Ǵ� info_client)�� ������ ȭ�鿡 ���
	   �䱸����1: �� item(�Ǵ� client)�� �ݵ�� print_each()�Լ��� ����ؼ� ȭ�鿡 ���
	*/
	
	for (int index = 0; index < info[0].size(); index++) {
		print_each(info, index);
	}
	cout << endl;
}


vector<string> extract_regions(const Matrix& info_client) {
	/* ���: ȸ���� ���� ������ �ߺ��� ������� �ʰ� vector�� element�� ������ ���� �ش� vector�� ��ȯ
	   ��: ȸ���� ������ (����, ����, �λ�, �λ� �λ�, ����) �� ��� --> (����, �λ�, ����) ���� �ߺ��� ����
	       �̶� ������ ��� ������ �������(���ĵ��� �ʾƵ� ��)
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
	/* ���: ���θ��� ����� ���� �������� �ֹ��� ��ǰ���� ������ ȭ�鿡 ����� ��
	   �䱸����: �Ʒ� regions�� �ݵ�� ����� ��
	   ����: �� ������ ���� ��ǰ ID�� ��µ� �� ������, ���ĵ��� �ʾƵ� ��(���� ���, ����: F04,C01,F04,) 
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
	/* ���: ID�� Ű����κ��� �Է¹޾� info_item���� �ش� id�� ������ id�� ã����� label�� item�� ���� ������ ȭ�鿡 ����ϰ� vector�� �ش� index�� ��ȯ
	         ���� ������ id�� ã�� ���ϸ� -1�� ��ȯ
	*/

	cout << "ID�� �Է��ϼ���>>";
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
	/* ���: ID�� Ű����κ��� �Է¹޾� info_client���� �ش� id�� ������ id�� ã����� label�� client�� ���� ������ ȭ�鿡 ����ϰ� vector�� �ش� index�� ��ȯ
	         ���� ������ id�� ã�� ���ϸ� -1�� ��ȯ
	*/

	cout << "ID�� �Է��ϼ���>>";
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
	/* ���: id�� Ű����� ���� �Է¹޾�, �ش� id�� ���� ���� info_client�� �̹� �����ϸ� "������ ID�� �����մϴ�"�� ȭ�鿡 ���
	         �׷��� ������ �߰��� ��й�ȣ�� ������ �Է����� �޾� vector���� ���� ������ �κп� �߰�(�̶�, info_client[CLIENT_ORDER_LIST]���� "N/A" ���ڿ��� �߰�) 
       �䱸����: search_client_by_id()�� ����ؼ� id�� �����ϴ��� ã�� ��
	*/

	string input;

	if (search_client_by_id(info_client, input) > 0)
		cout << "������ ID�� �����մϴ�." << endl << endl;
	else {
		info_client[CLIENT_ID].push_back(input);
		cout << "��й�ȣ�� �Է��ϼ���>>";
		cin >> input;
		info_client[CLIENT_PW].push_back(input);
		cout << "������ �Է��ϼ���>>";
		cin >> input;
		info_client[CLIENT_REGION].push_back(input);
		info_client[CLIENT_ORDER_LIST].push_back("N/A");
		cout << "�߰� �Ϸ�." << endl << endl;
	}
}


void delete_client(Matrix& info_client) {
	/* ���: id�� Ű����� ���� �Է¹޾�, �ش� id�� ���� ���� info_client�� �̹� �������� ������ "ID�� �������� �ʽ��ϴ�"�� ȭ�鿡 ���
	         ������ ��� �ش� �������� vector���� ������ ��
			 (��Ʈ: �����ؾ� �� element�� index�� i���, [i+1]��° element�� [i]��° element�� �����ϰ�, �̸� ������ element���� �ݺ� �� pop_back()���) 
	�䱸����: search_client_by_id()�� ����ؼ� id�� �����ϴ��� ã�� ��
	*/

	string input;
	
	int index = search_client_by_id(info_client, input);
	if (index == -1)
		cout << "ID�� �������� �ʽ��ϴ�." << endl << endl;
	else {
		for (int i = 0; i < 4; i++) {
			for (int j = index + 1; j < info_client[i].size(); j++) {
				info_client[i][j - 1] = info_client[i][j];
			}
			info_client[i].pop_back();
		}
		cout << "�����Ǿ����ϴ�." << endl << endl;
	}
}


void add_item(Matrix& info_item) {
	/* ���: id�� Ű����� ���� �Է¹޾�, �ش� id�� ���� ���� info_item�� �̹� �����ϸ� "������ ID�� �����մϴ�"�� ȭ�鿡 ���
	         �׷��� ������ �߰��� ��ǰ��� ������ �Է����� �޾� vector���� ���� ������ �κп� �߰�(��ǰ��, ������ ���ڵ� ��� string���ڿ��� ó���� ��)
			 �䱸����: search_client_by_id()�� ����ؼ� id�� �����ϴ��� ã�� ��
	*/

	string input;
	
	if (search_item_by_id(info_item, input) > 0)
		cout << "������ ID�� �����մϴ�." << endl << endl;
	else {
		info_item[CLIENT_ID].push_back(input);
		cout << "��ǰ���� �Է��ϼ���>>";
		cin >> input;
		info_item[ITEM_NAME].push_back(input);
		cout << "������ �Է��ϼ���>>";
		cin >> input;
		info_item[ITEM_PRICE].push_back(input);
		cout << "������ �Է��ϼ���>>";
		cin >> input;
		info_item[ITEM_QUANTITY].push_back(input);
		cout << "�߰� �Ϸ�." << endl << endl;
	}
}


void delete_item(Matrix& info_item) {
	/* ���: id�� Ű����� ���� �Է¹޾�, �ش� id�� ���� ��ǰ�� info_client�� �̹� �������� ������ "ID�� �������� �ʽ��ϴ�"�� ȭ�鿡 ���
	         ������ ���, �ش� ��ǰ������ vector���� ������ ��
	         (��Ʈ: �����ؾ� �� element�� index�� i���, [i+1]��° element�� [i]��° element�� �����ϰ�, �̸� ������ element���� �ݺ� �� pop_back()���)
	�䱸����: search_item_by_id()�� ����ؼ� id�� �����ϴ��� ã�� ��
	*/

	string input;
	
	int index = search_item_by_id(info_item, input);
	if (index == -1)
		cout << "ID�� �������� �ʽ��ϴ�." << endl << endl;
	else {
		for (int i = 0; i < 4; i++) {
			for (int j = index + 1; j < info_item[i].size(); j++) {
				info_item[i][j - 1] = info_item[i][j];
			}
			info_item[i].pop_back();
		}
		cout << "�����Ǿ����ϴ�." << endl << endl;
	}
}



void client_start(Matrix& info_client, Matrix& info_item) {
	/* ���: �Ʒ��� ��ɵ��� ������ ��� ������ (����� ���̵� �� ������ ����) �߰�
	(������ ���̵��� ����)����ִ� ����� �����ص���
	����� ��: �α��� �� password ����, �ֹ��� ��ǰ ���� ��ȸ(ID�� �̿��ؼ� �� ��ǰ�� ������ ȭ�鿡 ���) ��ǰ �ֹ�, ��ǰ ���� Ȯ�� ��
	�䱸����: �� ��ɵ��� �Լ��� ������ ��
	�䱸����: �� ��ɵ鿡 ���� ����ó���� �Ϻ��ؾ� ��(���� ���, '��ǰ �ֹ�' �� ������ ���� ��ǰ�� �ֹ��ϸ� "������ �����մϴ�"�� ȭ�鿡 ����ϰ� �ֹ��� ��ҵǾ�� ��)
	*/

	string id, pw, command;
	int client_index;
	get_id_pw(id, pw);
	if (client_login(info_client, id, pw, client_index)) {
		cout << "�α��� �Ϸ�." << endl << endl;
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
			else                     cout << "�߸� �Է��Ͽ����ϴ�." << endl << endl;
		}
	}
	else {
		cout << "ID �Ǵ� ��ȣ�� �߸��Ǿ����ϴ�." << endl << endl;
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
	cout << "1. ��ȣ ����         " << endl;
	cout << "2. ���� ����         " << endl;
	cout << "3. ȸ��Ż��          " << endl;
	cout << "---------------------" << endl;
	cout << "4. �ֹ��ϱ�          " << endl;
	cout << "---------------------" << endl;
	cout << "0. ����              " << endl;
	cout << ">>";
	cin >> command;
	return command;
}


bool identify_password(const Matrix& info_client, int client_index) {
	string pw;
	cout << "����Ȯ���� ���� ��ȣ�� �Է��ϼ���>>";
	cin >> pw;
	if (info_client[CLIENT_PW][client_index] == pw)
		return 1;
	cout << "��ȣ�� �߸��Ǿ����ϴ�." << endl << endl;
	return 0;
}


void change_password(Matrix& info_client, int client_index) {
	if (identify_password(info_client, client_index)) {
		string input;
		cout << "���ο� ��ȣ�� �Է��ϼ���>>";
		cin >> input;
		info_client[CLIENT_PW][client_index] = input;
		cout << "���� �Ϸ�." << endl << endl;
	}
}


void change_region(Matrix& info_client, int client_index) {
	if (identify_password(info_client, client_index)) {
		string input;
		cout << "���ο� ������ �Է��ϼ���>>";
		cin >> input;
		info_client[CLIENT_REGION][client_index] = input;
		cout << "���� �Ϸ�." << endl << endl;
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
		cout << "Ż�� �Ϸ�." << endl << endl;
	}
}


void order_item(Matrix& info_client, Matrix& info_item, int client_index) {
	int num;
	print_each(info_item, 0);
	for (int index = 1; index < info_item[ITEM_NAME].size(); index++) {
		cout << index << ". ";
		print_each(info_item, index);
	}
	cout << "�ֹ��� ��ǰ�� ��ȣ�� �Է��ϼ���(������ 0)>>";
	cin >> num;
	if (num == 0) {}
	else if (0 < num && num < info_item[ITEM_NAME].size()) {
		if (info_item[ITEM_QUANTITY][num] == "0")
			cout << "ǰ���Ǿ����ϴ�." << endl << endl;
		else {
			info_item[ITEM_QUANTITY][num] = to_string(atoi(info_item[ITEM_QUANTITY][num].c_str()) - 1);
			info_client[CLIENT_ORDER_LIST][client_index] += "," + info_item[ITEM_ID][num];
			print_each(info_client, 0);
			print_each(info_client, client_index);
			cout << "�ֹ� �Ϸ�." << endl << endl;
		}
	}
	else
		cout << "�߸��� �ֹ��Դϴ�." << endl << endl;
}