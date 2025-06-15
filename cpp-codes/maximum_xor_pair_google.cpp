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
	int bit;
	node *left;
	node *right;
	node(int b){
		bit = b;
		left = NULL;
		right = NULL;
	}
};

class Trie{
	node *root;
public:
	Trie(){
		root = new node(-1);
	}

	void insertNum(int x){
		node * temp = root;
		for(int i=31;i>=0;i--){
			if((x>>i)&1){
				if(temp->right == NULL){
					node * n = new node(1);
					temp->right = n;
				}
				temp = temp->right;
			}else{
				if(temp->left == NULL){
					node * n = new node(0);
					temp->left = n;
				}
				temp = temp->left;
			}
		}
	}


	int findCurrMaxXor(int x){
		int xorr = 0;
		node * temp = root;
		for(int i=31;i>=0;i--){
			if((x>>i&1)){
				if(temp->left){
					xorr += pow(2,i);
					temp = temp->left;
				}else{
					temp = temp->right;
				}

			}else{
				if(temp->right){
					xorr += pow(2,i);
					temp = temp->right;
				}else{
					temp = temp->left;
				}
			}
		}

		return xorr;
	}
};

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		Trie t;
		t.insertNum(25);
		cout << t.findCurrMaxXor(10);
	}
	return 0;
}
