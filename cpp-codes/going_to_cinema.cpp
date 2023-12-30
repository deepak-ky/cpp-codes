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
	cin >> t;
	while (t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		sort(a,a+n);
		vector<bool> can_take(n,false);
		for(int i=0;i<n;i++){
			//number of people already been taken is : i
			if(i >= a[i]){
				can_take[i] = true;
			}

		}

		int cnt = 0;

		for(int i=0;i<n;i++){
			if(i == 0){
				if(a[0] == 0 && can_take[0]){
					cnt++;
				}
			}else if(can_take[i-1] == false && can_take[i] == true){
				cnt++;
			}
		}

		if(a[0] > 0) cnt++;

		cout << cnt << endl;

	}
	return 0;
}
