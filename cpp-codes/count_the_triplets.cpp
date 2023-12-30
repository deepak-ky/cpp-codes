#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define asdff(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int count_of_triplet(int *a, int s, int e, int x)
{
	int cnt = 0;
	while (s < e)
	{
		int w = a[s] + a[e];
		if (x == w)
		{
			s++;
			e--;
			cnt++;
		}
		else if (w < x)
		{
			s++;
		}
		else e--;
	}
	return cnt;
}
int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	int a[n];
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int w;
		cin >> w;
		a[i] = w;
		v.push_back(w);
	}
	// int max_ele = *max_element(a, a + n);
	// map<int, int> freq;
	// for (int i = 0; i <= max_ele; i++)
	// {
	// 	freq[i] = 0;
	// }
	// for (int i = 0; i < n; i++)
	// {
	// 	freq[a[i]]++;
	// }
	// // for (auto x : freq)
	// // {
	// // 	cout << x.first << " " << x.second << endl;
	// // }
	// int ans = 0;

	// //case 1 : 0,0,0
	// int freq_0 = (freq[0] * (freq[0] - 1) * (freq[0] - 2)) / 6;
	// ans += freq_0;

	// //case 2 : 0,x,x

	// for (int i = 1; i <= max_ele; i++)
	// {
	// 	int freq_1 = (freq[i] * (freq[i] - 1)) / 2;
	// 	ans  += freq[0] * freq_1;
	// }

	// //case 3 : x,x,2x

	// for (int i = 1; i * 2 <= max_ele; i++)
	// {
	// 	int freq_1 = (freq[i] * (freq[i] - 1)) / 2;
	// 	ans += freq_1 * freq[2 * i];
	// }

	// //case 4 : x,y,x+y
	// for (int i = 1; i <= max_ele; i++)
	// {
	// 	for (int j = (i + 1); (j + i) <= max_ele; j++)
	// 	{
	// 		int freq_1 = freq[i] * freq[j] * freq[i + j];
	// 		ans += freq_1;
	// 	}
	// }
	sort(a, a + n);

	//considering all the elements occur only once in the array and no 0 element is present
	int ans = 0;
	for (int i = 2; i < n; i++)
	{

		ans += count_of_triplet(a, 0, i - 1, a[i]);

	}
	cout << ans << endl;
	return 0;
}
