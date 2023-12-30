#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char print[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void printdigits(int n)
{
	if (n == 0)
	{
		return;
	}
	printdigits(n / 10);
	cout << print[n % 10] << " ";
}
int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	printdigits(n);
	return 0;
}
