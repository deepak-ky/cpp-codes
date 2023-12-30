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

const int N = 5;
int dp[N][N];

int get_minimum_time(int line_no, int idx, int a[][4], int time[][4], int entry_time[], int exit_time[])
{

	if (dp[line_no][idx] != -1)
	{
		return dp[line_no][idx];
	}



	if (idx == 3)
	{
		return dp[line_no][idx] = a[line_no][idx] + exit_time[line_no];
	}


	//At every point of time I have two options whether to move into the same
	//one or change


	int opt1 = a[line_no][idx] + get_minimum_time(line_no, idx + 1, a, time, entry_time, exit_time);
	int opt2 = a[line_no][idx] + time[line_no][idx + 1] + get_minimum_time(1 - line_no, idx + 1, a, time, entry_time, exit_time);


	return dp[line_no][idx] = min(opt1, opt2);

}



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		int entry_time[2] = {10, 12};
		int exit_time[2]  = {18, 7};

		int a[2][4] = {{4, 5, 3, 2},
			{2, 10, 1, 4}
		};

		int time[2][4] = {{0, 7, 4, 5},
			{0, 9, 2, 8}
		};

		memset(dp, -1, sizeof(dp));


		int opt1 = entry_time[0] + get_minimum_time(0, 0, a, time, entry_time, exit_time);
		int opt2 = entry_time[1] + get_minimum_time(1, 0, a, time, entry_time, exit_time);

		cout << min(opt1, opt2);

	}
	return 0;
}
