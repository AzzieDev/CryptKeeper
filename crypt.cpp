//
// Created by Azriel on 8/29/2022.
//
#include <iostream>
#include <string>
#include <algorithm>
#include "crypt.h"

using namespace std;

//intro function
int main() {
	cout << "Welcome to the Cryptkeeper" << endl;
	string moder;
	while (moder.empty()) {
		cout << "Enter a mode, or help to list all modes" << endl;
		cin >> moder;
		if (!moder.empty()) {
			stringUppercase(moder);
			modeChecker(moder);
			moder = "";
		}
	}
}

//handles modes submitted by user
void modeChecker(const string& moderCheck) {
	//if-else structure because switch-case is not suitable
	if (moderCheck == "SHIFT" || moderCheck == "CAESAR") {
		shiftCipher();
	} else {
		showModeList();
	}
}

void showModeList() {
	cout << "HELP - show this list" << endl;
	cout << "SHIFT or CAESAR - shift cipher with optional brute force" << endl;
}

void shiftCipher() {
	cout << "What is your message you want to encode/decode?" << endl;
	string message;
	cin >> message;
	//choice of brute force or manual shift
	cout << "What would your shift be?" << endl;
	cout << "Enter 0 for brute force of all possibilities:";
	int shift;
	cin >> shift;
	//handle
}

//convert any passed string to uppercase form
void stringUppercase(string &input) {
	transform(input.begin(), input.end(), input.begin(), [](unsigned char c){ return toupper(c); });
}

//intended to purge unwanted symbols from a string
//this will not purge the space symbol
string cleanSymbols(string input) {
	string output = "";
	return output;
}