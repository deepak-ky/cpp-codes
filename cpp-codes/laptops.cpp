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
class laptop
{
public:
	int price;
	int quality;
};
bool compare(laptop l1, laptop l2)
{
	return l1.price < l2.price;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	laptop l[n];
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> l[i].price >> l[i].quality;
	}
	sort(l, l + n, compare);
	/*	for (int i = 0; i < n; i++)
		{
			cout << l[i].price << " ";
		}
		for (int i = 0; i < n; i++)
		{
			cout << l[i].quality << " ";
		}*/
	for (int i = 0; i <= (n - 2); i++)
	{
		if (((l[i].price) < (l[i + 1].price)) && ((l[i].quality) > (l[i + 1].quality)))
		{
			flag = 1;
			break;
		}
	}
	if (flag)
	{
		cout << "Happy Alex";
	}
	else cout << "Poor Alex";


	return 0;
}
