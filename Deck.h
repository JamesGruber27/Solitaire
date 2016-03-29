#include <iostream>
#include <string>
using namespace std;

class Node {
private:
  int number;
  string suit;
  Node *next;

public:
  void SetNum(int n) {number = n;}
  void SetNext(Node *a) {next = a;}
  void SetSuit(string n) {suit = n;}
  int Num() {return number;}
  Node *Next() {return next;}
  string Suit() {return suit;}
};

class List {
private:
  Node *head;
  
public:
  List();
  void Print();
};

List::List() {
  head = new Node();
  Node *temp = head;
  for(int i = 0; i < 4; i++){
    for(int j = 1; j < 14; j++){
      temp->SetNum(j);
      if(i==0){
        temp->SetSuit("C");
      }
      else if (i==1){
        temp->SetSuit("D");
      }
      else if (i==2){
        temp->SetSuit("S");
      }
      else if (i==3){
        temp->SetSuit("H");
      }
      if(i==3 && j==13){
        break;
      }
      Node *card = new Node();
      temp->SetNext(card);
      temp=temp->Next();
    }
  }
}

void List::Print(){
  Node *temp = head;
  for(int i = 0; i < 52; i++){
    if(temp->Num() == 1){
      cout<<"A";
    }
    else if(temp->Num() == 11){
      cout<<"J";
    }
    else if(temp->Num()==12){
      cout<<"Q";
    }
    else if(temp->Num()==13){
      cout<<"K";
    }
    else cout<<temp->Num();
    cout<<temp->Suit()<<" -> ";
    temp = temp->Next();
  }
  cout<<"NULL"<<endl;
  return;
}
