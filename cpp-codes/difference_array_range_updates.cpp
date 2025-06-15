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

void update(int l,int r,int x,vector<int> &d){
	d[l] += x;
	if(r+1 < d.size()){
		d[r+1] -= x;
	}
}

void printArray(vector<int> v, vector<int> d){
	for(int i=1;i<d.size();i++){
		d[i] += d[i-1];
	}

	for(int i=0;i<v.size();i++){
		cout << v[i] + d[i] << " , ";
	}

	cout << endl;
}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		// Watch Priyansh Agarwal Video on this quite helpful
		// https://www.youtube.com/watch?v=96RG7EBF8LI&ab_channel=TLEEliminators-byPriyansh
		vector<int> v = {10,5,20,40};
		int n = v.size();
		vector<int> d(n,0);

		printArray(v,d);
		update(0,1,10,d);
		printArray(v,d);

		update(1,3,20,d);
		update(2,2,30,d);
		printArray(v,d);


		/*
		0 	0 	0 	 0

		update(0,1,10,d);
		10  0 	-10  0
		preSum => 10 10 0 0 
		and that is correct because I want to add 10 to both indcies 0 and 1
	
		update(1,3,20,d);
		10 20 -10 0
		preSum => 10 30 20 20
		and that is correct because I want ot add 20 to indices 1 to 3, so index 1 would have now (+10+20)
		and index 2 and index 3 would have +20 and +20
		
		update(2,2,30,d);
		10 20 20 -30
		preSum => 10 30 50 20
		index 0 -> +10      = 10
		index 1 -> +10 +20	= 30
		index 2 -> +20 +30	= 50
		index 3 -> +20 		= 20
		which are the correct values

		Time complexty of final status => O(n) + O(q) // O(q) to process all queries // O(n) to build the final array
		*/

	}
	return 0;
}
