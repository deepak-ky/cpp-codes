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
	//pronic_numbers();
	int pronic_num[1000];
	pronic_num[0] = 2;
	for (int i = 1; i < 1000; i++)
	{
		pronic_num[i] = (i + 1) * (i + 2);
	}
	out(pronic_num, 30);
	//pronic numbers can also be found out if y = int(sqrt(num)) then y*(y+1) should be equal to the number
	string s;
	cin >> s;
	int n = s.length();
	set<int> st;
	int i = 0;
	int j = 0;
	int flag = 0;
	while (j < n)
	{
		/*wer(i);
		wer(j);*/
		string str = s.substr(j, 1);
		int t = stoi(str);
		//cout << endl << t;
		if (!(t & 1))
		{	//cout << "\ninside if condition is getting executed!!";
			while (i <= j)
			{
				string str1 = s.substr(i, (j - i + 1));
				int x = stoi(str1);
				//cout << endl << x ;
				bool ispresent = binary_search(pronic_num, pronic_num + 1000, x);
				if (ispresent)
				{
					flag = 1;
					st.insert(x);
				}
				i++;
			}
			i = 0;
			//wer(i);
			//wer(j);
		}
		j++;
	}
	if (flag)
	{
		for (auto y : st)
		{
			cout << y << " ";
		}
	}
	else cout << -1;
	return 0;
}
