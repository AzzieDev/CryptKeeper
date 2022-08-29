//
// Created by Azriel on 8/29/2022.
//
#include <iostream>
#include <string>
#include "crypt.h"

using namespace std;

//intro function
int main() {
	cout << "Welcome to the Cryptkeeper" << endl;
	string moder = "";
	while (moder == "") {
		cout << "Enter a mode, or help to list all modes" << endl;
		cin >> moder;
		if (moder != "") {
			modeChecker(moder);
			moder = "";
		}
	}
}

//handles modes submitted by user
void modeChecker(string moderCheck) {
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
	string message = "";
	cin >> message;
	//choice of brute force or manual shift
	cout << "What would your shift be?" << endl;
	cout << "Enter 0 for brute force of all possibilities:";
	int shift;
	cin >> shift;
	//handle
}

//intended to convert any passed stream to uppercase form
string stringUppercase(string input) {
	string output = "";
	return output;
}

//intended to purge unwanted symbols from a string
//this will not purge the space symbol
string cleanSymbols(string input) {
	string output = "";
	return output;
}



