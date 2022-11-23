#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct Node {
  int ID = -1;
  double GPA;
  string name;
  Node *next;
};
typedef Node *nodeptr;

bool ckll(nodeptr start, int ans) {
  if (start == NULL) {
    cout << "Create a Linked List First" << endl;
			return false;
  } else {
    	if (start->ID == -1 && ans != 2) {
      	cout << "Linked list is empty" << endl;
				cout << "You must add first!" << endl;
    		}
		return true;
  	}
}
void fill(nodeptr &filling) {
  cout << "Please enter ID" << endl;
  cin >> filling->ID;
  cout << "Please enter GPA" << endl;
  cin >> filling->GPA;
  cout << "Please enter name" << endl;
  getline(cin,filling->name);
	getline(cin,filling->name);
  filling->next = NULL;
  return;
}
void create(nodeptr &start) {
	if(start == NULL){
		  start = new Node;
  		start->next = NULL;
  		cout << "Linked list has been created!" << endl;
  return;
	}
	cout << "Linked list already created." << endl;
}
void add(nodeptr &start, nodeptr &temp) {
	nodeptr hold1 = start;
  nodeptr hold2 = start->next;
	nodeptr hold3;
	int count = 0;
	if(start -> ID == -1){
		start = temp;
		cout << endl;
		cout << "New List has been added" << endl;
		return;
	}
	if(temp->ID < hold1->ID){
		temp ->next = hold1;
		hold1->next = hold2;
		start = temp;
		cout << endl;
		cout << "New List has been added" << endl;
		return;
	}
	while(hold1 != NULL){
		if(temp->ID == hold1->ID){
			cout << "***Duplicate ID. Please Enter a different ID***" << endl;
			break;
		}
		if(hold2 == NULL && temp->ID > hold1->ID){
			hold1->next = temp;
			cout << endl;
			cout << "New List has been added" << endl;
			break;
		}
		if(temp->ID > hold1->ID && temp->ID < hold2->ID){
			hold3 = hold2;
			hold1->next = temp;
			temp->next =hold3;
			cout << endl;
			cout << "New List has been added" << endl;
			break;
		}
		hold1 = hold2;
		hold2 = hold2->next;
	}
}
void menu() {
	cout <<endl;
  cout << "Please select an option" << endl
       << "1:Create" << endl
       << "2:Add" << endl
       << "3:Delete" << endl
       << "4:Display" << endl
       << "5:Modify" << endl
       << "6:Purge" << endl
       << "7:Search for node" << endl
       << "8:Exit" << endl
       << endl;
  return;
}
void input(int &inp) {
  while (!(cin >> inp) && (inp >= 1 && inp <= 8)) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Please Enter a value from 1 to 8" << endl;
  }
  return;
}
void disp(nodeptr nodes) {
  while (nodes != NULL) {
    cout << "ID: " << nodes->ID << setw(5) << " | "
         << " GPA: " << nodes->GPA << setw(5) << " | "
         << "Name: " << nodes->name << endl;
    nodes = nodes->next;
  }
  return;
}
void addition(nodeptr &start, nodeptr &add) {
  nodeptr temp = start->next;
  if (start->ID == -1) {
    start = add;
  }
  if (temp->next == NULL) {
    temp->next = add;
  }
  while (temp->next != NULL) {
    if (add->ID >= temp->ID && add->ID <= temp->next->ID) {
      add->next = temp->next;
      temp->next = add;
    }
    temp = temp->next;
  }
}
void del(nodeptr &start){
	nodeptr hold1 = start;
	nodeptr hold2 = start->next;
	nodeptr hold3;
	int val;
	cout << "Please enter the ID number you want to delete" << endl;
	cin >> val;
	if(hold1->ID == val && hold1->next == NULL){
		start = hold2;
		delete hold1;
		start = new Node;
		cout << "ID has been deleted" << endl;
		return;
	}
	while(hold1 != NULL){
		if(hold2 == NULL && val != hold1->ID){
			cout << "*******ID was not found*******" << endl;
			return;
		}
		if(hold1->ID == val && hold2 != NULL){
			hold3 = hold2;
			delete hold1;
			start = hold3;
			cout <<"ID has been deleted" << endl;
			return;
		}
		if(hold2->ID == val){
			hold1->next = hold2->next;
			delete hold2;
			cout << "ID has been deleted" << endl;
			return;
		}
		hold1 = hold2;
		hold2 = hold2->next;
	}
}
void modify(nodeptr &start){
	nodeptr head1 = start;
	nodeptr head2 = start->next;
	nodeptr nw = new Node;
	fill(nw);
	if(nw->ID == head1->ID){
		cout << "Matching ID found!" << endl;
		cout << "ID: " << head1->ID << setw(5) << " | " << "GPA: " << head1->GPA << setw(5) << " | " << "Name:" << head1->name << endl;
		head1->name = nw->name;
		head1->GPA = nw->GPA;
		cout << endl << "The ID info has been modified to the one below" << endl;
		cout << "ID: " << head1->ID << setw(5) << " | " << "GPA: " << head1->GPA << setw(5) << " | " << "Name:" << head1->name << endl;
		return;
	}
	while(head2->next != NULL){
		if(nw->ID == head2 ->ID){
			break;
		}
		head1 = head2;
		head2 = head2->next;
	}
	if(nw->ID == head1->ID){
		cout << "Matching ID found!" << endl;
		cout << "ID: " << head1->ID << setw(5) << " | " << "GPA: " << head1->GPA << setw(5) << " | " << "Name:" << head1->name << endl;
		head1->name = nw->name;
		head1->GPA = nw->GPA;
		cout << endl << "The ID info has been modified to the one below" << endl;
		cout << "ID: " << head1->ID << setw(5) << " | " << "GPA: " << head1->GPA << setw(5) << " | " << "Name:" << head1->name << endl;
		return;
	}
	if(nw->ID == head2->ID){
		cout << "Matching ID found!" << endl;
		cout << "ID: " << head2->ID << setw(5) << " | " << "GPA: " << head2->GPA << setw(5) << " | " << "Name:" << head2->name << endl;
		head2->name = nw->name;
		head2->GPA = nw->GPA;
		cout << endl << "The ID info has been modified to the one below" << endl;
		cout << "ID: " << head2->ID << setw(5) << " | " << "GPA: " << head2->GPA << setw(5) << " | " << "Name:" << head2->name << endl;
		return;
	}
	if(nw->ID != (head2->ID || head1->ID)){
		cout << "ID was not found" << endl;
		return;
	}
}
void purge(nodeptr &start){
	nodeptr head1 = start;
	nodeptr head2 = start->next;
	while (head1 != NULL){
		if(head2 == NULL){
			delete head1;
			head1 = new Node;
			cout << "List has been deleted" << endl;
			break;
		}
		delete head1;
		head1 = new Node;
		head1 = head2;
		head2 = head2->next;
		cout << "List has been deleted" << endl;
	}
}
void search(nodeptr &start){
	int val;
	nodeptr head1 = start;
	cout << "Please enter student ID: " << endl;
	cin >> val;
	while(head1 != NULL){
		if(head1->ID == val){
			cout << "We found a matching ID!" << endl;
			cout << "ID: " << head1->ID << setw(5) << " | " << "GPA: " << head1->GPA << setw(5) << " | " << "Name:" << head1->name << endl;
			return;
		}
		head1 = head1->next;
	}
	cout << "No matching ID found" << endl;
}
int main() {
  nodeptr start = NULL;
  int user;
  while (user != 8) {
    menu();
    input(user);
    switch (user) {
    case 1:
      create(start);
      break;

    case 2:
			ckll(start, user);
      if(start != NULL){
				nodeptr temp;
      	temp = new Node;
      	fill(temp);
      	add(start, temp);
				}
      break;
    case 3:
      if(ckll(start, user)){
				if(start->ID != -1){
				del(start);
				}
			}
      break;

    case 4:
			if(ckll(start, user)){
				if(start->ID != -1){
					disp(start);
				}
			}
      break;

    case 5:
			if(ckll(start, user)){
				if(start->ID != -1){
					modify(start);
				}
			}
  
      break;

    case 6:
      if(ckll(start, user)){
				if(start->ID != -1){
					purge(start);
				}
			}
      break;

    case 7:
      if(ckll(start, user)){
				if(start->ID != -1){
					search(start);
				}
			}
      break;

    case 8:
      cout << "Program Terminating" << endl;
      break;
    }
  }
}
