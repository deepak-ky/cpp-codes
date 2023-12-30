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
		int n,m,d;
		cin >> n >> m >> d;
		map<int,int> indexes;
		for(int i=0;i<n;i++){
			int w;
			cin >> w;
			indexes[w] = i;
		}

		int a[m];
		for(int i=0;i<m;i++){
			cin >> a[i];
		}

		bool flag = false;

		int ans = INT_MAX;
		for(int i=0;i<m-1;i++){
			int index1 = indexes[a[i]];
			int index2 = indexes[a[i+1]];
			//wer(index1);
			//wer(index2);

			if((index1 < index2) && (index2 <= (index1 + d))){

				//paas leke aake swap karte hain
				int ans1 = index2 - index1;
				//dur le jaake swap karte hain
				int left_swaps = index1;
				int right_swaps = (n - (index2+1));
				int ans2 = INT_MAX;
				if((left_swaps+right_swaps) >= ((d+1)-ans1)){
					ans2 = ((d+1)-ans1);
				}

				ans = min(ans,min(ans1,ans2));

			}else{
				flag = true;
				break;
			}
		}

		if(flag){
			cout << 0 << endl;
		}else{
			cout << ans << endl;
		}
	}
	return 0;
}
