//
// Created by Azriel on 8/29/2022.
//

#ifndef CRYPTKEEPER_CRYPT_H
#define CRYPTKEEPER_CRYPT_H
using namespace std;
void modeChecker(const string& moderCheck);
void shiftCipher();
void vigCipher();
void showModeList();
void stringUppercase(string &input);
void cleanSymbols(string &input);
void cleanSymbolsSpace(string &input);
void shiftHelper(const string& theMessage, int theShift);
void vigHelper(const string& theMessage, const string& theKeyWord);
void euclidAlgo();
int gcd(int a, int b);



class crypt {

};


#endif //CRYPTKEEPER_CRYPT_H
