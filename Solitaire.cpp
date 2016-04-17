#include "Deck.h"
using namespace std;

List* DrawCard(List* deck) {
	deck->Draw();
	return deck;
}

int main() {
	vector<string> shuffler;
	shuffler.push_back("1C");
	shuffler.push_back("2C");
	shuffler.push_back("3C");
	shuffler.push_back("4C");
	shuffler.push_back("5C");
	shuffler.push_back("6C");
	shuffler.push_back("7C");
	shuffler.push_back("8C");
	shuffler.push_back("9C");
	shuffler.push_back("10C");
	shuffler.push_back("11C");
	shuffler.push_back("12C");
	shuffler.push_back("13C");
	shuffler.push_back("1D");
	shuffler.push_back("2D");
	shuffler.push_back("3D");
	shuffler.push_back("4D");
	shuffler.push_back("5D");
	shuffler.push_back("6D");
	shuffler.push_back("7D");
	shuffler.push_back("8D");
	shuffler.push_back("9D");
	shuffler.push_back("10D");
	shuffler.push_back("11D");
	shuffler.push_back("12D");
	shuffler.push_back("13D");
	shuffler.push_back("1S");
	shuffler.push_back("2S");
	shuffler.push_back("3S");
	shuffler.push_back("4S");
	shuffler.push_back("5S");
	shuffler.push_back("6S");
	shuffler.push_back("7S");
	shuffler.push_back("8S");
	shuffler.push_back("9S");
	shuffler.push_back("10S");
	shuffler.push_back("11S");
	shuffler.push_back("12S");
	shuffler.push_back("13S");
	shuffler.push_back("1H");
	shuffler.push_back("2H");
	shuffler.push_back("3H");
	shuffler.push_back("4H");
	shuffler.push_back("5H");
	shuffler.push_back("6H");
	shuffler.push_back("7H");
	shuffler.push_back("8H");
	shuffler.push_back("9H");
	shuffler.push_back("10H");
	shuffler.push_back("11H");
	shuffler.push_back("12H");
	shuffler.push_back("13H");

	//Shuffle the 52-long vector
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(shuffler.begin(), shuffler.end(), default_random_engine(seed));

	//Creating the 52-card deck object
	List* deck = new List(shuffler);

	//Greetings
	cout << "Welcome to Solitaire! Here is your starting board." << endl << endl << endl;



	//Create columns of the tableau
	vector<Node*> col1 = deck->createColumn(1);
	vector<Node*> col2 = deck->createColumn(2);
	vector<Node*> col3 = deck->createColumn(3);
	vector<Node*> col4 = deck->createColumn(4);
	vector<Node*> col5 = deck->createColumn(5);
	vector<Node*> col6 = deck->createColumn(6);
	vector<Node*> col7 = deck->createColumn(7);
	int initCount1 = 1, initCount2 = 2, initCount3 = 3, initCount4 = 4, initCount5 = 5, initCount6 = 6, initCount7 = 7;

	//create foundations
	vector<Node*> foundClubs = deck->createColumn(0);
	vector<Node*> foundDiamonds = deck->createColumn(0);
	vector<Node*> foundSpades = deck->createColumn(0);
	vector<Node*> foundHearts = deck->createColumn(0);


	//Print columns
	cout << "Deck" << endl;
	deck->PrintCol(col1, col2, col3, col4, col5, col6, col7);

	//Print deck again to show you that the correct cards were taken out

	cout << endl << endl;

	deck->turnOver(col1);
	deck->turnOver(col2);
	deck->turnOver(col3);
	deck->turnOver(col4);
	deck->turnOver(col5);
	deck->turnOver(col6);
	deck->turnOver(col7);

	//The Game should take place here
	while (true) {
		if (foundClubs.size() > 0 && foundDiamonds.size()>0 && foundSpades.size() > 0 && foundHearts.size() > 0) {
			if (foundClubs.back()->Num() == 13 && foundDiamonds.back()->Num() == 13 && foundSpades.back()->Num() == 13 && foundHearts.back()->Num() == 13) {
				cout << "Congratulations! You Win!" << endl;
				break;
			}
		}

		int choice;
		cout << endl << "Enter 999 for options." << endl << endl;
		cin >> choice;
		if (choice == 999) {
			cout << "Choice 0  - Draw a card." << endl;
			cout << "Choice 1  - Move Drawn card." << endl;
			cout << "Choice 2  - Move a part of a column." << endl;
			cout << "Choice 3  - Move a foundation." << endl;
			continue;
		}
		else if (choice == 0) {
			deck = DrawCard(deck);
			cin.clear();
		}
		else if (choice == 1) {
			if (deck->Length() == 1 || deck->DCard() == NULL) {
				continue;
			}
			int choice1;
			cout << "Enter 0 for optioins." << endl;
			cin >> choice1;


			if (choice1 == 0) {
				cout << "Choice 1  - Move drawn card to column 1." << endl;
				cout << "Choice 2  - Move drawn card to column 2." << endl;
				cout << "Choice 3  - Move drawn card to column 3." << endl;
				cout << "Choice 4  - Move drawn card to column 4." << endl;
				cout << "Choice 5  - Move drawn card to column 5." << endl;
				cout << "Choice 6  - Move drawn card to column 6." << endl;
				cout << "Choice 7  - Move drawn card to column 7." << endl;
				cout << "Choice 8  - Move drawn card to Clubs foundation." << endl;
				cout << "Choice 9  - Move drawn card to Diamonds foundation." << endl;
				cout << "Choice 10 - Move drawn card to Spades foundation." << endl;
				cout << "Choice 11 - Move drawn card to Hearts foundation." << endl;
				cin >> choice1;
			}
			if (choice1 == 1) {
				vector<Node*> temp = col1;
				col1 = deck->add(deck->DCard(), col1);
				if (col1.size() > temp.size()) {
					deck = deck->RemoveCard(deck->DCard());
				}
			}
			else if (choice1 == 2) {
				vector<Node*> temp = col2;
				col2 = deck->add(deck->DCard(), col2);
				if (col2.size() > temp.size()) {
					deck = deck->RemoveCard(deck->DCard());
				}
			}
			else if (choice1 == 3) {
				vector<Node*> temp = col3;
				col3 = deck->add(deck->DCard(), col3);
				if (col3.size() > temp.size()) {
					deck = deck->RemoveCard(deck->DCard());
				}
			}
			else if (choice1 == 4) {
				vector<Node*> temp = col4;
				col4 = deck->add(deck->DCard(), col4);
				if (col4.size() > temp.size()) {
					deck = deck->RemoveCard(deck->DCard());
				}
			}
			else if (choice1 == 5) {
				vector<Node*> temp = col5;
				col5 = deck->add(deck->DCard(), col5);
				if (col5.size() > temp.size()) {
					deck = deck->RemoveCard(deck->DCard());
				}
			}
			else if (choice1 == 6) {
				vector<Node*> temp = col6;
				col6 = deck->add(deck->DCard(), col6);
				if (col6.size() > temp.size()) {
					deck = deck->RemoveCard(deck->DCard());
				}
			}
			else if (choice1 == 7) {
				vector<Node*> temp = col7;
				col7 = deck->add(deck->DCard(), col7);
				if (col7.size() > temp.size()) {
					deck = deck->RemoveCard(deck->DCard());
				}
			}
			else if (choice1 == 8) {
				if (deck->DCard()->Suit() != "C") {
					cout << "Incorrect foundation" << endl;
					continue;
				}
				foundClubs = deck->addFound(deck->DCard(), foundClubs);
				deck = deck->RemoveCard(deck->DCard());
			}
			else if (choice1 == 9) {
				if (deck->DCard()->Suit() != "D") {
					cout << "Incorrect foundation" << endl;
					continue;
				}
				foundDiamonds = deck->addFound(deck->DCard(), foundDiamonds);
				deck = deck->RemoveCard(deck->DCard());
			}
			else if (choice1 == 10) {
				if (deck->DCard()->Suit() != "S") {
					cout << "Incorrect foundation" << endl;
					continue;
				}
				foundSpades = deck->addFound(deck->DCard(), foundSpades);
				deck = deck->RemoveCard(deck->DCard());
			}
			else if (choice1 == 11) {
				if (deck->DCard()->Suit() != "H") {
					cout << "Incorrect foundation" << endl;
					continue;
				}
				foundHearts = deck->addFound(deck->DCard(), foundHearts);
				deck = deck->RemoveCard(deck->DCard());
			}
		}

		//Moving the columns
		else if (choice == 2) {
			cout << "Choose a column." << endl;
			int choice1;
			cin >> choice1;
			if (choice1 == 1) {
				if (col1.size() == 0) {
					cout << "Column empty!" << endl;
					continue;
				}
				cout << "How many cards would you like to move?" << endl;
				int num = 0;
				cin >> num;
				vector<Node*> colFrom, temp;
				colFrom = col1;

				//check that this amount of cards exist
				for (int i = 0; i < colFrom.size(); i++) {
					if (colFrom.at(i)->Faceup()) {
						temp.push_back(colFrom.at(i));
					}
				}
				if (num > temp.size()) {
					cout << "Too many!" << endl;
					continue;
				}


				//split moving cards from non-moving cards
				vector<Node*> moving, nonmoving;
				for (int i = 0; i < col1.size() - num; i++) {
					nonmoving.push_back(col1.at(i));
				}
				for (int i = 0; i < num; i++) {
					moving.push_back(col1.at(i + nonmoving.size()));
				}

				bool check;

				cout << "...And to which column?" << endl;
				cout << "8 is Clubs." << endl;
				cout << "9 is Diamonds." << endl;
				cout << "10 is Spades." << endl;
				cout << "11 is Hearts." << endl;
				int col = 0;
				cin >> col;
				if (col == 2) {
					col2 = deck->ColtoCol(moving, col2);
					check = deck->CheckMovetoCol(moving, col2);
					if (check) {
						col1 = nonmoving;
					}
				}
				else if (col == 3) {
					col3 = deck->ColtoCol(moving, col3);
					check = deck->CheckMovetoCol(moving, col3);
					if (check) {
						col1 = nonmoving;
					}
				}
				else if (col == 4) {
					col4 = deck->ColtoCol(moving, col4);
					check = deck->CheckMovetoCol(moving, col4);
					if (check) {
						col1 = nonmoving;
					}
				}
				else if (col == 5) {
					col5 = deck->ColtoCol(moving, col5);
					check = deck->CheckMovetoCol(moving, col5);
					if (check) {
						col1 = nonmoving;
					}
				}
				else if (col == 6) {
					col6 = deck->ColtoCol(moving, col6);
					check = deck->CheckMovetoCol(moving, col6);
					if (check) {
						col1 = nonmoving;
					}
				}
				else if (col == 7) {
					col7 = deck->ColtoCol(moving, col7);
					check = deck->CheckMovetoCol(moving, col7);
					if (check) {
						col1 = nonmoving;
					}
				}
				else if (col == 8) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "C") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundClubs;
					foundClubs = deck->addFound(moving.at(0), foundClubs);
					if (foundClubs.size() > temp.size()) {
						col1 = nonmoving;
					}
				}
				else if (col == 9) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "D") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundDiamonds;
					foundDiamonds = deck->addFound(moving.at(0), foundDiamonds);
					if (foundDiamonds.size() > temp.size()) {
						col1 = nonmoving;
					}
				}
				else if (col == 10) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "S") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundSpades;
					foundSpades = deck->addFound(moving.at(0), foundSpades);
					if (foundSpades.size() > temp.size()) {
						col1 = nonmoving;
					}
				}
				else if (col == 11) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "H") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundHearts;
					foundHearts = deck->addFound(moving.at(0), foundHearts);
					if (foundHearts.size() > temp.size()) {
						col1 = nonmoving;
					}
				}
			}
			else if (choice1 == 2) {
				cout << "How many cards would you like to move?" << endl;
				int num = 0;
				cin >> num;
				vector<Node*> colFrom, temp;
				colFrom = col2;

				//check that this amount of cards exist
				for (int i = 0; i < colFrom.size(); i++) {
					if (colFrom.at(i)->Faceup()) {
						temp.push_back(colFrom.at(i));
					}
				}
				if (num > temp.size()) {
					cout << "Too many!" << endl;
					continue;
				}


				//split moving cards from non-moving cards
				vector<Node*> moving, nonmoving;
				for (int i = 0; i < col2.size() - num; i++) {
					nonmoving.push_back(col2.at(i));
				}
				for (int i = 0; i < num; i++) {
					moving.push_back(col2.at(i + nonmoving.size()));
				}

				bool check;

				cout << "...And to which column?" << endl;
				cout << "8 is Clubs." << endl;
				cout << "9 is Diamonds." << endl;
				cout << "10 is Spades." << endl;
				cout << "11 is Hearts." << endl;
				int col = 0;
				cin >> col;
				if (col == 1) {
					col1 = deck->ColtoCol(moving, col1);
					check = deck->CheckMovetoCol(moving, col1);
					if (check) {
						col2 = nonmoving;
					}
				}
				else if (col == 3) {
					col3 = deck->ColtoCol(moving, col3);
					check = deck->CheckMovetoCol(moving, col3);
					if (check) {
						col2 = nonmoving;
					}
				}
				else if (col == 4) {
					col4 = deck->ColtoCol(moving, col4);
					check = deck->CheckMovetoCol(moving, col4);
					if (check) {
						col2 = nonmoving;
					}
				}
				else if (col == 5) {
					col5 = deck->ColtoCol(moving, col5);
					check = deck->CheckMovetoCol(moving, col5);
					if (check) {
						col2 = nonmoving;
					}
				}
				else if (col == 6) {
					col6 = deck->ColtoCol(moving, col6);
					check = deck->CheckMovetoCol(moving, col6);
					if (check) {
						col2 = nonmoving;
					}
				}
				else if (col == 7) {
					col7 = deck->ColtoCol(moving, col7);
					check = deck->CheckMovetoCol(moving, col7);
					if (check) {
						col2 = nonmoving;
					}
				}
				else if (col == 8) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "C") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundClubs;
					foundClubs = deck->addFound(moving.at(0), foundClubs);
					if (foundClubs.size() > temp.size()) {
						col2 = nonmoving;
					}
				}
				else if (col == 9) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "D") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundDiamonds;
					foundDiamonds = deck->addFound(moving.at(0), foundDiamonds);
					if (foundDiamonds.size() > temp.size()) {
						col2 = nonmoving;
					}
				}
				else if (col == 10) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "S") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundSpades;
					foundSpades = deck->addFound(moving.at(0), foundSpades);
					if (foundSpades.size() > temp.size()) {
						col2 = nonmoving;
					}
				}
				else if (col == 11) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "H") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundHearts;
					foundHearts = deck->addFound(moving.at(0), foundHearts);
					if (foundHearts.size() > temp.size()) {
						col2 = nonmoving;
					}
				}
			}
			else if (choice1 == 3) {
				cout << "How many cards would you like to move?" << endl;
				int num = 0;
				cin >> num;
				vector<Node*> colFrom, temp;
				colFrom = col3;

				//check that this amount of cards exist
				for (int i = 0; i < colFrom.size(); i++) {
					if (colFrom.at(i)->Faceup()) {
						temp.push_back(colFrom.at(i));
					}
				}
				if (num > temp.size()) {
					cout << "Too many!" << endl;
					continue;
				}


				//split moving cards from non-moving cards
				vector<Node*> moving, nonmoving;
				for (int i = 0; i < col3.size() - num; i++) {
					nonmoving.push_back(col3.at(i));
				}
				for (int i = 0; i < num; i++) {
					moving.push_back(col3.at(i + nonmoving.size()));
				}

				bool check;

				cout << "...And to which column?" << endl;
				cout << "8 is Clubs." << endl;
				cout << "9 is Diamonds." << endl;
				cout << "10 is Spades." << endl;
				cout << "11 is Hearts." << endl;
				int col = 0;
				cin >> col;
				if (col == 2) {
					col2 = deck->ColtoCol(moving, col2);
					check = deck->CheckMovetoCol(moving, col2);
					if (check) {
						col3 = nonmoving;
					}
				}
				else if (col == 1) {
					col1 = deck->ColtoCol(moving, col1);
					check = deck->CheckMovetoCol(moving, col1);
					if (check) {
						col3 = nonmoving;
					}
				}
				else if (col == 4) {
					col4 = deck->ColtoCol(moving, col4);
					check = deck->CheckMovetoCol(moving, col4);
					if (check) {
						col3 = nonmoving;
					}
				}
				else if (col == 5) {
					col5 = deck->ColtoCol(moving, col5);
					check = deck->CheckMovetoCol(moving, col5);
					if (check) {
						col3 = nonmoving;
					}
				}
				else if (col == 6) {
					col6 = deck->ColtoCol(moving, col6);
					check = deck->CheckMovetoCol(moving, col6);
					if (check) {
						col3 = nonmoving;
					}
				}
				else if (col == 7) {
					col7 = deck->ColtoCol(moving, col7);
					check = deck->CheckMovetoCol(moving, col7);
					if (check) {
						col3 = nonmoving;
					}
				}
				else if (col == 8) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "C") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundClubs;
					foundClubs = deck->addFound(moving.at(0), foundClubs);
					if (foundClubs.size() > temp.size()) {
						col3 = nonmoving;
					}
				}
				else if (col == 9) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "D") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundDiamonds;
					foundDiamonds = deck->addFound(moving.at(0), foundDiamonds);
					if (foundDiamonds.size() > temp.size()) {
						col3 = nonmoving;
					}
				}
				else if (col == 10) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "S") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundSpades;
					foundSpades = deck->addFound(moving.at(0), foundSpades);
					if (foundSpades.size() > temp.size()) {
						col3 = nonmoving;
					}
				}
				else if (col == 11) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "H") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundHearts;
					foundHearts = deck->addFound(moving.at(0), foundHearts);
					if (foundHearts.size() > temp.size()) {
						col3 = nonmoving;
					}
				}
			}
			else if (choice1 == 4) {
				cout << "How many cards would you like to move?" << endl;
				int num = 0;
				cin >> num;
				vector<Node*> colFrom, temp;
				colFrom = col4;

				//check that this amount of cards exist
				for (int i = 0; i < colFrom.size(); i++) {
					if (colFrom.at(i)->Faceup()) {
						temp.push_back(colFrom.at(i));
					}
				}
				if (num > temp.size()) {
					cout << "Too many!" << endl;
					continue;
				}


				//split moving cards from non-moving cards
				vector<Node*> moving, nonmoving;
				for (int i = 0; i < col4.size() - num; i++) {
					nonmoving.push_back(col4.at(i));
				}
				for (int i = 0; i < num; i++) {
					moving.push_back(col4.at(i + nonmoving.size()));
				}

				bool check;

				cout << "...And to which column?" << endl;
				cout << "8 is Clubs." << endl;
				cout << "9 is Diamonds." << endl;
				cout << "10 is Spades." << endl;
				cout << "11 is Hearts." << endl;
				int col = 0;
				cin >> col;
				if (col == 2) {
					col2 = deck->ColtoCol(moving, col2);
					check = deck->CheckMovetoCol(moving, col2);
					if (check) {
						col4 = nonmoving;
					}
				}
				else if (col == 3) {
					col3 = deck->ColtoCol(moving, col3);
					check = deck->CheckMovetoCol(moving, col3);
					if (check) {
						col4 = nonmoving;
					}
				}
				else if (col == 1) {
					col1 = deck->ColtoCol(moving, col1);
					check = deck->CheckMovetoCol(moving, col1);
					if (check) {
						col4 = nonmoving;
					}
				}
				else if (col == 5) {
					col5 = deck->ColtoCol(moving, col5);
					check = deck->CheckMovetoCol(moving, col5);
					if (check) {
						col4 = nonmoving;
					}
				}
				else if (col == 6) {
					col6 = deck->ColtoCol(moving, col6);
					check = deck->CheckMovetoCol(moving, col6);
					if (check) {
						col4 = nonmoving;
					}
				}
				else if (col == 7) {
					col7 = deck->ColtoCol(moving, col7);
					check = deck->CheckMovetoCol(moving, col7);
					if (check) {
						col4 = nonmoving;
					}
				}
				else if (col == 8) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "C") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundClubs;
					foundClubs = deck->addFound(moving.at(0), foundClubs);
					if (foundClubs.size() > temp.size()) {
						col4 = nonmoving;
					}
				}
				else if (col == 9) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "D") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundDiamonds;
					foundDiamonds = deck->addFound(moving.at(0), foundDiamonds);
					if (foundDiamonds.size() > temp.size()) {
						col4 = nonmoving;
					}
				}
				else if (col == 10) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "S") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundSpades;
					foundSpades = deck->addFound(moving.at(0), foundSpades);
					if (foundSpades.size() > temp.size()) {
						col4 = nonmoving;
					}
				}
				else if (col == 11) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "H") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundHearts;
					foundHearts = deck->addFound(moving.at(0), foundHearts);
					if (foundHearts.size() > temp.size()) {
						col4 = nonmoving;
					}
				}
			}
			else if (choice1 == 5) {
				cout << "How many cards would you like to move?" << endl;
				int num = 0;
				cin >> num;
				vector<Node*> colFrom, temp;
				colFrom = col5;

				//check that this amount of cards exist
				for (int i = 0; i < colFrom.size(); i++) {
					if (colFrom.at(i)->Faceup()) {
						temp.push_back(colFrom.at(i));
					}
				}
				if (num > temp.size()) {
					cout << "Too many!" << endl;
					continue;
				}


				//split moving cards from non-moving cards
				vector<Node*> moving, nonmoving;
				for (int i = 0; i < col5.size() - num; i++) {
					nonmoving.push_back(col5.at(i));
				}
				for (int i = 0; i < num; i++) {
					moving.push_back(col5.at(i + nonmoving.size()));
				}

				bool check;

				cout << "...And to which column?" << endl;
				cout << "8 is Clubs." << endl;
				cout << "9 is Diamonds." << endl;
				cout << "10 is Spades." << endl;
				cout << "11 is Hearts." << endl;
				int col = 0;
				cin >> col;
				if (col == 2) {
					col2 = deck->ColtoCol(moving, col2);
					check = deck->CheckMovetoCol(moving, col2);
					if (check) {
						col5 = nonmoving;
					}
				}
				else if (col == 3) {
					col3 = deck->ColtoCol(moving, col3);
					check = deck->CheckMovetoCol(moving, col3);
					if (check) {
						col5 = nonmoving;
					}
				}
				else if (col == 4) {
					col4 = deck->ColtoCol(moving, col4);
					check = deck->CheckMovetoCol(moving, col4);
					if (check) {
						col5 = nonmoving;
					}
				}
				else if (col == 1) {
					col1 = deck->ColtoCol(moving, col1);
					check = deck->CheckMovetoCol(moving, col1);
					if (check) {
						col5 = nonmoving;
					}
				}
				else if (col == 6) {
					col6 = deck->ColtoCol(moving, col6);
					check = deck->CheckMovetoCol(moving, col6);
					if (check) {
						col5 = nonmoving;
					}
				}
				else if (col == 7) {
					col7 = deck->ColtoCol(moving, col7);
					check = deck->CheckMovetoCol(moving, col7);
					if (check) {
						col5 = nonmoving;
					}
				}
				else if (col == 8) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "C") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundClubs;
					foundClubs = deck->addFound(moving.at(0), foundClubs);
					if (foundClubs.size() > temp.size()) {
						col5 = nonmoving;
					}
				}
				else if (col == 9) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "D") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundDiamonds;
					foundDiamonds = deck->addFound(moving.at(0), foundDiamonds);
					if (foundDiamonds.size() > temp.size()) {
						col5 = nonmoving;
					}
				}
				else if (col == 10) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "S") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundSpades;
					foundSpades = deck->addFound(moving.at(0), foundSpades);
					if (foundSpades.size() > temp.size()) {
						col5 = nonmoving;
					}
				}
				else if (col == 11) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "H") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundHearts;
					foundHearts = deck->addFound(moving.at(0), foundHearts);
					if (foundHearts.size() > temp.size()) {
						col5 = nonmoving;
					}
				}
			}
			else if (choice1 == 6) {
				cout << "How many cards would you like to move?" << endl;
				int num = 0;
				cin >> num;
				vector<Node*> colFrom, temp;
				colFrom = col6;

				//check that this amount of cards exist
				for (int i = 0; i < colFrom.size(); i++) {
					if (colFrom.at(i)->Faceup()) {
						temp.push_back(colFrom.at(i));
					}
				}
				if (num > temp.size()) {
					cout << "Too many!" << endl;
					continue;
				}


				//split moving cards from non-moving cards
				vector<Node*> moving, nonmoving;
				for (int i = 0; i < col6.size() - num; i++) {
					nonmoving.push_back(col6.at(i));
				}
				for (int i = 0; i < num; i++) {
					moving.push_back(col6.at(i + nonmoving.size()));
				}

				bool check;

				cout << "...And to which column?" << endl;
				cout << "8 is Clubs." << endl;
				cout << "9 is Diamonds." << endl;
				cout << "10 is Spades." << endl;
				cout << "11 is Hearts." << endl;
				int col = 0;
				cin >> col;
				if (col == 2) {
					col2 = deck->ColtoCol(moving, col2);
					check = deck->CheckMovetoCol(moving, col2);
					if (check) {
						col6 = nonmoving;
					}
				}
				else if (col == 3) {
					col3 = deck->ColtoCol(moving, col3);
					check = deck->CheckMovetoCol(moving, col3);
					if (check) {
						col6 = nonmoving;
					}
				}
				else if (col == 4) {
					col4 = deck->ColtoCol(moving, col4);
					check = deck->CheckMovetoCol(moving, col4);
					if (check) {
						col6 = nonmoving;
					}
				}
				else if (col == 5) {
					col5 = deck->ColtoCol(moving, col5);
					check = deck->CheckMovetoCol(moving, col5);
					if (check) {
						col6 = nonmoving;
					}
				}
				else if (col == 1) {
					col1 = deck->ColtoCol(moving, col1);
					check = deck->CheckMovetoCol(moving, col1);
					if (check) {
						col6 = nonmoving;
					}
				}
				else if (col == 7) {
					col7 = deck->ColtoCol(moving, col7);
					check = deck->CheckMovetoCol(moving, col7);
					if (check) {
						col6 = nonmoving;
					}
				}
				else if (col == 8) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "C") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundClubs;
					foundClubs = deck->addFound(moving.at(0), foundClubs);
					if (foundClubs.size() > temp.size()) {
						col6 = nonmoving;
					}
				}
				else if (col == 9) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "D") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundDiamonds;
					foundDiamonds = deck->addFound(moving.at(0), foundDiamonds);
					if (foundDiamonds.size() > temp.size()) {
						col6 = nonmoving;
					}
				}
				else if (col == 10) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "S") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundSpades;
					foundSpades = deck->addFound(moving.at(0), foundSpades);
					if (foundSpades.size() > temp.size()) {
						col6 = nonmoving;
					}
				}
				else if (col == 11) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "H") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundHearts;
					foundHearts = deck->addFound(moving.at(0), foundHearts);
					if (foundHearts.size() > temp.size()) {
						col6 = nonmoving;
					}
				}
			}
			else if (choice1 == 7) {
				cout << "How many cards would you like to move?" << endl;
				int num = 0;
				cin >> num;
				vector<Node*> colFrom, temp;
				colFrom = col7;

				//check that this amount of cards exist
				for (int i = 0; i < colFrom.size(); i++) {
					if (colFrom.at(i)->Faceup()) {
						temp.push_back(colFrom.at(i));
					}
				}
				if (num > temp.size()) {
					cout << "Too many!" << endl;
					continue;
				}


				//split moving cards from non-moving cards
				vector<Node*> moving, nonmoving;
				for (int i = 0; i < col7.size() - num; i++) {
					nonmoving.push_back(col7.at(i));
				}
				for (int i = 0; i < num; i++) {
					moving.push_back(col7.at(i + nonmoving.size()));
				}

				bool check;

				cout << "...And to which column?" << endl;
				cout << "8 is Clubs." << endl;
				cout << "9 is Diamonds." << endl;
				cout << "10 is Spades." << endl;
				cout << "11 is Hearts." << endl;
				int col = 0;
				cin >> col;
				if (col == 2) {
					col2 = deck->ColtoCol(moving, col2);
					check = deck->CheckMovetoCol(moving, col2);
					if (check) {
						col7 = nonmoving;
					}
				}
				else if (col == 3) {
					col3 = deck->ColtoCol(moving, col3);
					check = deck->CheckMovetoCol(moving, col3);
					if (check) {
						col7 = nonmoving;
					}
				}
				else if (col == 4) {
					col4 = deck->ColtoCol(moving, col4);
					check = deck->CheckMovetoCol(moving, col4);
					if (check) {
						col7 = nonmoving;
					}
				}
				else if (col == 5) {
					col5 = deck->ColtoCol(moving, col5);
					check = deck->CheckMovetoCol(moving, col5);
					if (check) {
						col7 = nonmoving;
					}
				}
				else if (col == 6) {
					col6 = deck->ColtoCol(moving, col6);
					check = deck->CheckMovetoCol(moving, col6);
					if (check) {
						col7 = nonmoving;
					}
				}
				else if (col == 1) {
					col1 = deck->ColtoCol(moving, col1);
					check = deck->CheckMovetoCol(moving, col1);
					if (check) {
						col7 = nonmoving;
					}
				}
				else if (col == 8) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "C") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundClubs;
					foundClubs = deck->addFound(moving.at(0), foundClubs);
					if (foundClubs.size() > temp.size()) {
						col7 = nonmoving;
					}
				}
				else if (col == 9) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "D") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundDiamonds;
					foundDiamonds = deck->addFound(moving.at(0), foundDiamonds);
					if (foundDiamonds.size() > temp.size()) {
						col7 = nonmoving;
					}
				}
				else if (col == 10) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "S") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundSpades;
					foundSpades = deck->addFound(moving.at(0), foundSpades);
					if (foundSpades.size() > temp.size()) {
						col7 = nonmoving;
					}
				}
				else if (col == 11) {
					if (moving.size() != 1) {
						cout << "Can only move one card at a time!" << endl;
						continue;
					}
					if (moving.at(0)->Suit() != "H") {
						cout << "Incorrect foundation" << endl;
						continue;
					}
					vector<Node*> temp = foundHearts;
					foundHearts = deck->addFound(moving.at(0), foundHearts);
					if (foundHearts.size() > temp.size()) {
						col7 = nonmoving;
					}
				}
			}
		}

		//Moving foundations
		else if (choice == 3) {
			cout << "Choose a foundation." << endl;
			int choice1;
			cin >> choice1;
			if (choice1 == 1) {
				if (foundClubs.size() == 0) {
					cout << "Invalid Move!" << endl;
					continue;
				}
				Node *temp = foundClubs.back();
				bool check = false;

				cout << "Move foundation card where?" << endl;
				int col = 0;
				cin >> col;
				if (col == 1) {
					vector<Node*> checker = col1;
					col1 = deck->FoundtoCol(temp, col1);
					if (col1.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 2) {
					vector<Node*> checker = col2;
					col2 = deck->FoundtoCol(temp, col2);
					if (col2.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 3) {
					vector<Node*> checker = col3;
					col3 = deck->FoundtoCol(temp, col3);
					if (col3.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 4) {
					vector<Node*> checker = col4;
					col4 = deck->FoundtoCol(temp, col4);
					if (col4.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 5) {
					vector<Node*> checker = col5;
					col5 = deck->FoundtoCol(temp, col5);
					if (col5.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 6) {
					vector<Node*> checker = col6;
					col6 = deck->FoundtoCol(temp, col6);
					if (col6.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 7) {
					vector<Node*> checker = col7;
					col7 = deck->FoundtoCol(temp, col7);
					if (col7.size() > checker.size()) {
						check = true;
					}
				}
				else {
					cout << "Invalid Move!";
				}
				if (check) {
					foundClubs.pop_back();
				}
			}
			else if (choice1 == 2) {
				if (foundDiamonds.size() == 0) {
					cout << "Invalid Move!" << endl;
					continue;
				}
				Node *temp = foundDiamonds.back();
				bool check = false;

				cout << "Move foundation card where?" << endl;
				int col = 0;
				cin >> col;
				if (col == 1) {
					vector<Node*> checker = col1;
					col1 = deck->FoundtoCol(temp, col1);
					if (col1.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 2) {
					vector<Node*> checker = col2;
					col2 = deck->FoundtoCol(temp, col2);
					if (col2.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 3) {
					vector<Node*> checker = col3;
					col3 = deck->FoundtoCol(temp, col3);
					if (col3.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 4) {
					vector<Node*> checker = col4;
					col4 = deck->FoundtoCol(temp, col4);
					if (col4.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 5) {
					vector<Node*> checker = col5;
					col5 = deck->FoundtoCol(temp, col5);
					if (col5.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 6) {
					vector<Node*> checker = col6;
					col6 = deck->FoundtoCol(temp, col6);
					if (col6.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 7) {
					vector<Node*> checker = col7;
					col7 = deck->FoundtoCol(temp, col7);
					if (col7.size() > checker.size()) {
						check = true;
					}
				}
				else {
					cout << "Invalid Move!";
				}
				if (check) {
					foundDiamonds.pop_back();
				}
			}
			else if (choice1 == 3) {
				if (foundSpades.size() == 0) {
					cout << "Invalid Move!" << endl;
					continue;
				}
				Node *temp = foundSpades.back();
				bool check = false;

				cout << "Move foundation card where?" << endl;
				int col = 0;
				cin >> col;
				if (col == 1) {
					vector<Node*> checker = col1;
					col1 = deck->FoundtoCol(temp, col1);
					if (col1.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 2) {
					vector<Node*> checker = col2;
					col2 = deck->FoundtoCol(temp, col2);
					if (col2.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 3) {
					vector<Node*> checker = col3;
					col3 = deck->FoundtoCol(temp, col3);
					if (col3.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 4) {
					vector<Node*> checker = col4;
					col4 = deck->FoundtoCol(temp, col4);
					if (col4.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 5) {
					vector<Node*> checker = col5;
					col5 = deck->FoundtoCol(temp, col5);
					if (col5.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 6) {
					vector<Node*> checker = col6;
					col6 = deck->FoundtoCol(temp, col6);
					if (col6.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 7) {
					vector<Node*> checker = col7;
					col7 = deck->FoundtoCol(temp, col7);
					if (col7.size() > checker.size()) {
						check = true;
					}
				}
				else {
					cout << "Invalid Move!";
				}
				if (check) {
					foundSpades.pop_back();
				}
			}
			else if (choice1 == 4) {
				if (foundHearts.size() == 0) {
					cout << "Invalid Move!" << endl;
					continue;
				}
				Node *temp = foundHearts.back();
				bool check = false;

				cout << "Move foundation card where?" << endl;
				int col = 0;
				cin >> col;
				if (col == 1) {
					vector<Node*> checker = col1;
					col1 = deck->FoundtoCol(temp, col1);
					if (col1.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 2) {
					vector<Node*> checker = col2;
					col2 = deck->FoundtoCol(temp, col2);
					if (col2.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 3) {
					vector<Node*> checker = col3;
					col3 = deck->FoundtoCol(temp, col3);
					if (col3.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 4) {
					vector<Node*> checker = col4;
					col4 = deck->FoundtoCol(temp, col4);
					if (col4.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 5) {
					vector<Node*> checker = col5;
					col5 = deck->FoundtoCol(temp, col5);
					if (col5.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 6) {
					vector<Node*> checker = col6;
					col6 = deck->FoundtoCol(temp, col6);
					if (col6.size() > checker.size()) {
						check = true;
					}
				}
				else if (col == 7) {
					vector<Node*> checker = col7;
					col7 = deck->FoundtoCol(temp, col7);
					if (col7.size() > checker.size()) {
						check = true;
					}
				}
				else {
					cout << "Invalid Move!";
				}
				if (check) {
					foundHearts.pop_back();
				}
			}
		}
		else {
			cout << "Please enter a Valid value!";
		}
		for (int i = 0; i < 300; i++) {
			cout << endl;
		}
		deck->turnOver(col1);
		deck->turnOver(col2);
		deck->turnOver(col3);
		deck->turnOver(col4);
		deck->turnOver(col5);
		deck->turnOver(col6);
		deck->turnOver(col7);

		if (deck->ReturnLoc() == deck->Length() - 1) {

		}
		else cout << "DECK";

		cout << "\t";
		if (deck->DCard() != NULL) {
			if (deck->DCard()->Num() == 0) {

			}
			else if (deck->DCard()->Num() == 1) {
				cout << "A";
				cout << deck->DCard()->Suit();
			}
			else if (deck->DCard()->Num() == 11) {
				cout << "J";
				cout << deck->DCard()->Suit();
			}
			else if (deck->DCard()->Num() == 12) {
				cout << "Q";
				cout << deck->DCard()->Suit();
			}
			else if (deck->DCard()->Num() == 13) {
				cout << "K";
				cout << deck->DCard()->Suit();
			}
			else {
				cout << deck->DCard()->Num();
				cout << deck->DCard()->Suit();
			}
		}
		cout << "\t\t";
		if (foundClubs.size() > 0) {
			if (foundClubs.back()->Num() == 1) {
				cout << "A";
				cout << foundClubs.back()->Suit();
			}
			else if (foundClubs.back()->Num() == 11) {
				cout << "J";
				cout << foundClubs.back()->Suit();
			}
			else if (foundClubs.back()->Num() == 12) {
				cout << "Q";
				cout << foundClubs.back()->Suit();
			}
			else if (foundClubs.back()->Num() == 13) {
				cout << "K";
				cout << foundClubs.back()->Suit();
			}
			else {
				cout << foundClubs.back()->Num();
				cout << foundClubs.back()->Suit();
			}
		}
		cout << "\t";
		if (foundDiamonds.size() > 0) {
			if (foundDiamonds.back()->Num() == 1) {
				cout << "A";
				cout << foundDiamonds.back()->Suit();
			}
			else if (foundDiamonds.back()->Num() == 11) {
				cout << "J";
				cout << foundDiamonds.back()->Suit();
			}
			else if (foundDiamonds.back()->Num() == 12) {
				cout << "Q";
				cout << foundDiamonds.back()->Suit();
			}
			else if (foundDiamonds.back()->Num() == 13) {
				cout << "K";
				cout << foundDiamonds.back()->Suit();
			}
			else {
				cout << foundDiamonds.back()->Num();
				cout << foundDiamonds.back()->Suit();
			}
		}
		cout << "\t";
		if (foundSpades.size() > 0) {
			if (foundSpades.back()->Num() == 1) {
				cout << "A";
				cout << foundSpades.back()->Suit();
			}
			else if (foundSpades.back()->Num() == 11) {
				cout << "J";
				cout << foundSpades.back()->Suit();
			}
			else if (foundSpades.back()->Num() == 12) {
				cout << "Q";
				cout << foundSpades.back()->Suit();
			}
			else if (foundSpades.back()->Num() == 13) {
				cout << "K";
				cout << foundSpades.back()->Suit();
			}
			else {
				cout << foundSpades.back()->Num();
				cout << foundSpades.back()->Suit();
			}
		}
		cout << "\t";
		if (foundHearts.size() > 0) {
			if (foundHearts.back()->Num() == 1) {
				cout << "A";
				cout << foundHearts.back()->Suit();
			}
			else if (foundHearts.back()->Num() == 11) {
				cout << "J";
				cout << foundHearts.back()->Suit();
			}
			else if (foundHearts.back()->Num() == 12) {
				cout << "Q";
				cout << foundHearts.back()->Suit();
			}
			else if (foundHearts.back()->Num() == 13) {
				cout << "K";
				cout << foundHearts.back()->Suit();
			}
			else {
				cout << foundHearts.back()->Num();
				cout << foundHearts.back()->Suit();
			}
		}
		cout << "\t";
		cout << endl << endl;
		deck->PrintCol(col1, col2, col3, col4, col5, col6, col7);
		cout << endl << endl;

	}
	//NEED TO PUT A WHILE LOOP
	return 0;
}
