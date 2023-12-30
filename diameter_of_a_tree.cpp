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



int diameter_of_tree_basic(node * head)
{
	if (head == NULL)
	{
		return 0;
	}


	int opt1 = height_of_tree(head->left) + height_of_tree(head->right) + 2;
	int opt2 = diameter_of_tree_basic(head->left);
	int opt3 = diameter_of_tree_basic(head->right);

	return max(opt1, max(opt2, opt3));
}

class pair_class
{
public:
	int height;
	int diameter;
};


pair_class diameter_of_tree_advanced(node * head)
{
	pair_class p;

	if (head == NULL)
	{
		p.height = -1;
		p.diameter = 0;
		return p;
	}
	else
	{
		pair_class left_p = diameter_of_tree_advanced(head->left);
		pair_class right_p = diameter_of_tree_advanced(head->right);

		int opt1 = left_p.height + right_p.height + 2;
		int opt2 = left_p.diameter;
		int opt3 = right_p.diameter;

		p.height = max(left_p.height, right_p.height) + 1;
		p.diameter = max(opt1, max(opt2, opt3));

		return p;
	}
}




int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		node * head = build_tree();
		cout << diameter_of_tree_basic(head);

		cout << endl;
		cout << endl;

		pair_class get_ans = diameter_of_tree_advanced(head);
		cout << "Height : " << get_ans.height << endl;
		cout << "Diameter : " << get_ans.diameter << endl;

	}
	return 0;
}
