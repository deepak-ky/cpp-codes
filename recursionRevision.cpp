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


//1. Find all subset sums
vector<int> ans;
void findSubsetSum(int idx,vector<int> &arr,int n,int sum_till_now){
	if(idx == n){
		ans.push_back(sum_till_now);
		return;
	}

	findSubsetSum(idx+1,arr,n,sum_till_now);
	findSubsetSum(idx+1,arr,n,sum_till_now+arr[idx]);
}
vector<int> findAllSubsetSums(vector<int> &arr,int n){
	ans.clear();
	findSubsetSum(0,arr,n,0);
	return ans;
}


//2. Find all subsets(without duplicates) - pass by value (actually there is no requirement of set in this one)
// since all the elements are unique, there will by default be no same vectors
/*set<vector<int>> s;
void findSubsets(int idx,vector<int> v,vector<int> &nums){
	if(idx == nums.size()){
		s.insert(v);
		return;
	}

	findSubsets(idx+1,v,nums);
	v.push_back(nums[idx]);
	findSubsets(idx+1,v,nums);
	return;
}
vector<vector<int>> subsets(vector<int> &nums){
	s.clear();
	vector<int> v;
	findSubsets(0,v,nums);

	vector<vector<int>> ans;
	for(auto &x : s){
		ans.push_back(x);
	}
	return ans;
}*/


// pass by reference
void findSubsets(vector<vector<int>> &ans,vector<int> &nums,int idx,vector<int> &v){
	if(idx == nums.size()){
		ans.push_back(v);
		return;
	}

	findSubsets(ans,nums,idx+1,v);
	v.push_back(nums[idx]);
	findSubsets(ans,nums,idx+1,v);
	v.pop_back();
	return;
}
vector<vector<int>> subsets(vector<int> &nums){
	vector<vector<int>> ans;
	vector<int> v;
	findSubsets(ans,nums,0,v);
	return ans;
}


//3. Find all subsets with duplicates
// can be done using set also --> https://leetcode.com/submissions/detail/958895656/
// cannot use pass by reference in this one because , we are sorting in base case, which changes the last element
void findSubsetsWithDup(map<vector<int>,bool> &mp,vector<vector<int>> &ans,vector<int> &nums,int idx,vector<int> v){
	if(idx == nums.size()){
		sort(v.begin(),v.end());
		if(mp.find(v) == mp.end()){
			ans.push_back(v);
			mp[v] = true;
		}
		return;
	}

	findSubsetsWithDup(mp,ans,nums,idx+1,v);
	v.push_back(nums[idx]);
	findSubsetsWithDup(mp,ans,nums,idx+1,v);
	return;
}
vector<vector<int>> subsetsWithDup(vector<int> &nums){
	vector<vector<int>> ans;
	map<vector<int>,bool> mp;
	vector<int> v;
	findSubsetsWithDup(mp,ans,nums,0,v);
	return ans;
}



//4. Combination Sum 1
// void findCombinationSum1(vector<vector<int>> &ans,vector<int>& nums, int t,int idx,vector<int> v){
// 	if(t == 0){
// 		ans.push_back(v);
// 		return;
// 	}
// 	if(idx == nums.size()){
// 		return;
// 	}

// 	while(t >= 0){
// 		findCombinationSum1(ans,nums,t,idx+1,v);
// 		t -= nums[idx];
// 		v.push_back(nums[idx]);
// 	}

// 	return;
// }

// vector<vector<int>> combinationSum(vector<int>& nums,int target){
// 	vector<vector<int>> ans;
// 	vector<int> v;
// 	findCombinationSum1(ans,nums,target,0,v);
// 	return ans;
// }

// Approach - 2, using other approach
// the basic approach is simple, I am having a lenght X and I want to make length X+1 
// I will try to make it using the given numbers that I have in front on me
// In this case when I can repeat I am passing i and in the next case when I cannot repeat I am passing i+1
void findCombinationSum1(vector<vector<int>> &ans,vector<int>& nums, int t,int idx,vector<int> v){
	if(t == 0){
		ans.push_back(v);
		return;
	}
	if(idx == nums.size()){
		return;
	}

	for(int i=idx;i<nums.size();i++){
		if(nums[i] > t) break;
		v.push_back(nums[i]);
		findCombinationSum1(ans,nums,t-nums[i],i,v); // here we are passing i and not i+1
		v.pop_back();
	}

	return;
}

vector<vector<int>> combinationSum(vector<int>& nums,int target){
	vector<vector<int>> ans;
	vector<int> v;
	sort(nums.begin(),nums.end());
	findCombinationSum1(ans,nums,target,0,v);
	return ans;
}

