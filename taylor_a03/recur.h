/*
 * recur.h
 *
 *  Created on: Oct 3, 2019
 *      Author: gregorytaylor
 */

#ifndef RECUR_H_
#define RECUR_H_

#include <iostream>
#include <string>

using namespace std;

// prototypes
int fact(int);
int fib(int);
void prime(int);
bool isPrime(int, int);
int mult(int, int);
string reverseString(string);
void rev(string&, int);
int countOccurrences(string, string);
int match(string, string, int, int);

// Factorial calculation
int fact(int multiplicand)
{
	if (multiplicand == 0)
	{
		return 1;
	}
	else if (multiplicand == 1)
	{
		return 1;
	}
	else
	{
		return (multiplicand * fact(multiplicand - 1));
	}
}

// Fibonocci number calculation by sequence designation
int fib(int seq_num)
{
	if (seq_num == 1)
		return 0;
	else if (seq_num == 2)
		return 1;
	else
		return (fib(seq_num - 1) + fib(seq_num - 2));
}

// Display a sequence of prime numbers
void prime(int seq_num)
{
	int counter = 0, tester = 2;
	while (counter != seq_num)
	{
		bool x = isPrime(tester, 2);
		if (x == 1)
		{
			cout << tester << " ";
			counter++;
		}
		tester++;
	}
}

// Helper function for evaluating numbers in terms of prime status
bool isPrime(int test, int div)
{
	if (test == 2)
		return true;
	if (test == div)
		return true;
	if (test % div == 0)
		return false;

	return isPrime(test, div + 1);
}

// Recursive multiplication
int mult(int multiplicand, int multiplier)
{
	if (multiplier == 0)
	{
		return 0;
	}
	else if (multiplier == 1)
	{
		return multiplicand;
	}
	else
		return multiplicand + mult(multiplicand, multiplier - 1);
}

// String reversal
string reverseString(string subject)
{
	rev(subject, 0);
	return subject;
}

// String reversal helper function
void rev(string &subject, int position = 0)
{
	if (position == subject.length() / 2)
		return;
	swap(subject[position], subject[subject.length() - 1 - position]);
	rev(subject, position + 1);
}

// Pattern search within a string
int countOccurrences(string pattern, string subject)
{
	int x= match(pattern, subject, 0, 0);
	return x;
}

// helper function for pattern matching function
int match(string subject, string pattern, int cursor, int count)
{
	if (cursor == subject.length())
		return count;
	if (subject[cursor] == pattern[0])
		count++;
	return match(subject, pattern, cursor + 1, count);
}

#endif /* RECUR_H_ */
