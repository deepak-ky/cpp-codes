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
vector<int> merge(vector<int> a, vector<int> b)
{
	vector<int> ans;
	int i = 0;
	int j = 0;


	while (i < a.size() && j < b.size())
	{
		if (a[i] <= b[j])
		{
			ans.pb(a[i]);
			i++;
		}
		else
		{
			ans.pb(b[j]);
			j++;
		}
	}

	while (i < a.size())
	{
		ans.pb(a[i]);
		i++;
	}

	while (j < b.size())
	{
		ans.pb(b[j]);
		j++;
	}

	return ans;
}

vector<int> sort_k(vector<vector<int>> v, int i, int j)
{
	if (i == j)
	{
		return v[i];
	}

	if (j - i == 1)
	{
		return merge(v[i], v[j]);
	}

	int mid = i + ((j - i) / 2);

	vector<int> v1 = sort_k(v, i, mid);
	vector<int> v2 = sort_k(v, mid + 1, j);

	return merge(v1, v2);
}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		vector< vector<int> > matrix;
		vector<int> v1 = {1, 2, 3};
		vector<int> v2 = {4, 5, 6};
		vector<int> v3 = {7, 8, 9};

		matrix.pb(v3);
		matrix.pb(v1);
		matrix.pb(v2);

		vector<int> ans = sort_k(matrix, 0, matrix.size() - 1);


		for (auto x : ans)
		{
			cout << x << " ";
		}
	}
	return 0;
}
