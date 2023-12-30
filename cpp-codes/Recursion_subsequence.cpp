#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
vector<string> v;
void subsequences(char *a, char *b, int i, int j)
{
	//Rec Case
	if (a[i] == '\0')
	{
		b[j] = '\0';
		v.push_back(b);
		return;
	}
	b[j] = a[i];
	subsequences(a, b, i + 1, j + 1);
	subsequences(a, b, i + 1, j);
}
int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	char a[100];
	cin >> a;
	int len = strlen(a);
	cout << "Lenght is : " << len << endl;
	cout << "Test Check is " << a[len - 1] << endl;
	char b[100];
	subsequences(a, b, 0, 0);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ":";
	}
	cout << endl << (1 << len);
	return 0;
}
