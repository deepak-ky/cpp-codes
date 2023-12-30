#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
class node
{
public:
	int data;
	node * left;
	node * right;
	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}


};
string t = "true";
node* buildbst()
{
	int d;
	cin >> d;
	node * root = new node(d);
	string val1, val2;
	cin >> val1;
	if (val1 == t)
	{

		root->left = buildbst();
	}

	cin >> val2;

	if (val2 == t)
	{
		root->right = buildbst();
	}


	return root;

}
void linebyline_bfs(node * root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty())
	{
		node * f = q.front();
		if (f == NULL)
		{
			cout << endl;
			q.pop();
			if (!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{
			cout << f->data << ",";
			q.pop();
			if (f->left) {q.push(f->left);}
			if (f->right) {q.push(f->right);}
		}
	}
}
class hbpair
{
public:
	int hie;
	bool balance;
};
hbpair is_height_balanced(node * root)
{
	hbpair w;
	if (root == NULL)
	{
		w.hie = 0;
		w.balance = true;
		return w;
	}
	hbpair left = is_height_balanced(root->left);
	hbpair right = is_height_balanced(root->right);
	w.hie = max(left.hie, right.hie) + 1;
	if ((abs(left.hie - right.hie) <= 1) && left.balance && right.balance)
	{
		w.balance = true;
	}
	else w.balance = false;
	return w;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	node * root = buildbst();
	hbpair p = is_height_balanced(root);
	if (p.balance)
	{
		cout << "true";
	}
	else cout << "false";
	return 0;
}
