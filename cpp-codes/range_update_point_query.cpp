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

int find_sum_of_digits(int w){
	int sum = 0;
	while(w > 0){
		sum += (w%10);
		w = w/10;
	}
	return sum;
}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		int n,q;
		cin >> n >> q;
		int a[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}

		set<int> s;
		for(int i=0;i<n;i++){
			s.insert(i);
		}

		for(int i=0;i<q;i++){
			int w;
			cin >> w;
			if(w == 1){

				int l,r;
				cin >> l >> r;
				l--;
				r--;

				while( l<= r){
					auto w = s.lower_bound(l);
					if(w == s.end()) break;
					if( (*w) > r) break;

					int orig = a[(*w)];
					int w1 = find_sum_of_digits(a[(*w)]);

					int idx = (*w);

					if(orig == idx){
						s.erase(w);
					}


					l = idx;
				}



			}else{
				int idx;
				cin >> idx;
				idx--; 
				cout << a[idx] << endl;
			}
		}

	}
	return 0;
}
