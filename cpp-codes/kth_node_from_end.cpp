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
node* kthnodefromend(node*&head, int k)
{
	node* fast = head;
	node* slow = head;
	int jump = 1;
	while (jump <= k)
	{
		fast = fast->next;
		jump++;
	}
	while (fast != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	node*head = NULL;
	int w;
	cin >> w;
	while (w != -1)
	{
		insertattail(head, w);
		cin >> w;
	}
	int k;
	cin >> k;
	node*m = kthnodefromend(head, k);
	cout << m->data << endl;
	return 0;
}
