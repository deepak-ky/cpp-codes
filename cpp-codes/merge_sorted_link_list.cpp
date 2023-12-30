#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
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
void insertathead(node*&head, int d)
{
	node* n = new node(d);
	n->next = head;
	head = n;
}
void insertattail(node*&head, int d)
{
	if (head == NULL)
	{
		insertathead(head, d);
	}
	else
	{
		node *n = new node(d);
		node*temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = n;
		n->next = NULL;
	}
}
void printlist(node*head)
{
	node*temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}
void reverse(node*&head)
{
	node* curr = head;
	node* prev = NULL;
	node* nn;
	while (curr != NULL)
	{
		nn = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nn;
	}
	head = prev;
}
node* merge(node*a, node*b)
{
	if (a == NULL)
	{
		return b;
	}
	if (b == NULL)
	{
		return a;
	}
	node *c;
	if (a->data < b->data)
	{
		c = a;
		c->next = merge(a->next, b);
	}
	else {
		c = b;
		c->next = merge(a, b->next);
	}
	return c;
}
int32_t main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		node*head = NULL;
		for (int i = 0; i < n; i++)
		{
			int w;
			cin >> w;
			insertattail(head, w);
		}
		int n1;
		cin >> n1;
		node*head1 = NULL;
		for (int i = 0; i < n1; i++)
		{
			int w;
			cin >> w;
			insertattail(head1, w);
		}
		node* head3 = merge(head, head1);
		printlist(head3);
		cout << endl;

	}
	return 0;
}
