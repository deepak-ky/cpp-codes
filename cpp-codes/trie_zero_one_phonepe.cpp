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

class node{
public:
	int data;
	node*left;
	node*right;
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};


class ZeroOneTrie{
	node *root;
public:
	ZeroOneTrie(){
		root = new node(0);
	}

	void insert(int num){
		node *temp = root;
		for(int pos=32;pos>=1;pos--){
			int idx = pos-1;
			if((num>>idx)&1){
				if(temp->right){
					temp = temp->right;
				}else{
					node *n = new node(1);
					temp->right = n;
					temp = temp->right;
				}
			}else{
				if(temp->left){
					temp = temp->left;
				}else{
					node *n = new node(0);
					temp->left = n;
					temp = temp->left;
				}
			}
		}
	}

	int findMaximumXor(int num) {
		// you start picking things from the most significant bit
		int ans = 0;
		node *temp = root;
		for(int pos=32;pos>=1;pos--){
			int idx = pos-1;
			if((num>>idx)&1){
				if(temp->left){
					ans += (1<<idx);
					temp = temp->left;
				}else{
					temp = temp->right;
				}
			}else{
				if(temp->right){
					ans += (1<<idx);
					temp = temp->right;
				}else{
					temp = temp->left;
				}
			}
		}
		return ans;
	}
};


int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		ZeroOneTrie zot;
		int ans = 0;
		int a[6] = {25,10,2,8,5,3};
		zot.insert(a[0]);

		for(int i=1;i<6;i++){
			int w = zot.findMaximumXor(a[i]);
			ans = max(ans,w);
			zot.insert(a[i]);
		}
		cout << ans << " ";
	}
	return 0;
}
