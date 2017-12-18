#include<iostream>
#include <string>
using namespace std;
struct Node {
	int data;
	Node *next;
};

class List {
private:
	Node *head, *tail;
public:
	List() {
		head = NULL;
		tail = NULL;
	}
	//copy constructor

	List(const List& obj) {
		cout << "Hey" << endl;
		head = obj.head;
		tail = obj.tail;
	}

	//assignment operator Implement an assignment operator that implements a proper assignment of one List object into another List object.  
	List& operator=(const List& obj){
		
		return *this;
	}

	// Implement a stream output operator (<<) that prints out to an output stream all the values contained in a List object.
	friend ostream& operator<<(std::ostream& out, const List& list) {
		Node *temp = new Node;
		temp = list.head;
		while (temp != NULL) {
			out << temp->data << "\t";
			temp = temp->next;
		}
		out << endl;
		return out;
	}
	// Implement a stream input operator (>>) that allows the user to input an integer value on the keyboard, 
	// which is then added at then end of an existing List object.  
	friend istream& operator>>(std::istream& in, List& list) {
		int x;
		in >> x;
		list.insert_position((list.getSize()+1), x);
		return in;
	}
	//+ operator
	 List operator+(List& obj4) {
		int data1, data2, total;
		Node *temp = new Node;
		Node *temp1 = new Node;
		Node *temp2 = new Node;
		List SumList;
		temp1 = this->head;
		temp2 = obj4.head;
		temp = this->getSize() < obj4.getSize() ? temp1 : temp2;
		while (temp != NULL) {
			
			data1 = temp1->data;
			data2 = temp2->data;
			total = data1 + data2;
			temp = temp->next;
			temp1=temp1->next;
			temp2=temp2->next;
			SumList.createnode(total);
		}
		return SumList;
	}
	int getSize() {
		int size = 0;
		Node *temp = new Node;
		temp = head;
		while (temp != NULL) {
			size++;
			temp = temp->next;
		}
		return size;
	}

	void createnode(int value) {
		Node *temp = new Node;
		temp->data = value;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}
	void display() {
		Node *temp = new Node;
		temp = head;
		while (temp != NULL) {
			cout << temp->data << "\t";
			temp = temp->next;
		}
	}
	void insert_start(int value) {
		Node *temp = new Node;
		temp->data = value;
		temp->next = head;
		head = temp;
	}
	void insert_position(int pos, int value) {
		Node *pre = new Node;
		Node *cur = new Node;
		Node *temp = new Node;
		cur = head;
		for (int i = 1; i<pos; i++) {
			pre = cur;
			cur = cur->next;
		}
		temp->data = value;
		pre->next = temp;
		temp->next = cur;
	}
	void delete_first() {
		Node *temp = new Node;
		temp = head;
		head = head->next;
		delete temp;
	}
	void delete_last() {
		Node *current = new Node;
		Node *previous = new Node;
		current = head;
		while (current->next != NULL) {
			previous = current;
			current = current->next;
		}
		tail = previous;
		previous->next = NULL;
		delete current;
	}
	void delete_position(int pos) {
		Node *current = new Node;
		Node *previous = new Node;
		current = head;
		for (int i = 1; i<pos; i++) {
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		delete current;
	}
};
int main() {
	

	
	List obj;
	obj.createnode(25);
	obj.createnode(50);
	obj.createnode(90);
	obj.createnode(40);
	cout << "\n--------------------------------------------------\n";
	cout << "---------------Displaying All nodes---------------";
	cout << "\n--------------------------------------------------\n";
	obj.display();
	cout << "\n--------------------------------------------------\n";
	cout << "-----------------Inserting At End-----------------";
	cout << "\n--------------------------------------------------\n";
	obj.createnode(55);
	obj.display();
	cout << "\n--------------------------------------------------\n";
	cout << "----------------Inserting At Start----------------";
	cout << "\n--------------------------------------------------\n";
	obj.insert_start(50);
	obj.display();
	cout << "\n--------------------------------------------------\n";
	cout << "-------------Inserting At Particular--------------";
	cout << "\n--------------------------------------------------\n";
	obj.insert_position(5, 60);
	obj.display();
	cout << "\n--------------------------------------------------\n";
	cout << "----------------Deleting At Start-----------------";
	cout << "\n--------------------------------------------------\n";
	obj.delete_first();
	obj.display();
	cout << "\n--------------------------------------------------\n";
	cout << "-----------------Deleting At End-------------------";
	cout << "\n--------------------------------------------------\n";
	obj.delete_last();
	obj.display();
	cout << "\n--------------------------------------------------\n";
	cout << "--------------Deleting At Particular--------------";
	cout << "\n--------------------------------------------------\n";
	obj.delete_position(4);
	obj.display();

	cout << "\n--------------------------------------------------\n";
	cout << "--------------Using answer code-----------------";
	cout << "\n--------------------------------------------------\n";

	cout << "\n--------------------------------------------------\n";
	cout << "--------------Using copy constructor-----------------";
	cout << "\n--------------------------------------------------\n";
	List obj1(obj);
	cout << obj1 << endl;

	cout << "\n--------------------------------------------------\n";
	cout << "--------------Using assignment operator-----------------";
	cout << "\n--------------------------------------------------\n";
	List obj2;
	obj2 = obj1;
	cout << obj1 << endl;

	cout << "\n--------------------------------------------------\n";
	cout << "--------------Using stream input------------------";
	cout << "\n--------------------------------------------------\n";
	cin >> obj1 >> obj1;
	cout << obj1 << endl;

	cout << "\n--------------------------------------------------\n";
	cout << "--------------Using operator+------------------";
	cout << "\n--------------------------------------------------\n";
	List obj3, obj4;
	obj3.createnode(1);
	obj3.createnode(2);
	obj3.createnode(3);
	obj3.createnode(3);
	obj4.createnode(4);
	obj4.createnode(5);
	obj4.createnode(6);
	cout << "obj3 List: " << endl << obj3 << endl;
	cout << "obj4 List: " << endl << obj4 << endl;
		cout << "obj3 + obj4: " << endl << obj3 + obj4 << endl;
		int x; cin >> x;
		return 0;
	
}