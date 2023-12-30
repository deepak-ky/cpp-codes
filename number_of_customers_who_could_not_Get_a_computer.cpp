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

		int n = 3;
		//cin >> n;

		string sequence = "GACCBGDDBAEE";
		//cin >> sequence;

		int cnt = 0;
		int ans = 0;

		unordered_map<char, int> using_comp;
		//0  -> has departed after using a computer // not arrived till now
		//1  -> already using a computer
		//2  -> waiting in queue for a computer

		for (int i = 0; i < sequence.length(); i++)
		{
			char person = sequence[i];
			//wer(person);

			//If that person is currently using any computer
			if (using_comp[person] == 1)
			{
				//number of computers being used will decrement by 1
				cnt--;
				using_comp[person] = 0;
			}
			else if (using_comp[person] == 0)
			{
				//if it is a new person
				if (cnt == n)
				{
					//all the computers are now being used
					ans++;
					using_comp[person] = 2;

				}
				else
				{
					cnt++;
					using_comp[person] = 1;
				}
			}
			else
			{
				using_comp[person] = 0;
			}


			/*	wer(using_comp[person]);
				wer(cnt);
				wer(ans);
				cout << "---------------" << endl;*/
		}

		cout << ans << endl;
	}
	return 0;
}
