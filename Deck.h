#include <iostream>
#include <algorithm>
#include <string>
#include <chrono>
#include <random>
#include <vector>
using namespace std;

class Node {
private:
	int number;
	string suit;
	bool faceup;
	Node *next;

public:
	//GETTER & SETTER METHODS
	void SetNum(int n) { number = n; }
	void SetNext(Node *a) { next = a; }
	void SetSuit(char n) { suit = n; }
	void SetFaceup(bool boolean) { faceup = boolean; }
	int Num() { return number; }
	Node *Next() { return next; }
	string Suit() { return suit; }
	bool Faceup() { return faceup; }
};

class List {
private:
	Node *head;
	int Loc;
	Node *DrawnCard;

public:
	List(vector<string> cards);
	void Print();
	void PrintCol(vector<Node*> col1, vector<Node*> col2, vector<Node*> col3, vector<Node*> col4, vector<Node*> col5, vector<Node*> col6, vector<Node*> col7);
	vector<Node*> createColumn(int size);
	vector<Node*> add(Node* card, vector<Node*> tableau);
	void turnOver(vector<Node*> tableau);
	void Draw();
	int Length();
	void addFound(Node* card, vector<Node*> found);
	Node* DCard() { return DrawnCard; }
	List* RemoveCard(Node* card);
};

//OUT-OF-LINE FUNCTIONS

//CONSTRUCTOR - creates a 52 card deck
List::List(vector<string> cards) {
	head = new Node();
	Loc = 0;
	Node* temp = head;
	for (int i = 0; i < 52; i++) {
		string suit = cards[i];
		//if the number is 10,11,12,13
		if (suit[1] == 48 || suit[1] == 49 || suit[1] == 50 || suit[1] == 51)
		{
			temp->SetSuit(suit[2]);
			int num1 = suit[0];
			int num2 = suit[1];
			int num = num1 + num2;
			num -= 97;
			temp->SetNum(num + 10);
		}
		else {
			temp->SetSuit(suit[1]);
			int num = suit[0];
			num = num - 48;
			temp->SetNum(num);
			temp->SetFaceup(false);
		}
		Node *card = new Node();
		temp->SetNext(card);
		temp = temp->Next();
	}
}

void List::Print() {
	Node *temp = head;
	cout << "\nCurrent deck (top to bottom): \n" << endl;
	for (int i = 0; i < this->Length() - 1; i++) {
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
		else {
			cout << temp->Num();
		}
		cout << temp->Suit() << "\t";

		if (temp->Next() == NULL) {
			break;
		}
		else {
			temp = temp->Next();

		}
	}
	cout << endl;
}

//CREATE COLUMN - creates the columns
vector<Node*> List::createColumn(int n) {

	//Creates a vector that contains the Node pointers of specified size
	Node* current = head;
	vector<Node*> arr;

	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			current->SetFaceup(true); //places the last card of each column faceup
		}
		arr.push_back(current);
		current = current->Next();
	}
	head = current;//Removes the first n nodes,they're in the vector list now, moves linked list head
	return arr;
}

