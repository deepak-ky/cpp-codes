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
#define s                            second

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

int all_occ(int *a, int idx, int n, int key, int occ_idx[], int j)
{
	if (idx == n)
	{
		return j;
	}
	if (a[idx] == key)
	{
		occ_idx[j] = idx;
		return all_occ(a, idx + 1, n, key, occ_idx, j + 1);
	}
	return all_occ(a, idx + 1, n, key, occ_idx, j);


}

void all_occ_2(int *a, int idx, int n, int key)
{
	if (idx == n)
	{
		return;
	}
	if (a[idx] == key)
	{
		cout << idx << ",";
	}
	all_occ_2(a, idx + 1, n, key);
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int a[] = {1, 2, 3, 7, 4, 5, 6, 7, 10};
		int key = 7;
		int n = sizeof(a) / sizeof(int);
		int occ_idx[100];
		int num_of_occ = all_occ(a, 0, n, key, occ_idx, 0);
		for (int i = 0; i < num_of_occ; i++)
		{
			cout << occ_idx[i] << ",";
		}

		cout << endl;
		all_occ_2(a, 0, n, key);

	}
	return 0;
}
