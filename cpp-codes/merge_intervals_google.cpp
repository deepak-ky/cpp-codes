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

bool customSort(const vector<int> &v1, const vector<int> &v2) {
	if(v1[0] < v2[0]){
		return true;
	}else if(v1[0] == v2[0]){
		if(v1[1] > v2[1]){
			return true;
		}
		return false;
	}

	return false;
}

bool customSort2(const vector<int> &v1, const vector<int> &v2) {
	if(v1[1] < v2[1]){
		return true;
	}else if(v1[1] == v2[1]){
		if(v1[0] < v2[0]){
			return true;
		}
		return false;
	}

	return false;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	vector<vector<int>> ans;
	sort(intervals.begin(), intervals.end(), customSort);
	//sort(intervals.begin(),intervals.end()); -> works with this also

	int start = intervals[0][0];
	int end = intervals[0][1];

	int i=1;
	while(i < intervals.size()){
		if(end < intervals[i][0]){
			ans.push_back({start,end});
			start = intervals[i][0];
			end = intervals[i][1];
			i++;
		}else{
			end = max(end,intervals[i][1]);
			i++;
		}
	}  

	ans.push_back({start,end});
	return ans; 
}


/*
	Sorting on the basis of endpoint would not work in this case
	[2,3], [4,9], [1,14]
	--> output 		  => [2,3],[1,14]
	--> actual output => [1,14]
*/


int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		//vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
		vector<vector<int>> intervals = {{2,9},{1,15}};
		vector<vector<int>> mergedIntervals = merge(intervals);

		for(auto &x : mergedIntervals) {
			cout << x[0] <<"," << x[1] << endl;
		}

	}
	return 0;
}
	