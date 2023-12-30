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

int find_sum_of_number(int n)
{
	int sum = 0;
	while (n > 0)
	{
		int r = n % 10;
		sum += r;
		n = n / 10;
	}
	return sum;
}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		int *cnt = new int[48] {0};
		int curr = find_sum_of_number(a);
		cnt[curr]++;
		curr++;
		for (int i = a + 1; i <= b; i++)
		{
			if (i % 10 == 0)
			{
				curr = find_sum_of_number(i);
				cnt[curr]++;
				curr++;
			}
			else
			{
				cnt[curr]++;
				curr++;
			}
		}

		int max = 0;
		int max_cnt = 0;
		for (int i = 1; i < 48; i++)
		{
			if (cnt[i] > max_cnt)
			{
				max_cnt = cnt[i];
				max = i;
			}
		}
		for (int i = 0; i < 48; i++)
		{
			cout << i << " -> " << cnt[i] << endl;
		}
		cout << max_cnt << endl;

	}
	return 0;
}
