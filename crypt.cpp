//
// Created by Azriel on 8/29/2022.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>

#include "crypt.h"

void euclidAlgo();

using namespace std;

//intro function
int main() {
	cout << "Welcome to the Cryptkeeper" << endl;
	string moder;
	while (moder.empty()) {
		cout << "Enter a mode, or help to list all modes, quit/exit" << endl;
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
void modeChecker(const string &moderCheck) {
	//if-else structure because switch-case is not suitable
	if (moderCheck == "EXIT" || moderCheck == "QUIT") {
		exit(0);
	} else if (moderCheck == "SHIFT" || moderCheck == "CAESAR") {
		shiftCipher();
//	} else if (moderCheck == "VIGENERE" || moderCheck == "SQUARE") {
//		vigCipher();
	} else if (moderCheck == "GCD" || moderCheck == "EUCLID") {
		euclidAlgo();
	} else if (moderCheck == "BIG" || moderCheck == "OPERATOR") {
		bigMaths();
	} else if (moderCheck == "POWERMOD" || moderCheck == "MODEXP") {
		modularExp();
	} else if (moderCheck == "PHI" || moderCheck == "EULER") {
		eulerHelper();
	} else {
		showModeList();

	}
}

void showModeList() {
	cout << "HELP - show this list" << endl;
	cout << "EXIT or QUIT - terminate the program" << endl;
	cout << "SHIFT or CAESAR - shift cipher with optional brute force" << endl;
	//cout << "VIGENERE or SQUARE - shift cipher using a key word" << endl;
	cout << "GCD or EUCLID - solve for greatest common denominator" << endl;
	cout << "BIG or OPERATOR - allow large calculations" << endl;
	cout << "POWERMOD or MODEXP - solve modular exponentiation" << endl;
	cout << "EULER or PHI - compute Euler's Totient Function" << endl;

//	cout << "EGCD or EUCLID - solve for extended euclid values" << endl;
}

// procedure for a simple shift cipher
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
		shiftHelper(message, shift % 26);
	}
}

// procedure for a vigenere cipher
void vigCipher() {
	cout << "Welcome to Vigenere Cipher mode!" << endl;
	cout << "Rules: alpha non-numeric messages only. Spaces are allowed." << endl;
	cout << "What is your message you want to encode/decode?" << endl;
	//clear the cin buffer and retrieve message
	cin.ignore();
	string message;
	getline(cin, message);
	stringUppercase(message);
	cleanSymbols(message);
	//retrieve key
	cout << "What is your key word or phrase?" << endl;
	//might add brute force later with dictionary attack
	//cout << "Enter 0 for brute force of all possibilities," << endl;
	//clear the cin buffer and retrieve message
	cin.ignore();
	string keyword;
	getline(cin, keyword);
	stringUppercase(keyword);
	cleanSymbolsSpace(keyword);

	//data is processed, call the decryption




	//brute force
//	if (shift == 0) {
//		cout << "Brute force of all possible combinations of shifts for your message:" << endl;
//		for (int i = 0; i < 26; i++) {
//			shiftHelper(message, i);
//		}
//	} else {
//		//mod 26 of shift
//		shiftHelper(message, shift%26);
//	}
}

//shift helper function to perform specific shift
void shiftHelper(const string &theMessage, int theShift) {
	for (char i: theMessage) {
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
	transform(input.begin(), input.end(), input.begin(), [](unsigned char c) {
		return toupper(c);
	});
}

//intended to purge unwanted symbols from a string
//this will not purge the space symbol
void cleanSymbols(string &input) {
	string output;
	for (char i: input) {
		if (isalpha(i) || isspace(i)) {
			output.push_back(i);
		}
	}
	input = output;
}

//intended to purge any non-alpha symbols from a string
//this will include whitespace characters like space and tab
void cleanSymbolsSpace(string &input) {
	string output;
	for (char i: input) {
		if (isalpha(i)) {
			output.push_back(i);
		}
	}
	input = output;
}

//procedure that will process the euclidian algorithm including extended
void euclidAlgo() {
	cout << "Welcome to Euclid GCD mode!" << endl;
	cout << "Enter the first integer:" << endl;
	cpp_int a;
	cin >> a;
	cout << "Enter the second integer:" << endl;
	cpp_int b;
	cin >> b;
	cout << "---------" << endl;
	cpp_int d;
	d = gcd(a, b);
	cout << "GCD(" << a << ", " << b << ") = " << d << endl;
	cpp_int x, y;
	cpp_int g = gcdExtended(a, b, &x, &y);
	cout << "EGCD(" << a << " * " << x << ") + (" << b << " * " << y << ") = " << g << endl;
}

//basic gcd using euclidian algorithm
cpp_int gcd(cpp_int a, cpp_int b) {
	cout << "Computing GCD(" << a << ", " << b << "):\n";
	cpp_int r, q;
	while (b != 0) {
		q = a / b;
		r = a % b;
		cout << a << " = " << b << " * " << q << " + " << r << "\n";
		a = b;
		b = r;
	}
	cout << "GCD is " << a << "\n";
	return a;
}


// Function for extended Euclidean Algorithm
cpp_int gcdExtended(cpp_int a, cpp_int b, cpp_int *x, cpp_int *y) {
	// Base Case
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}

	cpp_int x1, y1; // To store results of recursive call
	cpp_int gcd = gcdExtended(b % a, a, &x1, &y1);

	// Update x and y using results of
	// recursive call
	*x = y1 - (b / a) * x1;
	*y = x1;

	// Print out gcd = a*x + b*y
	cout << gcd << " = " << a << "*" << *x << " + " << b << "*" << *y << endl;

	return gcd;
}

