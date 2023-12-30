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
#define se                           second

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
		int l_limit;
		cin >> l_limit;
		int h_limit;
		cin >> h_limit;
		cout << "INPUT DOMAINS : ";
		cout << endl;
		int cnt = 1;
		for (int x = 0; x < 3; x++)
		{

			for (int y = 0; y < 3; y++)
			{

				for (int z = 0; z < 3; z++)
				{
					cout << "E" << cnt << " : ";
					cnt++;
					cout << "\t";
					if (x == 1)
					{
						cout << l_limit << "<= x <= " << h_limit << "\t\t";
					}
					else if (x == 2)
					{
						cout << "x > " << h_limit << "\t\t";
					}
					else if (x == 0)
					{
						cout << "x < " << l_limit << "\t\t";
					}
					if (y == 1)
					{
						cout << l_limit << "<= y <= " << h_limit << "\t\t";
					}
					else if (y == 2)
					{
						cout << "y > " << h_limit << "\t\t";
					}
					else if (y == 0)
					{
						cout << "y < " << l_limit << "\t\t";
					}
					if (z == 1)
					{
						cout << l_limit << "<= z <= " << h_limit << "\t\t";
					}
					else if (z == 2)
					{
						cout << "z > " << h_limit << "\t\t";
					}
					else if (z == 0)
					{
						cout << "z < " << l_limit << "\t\t";
					}

					cout << "(";
					if (x != 1)
					{
						cout << "Invalid" << " ";
					}
					else cout << "Valid" << " ";
					cout << ",";
					if (y != 1)
					{
						cout << "Invalid" << " ";
					}
					else cout << "Valid" << " ";
					cout << ",";
					if (z != 1)
					{
						cout << "Invalid" << " ";
					}
					else cout << "Valid" << " ";
					cout << ") ";
					cout << endl;
					cout << endl;

				}
			}

		}
		cout << endl;
		cnt = 1;
		cout << "INPUT TEST CASES : ";
		cout << endl << endl;
		int *a = new int[3];
		a[0] = l_limit - 1;
		a[1] = l_limit + ((h_limit - l_limit) / 2);
		a[2] = h_limit + 1;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					cout << "T" << cnt << " : ";
					cnt++;
					cout << "\t" << a[i] << "\t" << a[j] << "\t" << a[k];
					cout << "\t\t";
					if (i != 1 || j != 1 || k != 1)
					{
						cout << "Input Values out of Range";
					}
					else cout << max(a[i], max(a[j], a[k]));
					cout << endl;
				}
			}
		}


		cout << endl << endl << "OUTPUT DOMAINS";
		cout << endl;
		cout << endl;
		cout << "O1 : " << " Largest among the three numbers";
		cout << endl;
		cout << "O2 : " << " Input Values is/are out of Range";
		cout << endl;

		cout << endl << endl << "Output Test cases : ";
		cout << endl << endl;
		int i = 0;
		bool valid_values = true;
		cnt = 1;
		while (cnt < 3)
		{
			cout << "O" << cnt << " : ";
			if (valid_values)
			{
				cout << "\t" << a[1] << "\t" << a[1] << "\t" << a[1] << "\t\t" << max(a[1], max(a[1], a[1]));
				cout << endl;
				valid_values = false;
			}
			else {
				cout << "\t" << a[2] << "\t" << a[1] << "\t" << a[1] << "\t\t" << "Input Values out of Range";
				cout << endl;
			}
			cnt++;
		}






	}
	return 0;
}
