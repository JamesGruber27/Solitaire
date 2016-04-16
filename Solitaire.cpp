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

	//Every turn of Solitaire
	while (true) {
<<<<<<< HEAD
        
        //Menu and user input
        cout << "\nWhat choice would you like to choose?" << endl;
        cout << "1 - Draw a card" << endl;
        cout << "2 - Attempts to add the drawn card to the first column" << endl;
        cout << "3 - Attempts to add the drawn card to the second column" << endl;
        cout << "4 - Attempts to add the drawn card to the third column" << endl;
        cout << "5 - Attempts to add the drawn card to the fourth column" << endl;
        cout << "6 - Attempts to add the drawn card to the fifth column" << endl;
        cout << "7 - Attempts to add the drawn card to the sixth column" << endl;
        cout << "8 - Attempts to add the drawn card to the seventh column" << endl;
        cout << "9 - Take cards from a column and add it to another column" << endl;

=======
		if (deck->DCard() != NULL) {
			cout << "Currently drawn card: " << deck->DCard()->Num() << deck->DCard()->Suit();
		}
		else {
			cout << "No card drawn";
		}
>>>>>>> abbd168562ad267229f05dd5f04e2a15e7700e33
		int choice;
		cin >> choice;
        
        //1. Draw a card from the deck
		if (choice == 1) {
            deck->PrintCol(col1, col2, col3, col4, col5, col6, col7);
            deck = DrawCard(deck);
			cin.clear();
			continue;
		}
        
        //2. Attempts to add the drawn card to the first column
		else if (choice == 2) {
			vector<Node*> temp = col1;
			col1 = deck->add(deck->DCard(), col1);
			if (col1.size() > temp.size()) {
				deck = deck->RemoveCard(deck->DCard());
			}
			deck->PrintCol(col1, col2, col3, col4, col5, col6, col7);
		}
        
        //3. Attempts to add the drawn card to the second column
		else if (choice == 3) {
			vector<Node*> temp = col2;
			col2 = deck->add(deck->DCard(), col2);
			if (col2.size() > temp.size()) {
				deck = deck->RemoveCard(deck->DCard());
			}
			deck->PrintCol(col1, col2, col3, col4, col5, col6, col7);
		}
        
        //4. Attempts to add the drawn card to the third column
		else if (choice == 4) {
			vector<Node*> temp = col3;
			col3 = deck->add(deck->DCard(), col3);
			if (col3.size() > temp.size()) {
				deck = deck->RemoveCard(deck->DCard());
			}
			deck->PrintCol(col1, col2, col3, col4, col5, col6, col7);
		}
        
        //5. Attempts to add the drawn card to the fourth column
		else if (choice == 5) {
			vector<Node*> temp = col4;
			col4 = deck->add(deck->DCard(), col4);
			if (col4.size() > temp.size()) {
				deck = deck->RemoveCard(deck->DCard());
			}
			deck->PrintCol(col1, col2, col3, col4, col5, col6, col7);
		}
        
        //6. Attempts to add the drawn card to the fifth column
		else if (choice == 6) {
			vector<Node*> temp = col5;
			col5 = deck->add(deck->DCard(), col5);
			if (col5.size() > temp.size()) {
				deck = deck->RemoveCard(deck->DCard());
			}
			deck->PrintCol(col1, col2, col3, col4, col5, col6, col7);
		}
        
        //7. Attempts to add the drawn card to the sixth column
		else if (choice == 7) {
			vector<Node*> temp = col6;
			col6 = deck->add(deck->DCard(), col6);
			if (col6.size() > temp.size()) {
				deck = deck->RemoveCard(deck->DCard());
			}
			deck->PrintCol(col1, col2, col3, col4, col5, col6, col7);
		}
        
        //8. Attempts to add the drawn card to the seventh column
		else if (choice == 8) {
			vector<Node*> temp = col7;
			col7 = deck->add(deck->DCard(), col7);
			if (col7.size() > temp.size()) {
				deck = deck->RemoveCard(deck->DCard());
			}
			deck->PrintCol(col1, col2, col3, col4, col5, col6, col7);
		}
		
        //9 Moving from column to column
        else if (choice == 9){
            cout << "What column do you want to move cards from (enter 1,2,3,4,5,6,7): ";
            vector<Node*> colFrom, temp;
            int input;
            cin >>input;
            
            //From Col1
            if (input == 1)
                colFrom = col1;
            //From Col2
            else if (input == 2)
                colFrom = col2;
            //From Col3
            else if (input == 3)
                colFrom = col3;
            //From Col4
            else if (input == 4)
                colFrom = col4;
            //From Col5
            else if (input == 5)
                colFrom = col5;
            //From Col6
            else if (input == 6)
                colFrom = col6;
            //From Col7
            else if (input == 7)
                colFrom = col7;
            //INCLUDE INPUT ERROR I GUESS
            else {}
            
            //CREATING A SET OF ALL OF THE FACEUP CARDS OF THE COLUMN
            
            for (int i = 0; i < colFrom.size(); i++){
                if (colFrom.at(i)->Faceup()){
                    temp.push_back(colFrom.at(i));
                }
            }
            
            //GETTING THE CORRECT SET OF CARDS TO MOVE FROM THE COLUMN
            cout << "What card(s) would you like to move from the column? Enter Y if you want to move the set of cards starting from that position and N if you want to start further down the tableau column.";
            char here;
            int tempCount = 0;
            for (int i = 0; i < temp.size(); i++){
                cout << "\nStarting from: " << temp.at(i)->Num() << temp.at(i)->Suit() << endl;
                cout << "Y or N?";
                cin >> here;
                tempCount++;
                if (here == 'Y')
                    break;
                else {
                    temp.erase(temp.begin());
                }
            }
            
            //Need to include the add "rules"
            cout << "What column would you like to move the card(s) to? (enter 1,2,3,4,5,6,7): ";
            int colTo;
            cin >> colTo;

            if (colTo == 1){
                vector<Node*> testCol = deck->add(temp.at(0), col1);
                if (testCol.size() > col1.size()){
                    for (int i = 0; i < temp.size(); i++){
                        col1.push_back(temp.at(i));
                    }
                }
            }
            else if (colTo == 2){
                vector<Node*> testCol = deck->add(temp.at(0), col2);
                if (testCol.size() > col2.size()){
                    for (int i = 0; i < temp.size(); i++){
                        col2.push_back(temp.at(i));
                    }
                }
            }
            else if (colTo == 3){
                vector<Node*> testCol = deck->add(temp.at(0), col3);
                if (testCol.size() > col3.size()){
                    for (int i = 0; i < temp.size(); i++){
                        col3.push_back(temp.at(i));
                    }
                }
            }
            else if (colTo == 4){
                vector<Node*> testCol = deck->add(temp.at(0), col4);
                if (testCol.size() > col4.size()){
                    for (int i = 0; i < temp.size(); i++){
                        col4.push_back(temp.at(i));
                    }
                }
            }
            else if (colTo == 5){
                vector<Node*> testCol = deck->add(temp.at(0), col5);
                if (testCol.size() > col5.size()){
                    for (int i = 0; i < temp.size(); i++){
                        col5.push_back(temp.at(i));
                    }
                }
            }
            else if (colTo == 6){
                vector<Node*> testCol = deck->add(temp.at(0), col6);
                if (testCol.size() > col6.size()){
                    for (int i = 0; i < temp.size(); i++){
                        col6.push_back(temp.at(i));
                    }
                }
            }
            else if (colTo == 7){
                vector<Node*> testCol = deck->add(temp.at(0), col7);
                if (testCol.size() > col7.size()){
                    
                    for (int i = 0; i < temp.size(); i++){
                        col7.push_back(temp.at(i));
                    }
                }
            }
        }
        else {
			break;
		}
		deck->Print();
        deck->PrintCol(col1, col2, col3, col4, col5, col6, col7);
	}
	return 0;
}
