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
#define s                            second

//Prints
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "}"; }

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
	//cin >> t;
	while (t--)
	{
		vector<int> v = {49,78,84,101,152,178,178,182,212,236,243,248,283,288,301,361,364,376,399,409,416,421,435,478,489,491,540,546,558,578,579,592,593,603,642,665,694,695,745,762,807,831,854,869,897,942,979,985,985,986,1036,1036,1071,1073,1112,1196,1203,1281,1334,1351,1386,1402,1407,1411,1419,1442,1449,1454,1454,1473,1478,1482,1493,1547,1555,1557,1589,1596,1625,1685,1710,1713,1725,1747,1768,1796,1797,1815,1856,1866,1871,1913,1920,1927,1930,1939,1974,1976,1984,1991,2000};
		int k = 985;
		auto lb = lower_bound(v.begin(),v.end(),k);
		auto ub = upper_bound(v.begin(),v.end(),k);
		cout << lb - v.begin() << endl;
		cout << ub - v.begin() << endl;
	}
	return 0;
}
