#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void permute(char in[], int idx)
{
	if (in[idx] == '\0')
	{
		cout << in << endl;
	}
	for (int i = idx; in[i] != '\0'; i++)
	{
		swap(in[i], in[idx]);
		permute(in, idx + 1);
		//Back Tracking
		swap(in[i], in[idx]);
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

	int n = strlen(in);
	cout << "\nlength here : " << n;
	sort(in, in + n);
	cout << "\narray here : " << in << endl;
	permute(in, 0);
	return 0;
}
