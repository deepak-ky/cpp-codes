#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	//wer(n);
	//wer(m);
	int cnt = 0;
	int best_marks[m];
	int k = 0;
	int mat[n][m];
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			mat[i][j] = s[j] - '0';
		}
	}
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}*/

	for (int j = 0; j < m; j++)
	{
		int max_mark = INT_MIN;
		for (int i = 0; i < n; i++)
		{	//wer(mat[i][j]);
			max_mark = max(max_mark, mat[i][j]);
		}
		//wer(max_mark);
		best_marks[k++] = max_mark;
	}
	//out(best_marks, m);

	for (int i = 0; i < n; i++)
	{
		//bool is_successful = false;
		for (int j = 0; j < m; j++)
		{
			if (mat[i][j] >= best_marks[j])
			{
				cnt++;
				break;
			}
		}
	}
	cout << cnt << endl;

	return 0;
}
