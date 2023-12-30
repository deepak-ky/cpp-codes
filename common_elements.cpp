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
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	int *a = new int[n1];
	int *b = new int[n2];
	int *c = new int[n3];
	for (int i = 0; i < n1; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n2; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < n3; i++)
	{
		cin >> c[i];
	}
	int i = 0; int j = 0; int k = 0;
	while (i < n1 && j < n2 && k < n3)
	{
		if (a[i] == b[j] && b[j] == c[k])
		{
			cout << a[i] << " ";
			i++;
			j++;
			k++;
		}
		else if (a[i] < b[j])
		{
			i++;
		}
		//when we skip the above case we know that the elemente
		//in the first array is either greater that or equal to
		//the second array element

		else if (c[k] > b[j])
		{
			j++;
		}
		else k++;
	}
	//cout << cnt << endl;
	return 0;
}
