#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
void printkeypads(char in[], char out[], int i, int j)
{
	if (in[i] == '\0')
	{
		out[j] = '\0';
		cout << out << endl;
		return;
	}
	int digit = in[i] - '0';
	if (digit == 1 || digit == 0)
	{
		printkeypads(in, out, i + 1, j);
	}
	for (int k = 0; keypad[digit][k] != '\0'; k++)
	{
		out[j] = keypad[digit][k];
		printkeypads(in, out, i + 1, j + 1);
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	char in[100];
	cin >> in;
	char out[100];
	printkeypads(in, out, 0, 0);
	return 0;
}