//main sequence for PowerMod operations
void modularExp() {
	cout << "Welcome to PowerMod mode!" << endl;
	cout << "Enter the first integer A (the base number):" << endl;
	cpp_int a;
	cin >> a;
	cout << "Enter the second integer K (the exponent):" << endl;
	cpp_int k;
	cin >> k;
	cout << "Enter the third integer M (the modulo):" << endl;
	cpp_int m;
	cin >> m;
	cout << "Now we take the binary form of K:" << endl;
	// Get the number of bits needed to represent b
	int num_bits = 0;
	cpp_int temp = k;
	while (temp != 0) {
		num_bits++;
		temp >>= 1;
	}
	std::vector<cpp_int> binary(num_bits);
	for (int i = num_bits - 1; i >= 0; i--) {
		binary[num_bits - i - 1] = (k >> i) & 1;
	}
	cout << "| ";
	for (int i = 0; i < binary.size(); i++) {
		cout << " " << binary[i] << "  | ";
	}
	cout << endl;
	cout << "And for each bit, find a remainder in a table:" << endl;
	cout << "| ";
	cpp_int c = 0;
	for (int i = 0; i < binary.size(); i++) {
		if (i == 0) {
			c = a;
		} else if (binary[i] == 0) {
			c = c * c % m;
		} else {
			c = (c * c * a) % m;
		}
		cout << " " << c << "  | ";
	}
	cout << endl << endl;
	c = 0;
	for (int i = 0; i < binary.size(); i++) {
		if (i == 0) {
			c = a;
			cout << "First we start with " << a << endl;
		} else if (binary[i] == 0) {
			cout << "The current bit is 0, so we square: " << endl;
			cout << c << "^2 (mod " << m << ") = ";
			c = pow(c, 2) % m;
			cout << c << endl;
		} else {
			cout << "The current bit is 1, so we square and multiply by A: " << endl;
			cout << c << " * " << c << " * " << a << " (mod " << m << ") = ";
			c = (c * c * a) % m;
			cout << c << endl;
		}
	}
	cout << "The final remainder is: " << c << endl;
	cout << endl;
	cout << a << " ^ " << k << " (mod " << m << ") = " << c << endl;
	cout << endl;

}

//helper for phi(n)
void eulerHelper() {
	cout << "Welcome to Euler's Totient Function mode!" << endl;
//	cout << "Enter 'n' for integer, '!' for factorial:" << endl;
//	char choice;
//	cin >> choice;
//	if (choice == 'n') {
	cout << "Enter an integer N:" << endl;
	cpp_int n;
	cin >> n;
	cout << "\u03A6(" << n << ") = " << phi(n) << endl;
	//}
}

//compute Euler's Totient Function
cpp_int phi(cpp_int n) {
	// Base case: if n is 1, return 1
	if (n == 1) {
		return 1;
	}

	// Initialize result to n
	cpp_int result = n;

	// Check for factors of n up to the square root of n
	for (cpp_int i = 2; i * i <= n; i++) {
		// If i is a factor of n, remove all factors of i from n
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
			}

			// Update result to account for i not being relatively prime to n
			result -= result / i;
		}
	}

	// If n is still greater than 1, it must be a prime factor
	// so update result accordingly
	if (n > 1) {
		result -= result / n;
	}

	// Return the final value of result
	return result;
}

//function for handling large integers
void bigMaths() {
	cout << "Welcome to Big Math mode!" << endl;
	cout << "Enter an integer A:" << endl;
	cpp_int a;
	cin >> a;
	cout << "Enter an integer B:" << endl;
	cpp_int b;
	cin >> b;

	cpp_int adder = a + b;
	cpp_int subB = a - b;
	cpp_int subA = b - a;
	cpp_int multer = a * b;

	cpp_int modB = a % b;
	cpp_int divA = (a - modB) / b;

	cpp_int modA = b % a;
	cpp_int divB = (b - modA) / a;

//	cpp_int expA = boost::multiprecision::pow(a, b.convert_to<int>());

//	cpp_int expB = boost::multiprecision::pow(a, b.convert_to<int>());


	cout << a << " + " << b << " = " << adder << endl;
	cout << a << "  - " << b << " = " << subB << endl;
	cout << b << "  - " << a << " = " << subA << endl;
	cout << a << "  * " << b << " = " << multer << endl;
	cout << a << "  / " << b << " = " << divA << " R" << modB << endl;
	cout << b << "  / " << a << " = " << divB << " R" << modA << endl;
	//cout << a << "  ^ " << b << " = " << expA << endl;
//	cout << b << "  ^ " << a << " = " << expB << endl;
}