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


void print_pre_order(node * head)
{
	if (head == NULL)
	{
		return;
	}

	cout << head->data << " ";
	print_pre_order(head->left);
	print_pre_order(head->right);
	return;
}


void print_in_order(node * head)
{
	if (head == NULL)
	{
		return;
	}

	print_in_order(head->left);
	cout << head->data << " ";
	print_in_order(head->right);
	return;
}

void print_post_order(node * head)
{
	if (head == NULL)
	{
		return;
	}

	print_post_order(head->left);
	print_post_order(head->right);
	cout << head->data << " ";
	return;
}



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		node * head = NULL;
		head = build_tree();
		cout << " Pre-Order:  "; print_pre_order(head);  cout << endl;
		cout << "  In-Order:  "; print_in_order(head);  cout << endl;
		cout << "Post-Order:  "; print_post_order(head);  cout << endl;

	}
	return 0;
}
