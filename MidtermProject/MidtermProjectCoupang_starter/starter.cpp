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

	// ...
	cout << "���� �б� �Ϸ�." << endl << endl;

}


void write_info(const Matrix& info_client, const Matrix& info_item, string filename_client, string filename_item) {
	/* ���: info_client�� info_item�� ������ filename_client�� filename_item�� ������ ��
	  �䱸����1: ���� ���⸦ ��ģ �� �ݵ�� ������
	*/

	// ...	
	cout << "����Ϸ� - ���α׷��� �����մϴ�." << endl;
}


void print_each(const Matrix& info, int index) {
	/* ���: �ش� index�� �ش��ϴ� info_item(�Ǵ� info_client)�� ������ ȭ�鿡 ���
	   �䱸����: setw(15)�� �̿��Ͽ� �� element�� ������ ���� ��
	*/
}


void print_all(const Matrix& info) {
	/* ���: info_item(�Ǵ� info_client)�� ������ ȭ�鿡 ���
	   �䱸����1: �� item(�Ǵ� client)�� �ݵ�� print_each()�Լ��� ����ؼ� ȭ�鿡 ���
	*/
}


vector<string> extract_regions(const Matrix& info_client) {
	/* ���: ȸ���� ���� ������ �ߺ��� ������� �ʰ� vector�� element�� ������ ���� �ش� vector�� ��ȯ
	   ��: ȸ���� ������ (����, ����, �λ�, �λ� �λ�, ����) �� ��� --> (����, �λ�, ����) ���� �ߺ��� ����
	       �̶� ������ ��� ������ �������(���ĵ��� �ʾƵ� ��)
	*/

	vector<string> regions;

	// ...

	return regions;
}


void print_items_by_region(const Matrix& info_client, const Matrix& info_item) {
	/* ���: ���θ��� ����� ���� �������� �ֹ��� ��ǰ���� ������ ȭ�鿡 ����� ��
	   �䱸����: �Ʒ� regions�� �ݵ�� ����� ��
	   ����: �� ������ ���� ��ǰ ID�� ��µ� �� ������, ���ĵ��� �ʾƵ� ��(���� ���, ����: F04,C01,F04,) 
	*/

	vector<string> regions = extract_regions(info_client);
	// ...
}


int search_item_by_id(const Matrix& info_item, string& id) {
	/* ���: ID�� Ű����κ��� �Է¹޾� info_item���� �ش� id�� ������ id�� ã����� label�� item�� ���� ������ ȭ�鿡 ����ϰ� vector�� �ش� index�� ��ȯ
	         ���� ������ id�� ã�� ���ϸ� -1�� ��ȯ
	*/

	cout << "ID�� �Է��ϼ���>>";
	cin >> id;
	// ...

	return -1;
}


int search_client_by_id(const Matrix& info_client, string& id) {
	/* ���: ID�� Ű����κ��� �Է¹޾� info_client���� �ش� id�� ������ id�� ã����� label�� client�� ���� ������ ȭ�鿡 ����ϰ� vector�� �ش� index�� ��ȯ
	         ���� ������ id�� ã�� ���ϸ� -1�� ��ȯ
	*/

	cout << "ID�� �Է��ϼ���>>";
	cin >> id;
	// ...

	return -1;
}


void add_client(Matrix& info_client) {
	/* ���: id�� Ű����� ���� �Է¹޾�, �ش� id�� ���� ���� info_client�� �̹� �����ϸ� "������ ID�� �����մϴ�"�� ȭ�鿡 ���
	         �׷��� ������ �߰��� ��й�ȣ�� ������ �Է����� �޾� vector���� ���� ������ �κп� �߰�(�̶�, info_client[CLIENT_ORDER_LIST]���� "N/A" ���ڿ��� �߰�) 
       �䱸����: search_client_by_id()�� ����ؼ� id�� �����ϴ��� ã�� ��
	*/
}


void delete_client(Matrix& info_client) {
	/* ���: id�� Ű����� ���� �Է¹޾�, �ش� id�� ���� ���� info_client�� �̹� �������� ������ "ID�� �������� �ʽ��ϴ�"�� ȭ�鿡 ���
	         ������ ��� �ش� �������� vector���� ������ ��
			 (��Ʈ: �����ؾ� �� element�� index�� i���, [i+1]��° element�� [i]��° element�� �����ϰ�, �̸� ������ element���� �ݺ� �� pop_back()���) 
	�䱸����: search_client_by_id()�� ����ؼ� id�� �����ϴ��� ã�� ��
	*/
}


void add_item(Matrix& info_item) {
	/* ���: id�� Ű����� ���� �Է¹޾�, �ش� id�� ���� ���� info_item�� �̹� �����ϸ� "������ ID�� �����մϴ�"�� ȭ�鿡 ���
	         �׷��� ������ �߰��� ��ǰ��� ������ �Է����� �޾� vector���� ���� ������ �κп� �߰�(��ǰ��, ������ ���ڵ� ��� string���ڿ��� ó���� ��)
			 �䱸����: search_client_by_id()�� ����ؼ� id�� �����ϴ��� ã�� ��
	*/
}


void delete_item(Matrix& info_item) {
	/* ���: id�� Ű����� ���� �Է¹޾�, �ش� id�� ���� ��ǰ�� info_client�� �̹� �������� ������ "ID�� �������� �ʽ��ϴ�"�� ȭ�鿡 ���
	         ������ ���, �ش� ��ǰ������ vector���� ������ ��
	         (��Ʈ: �����ؾ� �� element�� index�� i���, [i+1]��° element�� [i]��° element�� �����ϰ�, �̸� ������ element���� �ݺ� �� pop_back()���)
	�䱸����: search_item_by_id()�� ����ؼ� id�� �����ϴ��� ã�� ��
	*/

}



void client_start(Matrix& info_client, Matrix& info_item) {
	/* ���: �Ʒ��� ��ɵ��� ������ ��� ������ (����� ���̵� �� ������ ����) �߰�
	(������ ���̵��� ����)����ִ� ����� �����ص���
	����� ��: �α��� �� password ����, �ֹ��� ��ǰ ���� ��ȸ(ID�� �̿��ؼ� �� ��ǰ�� ������ ȭ�鿡 ���) ��ǰ �ֹ�, ��ǰ ���� Ȯ�� ��
	�䱸����: �� ��ɵ��� �Լ��� ������ ��
	�䱸����: �� ��ɵ鿡 ���� ����ó���� �Ϻ��ؾ� ��(���� ���, '��ǰ �ֹ�' �� ������ ���� ��ǰ�� �ֹ��ϸ� "������ �����մϴ�"�� ȭ�鿡 ����ϰ� �ֹ��� ��ҵǾ�� ��)
	*/
}
