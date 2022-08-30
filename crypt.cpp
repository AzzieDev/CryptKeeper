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
			cleanSymbols(moder);
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
	cout << "Welcome to Shift/Caesar Cipher mode!" << endl;
	cout << "Rules: alpha non-numeric messages only. Spaces are allowed." << endl;
	cout << "What is your message you want to encode/decode?" << endl;
	//clear the cin buffer
	cin.ignore();
	string message;
	getline(cin, message);
	stringUppercase(message);
	cleanSymbols(message);
	//choice of brute force or manual shift
	cout << "What would your shift be?" << endl;
	cout << "Enter 0 for brute force of all possibilities," << endl;
	cout << "Enter a positive or negative integer for a specific shift:" << endl;
	int shift;
	cin >> shift;
	//handle shifts
	//brute force
	if (shift == 0) {
		cout << "Brute force of all possible combinations of shifts for your message:" << endl;
		for (int i = 0; i < 26; i++) {
			shiftHelper(message, i);
		}
	} else {
		//mod 26 of shift
		shiftHelper(message, shift%26);
	}
}

//shift helper function to perform specific shift
void shiftHelper(const string& theMessage, int theShift) {
	for (char i : theMessage) {
		//if space then skip
		if (!isspace(i)) {
			char currentChar = {static_cast<char>(i + theShift)};
			//handle loop from Z to A
			if (currentChar > 90) {
				currentChar = {static_cast<char>(currentChar - 26)};
			}
			cout << currentChar;
		} else {
			cout << " ";
		}
	}
	cout << endl;
}

//convert any passed string to uppercase form
void stringUppercase(string &input) {
	transform(input.begin(), input.end(), input.begin(), [](unsigned char c){
		return toupper(c);
	});
}

//intended to purge unwanted symbols from a string
//this will not purge the space symbol
void cleanSymbols(string &input) {
	string output;
	for (char i : input) {
		if (isalpha(i) || isspace(i)) {
			output.push_back(i);
		}
	}
	input = output;
}