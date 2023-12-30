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
#define se                            second

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

class node
{
public:
	int data;
	node* left;
	node* right;

	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* build_tree()
{
	int d;
	cin >> d;

	if (d == -1)
	{
		return NULL;
	}
	else
	{
		node * temp_head = new node(d);
		temp_head->left = build_tree();
		temp_head->right = build_tree();
		return temp_head;
	}

}

void print_level_by_level(node * head)
{
	queue<node*> q;
	q.push(head);
	q.push(NULL);

	while (1)
	{
		node*f = q.front();
		q.pop();

		if (f)
		{
			cout << f->data << " ";
			if (f->left) q.push(f->left);
			if (f->right) q.push(f->right);
		}
		else
		{
			if (q.empty())
			{
				break;
			}
			else
			{
				cout << "\n";
				q.push(NULL);

			}
		}
	}
	return;
}

node* build_Tree_from_array(int *a, int s, int e)
{
	if (s > e)
	{
		return NULL;
	}

	int mid = (s + e) / 2;
	node * head = new node(a[mid]);
	head->left = build_Tree_from_array(a, s, mid - 1);
	head->right = build_Tree_from_array(a, mid + 1, e);

	return head;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		int a[] = {1, 2, 3, 4, 5, 6, 7};
		int n = sizeof(a) / sizeof(int);

		node * head = build_Tree_from_array(a, 0, n - 1);
		print_level_by_level(head);


	}
	return 0;
}
