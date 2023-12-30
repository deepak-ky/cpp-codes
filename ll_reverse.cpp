#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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
int32_t main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int k;
	cin >> k;
	for (int i = 0; i < (n / k); i++)
	{	node*head = NULL;
		for (int j = 0; j < k; j++) {
			int w;
			cin >> w;
			insertattail(head, w);
		}
		reverse(head);
		printlist(head);
	}


	return 0;
}
