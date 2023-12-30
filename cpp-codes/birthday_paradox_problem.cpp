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
	//we want the probability of two people having the same birthday to be greater than
	//50 , ie , we want it to be atleast 50 %
	float t = 365;
	float p = 1;
	float n = 1;
	float thresold;
	//cout << "Input the probability that is needed for people to have same birthday : ";
	cin >> thresold;
	thresold = thresold / 100; //assuming the input is in percentage
	if (thresold == 1)
	{
		cout << 366;
	}
	else
	{
		while ( thresold  > (1 - p) )
		{
			float w = 365 - n;
			w = w / 365;
			p = p * w;
			n++;

		}
		cout << "\nAnswer : " << n << endl;
	}
	return 0;
}
