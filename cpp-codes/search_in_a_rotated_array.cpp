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

int searh_in_rotated_array(int *a, int l, int h, int key)
{
	if (l > h)
	{
		return -1;
	}

	int mid = l + ((h - l) / 2);

	if (a[mid] == key)
	{
		return mid;
	}
	if (a[l] <= a[mid])
	{

		//If this happens then the first part of the array is sorted
		//and the pivot lies in the second part of the array , from mid+1 to h
		if (key >= a[l] && key <= a[mid])
		{
			return searh_in_rotated_array(a, l, mid, key);
		}
		else
		{
			return searh_in_rotated_array(a, mid + 1, h, key);
		}
	}
	else  //If the first part is not sorted then the second part must be sorted
	{
		if (key >= a[mid + 1] && key <= a[h])
		{
			return searh_in_rotated_array(a, mid + 1, h, key);
		}
		else
		{
			return searh_in_rotated_array(a, l, mid, key);
		}
	}


}



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		int key;
		cin >> key;

		cout << searh_in_rotated_array(a, 0, n - 1, key);

	}
	return 0;
}
