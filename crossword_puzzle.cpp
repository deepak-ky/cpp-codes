#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define se                            second

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}

bool fill_the_mat(char **mat, int i, int j, vector<string> &words)
{
	if (i < 0 || j < 0 || i >= 10 || j >= 10)
	{
		return false;
	}
	if (mat[i][j] != '+' && mat[i][j] != '-')
	{
		return false;
	}
	if (mat[i][j] == '+')
	{
		if (j == 9)
		{
			return fill_the_mat(mat, i + 1, 0, words);
		}
		else return fill_the_mat(mat, i, j + 1, words);
	}
	//If the current character is a minus
	for (int k = 0; k < words.size(); k++)
	{
		if (words[k] == "X")
		{
			continue;
		}
		int len = words.length();
		int row_len = 0;
		int col_len = 0;
		while (j < 10 && mat[i][row_len])


		}
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		char *mat = new char*[10];
		for (int i = 0; i < 10; i++)
		{
			mat[i] = new char[10];
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				cin >> mat[i][j];
			}
		}
		int n;
		cin >> n;
		vector<string> words;
		for (int i = 0; i < n; i++)
		{
			string w;
			cin >> w;
			words.pb(w);
		}
		fill_the_mat(mat, words);
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}

	}
	return 0;
}
