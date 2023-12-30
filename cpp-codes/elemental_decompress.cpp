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

int find_smallest_number_now(int &smallest_number_available,set<int> &numbers_used){
	while(!(numbers_used.find(smallest_number_available) == numbers_used.end())){
		smallest_number_available++;
	}
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
		map<int,int> mp;
		map<int,list<int>> original_indexes;
		bool flag = true;
		for(int i=0;i<n;i++){
			cin >> a[i];
			mp[a[i]]++;
			if(mp[a[i]] > 2){
				flag = false;
			}
			original_indexes[a[i]].push_back(i);
		}

		if((!flag) || (mp[1] > 1)){
			no;
		}else{

			int smallest_number_available = 1;
			vector<int> q1(n);
			vector<int> q2(n);
			set<int> numbers_used;
			sort(a,a+n);	
			int i = 0;
			while(i<n){
				int w = a[i];
				if(mp[w] == 1){
					numbers_used.insert(w);
					find_smallest_number_now(smallest_number_available,numbers_used);
					int orig_index = original_indexes[w].front();
					q1[orig_index] = w;
					q2[orig_index] = w;
					i++;
				}
				else{
					if(smallest_number_available >= w){
						flag = false;
						break;
					}

					int s_idx = original_indexes[w].front();
					int e_idx = original_indexes[w].back();
					q1[s_idx] = smallest_number_available;
					q1[e_idx] = w;
					q2[s_idx] = w;
					q2[e_idx] = smallest_number_available;

					numbers_used.insert(w);
					numbers_used.insert(smallest_number_available);
					find_smallest_number_now(smallest_number_available,numbers_used);
					i+=2;
				}
			}

			if (!flag){
				no;
			}else{
				yes;
				for(int i=0;i<n;i++){
					cout << q1[i] << " ";
				}
				cout << endl;
				for(int i=0;i<n;i++){
					cout << q2[i] << " ";
				}
				cout << endl;
			}

		}


	}
	return 0;
}
