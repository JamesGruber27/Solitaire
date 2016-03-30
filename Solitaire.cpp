#include <iostream>
#include <algorithm>
#include <string>
#include <chrono>
#include <random>
#include <vector>
#include "Deck.h"
using namespace std;

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
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(shuffler.begin(), shuffler.end(), default_random_engine(seed));
	List deck(shuffler);
	deck.Print();
	return 0;
}
