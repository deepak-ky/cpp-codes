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



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		//make an character array of size 256
		//make an map
		//make a boolean map

		// if two adjacent are same then duplicate
		string s;
		cin >> s;

		bool duplicates = false;



		//N2 Approach -> compare every character with every character


		//Are able to modify a string

		/*sort(s.begin(), s.end());
		for(i=0;i<s.size()-1;i++)
		{
			if(s[i] == s[i+1])
			{
				duplicates = true;
				break;

			}
		}*/



		//With using extra space
		bool *store = new bool[128];

		for (int i = 0; i < 128; i++) store[i] = false;

		for (int i = 0; i < s.size(); i++)
		{
			char a = s[i];
			int b = a;
			if (store[b] == true)
			{
				duplicates = true;
				break;
			}
			store[b] = true;
		}




		if (duplicates)
		{
			no;
		}
		else yes;
	}
	return 0;
}
