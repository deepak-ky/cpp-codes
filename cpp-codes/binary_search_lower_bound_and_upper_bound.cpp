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
	int sorted_a[] = {2, 3, 4, 4, 4, 5, 6, 7};
	int n = sizeof(sorted_a) / sizeof(int);

	int key;
	cin >> key;

	bool isPresent = binary_search(sorted_a, sorted_a + n, key);
	if (isPresent) cout << "Element is present";
	else  cout << "Element is not present";

	//USE the lower bound functions only when
	//-> The element is present in the array
	//-> The array is sorted

	cout << endl;
	auto lb = lower_bound(sorted_a, sorted_a + n, key);
	cout << "Lower Bound is : " << lb - sorted_a;
	cout << endl;
	auto ub = upper_bound(sorted_a, sorted_a + n, key);
	cout << "Upper Bound is : " << ub - sorted_a;
	cout << endl;
	cout << "Freq : " << key << " in the array is : " << ub - lb;
	return 0;
}
