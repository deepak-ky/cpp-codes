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
		/*priority_queue<int,vector<int>,greater<int>> pq;
		pq.push(1);
		pq.push(2);
		pq.push(3);

		while(!pq.empty()){
			cout << pq.top() << " ";
			pq.pop();

		}

		cout << endl;

		priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq1;
		pq1.push({1,3});
		pq1.push({2,2});
		pq1.push({3,1});

		while(!pq1.empty()){
			cout << pq1.top().first << "," << pq1.top().second << endl;
			pq1.pop();

		}*/


		// vector<int> a = {1,2,3,4,5};
		// for(int i=0;i<a.size()/2;i++){
		// 	swap(a[i],a[a.size()-1-i]);
		// }
		// cout << endl;
		// for(auto &x : a) cout << x << " ";


		/*vector<int> occur(256,-1);

		occur['a'] = 35;
		occur[' '] = 34;
		occur['1'] = 23;

		for(int i=0;i<256;i++){
			cout << i << " -> " << occur[i] << endl;
		}*/

		vector<int> v(1000000001);

	}
	return 0;
}
