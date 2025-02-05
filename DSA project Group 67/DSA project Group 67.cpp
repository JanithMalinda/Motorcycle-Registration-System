
#include <cstddef>
#include <iostream>
#include <string>
#include<cctype>

using namespace std;


class Node {
public:
	
	string char_part;
	int num_part;
	
	string chassis_number, type;
	string engine_number , category;
	int id_num;

	Node* next;
	Node* prev;

	
	Node() {
		num_part = -1;
		next = NULL;
		prev = NULL;
	}
	
	Node(string e, int num) {
		char_part = e;
		num_part = num;
		next = NULL;
		prev = NULL;
		input_data(); 

	}


	
	void input_data() {
		cout << endl;
		cout << "\t\t\t\tCategory   : ";
		cin >> category;

		cout << "\t\t\t\tEngine no  : ";
		cin >> engine_number;

		cout << "\t\t\t\tChassis no : ";
		cin >> chassis_number;

		cout << "\t\t\t\tId number  :  ";
		cin >> id_num;
	}




};


class Doubly_Linked_List {
private:
	Node* head;
	Node* tail;
	int size;

public:
	Doubly_Linked_List() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	
	Node* getHead() {
		return head;
	}

	
	Node* getTail() {
		return tail;
	}


	
	void insertFirst(string elem, int num) {
		Node* temp = new Node(elem, num);

		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			temp->next = head;
			head->prev = temp;
			head = temp;
			size++;
		}
	}

	
	void insertLast(string elem, int num) {
		Node* temp = new Node(elem, num);

		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
			size++;
		}
	}

	
	void insertAt(int pos, string elem, int num) {
		if (pos < 0 || pos > size)
			cout << "Not a valid position" << endl;
		else if (pos == 0)
			insertFirst(elem, num);
		else if (pos == size)
			insertLast(elem, num);
		else {
			Node* temp = new Node(elem, num);
			Node* current = head;

			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}
			temp->next = current->next;
			temp->prev = current;
			current->next = temp;
			(temp->next)->prev = temp;
			size++;
		}
	}
	
	void insert(string elem, int num) {
		int check = 0;
		int place = 1;
		int equal = 0;
		if (head == NULL) {  
			insertFirst(elem, num);
		}
		else {
			Node* temp = head;
			for (int j = 0; j < size; j++) {
				if ((int(temp->char_part[0])) == elem[0]) {
					equal = 1;
					break;
				}
				
				else if ((int(temp->char_part[0])) > elem[0]) {
					place -= 1;
					insertAt(place, elem, num);
					break;
				}
				else if (j == (size - 1)) {
					insertLast(elem, num);
					break;
				}
				temp = temp->next;
				place += 1;
			}

			
			if (equal == 1) {
				for (int i = 1; i < 3; i++) {
					for (int k = 0; k < size; k++) {

						if (((int(temp->char_part[i])) == elem[i]) && ((int(temp->char_part[i - 1])) == elem[i - 1])) {
							equal += 1;
							break;
						}

						else if (((int(temp->char_part[i])) > elem[i]) && ((int(temp->char_part[i - 1])) == elem[i - 1])) {
							place -= 1;
							check = check + 1;
							break;
						}
						else if (((int(temp->char_part[i - 1])) != elem[i - 1])) {
							place -= 1;
							check = check + 1;
							break;
						}
						else if (temp->next == NULL) {
							insertLast(elem, num);
							break;
						}
						temp = temp->next;
						place += 1;
					}
					if (check == 1) {
						insertAt(place, elem, num);
						break;
					}
				}
			}
			
			if (equal == 3) {
				for (int m = 0; m < size; m++) {
					if ((temp->char_part) == elem && (temp->num_part) == num) {
						cout << "This Registration number has already taken." << endl;
						break;
					}

					else if ((temp->char_part) == elem && (temp->num_part) > num) {
						place -= 1;
						insertAt(place, elem, num);
						break;
					}
					else if ((temp->char_part) != elem) {
						place -= 1;
						insertAt(place, elem, num);
						break;
					}
					else if (temp->next == NULL) {
						insertLast(elem, num);
						break;
					}
					temp = temp->next;
					place += 1;
				}
			}
		}
	}

	
	void Search() {
		Node* current = head;
		int n;
		
		cout << "\t\t\t\tSearch with Reg. no (press 1) : " << endl;
		cout << "\t\t\t\tSearch with Id no   (press 2) : " << endl;
		cin >> n;
		
		if (n == 1) {
			int flag = 0;
			string letter;
			cout << "\t\t\t\tchar part : ";
			cin >> letter;

			
			
			cout << "\t" << "|  REGISTRATION NUMBER" << "\t" << "|  CATEGORY" << "\t" << "|  ENGINE NUMBER" << "\t" << "|  CHASSIS NUMBER" << "\t" << "|  ID NUMBER\t|" << endl;
			
			for (int j = 0; j < size; j++) {
				if (current->char_part == letter) {
					flag = 1;
					cout << "\t" << "|   " << current->char_part << " " << current->num_part << "\t\t|   " << current->category << "\t\t|  " << current->engine_number << "\t\t\t|    " << current->chassis_number << "\t\t|     " << current->id_num << "\t|" << endl;
					cout << "\t+-----------------------+---------------+-----------------------+-----------------------+---------------+" << endl;
				}
				current = current->next;
			}
			if (flag == 0) {
				cout << "\t\t\t\tdata does not exist" << endl << endl;
			}
			else {
				int elem;
				cout << "\t\t\t\tnum part  : ";
				cin >> elem;
				current = head;
				for (int j = 0; j < size; j++) {
					if (current->char_part == letter) {
						flag += 1;
						break;
					}
					current = current->next;
				}
				
				if (flag == 2) {
					
					cout << "\t" << "|  REGISTRATION NUMBER" << "\t" << "|  CATEGORY" << "\t" << "|  ENGINE NUMBER" << "\t" << "|  CHASSIS NUMBER" << "\t" << "|  ID NUMBER\t|" << endl;
					
					for (int i = 0; i < size; i++) {
						if ((current->num_part == elem) && (current->char_part == letter)) {
							cout << "\t" << "| " << current->char_part << " " << current->num_part << "\t|   " << current->category << "\t\t|  " << current->engine_number << "\t\t\t|    " << current->chassis_number << "\t\t|     " << current->id_num << "\t|" << endl;
							cout << "\t+-----------------------+---------------+-----------------------+-----------------------+---------------+" << endl;
							flag += 1;
							break;
						}
						current = current->next;
					}
					cout << "\t\t\t\tData does not exist." << endl;
				}
				else {
					cout << "error" << endl;
				}
				 
				if (flag == 3) {
					int a = 0;
					cout << "\t\t\t\tnext(press 1) or previous(press 2) : ";
					cin >> a;
					switch (a) {
					case 1:
						cout << "\t\t\t\tNext data set  : " << endl;;
						current = current->next;
						
						cout << "\t" << "|  REGISTRATION NUMBER" << "\t" << "|  CATEGORY" << "\t" << "|  ENGINE NUMBER" << "\t" << "|  CHASSIS NUMBER" << "\t" << "|  ID NUMBER\t|" << endl;
						
						cout << "\t" << "|   " << current->char_part << " " << current->num_part << "\t\t|   " << current->category << "\t\t|  " << current->engine_number << "\t\t\t|    " << current->chassis_number << "\t\t|     " << current->id_num << "\t|" << endl;
						cout << "\t+-----------------------+---------------+-----------------------+-----------------------+---------------+" << endl;
						break;
					case 2:
						cout << "\t\t\t\tprevious data set : " << endl;
						current = current->prev;
						
						cout << "\t" << "|  REGISTRATION NUMBER" << "\t" << "|  CATEGORY" << "\t" << "|  ENGINE NUMBER" << "\t" << "|  CHASSIS NUMBER" << "\t" << "|  ID NUMBER\t|" << endl;
						
						cout << "\t" << "|   " << current->char_part << " " << current->num_part << "\t\t|   " << current->category << "\t\t|  " << current->engine_number << "\t\t|    " << current->chassis_number << "\t\t|     " << current->id_num << "\t|" << endl;
						cout << "\t+-----------------------+---------------+-----------------------+-----------------------+---------------+" << endl;
						break;
					default:

						break;
					}
				}
			}
		}
		
		if (n == 2) {
			int id;
			cout << "\t\t\t\tId number : ";
			cin >> id;

			for (int i = 0; i < size; i++) {
				if (current->id_num == id) {
					
					cout << "\t" << "|  REGISTRATION NUMBER" << "\t" << "|  CATEGORY" << "\t" << "|  ENGINE NUMBER" << "\t" << "|  CHASSIS NUMBER" << "\t" << "|  ID NUMBER\t|" << endl;
					
					cout << "\t" << "|   " << current->char_part << "      " << current->num_part << "\t|   " << current->category << "\t\t|  " << current->engine_number << "\t\t\t|    " << current->chassis_number << "\t\t|     " << current->id_num << "\t|" << endl;
					cout << "\t+-----------------------+---------------+-----------------------+-----------------------+---------------+" << endl;
				}
				current = current->next;
			}
			cout << endl;
		}


	}
	
	void print() {
		Node* current = head;

		
		cout << "\t" << "|  REGISTRATION NUMBER" << "\t" << "|  CATEGORY" << "\t" << "|  ENGINE NUMBER" << "\t" << "|  CHASSIS NUMBER" << "\t" << "|  ID NUMBER\t|" << endl;
		
		while (current != NULL) {
			cout << "\t" << "|   " << current->char_part << " " << current->num_part << "\t\t|   " << current->category << "\t\t|  " << current->engine_number << "\t\t\t |   " << current->chassis_number << "\t\t|     " << current->id_num << "\t|" << endl;
			cout << "\t+-----------------------+---------------+-----------------------+-----------------------+---------------+" << endl;
			current = current->next;
		}

		cout << endl;
	}
	
	void deleteFirst() {

		if (head == NULL)
			cout << "List is empty" << endl;
		else {
			Node* temp = head;

			if (size == 1) {
				delete temp;
				head = NULL;
				tail = NULL;
				size = 0;
			}
			else {
				head = head->next;
				head->prev = NULL;
				delete temp;
				size--;
			}
		}
	}
	
	void deleteLast() {

		if (head == NULL)
			cout << "List is empty" << endl;
		else {
			Node* temp = tail;
			if (size == 1) {
				delete temp;
				head = NULL;
				tail = NULL;
				size = 0;
			}
			else {
				tail = tail->prev;
				tail->next = NULL;
				delete temp;
				size--;
			}
		}
	}
	
	void deleteAt(int pos) {
		Node* current = head;
		for (int i = 0; i < pos; i++) {
			current = current->next;
		}
		Node* temp = current;
		(current->prev)->next = temp->next;
		(current->next)->prev = temp->prev;
		delete temp;
		size--;
	}
	
	void deletedata() {
		Node* current;
		string elem;
		int num;
		int flag = 0;
		int pos = 0;
		current = head;

		cout << "\t\t\t\tchar part : ";
		cin >> elem;
		cout << "\t\t\t\tnum part  :";
		cin >> num;


		if (head == NULL) {
			cout << "\t\t\t\tlist is empty." << endl;
		}
		else {
			for (int j = 0; j < size; j++) {
				if (current->char_part == elem) {
					flag = 1;
					break;
				}
				current = current->next;
				pos += 1;
			}

			if (flag == 0) {
				cout << "\t\t\t\tEntered registration number does not exist." << endl;
			}
			else if (flag == 1) {
				while (current != NULL) {
					if (current->num_part == num) {
						flag += 1;
						if (current == head) {
							deleteFirst();
						}
						else if (current->next == NULL) {
							deleteLast();
						}
						else {
							deleteAt(pos);

						}
						break;
					}
					current = current->next;
					pos += 1;
				}
				if (flag == 1) {
					cout << "\t\t\t\tEntered registration number does not exist." << endl;
				}
			}
		}
	}
	
	void edit() {
		Node* current;
		string elem;
		int num;
		int flag = 0;
		int n = 0;
		current = head;

		cout << "\t\t\t\tchar part : ";
		cin >> elem;
		cout << "\t\t\t\tnum part  : ";
		cin >> num;

		if (head == NULL) {
			cout << "\t\t\t\tlist is empty" << endl;
		}
		else {
			for (int j = 0; j < size; j++) {
				if (current->char_part == elem) {
					flag = 1;
					break;
				}
				current = current->next;
			}

			if (flag == 0) {
				cout << "\t\t\t\tEntered registration number does not exist." << endl;
			}
			else if (flag == 1) {
				while (current != NULL) {
					if (current->num_part == num) {
						flag += 1;
						cout << "\t\t\t\tvalue to edit  : " << endl;
						cout << "\t\t\t\tcategory       : (press 1)" << endl;
						cout << "\t\t\t\tEngine number  : (press 2)" << endl;
						cout << "\t\t\t\tChassis number : (press 3)" << endl;
						cout << "\t\t\t\tId number      : (press 4)" << endl;
						cin >> n;
						switch (n) {
						case 1:
							cout << "\t\t\t\tcategory       : ";
							cin >> current->category;
							break;
						case 2:
							cout << "\t\t\t\tEngine number  : ";
							cin >> current->engine_number;
							break;
						case 3:
							cout << "\t\t\t\tChassis number : ";
							cin >> current->chassis_number;
							break;
						case 4:
							cout << "\t\t\t\tId number      : ";
							cin >> current->id_num;
							break;
						default:

							break;
						}
					}
					current = current->next;
				}
				if (flag == 1) {
					cout << "Entered registration number does not exist." << endl;
				}
			}
		}
	}

};



