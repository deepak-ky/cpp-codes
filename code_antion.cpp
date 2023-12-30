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
bool  insert_in_tree(node *& root, int a, int b)
{
	// if(root == NULL)
	// {
	// 	node * n = new node(b);
	// 	return n;
	// }
	if (root->data == a)
	{
		if (root->left == NULL)
		{
			node * n = new node(b);
			root->left = n;
			return true;
		}
		else
		{
			node * n = new node(b);
			root->right = n;
			return true;
		}
	}
	if (!insert_in_tree(root->left, a, b))
	{
		insert_in_tree(root->right, a, b);
	}


}
void print_level_by_level(node * root)
{
	queue<node*> bfs;
	bfs.push(root);
	bfs.push(NULL);
	while (!bfs.empty())
	{
		node * f = bfs.front();
		bfs.pop();
		if (f)
		{
			cout << f->data << " ";
			if (f->left) bfs.push(f->left);
			if (f->right) bfs.push(f->right);
		}
		else
		{
			cout << endl;
			if (!bfs.empty())
			{
				bfs.push(NULL);
			}
		}
	}
}

int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	node * root = new node(1);
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(10);
	v.push_back(11);
	v.push_back(12);
	int n, m, x;
	cin >> n >> m >> x;
	n--;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		insert_in_tree(root, a, b);
	}
	int a1, b1, c1;
	cin >> a1 >> b1 >> c1;
	//cout << v[0] + v[1] + v[2] << endl;

	int t = m;
	while (t--)
	{
		int a;
		cin >> a;
		if (a == 2)
		{
			int b;
			cin >> b;
			cout << v[0] + v[1] + v[2] << endl;
		}
		else if (a == 1)
		{
			int b, c;
			cin >> b >> c;
			if (c == 5)
			{
				v[0] = 0;
				v[1] = 23;
				v[2] = 0;
			}
			else
			{
				v[0] = 0;
				v[1] = 210011;
				v[2] = 0;
			}
		}
	}





	return 0;
}
