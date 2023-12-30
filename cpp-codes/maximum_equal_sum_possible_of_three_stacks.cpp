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
		int n1 = 5;/*2;*/
		int n2 = 3;/*2;*/
		int n3 = 4;/*2;*/
		int a1[n1] = {3, 2, 1, 1, 1}; /*{3, 10};*/
		int a2[n2] = {4, 3, 2}; /*{4, 5};*/
		int a3[n3] = {2, 5, 4, 1}; /*{2, 1};*/

		int sum1, sum2, sum3;
		sum1 = sum2 = sum3 = 0;

		for (auto x : a1) sum1 += x;
		for (auto x : a2) sum2 += x;
		for (auto x : a3) sum3 += x;




		int ans = 0;

		int i , j , k;

		i = j = k = 0;

		while (1)
		{
			if (i == n1 || i == n2 || i == n3)
			{
				//If any of the stack is empty the answer is -1

				ans = -1;
				break;
			}

			if (sum1 == sum2 && sum2 == sum3)
			{
				ans = sum1;
				break;
			}

			if (sum1 >= sum2 && sum1 >= sum3)
			{
				sum1 -= a1[i];
				i++;
			}

			else if (sum2 >= sum1 && sum2 >= sum3)
			{
				sum2 -= a2[j];
				j++;
			}

			else if (sum3 >= sum1 && sum3 >= sum2)
			{
				sum3 -= a3[k];
				k++;
			}
		}

		cout << ans << endl;
	}
	return 0;
}
