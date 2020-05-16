#include <iostream>

using namespace std;

struct Node {
	int x;
	Node *next;
}*pbeg;

void Print(Node* b){
	Node* print = b;
	while (print){
		cout << print->x << "->";
		print = print->next;
	}
	cout << "NULL\n";
}

void remove(Node *b){
	Node *next = b->next;
	b->next = next->next;
}

void New(Node* b){
	Node* pr = b;
	while (pr){
		if ((pr->next != NULL) && (pr->x == pr->next->x))
			remove(pr);
		else
			pr = pr->next;
	}
}

const int nmax = 100;

int main(){
	int n = 0;
	cout << "Enter number of numbers\n";
	cin >> n;
	cout << "Enter numbers\n";
	int temp[nmax];
	for (int i = 0; i < n; i++)
		cin >> temp[i];

	Node* begin = NULL;
	begin = new Node;
	begin->x = temp[0];
	begin->next = NULL;
	Node* end = begin;
	for (int i = 1; i < n; i++){
		end->next = new Node;
		end = end->next;
		end->x = temp[i];
		end->next = NULL;
	}
	cout << "Your list\n";
	Print(begin);
	New(begin);
	cout << "Your new list\n";
	Print(begin);
	system("pause");
	return 0;
}

