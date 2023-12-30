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
		string s;
		cin >> s;
		int x1 = 0;
		int y = 0;
		bool flag = false;
		for(auto &x : s){
			if(x == 'U'){
				y++;
			}else if(x == 'D'){
				y--;
			}else if(x == 'R'){
				x1++;
			}else if(x == 'L'){
				x1--;
			}

			if(x1 == 1 && y == 1){
				flag = true;
				break;
			}

			//wer(x1);
			//wer(y);
		}

		if(flag){
			yes;
		}else{
			no;
		}

	}
	return 0;
}
