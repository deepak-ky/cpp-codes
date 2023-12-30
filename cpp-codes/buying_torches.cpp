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
	test
	{
		int x , y , n;
		cin >> x >> y >> n;
		//to make n torches I need to have n sticks and n coals
		//2 , 1 , 5
		//price of one coal is y stick
		//price on n coal is n * y sticks
		//total number of sticks required are n + (n*y)
		//total number of move are  n + ... (n because buying one coal in each operation)
		//after one move total number of sticks that I have are  prev_total  - 1 + x
		int total_sticks = n + n * y;
		int moves;
		if ((total_sticks - 1) % (x - 1) == 0)
		{
			moves = (total_sticks - 1) / (x - 1) ;
		}
		else
		{
			moves = (total_sticks - 1) / (x - 1) + 1;

		}
		cout << moves + n << endl;
	}
	return 0;
}
