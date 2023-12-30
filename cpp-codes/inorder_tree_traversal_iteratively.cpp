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

void inorder_recursive(node* head)
{
	if (head == NULL)
	{
		return;
	}

	inorder_recursive(head->left);
	cout << head->data << " ";
	inorder_recursive(head->right);
}

void print_stack(stack<pair<node*, int>> s)
{
	while (!s.empty())
	{
		pair<node*, int> p = s.top();
		node * n = p.first;
		if (n == NULL)
		{
			cout << "{" << "NULL" << " , " << s.top().second << " } ,";
		}
		else
			cout << "{" << n->data << " , " << s.top().second << " } ,";
		s.pop();
	}
	cout << endl;
}

void iterative_inorder(node * head)
{
	stack<pair<node*, int>> s;
	s.push({head, 1});

	while (!s.empty())
	{

		pair<node*, int> p = s.top();
		if (p.first == NULL)
		{
			s.pop();
			if (!s.empty()) {
				pair<node*, int> p2 = s.top();
				s.pop();

				cout << p2.first->data << " ";
				s.push({p2.first->right, 1});
			}
			else continue;
		}
		else
		{
			s.push({p.first->left, 1});
		}

		//print_stack(s);
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
		print_level_by_level(head);
		cout << endl;
		inorder_recursive(head);
		cout << endl;
		iterative_inorder(head);
	}
	return 0;
}
