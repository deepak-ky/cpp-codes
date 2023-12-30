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

void level_order_print(node*head)
{

	queue<node*> q;
	q.push(head);

	while (!q.empty())
	{
		node* temp = q.front();
		q.pop();

		cout << temp->data << " ";

		if (temp->left) q.push(temp->left);
		if (temp->right) q.push(temp->right);
	}

	return;
}

int height_of_tree(node * head)
{
	if (head == NULL)
	{
		return -1;
	}

	int h1 = height_of_tree(head->left);
	int h2 = height_of_tree(head->right);
	return max(h1, h2) + 1;
}

void print_kth_level(node * head, int curr_level, int k)
{
	if (curr_level == k)
	{
		if (head != NULL)
		{
			cout << head->data << " ";
		}
		return;
	}

	if (head == NULL)
	{
		return;
	}

	print_kth_level(head->left , curr_level + 1, k);
	print_kth_level(head->right , curr_level + 1, k);

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
		//print_pre_order(head);
		cout << "BFS PRINT: "; level_order_print(head);
		cout << endl;
		cout << height_of_tree(head);

		int k = 2;

		// 0 - based indexing
		cout << endl;
		cout << "The " << k << "th level of the tree is:";
		print_kth_level(head, 0, k);


		cout << endl;
		cout << endl;

		cout << "Printing Level by level: ";

		cout << endl;

		for (int i = 0; i <= height_of_tree(head); i++)
		{
			print_kth_level(head, 0, i);
			cout << endl;
		}
	}
	return 0;
}