//5. Combination Sum 2 // This method is not correct and gives TLE (constraints are changed on leetcode)
// void findCombinationSum2(set<vector<int>> &s,vector<int>& nums, int t,int idx,vector<int> v){
// 	if(t == 0){
// 		sort(v.begin(),v.end());
// 		s.insert(v);
// 		return;
// 	}
// 	if(idx == nums.size()){
// 		return;
// 	}

// 	findCombinationSum2(s,nums,t,idx+1,v);
// 	if((t - nums[idx]) >= 0){
// 		t -= nums[idx];
// 		v.push_back(nums[idx]);
// 		findCombinationSum2(s,nums,t,idx+1,v);
// 	}

// 	return;
// }

// vector<vector<int>> combinationSum2(vector<int>& nums,int target){
// 	set<vector<int>> s;
// 	vector<int> v;
// 	findCombinationSum2(s,nums,target,0,v);

// 	vector<vector<int>> ans;
// 	for(auto &x : s) ans.push_back(x);
// 	return ans;
// }

void findCombinationSum2(vector<vector<int>> &ans,vector<int>& nums, int t,int idx,vector<int> v){     
	if(t == 0){
		ans.push_back(v);
		return;
	}
	if(idx == nums.size()){
		return;
	}

	for(int i=idx;i<nums.size();i++){
		if(i>idx && nums[i] == nums[i-1]) continue;
		if(nums[i] > t) break;
		v.push_back(nums[i]);
		findCombinationSum2(ans,nums,t-nums[i],i+1,v);
		v.pop_back();
	}
	return;
}

vector<vector<int>> combinationSum2(vector<int>& nums,int target){
	sort(nums.begin(),nums.end());
	vector<vector<int>> ans;
	vector<int> v;
	findCombinationSum2(ans,nums,target,0,v);
	return ans;
}

bool isSubstring(string s){
	if(s.length() == 1) return true;
	int n = s.length();
	int w = n/2;
	for(int i=0;i<=w;i++){
		if(s[i] != s[n-1-i]) return false;
	}
	return true;
}

void makeCuts(vector<vector<string>> &ans, string s,int idx, vector<string> v){
	if(idx == s.length()){
		ans.push_back(v);
	}

	for(int i=idx;i<s.length();i++){
		string str = s.substr(idx,(i-idx+1));
		if(isSubstring(str)){
			v.push_back(str);
			makeCuts(ans,s,i+1,v);
			v.pop_back();
		}
	}

	return;
}

vector<vector<string>> partition(string s){
	vector<string> v;
	vector<vector<string>> ans;
	makeCuts(ans,s,0,v);
	return ans;
}

int cnt;
string anss;
void findPermutation(int n,vector<bool> &vis,string &s,int k,int nums_left){
	if(nums_left == 0){
		cnt++;
		if(cnt == k){
			anss = s;
		}
		return;
	}

	if(anss != "") return;

	for(int i=1;i<n+1;i++){
		if(vis[i] == false){
			vis[i] = true;
			s.push_back(char(i + 48));
			findPermutation(n,vis,s,k,nums_left-1);
			s.pop_back();
			vis[i] = false;
		}
		//if(anss != "") return;
 	}

	return;
}
// Lesson learnt
// Do not do parameters changes inside function call
// Wherever possible pass by reference

string getPermutation(int n,int k){
	vector<bool> vis(n+1,false);
	cnt = 0;
	anss = "";
	string s = "";
	findPermutation(n,vis,s,k,n);
	return anss;
}




int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		// vector<int> v1 = {1,2,3};
		// vector<int> v = findAllSubsetSums(v1,3);
		// for(auto &x : v){
		// 	cout << x << " ";
		// }
		// cout << endl;

		// vector<int> v1 = {0,1,2};
		// vector<vector<int>> v = subsets(v1);
		// for(auto &x : v){
		// 	print_v(x);
		// }
		// cout << endl;

		// vector<int> v1 = {1,2,2};
		// vector<vector<int>> v = subsetsWithDup(v1);
		// for(auto &x : v){
		// 	print_v(x);
		// }
		// cout << endl;

		// vector<int> v1 = {2,3,5};
		// vector<vector<int>> v = combinationSum(v1,8);
		// for(auto &x : v){
		// 	print_v(x);
		// }
		// cout << endl;

		// vector<int> v1 = {10,1,2,7,6,1,5};
		// vector<vector<int>> v = combinationSum2(v1,8);
		// for(auto &x : v){
		// 	print_v(x);
		// }
		// cout << endl;

		// string s = "aaabc";
		// vector<vector<string>> v = partition(s);
		// for(auto &x : v){
		// 	for(auto &y : x){
		// 		cout << y << ",";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;

		string w = getPermutation(3,1);
		wer(w);


	}
	return 0;
}
