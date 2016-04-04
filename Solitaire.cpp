#include <iostream>
#include <string>
using namespace std;

class Node {
private:
	int number;
	string suit;
	Node *next;

public:
	void SetNum(int n) { number = n; }
	void SetNext(Node *a) { next = a; }
	void SetSuit(char n) { suit=n; }
	int Num() { return number; }
	Node *Next() { return next; }
	string Suit() { return suit; }
};

class List {
private:
	Node *head;
	int DeckLocation = 0;

public:
	List(vector<string> cards);
	void Print();
	Node *Draw();
	int Loc();
};

List::List(vector<string> cards) {
	head = new Node();
	Node *temp = head;
	for (int i = 0; i < 52; i++) {
		string suit = cards[i];
		if (suit[1] == 48 || suit[1] == 49 || suit[1] == 50 || suit[1] == 51) {
			temp->SetSuit(suit[2]);
			int num1 = suit[0];
			int num2 = suit[1];
			int num = num1 + num2;
			num = num - 97;
			temp->SetNum(num + 10);
		}
		else {
			temp->SetSuit(suit[1]);
			int num = suit[0];
			num = num - 48;
			temp->SetNum(num);
		}
		Node *card = new Node();
		temp->SetNext(card);
		temp = temp->Next();
	}
}

void List::Print() {
	//Print out the deck. This is more of just a check.
	Node *temp = head;
	for (int i = 0; i < 52; i++) {
		if (temp->Num() == 1) {
			cout << "A";
		}
		else if (temp->Num() == 11) {
			cout << "J";
		}
		else if (temp->Num() == 12) {
			cout << "Q";
		}
		else if (temp->Num() == 13) {
			cout << "K";
		}
		else cout << temp->Num();
		cout << temp->Suit() << "\t";
		temp = temp->Next();
	}
	cout << endl;
	return;
}

Node *List::Draw() {
	Node *temp = head;
	//find where we are in the deck
	for (int i = 0; i < DeckLocation; i++) {
		if (temp->Next() == NULL) {
			DeckLocation = 0;
			cout << DeckLocation << "Yay" << endl;
			return temp;
		}
		temp = temp->Next();
	}
	if (temp->Next() == NULL) {
		DeckLocation = 0;
		return temp;
	}
	DeckLocation++;
	return temp;
}

int List::Loc() {
	return DeckLocation;
}
