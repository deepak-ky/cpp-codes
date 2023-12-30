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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int len;
	cin >> len;
	string a;
	cin >> a;
	int first_right_index = -1;
	int last_right_index = -1;

	int first_left_index = -1;
	int last_left_index = -1;

	for (int i = 0; i < len; i++)
	{
		if (a[i] == 'R')
		{
			first_right_index = i;
			break;
		}
	}
	for (int i = 0; i < len; i++)
	{
		if (a[i] == 'R')
		{
			last_right_index = i;

		}
	}
	for (int i = 0; i < len; i++)
	{
		if (a[i] == 'L')
		{
			first_left_index = i;
			break;
		}
	}
	for (int i = 0; i < len; i++)
	{
		if (a[i] == 'L')
		{
			last_left_index = i;

		}
	}
	/*wer(first_right_index);
	wer(last_right_index);
	wer(first_left_index);
	wer(last_left_index);*/
	if (first_left_index == -1)
	{
		first_right_index++;
		last_right_index++;
		cout << first_right_index << " " << last_right_index + 1;
	}
	else if (first_right_index == -1)
	{
		//cout << "here";
		last_left_index++;
		first_left_index++;
		cout << last_left_index << " " << first_left_index - 1;
	}
	else
	{
		first_right_index++;

		first_left_index++;

		cout << first_right_index << " " << first_left_index - 1;
	}


	return 0;
}
