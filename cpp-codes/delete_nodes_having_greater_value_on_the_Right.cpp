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
	node* next;

	node(int n)
	{
		data = n;
		next = NULL;
	}
};

void insert_at_head(node *&head, int d)
{
	node * n = new node(d);
	n->next = head;
	head = n;
}
void insert_at_tail(node *&head, int d)
{
	node * n = new node(d);
	node * temp = head;
	if (head == NULL)
	{
		insert_at_head(head, d);
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = n;
	n->next = NULL;
	return;
}

void print_list(node * head)
{
	node * temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

node * reverse(node * head)
{
	node * p = NULL;
	node * c = head;
	while (c != NULL)
	{
		node * n = c->next;
		c->next = p;
		p = c;
		c = n;
	}

	return p;
}


node * delete_greater_on_right(node * head)
{
	head = reverse(head);
	node * ans = head;

	int prev_large = ans->data;
	node * temp = head;
	temp = temp->next;
	while (temp != NULL)
	{
		if (temp->data > prev_large)
		{
			ans->next = temp;
			ans = temp;
			prev_large = temp->data;
		}
		temp = temp->next;
	}

	ans->next = NULL;

	head = reverse(head);
	return head;
}
int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		node * head = NULL;
		insert_at_tail(head, 12);
		insert_at_tail(head, 15);
		insert_at_tail(head, 10);
		insert_at_tail(head, 11);
		insert_at_tail(head, 5);
		insert_at_tail(head, 6);
		insert_at_tail(head, 2);
		insert_at_tail(head, 3);

		node * new_head = delete_greater_on_right(head);
		print_list(new_head);
	}
	return 0;
}
