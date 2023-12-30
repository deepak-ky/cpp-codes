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
	int n;
	cin >> n;
	int *a = new int[n];
	int sum1 = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum1 += a[i];
	}
	int n1;
	cin >> n1;
	int *a1 = new int[n1];
	int sum2 = 0;
	for (int i = 0; i < n1; i++)
	{
		cin >> a1[i];
		sum2 += a1[i];

	}
	sort(a, a + n);
	sort(a1, a1 + n1);
	// out(a, n);
	// out(a1, n1);
	int i = n - 1;
	int j = n1 - 1;
	int flag  = false;
	while (i >= 0 && j >= 0)
	{
		// wer(a[i]);
		// wer(a1[j]);
		// wer(sum1);
		// wer(sum2);
		if (sum1 == sum2)
		{
			flag = true;
			break;
		}
		else if (sum1 < sum2)
		{
			//remove some element from sum1 and add a bigger element than it from sum2
			if (a[i] < a1[j])
			{
				sum1 = sum1 - a[i] + a1[j];
				sum2 = sum2 - a1[j] + a[i];
				swap(a[i], a1[j]);
			}
			else i--;
		}
		else if (sum1 > sum2)
		{
			//remove some element from sum2 and add a bigger element than it from sum1
			if (a[i] > a1[j])
			{
				sum1 = sum1 - a[i] + a1[j];
				sum2 = sum2 - a1[j] + a[i];
				swap(a[i], a1[j]);
			}
			else j--;
		}
	}
	if (flag) cout << 1;
	else cout << "here" << 0;
	return 0;
}
