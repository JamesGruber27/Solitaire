##include "Deck.h"
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
	shuffler.push_back("13C");

	//Shuffle the 52-long vector
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(shuffler.begin(), shuffler.end(), default_random_engine(seed));

	//Creating the 52-card deck object
	List* deck = new List(shuffler);

	//Greetings
	cout << "Welcome to Solitaire! Here is your starting board." << endl;

	//Printing the contents of the deck
	deck->Print();

	//Create columns of the tableau
	vector<Node*> col1 = deck->createColumn(1);
	vector<Node*> col2 = deck->createColumn(2);
	vector<Node*> col3 = deck->createColumn(3);
	vector<Node*> col4 = deck->createColumn(4);
	vector<Node*> col5 = deck->createColumn(5);
	vector<Node*> col6 = deck->createColumn(6);
	vector<Node*> col7 = deck->createColumn(7);
	int initCount1 = 1, initCount2 = 2, initCount3 = 3, initCount4 = 4, initCount5 = 5, initCount6 = 6, initCount7 = 7;


	//Print columns
	deck->PrintCol(col1, col2, col3, col4, col5, col6, col7);

	//Print deck again to show you that the correct cards were taken out
	deck->Print();

	deck->turnOver(col1);
	deck->turnOver(col2);
	deck->turnOver(col3);
	deck->turnOver(col4);
	deck->turnOver(col5);
	deck->turnOver(col6);
	deck->turnOver(col7);

	//The Game should take place here
	while (true) {
		if (deck->DCard() != NULL) {
			cout << "Currently drawn card: " << deck->DCard()->Num() << deck->DCard()->Suit();
		}
		else {
			cout << "No card drawn";
		}
		int choice;
		cin >> choice;
		if (choice == 1) {
			deck = DrawCard(deck);
			cin.clear();
			continue;
		}
		else if (choice == 2) {
			vector<Node*> temp = col1;
			col1 = deck->add(deck->DCard(), col1);
			if (col1.size() > temp.size()) {
				deck = deck->RemoveCard(deck->DCard());
			}
			deck->PrintCol(col1, col2, col3, col4, col5, col6, col7);
		}
		else if (choice == 3) {
			vector<Node*> temp = col2;
			col2 = deck->add(deck->DCard(), col2);
			if (col2.size() > temp.size()) {
				deck = deck->RemoveCard(deck->DCard());
			}
			deck->PrintCol(col1, col2, col3, col4, col5, col6, col7);
		}
		else if (choice == 4) {
			vector<Node*> temp = col3;
			col3 = deck->add(deck->DCard(), col3);
			if (col3.size() > temp.size()) {
				deck = deck->RemoveCard(deck->DCard());
			}
			deck->PrintCol(col1, col2, col3, col4, col5, col6, col7);
		}
		else if (choice == 5) {
			vector<Node*> temp = col4;
			col4 = deck->add(deck->DCard(), col4);
			if (col4.size() > temp.size()) {
				deck = deck->RemoveCard(deck->DCard());
			}
			deck->PrintCol(col1, col2, col3, col4, col5, col6, col7);
		}
		else if (choice == 6) {
			vector<Node*> temp = col5;
			col5 = deck->add(deck->DCard(), col5);
			if (col5.size() > temp.size()) {
				deck = deck->RemoveCard(deck->DCard());
			}
			deck->PrintCol(col1, col2, col3, col4, col5, col6, col7);
		}
		else if (choice == 7) {
			vector<Node*> temp = col6;
			col6 = deck->add(deck->DCard(), col6);
			if (col6.size() > temp.size()) {
				deck = deck->RemoveCard(deck->DCard());
			}
			deck->PrintCol(col1, col2, col3, col4, col5, col6, col7);
		}
		else if (choice == 8) {
			vector<Node*> temp = col7;
			col7 = deck->add(deck->DCard(), col7);
			if (col7.size() > temp.size()) {
				deck = deck->RemoveCard(deck->DCard());
			}
			deck->PrintCol(col1, col2, col3, col4, col5, col6, col7);
		}
		else {
			break;
		}
		deck->Print();
	}
	//NEED TO PUT A WHILE LOOP
	return 0;
}
