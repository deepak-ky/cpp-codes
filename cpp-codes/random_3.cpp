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
	node* left;
	node* right;
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

void printLevelByLevelBFS(node *root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node *t = q.front();
		q.pop();

		if(t != NULL){
			cout << t->data << " ";
			if(t->left) q.push(t->left);
			if(t->right) q.push(t->right);
		}else{
			cout << endl;
			if(!q.empty()) q.push(NULL);
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
		node * root = new node(1);
		node * left = new node(2);
		node * right = new node(3);

		root->left = left;
		root->right = right;

		printLevelByLevelBFS(root);

		root->right = NULL;
		delete right;
		// right = NULL;
		printLevelByLevelBFS(root);
	}	
	return 0;
}
