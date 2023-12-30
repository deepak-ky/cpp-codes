#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long

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

		//FLAG SEQUENCE  = 01111110
		char flag[9] = "0110";
		//ESCAPE SEQUENCE = '\t'

		char bits[100];


		cout << "Enter the bits : ";
		cin >> bits;
		int n = 0;
		for (int i = 0; bits[i] != '\0'; i++)
		{
			n++;
		}


		cout << "Before bit stuffing : ";
		cout << bits << " " << endl;


		cout << "After bit stuffing : ";

		for (int i = 0; i < n; i++)
		{
			if (bits[i] == '0')
			{
				if ((i + 3 < n))
				{
					if (bits[i + 1] == '1' && bits[i + 2] == '1' && bits[i + 3] == '0')
					{
						cout << "ESC";

					}
				}
			}
			else if (bits[i] == 'E')
			{
				if ((i + 2 < n))
				{
					if (bits[i + 1] == 'S' && bits[i + 2] == 'C')
					{
						cout << "ESC";

					}
				}
			}
			cout << bits[i];
		}



	}
	return 0;
}
