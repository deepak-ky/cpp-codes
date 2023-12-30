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

//a is usually the element that comes later in the array
// in array = > b , a

bool compare(int a, int b)
{
	wer(a);
	wer(b);

	cout << endl;
	if (a >= b)
	{
		return true;
	}
	else return false;
}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		int a = 4, b = 6;
		/*
				string a = "23423";
				cout << a.substr(0, 4) << endl;
				cout << a.substr(5);*/
		/*int a = 1e9;
		cout << INT_MAX << endl;
		cout << a << endl;*/
		/*int a = 4;
		cout << a << endl;

		int i = 0;
		while (a != 0)
		{
			int w = a >> i;
			if (w & 1 == 1)
			{
				break;
			}
			else i++;
		}


		cout << i << endl;

		int arr[] = {1, 2, 3 ,  4, 5};

		for (int j = 0; j < 5; j++)
		{
			int w = arr[j] >> i;
			if (w & 1 == 1)
			{
				cout << arr[j] << " ";
			}


		}*/
		/*a = a >> 1;

		cout << a << endl;
		*/

	}
	return 0;
}