int main()
{
	Doubly_Linked_List dll;
	string char_part;
	int num_part;
	int n = 0;
	char a;



top:
	cout << endl;
	cout << "\t>>> M O R T O R C Y C L E   R E G I S T R A T I O N   S Y S T E M <<<" << endl;
	cout << "\t....................................................................." << endl;
	cout << endl << "\t\t\t\t=>> INSERT\t: (press 1) " << endl << endl << "\t\t\t\t=>> VIEW\t: (press 2) "
		<< endl << endl << "\t\t\t\t=>> SEARCH\t: (press 3) " << endl << endl << "\t\t\t\t=>> DELETE\t: (press 4) "
		<< endl << endl << "\t\t\t\t=>> EDIT\t: (press 5) " << endl << endl;
	cin >> n;



	switch (n) {
	case 1:

		cout << "\t\t\t\tINPUT DATA" << endl;
		cout << "\t\t\t\t----------" << endl << endl;
		cout << "\t\t\t\tMortorcycle registration number : " << endl;
		cout << "\t\t\t\tchar part : ";
		cin >> char_part;
		cout << "\t\t\t\tnum part  :";
		cin >> num_part;
		dll.insert(char_part, num_part);
		break;
	case 2:

		cout << "\t\t\t\tLIST" << endl;
		cout << "\t\t\t\t----" << endl << endl;
		dll.print();
		break;
	case 3:

		cout << "\t\t\t\tSEARCH" << endl;
		cout << "\t\t\t\t------" << endl << endl;
		dll.Search();
		break;
	case 4:

		cout << "\t\t\t\tDELETE" << endl;
		cout << "\t\t\t\t------" << endl << endl;
		dll.deletedata();
		break;
	case 5:

		cout << "\t\t\t\tEDIT" << endl;
		cout << "\t\t\t\t----" << endl << endl;
		dll.edit();
		break;
	default:
		cout << " ";
		break;
	}
	cout << "\t\t\t\tPress O for continue : " << endl;
	cout << "\t\t\t\tPress X for exit     : " << endl;
	cin >> a;
	if (a == 'O' || a == 'o') {
		goto top;
	}
	else if (a == 'X' || a == 'x') {
		cout << endl << "\t\t\t\t..Welcome!.." << endl;
	}








	return 0;
}

