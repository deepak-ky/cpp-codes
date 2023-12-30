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

int cnt;
void knap_sack(vector<int> num, int size, int idx, int curr_sum, int x)
{
	if (curr_sum == x)
	{
		cnt++;
		return;
	}
	if (curr_sum > x)
	{
		return;
	}
	if (idx == size)
	{
		return;
	}
	knap_sack(num, size, idx + 1, curr_sum + num[idx], x);
	knap_sack(num, size, idx + 1, curr_sum, x);
	return;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int x;
		cin >> x;
		int n;
		cin >> n;
		vector<int> num;
		int w = 1;
		while (1)
		{
			int d = pow(w, n);
			if (d <= x)
			{
				num.pb(d);
				w++;
			}
			else
			{
				break;
			}
		}
		//for (auto i : num) cout << i << " ";
		cnt = 0;
		int size = num.size();
		knap_sack(num, size, 0, 0, x);
		cout << cnt << endl;
	}
	return 0;
}
