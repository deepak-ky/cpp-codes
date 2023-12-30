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
		int n = 4;
		char *sender = new char[n];
		char *receiver = new char[n];

		int pack_no = 1;

		sender[0] = 'D';
		sender[1] = 'A';
		sender[2] = 'D';
		sender[3] = 'X';

		receiver[0] = 'D';
		receiver[1] = 'A';
		receiver[2] = 'D';
		receiver[3] = 'A';

		int i = 0;
		int j = 0;

		bool receiver_side = true;

		cout << "SENDER : Sending Data Packet : " << pack_no;
		cout << endl;

		while (i < 4 && j < 4)
		{
			if (receiver_side)
			{
				if (sender[i] == receiver[j])
				{
					cout << "RECEIVER : Data Packet : " << pack_no << "  received";
					cout << endl;
					j++;
					i++;
					cout << "RECEIVER : Sending Acknowledgement for data Packet : " << pack_no << endl;
				}
				cout << endl << endl;
				receiver_side = false;
			}
			else
			{
				if (sender[i] == receiver[j])
				{
					cout << "SENDER : Acknowledgement for data packet : " << pack_no << " received";
					i++;
					j++;
					cout << endl;
					pack_no++;
					cout << "SENDER : Sending Data Packet : " << pack_no;
					cout << endl;
				}
				else
				{
					cout << "SENDER : Acknowledgement for data packet : " << pack_no << " NOT received";
					break;

				}
				cout << endl << endl;
				receiver_side = true;
			}

		}
	}
	return 0;
}
