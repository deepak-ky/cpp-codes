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

bool custom_compare(vector<int> &v1,vector<int> &v2){
	if(v1[2] < v2[2]){
		return true;
	}else{
		return false;
	}
}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		// set<int> s;
		// s.insert(5);
		// s.insert(7);
		// s.insert(8);
		// s.insert(2);
		// s.insert(3);
		// s.insert(1);

		// auto f = s.begin();

		// cout << *f << endl;

		// vector<int> v1 = {1,2,3};
		// vector<int> v2 = {2,3,1};
		// vector<int> v3 = {1,3, 1};



		// vector<vector<int>> v = {v1,v2,v3};

		// sort(v.begin(),v.end(),custom_compare);

		// for(int i=0;i<v.size();i++){
		// 	for(int j=0;j<v[i].size();j++){
		// 		cout << v[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }


		// priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		// pq.push({1,2});
		// pq.push({2,3});

		// while(!pq.empty()){
		// 	auto p = pq.top();
		// 	cout << p.first << "," << p.second << endl;
		// 	pq.pop();
		// }

		int a = -2;
		int b = 3;
		cout << (a % b)+b << endl;
		
	}
	return 0;
}
