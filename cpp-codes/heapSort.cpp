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

vector<int> buildMaxHeap(vector<int> &v){
	vector<int> newV;
	newV.push_back(-1);
	for(int i=0;i<v.size();i++){
		newV.push_back(v[i]);
	}

	for(int i=2;i<newV.size();i++){
		int idx = i;
		int parentIdx = i/2;
		while(parentIdx != 0 && newV[parentIdx] < newV[idx]){
			swap(newV[parentIdx],newV[idx]);
			idx = parentIdx;
			parentIdx = parentIdx/2;
		}
	}

	return newV;
}

void display(vector<int> v){
	for(auto &x : v) cout << x << " ";
		cout << endl << "Tree : " << endl;
	int i = 1;
	int j = 0;
	int elementCount = pow(2,j);
	int n = v.size();
	while(i < n){
		cout << v[i] << " ";
		i++;
		elementCount--;
		if(elementCount == 0){
			cout << endl;
			j++;
			elementCount = pow(2,j);
		}
	}
	cout << endl;
	cout << endl;
}

void heapfiyMax(vector<int> &v,int idx){
	while(idx < v.size()){
		int childReplaceValue = INT_MIN;
		int childReplaceIndex = -1;
		if(((2*idx) < v.size()) && (v[2*idx] > childReplaceValue)){
			childReplaceValue = v[2*idx];
			childReplaceIndex = 2*idx;
		}

		if((((2*idx)+1) < v.size()) && (v[(2*idx)+1] > childReplaceValue)){
			childReplaceValue = v[(2*idx)+1];
			childReplaceIndex = 2*idx+1;
		}	

		if(childReplaceValue > v[idx]){
			swap(v[idx],v[childReplaceIndex]);
			idx = childReplaceIndex;
		}else{
			break;
		}
	}
}

vector<int> buildMinHeap(vector<int> &v){
	vector<int> newV;
	newV.push_back(-1);
	for(int i=0;i<v.size();i++){
		newV.push_back(v[i]);
	}

	for(int i=2;i<newV.size();i++){
		int idx = i;
		int parentIdx = i/2;
		while(parentIdx != 0 && newV[parentIdx] > newV[idx]){
			swap(newV[parentIdx],newV[idx]);
			idx = parentIdx;
			parentIdx = parentIdx/2;
		}
	}

	return newV;
}

void heapfiyMin(vector<int> &v,int idx){
	while(idx < v.size()){
		int childReplaceValue = INT_MAX;
		int childReplaceIndex = -1;
		if(((2*idx) < v.size()) && (v[2*idx] < childReplaceValue)){
			childReplaceValue = v[2*idx];
			childReplaceIndex = 2*idx;
		}

		if((((2*idx)+1) < v.size()) && (v[(2*idx)+1] < childReplaceValue)){
			childReplaceValue = v[(2*idx)+1];
			childReplaceIndex = 2*idx+1;
		}	

		if(childReplaceValue < v[idx]){
			swap(v[idx],v[childReplaceIndex]);
			idx = childReplaceIndex;
		}else{
			break;
		}
	}
}





int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		vector<int> v = {9,23,11,4,-9,2};
		/*v = buildMaxHeap(v);
		display(v);
		while(v.size() > 1){
			cout << v[1] << ",";
			swap(v[1],v[v.size()-1]);
			v.pop_back();
			heapfiyMax(v,1);
		}*/


		v = buildMinHeap(v);
		display(v);
		while(v.size() > 1){
			cout << v[1] << ",";
			swap(v[1],v[v.size()-1]);
			v.pop_back();
			heapfiyMin(v,1);
		}
	}
	return 0;
}