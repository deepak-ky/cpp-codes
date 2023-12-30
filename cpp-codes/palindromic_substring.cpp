#include <iostream>
#include <string>
#include <unordered_set>
#include<bits/stdc++.h>
using namespace std;

// expand in both directions of low and high to find all palindromes
void expand(string str, int low, int high, set<string> &set)
{
	// run till str[low.high] is a palindrome
	while (low >= 0 && high < str.length()
	        && str[low] == str[high])
	{
		// push all palindromes into the set
		set.insert(str.substr(low, high - low + 1));

		// expand in both directions
		low--, high++;
	}
}

// Function to find all unique palindromic substrings of given string
void allPalindromicSubstrings(string str)
{
	// create an empty set to store all unique palindromic substrings
	set<string> set;

	for (int i = 0; i < str.length(); i++)
	{
		// find all odd length palindrome with str[i] as mid point
		expand(str, i, i, set);

		// find all even length palindrome with str[i] and str[i+1] as
		// its mid points
		expand(str, i, i + 1, set);
	}

	// print all unique palindromic substrings
	for (auto i : set)
		cout << i << " ";
}

// main function
int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	string str = "abaaa";

	allPalindromicSubstrings(str);

	return 0;
}