//PRINTCOL - prints the tableau
void List::PrintCol(vector<Node*> col1, vector<Node*> col2, vector<Node*> col3, vector<Node*> col4, vector<Node*> col5, vector<Node*> col6, vector<Node*> col7) {
	int max = col1.size();
	if (col2.size()>col1.size())
		max = col2.size();
	if (col3.size()>col2.size())
		max = col3.size();
	if (col4.size()>col3.size())
		max = col4.size();
	if (col5.size()>col4.size())
		max = col5.size();
	if (col6.size()>col5.size())
		max = col6.size();
	if (col7.size()>col6.size())
		max = col7.size();

	cout << endl;
	for (int i = 0; i < max; i++) {
		if (col1.size() > i) {
			if (col1.at(i)->Num() == 1) {
				cout << "A";
			}
			else if (col1.at(i)->Num() == 11) {
				cout << "J";
			}
			else if (col1.at(i)->Num() == 12) {
				cout << "Q";
			}
			else if (col1.at(i)->Num() == 13) {
				cout << "K";
			}
			else {
				cout << col1.at(i)->Num();
			}
			cout << col1.at(i)->Suit();
		}
		cout << "\t";
		if (col2.size() > i) {
			if (col2.at(i)->Num() == 1) {
				cout << "A";
			}
			else if (col2.at(i)->Num() == 11) {
				cout << "J";
			}
			else if (col2.at(i)->Num() == 12) {
				cout << "Q";
			}
			else if (col2.at(i)->Num() == 13) {
				cout << "K";
			}
			else {
				cout << col2.at(i)->Num();
			}
			cout << col2.at(i)->Suit();
		}
		cout << "\t";
		if (col3.size() > i) {
			if (col3.at(i)->Num() == 1) {
				cout << "A";
			}
			else if (col3.at(i)->Num() == 11) {
				cout << "J";
			}
			else if (col3.at(i)->Num() == 12) {
				cout << "Q";
			}
			else if (col3.at(i)->Num() == 13) {
				cout << "K";
			}
			else {
				cout << col3.at(i)->Num();
			}
			cout << col3.at(i)->Suit();
		}
		cout << "\t";
		if (col4.size() > i) {
			if (col4.at(i)->Num() == 1) {
				cout << "A";
			}
			else if (col4.at(i)->Num() == 11) {
				cout << "J";
			}
			else if (col4.at(i)->Num() == 12) {
				cout << "Q";
			}
			else if (col4.at(i)->Num() == 13) {
				cout << "K";
			}
			else {
				cout << col4.at(i)->Num();
			}
			cout << col4.at(i)->Suit();
		}
		cout << "\t";
		if (col5.size() > i) {
			if (col5.at(i)->Num() == 1) {
				cout << "A";
			}
			else if (col5.at(i)->Num() == 11) {
				cout << "J";
			}
			else if (col5.at(i)->Num() == 12) {
				cout << "Q";
			}
			else if (col5.at(i)->Num() == 13) {
				cout << "K";
			}
			else {
				cout << col5.at(i)->Num();
			}
			cout << col5.at(i)->Suit();
		}
		cout << "\t";
		if (col6.size() > i) {
			if (col6.at(i)->Num() == 1) {
				cout << "A";
			}
			else if (col6.at(i)->Num() == 11) {
				cout << "J";
			}
			else if (col6.at(i)->Num() == 12) {
				cout << "Q";
			}
			else if (col6.at(i)->Num() == 13) {
				cout << "K";
			}
			else {
				cout << col6.at(i)->Num();
			}
			cout << col6.at(i)->Suit();
		}
		cout << "\t";
		if (col7.size() > i) {
			if (col7.at(i)->Num() == 1) {
				cout << "A";
			}
			else if (col7.at(i)->Num() == 11) {
				cout << "J";
			}
			else if (col7.at(i)->Num() == 12) {
				cout << "Q";
			}
			else if (col7.at(i)->Num() == 13) {
				cout << "K";
			}
			else {
				cout << col7.at(i)->Num();
			}
			cout << col7.at(i)->Suit();
		}
		cout << "\n";
	}
}

//WE NEED TO MAKE IT SO THAT THE GUI IS ACTIVATED HERE
//NOT SURE IF JACKS AND ABOVE WILL BE ALRIGHT
vector<Node*> List::add(Node* card, vector<Node*> tableau) {
	if ((tableau.back()->Suit() == "C" || tableau.back()->Suit() == "S") && (card->Suit() == "D" || card->Suit() == "H") && (tableau.back()->Num() == (card->Num() + 1))) {
		tableau.push_back(card);
		return tableau;
	}
	else if ((tableau.back()->Suit() == "D" || tableau.back()->Suit() == "H") && (card->Suit() == "C" || card->Suit() == "S") && (tableau.back()->Num() == card->Num() + 1)) {
		tableau.push_back(card);
		return tableau;
	}
	else {
		cout << "Invalid move." << endl;
		return tableau;
	}
}

List* List::RemoveCard(Node* card) {
	int j = 0;
	Node *temp = head;
	if (card == temp) {
		temp = temp->Next();
		head = temp;
		DrawnCard = NULL;
		return this;
	}
	while (temp != NULL) {
		if (temp == card) {
			break;
		}
		j++;
		temp = temp->Next();
	}
	temp = head;
	Node *temp1 = head;
	for (int i = 0; i < j + 1; i++) {
		temp = temp->Next();
	}
	if (j > 0) {
		for (int i = 0; i < j - 1; i++) {
			temp1 = temp1->Next();
		}
	}
	temp1->SetNext(temp);
	Loc--;
	Loc--;
	this->Draw();
	return this;
}

void List::turnOver(vector<Node*> tableau) {
	if (tableau.back()->Faceup() == false) {
		tableau.back()->SetFaceup(true);
	}
}

void List::Draw() {
	Node *temp = head;
	int j = this->Length();
	if (Loc == j) {
		Loc = 0;
	}
	for (int i = 0; i<Loc; i++) {
		temp = temp->Next();
	}
	Loc++;
	DrawnCard = temp;
	return;
}

int List::Length() {
	int j = 0;
	Node* temp = head;
	while (temp != NULL) {
		j++;
		temp = temp->Next();
	}
	return j;
}

void List::addFound(Node* card, vector<Node*> found) {
	if (found.empty() && card->Num() == 1)
		found.push_back(card);
	else if ((found.front()->Suit() == card->Suit()) && (card->Num() == found.back()->Num() + 1)) {
		found.push_back(card);
	}
}