//
// Created by Azriel on 8/29/2022.
//

#ifndef CRYPTKEEPER_CRYPT_H
#define CRYPTKEEPER_CRYPT_H

#include <set>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

void modeChecker(const string &moderCheck);

void shiftCipher();

void vigCipher();

void showModeList();

void stringUppercase(string &input);

void cleanSymbols(string &input);

void cleanSymbolsSpace(string &input);

void shiftHelper(const string &theMessage, int theShift);

void vigHelper(const string &theMessage, const string &theKeyWord);

void euclidAlgo();

void bigMaths();

cpp_int gcd(cpp_int a, cpp_int b);

cpp_int gcdExtended(cpp_int a, cpp_int b, cpp_int *x, cpp_int *y);

void modularExp();

void eulerHelper();

set<cpp_int> factorialPrimes(cpp_int n);

set<cpp_int> primeFactors(cpp_int n);

cpp_int factorial(cpp_int n);

cpp_int phi(cpp_int n, set<cpp_int> primeFactors);

class crypt {

};


#endif //CRYPTKEEPER_CRYPT_H
