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


//1. Kth largest element, maintain a min heap of size k

//2. Maximum Sum Combination
vector<int> maxCombinations(int n,int k,vector<int> &a,vector<int> &b){
	set<pair<int,pair<int,int>>> s;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int n1 = a.size();
	int n2 = b.size();
	s.insert({a[n1-1] + b[n2-1],{n1-1,n2-1}});
	int idx = 0;
	vector<int> ans;
	while(idx < k){
		auto itr = s.end();
		itr--;
		pair<int,pair<int,int>> p = *itr;
		s.erase(itr);
		ans.push_back(p.first);

		int i = p.second.first;
		int j = p.second.second;

		if(i-1 >= 0) s.insert({a[i-1]+b[j],{i-1,j}});
		if(j-1 >= 0) s.insert({a[i] + b[j-1],{i,j-1}});

		idx++;
	}

	return ans;
}

//3. Find Median of Running Stream of Integers
float findCurrentMedian(priority_queue<int> &maxHeap,
	priority_queue<int,vector<int>,greater<int>> &minHeap){
	if(maxHeap.size() > minHeap.size()){
		return float(maxHeap.top());
	}else if(maxHeap.size() < minHeap.size()){
		return float(minHeap.top());
	}	
		
	int w1 = minHeap.top();
	int w2 = maxHeap.top();
	return float((w1+w2)/2.0);
}

void displayHeaps(priority_queue<int> maxHeap,
	priority_queue<int,vector<int>,greater<int>> minHeap){
	while(!maxHeap.empty() && !minHeap.empty()){
		cout << maxHeap.top() << " , " << minHeap.top() << endl;
		maxHeap.pop();
		minHeap.pop();
	}
	while(!maxHeap.empty()){
		cout << maxHeap.top() << " , " << "--";
		maxHeap.pop();
	}
	while(!minHeap.empty()){
		cout <<  "--" << ", " << minHeap.top() << endl;;
		minHeap.pop();
	}
	cout << endl;
	cout << endl;
}


vector<float> findMedianOfRunningStream(vector<int> &a){
	priority_queue<int> maxHeap;
	priority_queue<int,vector<int>,greater<int>> minHeap;

	vector<float> ans;
	float currentMedian = INT_MAX;

	for(int i=0;i<a.size();i++){
		if(a[i] <= currentMedian){
			if(maxHeap.size()<=minHeap.size()){
				maxHeap.push(a[i]);
			}else{
				int w = maxHeap.top();
				maxHeap.pop();
				maxHeap.push(a[i]);
				minHeap.push(w);
			}
		}else{
			if(maxHeap.size()>=minHeap.size()){
				minHeap.push(a[i]);
			}else{
				int w = minHeap.top();
				minHeap.pop();
				minHeap.push(a[i]);
				maxHeap.push(w);
			}
		}

		currentMedian = findCurrentMedian(maxHeap,minHeap);

		cout << "new Number: " << a[i] << endl;
		cout << "Median: " << currentMedian << endl;
		displayHeaps(maxHeap,minHeap);
		ans.push_back(currentMedian);
	}

	return ans;
}

class Element{
public:
	int val;
	int row;
	int col;
};

class Element_Compare{
public:
	// If this returns true, a will be popped later than b
	bool operator()(Element a, Element b){
		if(a.val > b.val){
			return true;
		}else{
			return false;
		}
	}
};


//4. Find Merge of K Sorted Arrays
vector<int> mergeKSortedArrays(vector<vector<int>> &mat,int n){
	priority_queue<Element,vector<Element>,Element_Compare> pq;
	for(int i=0;i<n;i++){
		Element e;
		e.val = mat[i][0];
		e.row = i;
		e.col = 0;
		pq.push(e);
	}

	vector<int> ans;

	while(!pq.empty()){
		Element e = pq.top();
		//cout <<"E=>" <<  e.row << "," << e.col << ":" << e.val << endl;
		pq.pop();
		ans.push_back(e.val);
		if(e.col + 1 < mat[e.row].size()){
			Element e1;
			e1.val = mat[e.row][e.col+1];
			e1.row = e.row;
			e1.col = e.col + 1;
			pq.push(e1);
			//cout <<"E1=>" <<  e1.row << "," << e1.col << ":" << e1.val << endl;
		}
	}

	return ans;
}

//5. Find kth Smallest Element

int kthSmallest(vector<vector<int>> &matrix,int k){
	int n = matrix.size();
	//This question is similiar to merge k sorted arrays in to one single sorted array
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
	for(int i=0;i<n;i++){
		pq.push({matrix[i][0],{i,0}});
	}

	int ans = -1;
	while(k--){
		pair<int,pair<int,int>> p = pq.top();
		pq.pop();
		ans = p.first;
		if(p.second.second + 1 < n){
			pq.push({matrix[p.second.first][p.second.second+1],{p.second.first,p.second.second+1}});
		}
	}

	return ans;

}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		/*vector<int> a = {1,4,2,3};
		vector<int> b = {2,5,1,6};*/

		// vector<int> v = maxCombinations(4,4,a,b);
		// for(auto &x : v){
		// 	cout << x << " ";
		// }

		// cout << endl;

/*		vector<int> a = {1,1,5,4,3,0,8};
		vector<float> medians = findMedianOfRunningStream(a);
		for(auto &x : medians) {
			cout << x << " ";
		}
		cout << endl;*/

/*		vector<vector<int>> a = {{3,5,9},{1,2,3,8},{5,6,7}};
		vector<int> sorted = mergeKSortedArrays(a,3);
		for(auto &x : sorted) {
			cout << x << " ";
		}
		cout << endl;*/

		vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
		cout << kthSmallest(a,5);
	}
	return 0;
}
