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
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}

		int two_cnt_left[n];
		int two_cnt_right[n];

		for(int i=0;i<n;i++){
			if(i == 0){
				if(a[i] == 2){
					two_cnt_left[i] = 1;
				}else{
					two_cnt_left[i] = 0;
				}
			}else{
				two_cnt_left[i] = two_cnt_left[i-1];
				if(a[i] == 2){
					two_cnt_left[i]++;
				}			
			}
		}


		for(int i=n-1;i>=0;i--){
			if(i == n-1){
				if(a[i] == 2){
					two_cnt_right[i] = 1;
				}else{
					two_cnt_right[i] = 0;
				}
			}else{
				two_cnt_right[i] = two_cnt_right[i+1];
				if(a[i] == 2){
					two_cnt_right[i]++;
				}			
			}
		}

		int ans = -1;
		for(int i=0;i<n-1;i++){
			if(two_cnt_left[i] == two_cnt_right[i+1]){
				ans = i+1;
				break;
			}
		}

		cout << ans << endl;
	}
	return 0;
}
