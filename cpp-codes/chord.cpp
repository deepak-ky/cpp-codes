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
int dist_between(int a, int b)
{
	if (b >= a) return b - a;
	else return 12 - (a - b);
}
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	map<string, int> mp;
	mp["C"] = 0;
	mp["C#"] = 1;
	mp["D"] = 2;
	mp["D#"] = 3;
	mp["E"] = 4;
	mp["F"] = 5;
	mp["F#"] = 6;
	mp["G"] = 7;
	mp["G#"] = 8;
	mp["A"] = 9;
	mp["B"] = 10;
	mp["H"] = 11;
	int pos[3];
	for (int i = 0; i < 3; i++)
	{
		string temp;
		cin >> temp;
		pos[i] = mp[temp];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j) continue;
			for (int k = 0; k < 3; k++)
			{
				if (k == i || k == j) continue;
				if ((dist_between(pos[i], pos[j]) == 4 ) && (dist_between(pos[j], pos[k]) == 3 ))
				{
					cout << "major";
					return 0;
				}
				else if ((dist_between(pos[i], pos[j]) == 3) && (dist_between(pos[j], pos[k]) == 4 ))
				{
					cout << "minor";
					return 0;
				}
			}
		}

	}
	cout << "strange";
	return 0;
}
