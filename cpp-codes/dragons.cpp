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
	int dragon;
	int bonus;
};
bool compare(str s1, str s2)
{
	return s1.dragon < s2.dragon;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int s, n;
	cin >> s >> n;
	str xy[n];
	for (int i = 0; i < n; i++)
	{
		cin >> xy[i].dragon >> xy[i].bonus;
	}


	sort(xy, xy + n, compare);
	// for (int i = 0; i < n; i++)
	// {
	// 	cout << xy[i].dragon << " ";
	// }
	// cout << endl;
	// for (int i = 0; i < n; i++)
	// {
	// 	cout << xy[i].bonus << " ";
	// }
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (s > (xy[i].dragon))
		{
			s += xy[i].bonus;
			cnt++;
		}
		else break;
	}
	//wer(cnt);
	if ( cnt == (n) )
	{
		cout << "YES";
	}
	else cout << "NO";
	return 0;
}
