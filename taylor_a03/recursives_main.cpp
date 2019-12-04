/*
 * recursives_main.cpp
 *
 *  Created on: Oct 3, 2019
 *      Author: gregorytaylor
 */
#include <iostream>
#include "recur.h"

using namespace std;

int main()
{
// factorial
	int count;
	int f=5;
	cout << "factorial of " << f << " is " << fact(f) << endl << endl;
// Fibonocci
	for (count=0;count < 10;count++)
	{
		cout << "Fibonocci sequence number " << count+1 << " is " << fib(count+1) << endl;
	}
// primes
	prime(10);
// multiplication
	int a=6, b=5;
	cout << endl << "product of " << a << " and " << b << " is " << mult(a,b) << endl << endl;
// string reversal
	string s = "abcde";
	cout << "original string " << s << " reversed string " << reverseString(s) << endl << endl;
// character counting
	string t="a";
	cout << "number of occurrences of " << t[0] << " in " << s << " is " << countOccurrences(s,t) << endl;
	// cout << countOccurrences("abcdea", t);
    return 0;
}



