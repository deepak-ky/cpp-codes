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
	node* next;
	node(int d)
	{
		data = d;
		next = NULL;
	}

};
void insertathead(node*&head , int d)
{
	node * n = new node(d);
	n->next = head;
	head = n;
}
void insertattail(node*&head, int d)
{
	node*n = new node(d);
	node * temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = n;
	n->next = NULL;
}
node * merge(node*a, node*b)
{
	if (a == NULL)
	{
		return b;
	}
	if (b == NULL)
	{
		return a;
	}
	node * c ;
	if (a->data < b->data)
	{
		c = a;
		c->next = merge(a->next, b);
	}
	else
	{
		c = b;
		c->next = merge(a, b->next);
	}
	return c;

}
void print(node * head)
{
	node*temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}

}
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	node * head = NULL;
	for (int i = 0; i < n; i++)
	{
		int d;
		cin >> d;
		if (i == 0)
		{
			insertathead(head, d);
		}
		else
		{
			node * head1  = NULL;
			insertathead(head1, d);
			head = merge(head, head1);
		}


	}
	print(head);


	return 0;
}
