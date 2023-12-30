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
class str
{
public:
	char ch;
	int len;
};
bool compare(str s1, str s2)
{
	return s1.len <= s2.len;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	str strings[4];
	string s1; cin >> s1; auto it1 = s1.begin(); s1.erase(it1); s1.erase(it1);
	strings[0].ch = 'A';
	int s1_len = s1.length();
	strings[0].len = s1_len;
	string s2; cin >> s2; auto it2 = s2.begin(); s2.erase(it2); s2.erase(it2);
	strings[1].ch = 'B';
	int s2_len = s2.length();
	strings[1].len = s2_len;
	string s3; cin >> s3; auto it3 = s3.begin(); s3.erase(it3); s3.erase(it3);
	strings[2].ch = 'C';
	int s3_len = s3.length();
	strings[2].len = s3_len;
	string s4; cin >> s4; auto it4 = s4.begin(); s4.erase(it4); s4.erase(it4);
	strings[3].ch = 'D';
	int s4_len = s4.length();
	strings[3].len = s4_len;
	sort(strings, strings + 4, compare);
	/*	for (int i = 0; i < 4; i++)
		{
			cout << strings[i].ch << " " << strings[i].len << "\n";
		}*/
	bool condition_1 = false;
	if ((2 * strings[0].len) <= (strings[1].len)) condition_1 = true;
	bool condition_2 = false;
	if ((2 * strings[2].len) <= (strings[3].len)) condition_2 = true;
	if ((condition_1) && (condition_2))
	{
		cout << "C";
	}
	else if (condition_1)
	{
		cout << strings[0].ch;
	}
	else if (condition_2)
	{
		cout << strings[3].ch;
	}
	else cout << "C";











	return 0;
}
