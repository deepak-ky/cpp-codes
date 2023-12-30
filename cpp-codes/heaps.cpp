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

class min_heap
{
	// We are implementing min_heap
	vector<int> v;
public:
	min_heap(){
		v.push_back(-1);
	}

	void addElement(int w){
		v.push_back(w);
		int idx = v.size() - 1;
		while(idx > 1){
			int parent_idx = idx/2;
			if(v[parent_idx] > v[idx]){
				swap(v[parent_idx],v[idx]);
				idx = parent_idx;
			}else{
				break;
			}
		}
	}

	void smallestElement(){
		if(v.size() == 1){
			cout << "No elements in min heap" << endl;
		}else{
			cout << "smallestElement uptil now is : " << v[1] << endl;
		}
		return;
	}

	void removeElement(){
		if(v.size() == 1){
			cout << "No elements to delete in min heap" << endl;
		}else{
			int n = v.size();
			swap(v[1],v[n-1]);
			v.pop_back();
			int idx = 1;
			while(idx < v.size()){
				int childIndexToReplace = (2*idx);
				int childReplaceValue = INT_MAX;
				if((idx*2) < v.size()) childReplaceValue = v[2*idx];
				if((((idx*2) + 1) < v.size()) && v[(idx*2) + 1] < childReplaceValue){
					childReplaceValue = v[(idx*2) + 1];
					childIndexToReplace = (idx*2) + 1;
				}

				// The reason we are taking the smallest element to swap with root is this
				// for example we have 9 and child 8,7 , now both are smaller than 9, but if 
				// we replace by 8 , then tree becomes . 8 -> 9,7 now 7 cannot be a child of 8
				// in a min heap, so we need to replace root with the smallest number only so
				// 7 -> 8,9 / is correct

				if(childReplaceValue < v[idx]){
					swap(v[childIndexToReplace],v[idx]);
					idx = childIndexToReplace;
				}else{
					break;
				}
			}
		}
		return;
	}

	void display(){
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
};

class max_heap
{
	vector<int> v;
public:
	max_heap(){
		v.push_back(-1);
	}

	void addElement(int w){
		v.push_back(w);
		int idx = v.size() - 1;
		while(idx > 1){
			int parent_idx = idx/2;
			if(v[parent_idx] < v[idx]){
				swap(v[parent_idx],v[idx]);
				idx = parent_idx;
			}else{
				break;
			}
		}
	}

	void biggestElement(){
		if(v.size() == 1){
			cout << "No elements in max heap" << endl;
		}else{
			cout << "biggestElement uptil now is : " << v[1] << endl;
		}
		return;
	}

	void removeElement(){
		if(v.size() == 1){
			cout << "No elements to delete in max heap" << endl;
		}else{
			int n = v.size();
			swap(v[1],v[n-1]);
			v.pop_back();
			int idx = 1;
			while(idx < v.size()){
				int childIndexToReplace = (2*idx);
				int childReplaceValue = INT_MIN;
				if((idx*2) < v.size()) childReplaceValue = v[2*idx];
				if((((idx*2) + 1) < v.size()) && v[(idx*2) + 1] > childReplaceValue){
					childReplaceValue = v[(idx*2) + 1];
					childIndexToReplace = (idx*2) + 1;
				}

				if(childReplaceValue > v[idx]){
					swap(v[childIndexToReplace],v[idx]);
					idx = childIndexToReplace;
				}else{
					break;
				}
			}
		}
		return;
	}

	void display(){
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
};

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
/*		min_heap mh;
		mh.addElement(6);
		mh.addElement(7);
		//mh.smallestElement();
		mh.addElement(5);
		mh.addElement(4);
		//mh.smallestElement();
		mh.display();

		mh.removeElement();
		mh.display();
*/
		min_heap mh;
		vector<int> v = {1,2,3,17,19,36,7,25,100};
		for(int i=0;i<v.size();i++){
			mh.addElement(v[i]);
			//mh.display();
		}

		mh.addElement(0);
		mh.display();

		mh.removeElement();
		mh.display();


		// Max heap
		/*max_heap mh;
		//vector<int> v = {4,10,3,5,1};
		vector<int> v = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
		for(int i=0;i<v.size();i++){
			mh.addElement(v[i]);
		}

		mh.display();
		mh.biggestElement();
		mh.removeElement();
		mh.display();*/
	}
	return 0;
}
