#include <iostream>
#include <string>
#include "Deck.h"
using namespace std;

List Draw(List Deck) {
	Node *NewCard = NULL;
	NewCard = Deck.Draw();
	if (NewCard->Num() == NULL) {
		cout << "TOP OF THE DECK" << endl;
		return Deck;
	}
	cout << "CARD " << Deck.Loc() << "\t";
	if (NewCard->Num() == 1) {
		cout << "A";
	}
	else if (NewCard->Num() == 11) {
		cout << "J";
	}
	else if (NewCard->Num() == 12) {
		cout << "Q";
	}
	else if (NewCard->Num() == 13) {
		cout << "K";
	}
	else cout << NewCard->Num();
	cout << NewCard->Suit() << endl << endl;
	return Deck;
}
