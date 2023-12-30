#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define watch(var,x)                 cout <<"\nValue of x here is : "<<(x) << endl
#define mod                          1000000007
class node {
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
	node*n = new node(d);
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
		node*n = new node(d);
		node*temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;

		}
		temp->next = n;
		n->next = NULL;
	}

}
node* midpoint(node*&head)
{
	node* fast = head->next;
	node* slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
node* merge(node*a, node*b)
{
	if (a == NULL) {return b;}
	if (b == NULL) {return a;}
	node*c;
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
node* mergesort(node*&head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	node*mid = midpoint(head);

	node* a = head;
	node*b = mid->next;
	mid->next = NULL;
	a = mergesort(a);
	b = mergesort(b);
	node*c = merge(a, b);
	return c;

}
void print(node*head)
{
	node*temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "->";
		temp = temp->next;

	}
}
void removeduplicate(node*&head)
{
	node*temp = head;
	node*d;
	if (head == NULL)
	{
		return;
	}
	while (temp->next != NULL)
	{
		if ((temp->data) == (temp->next->data))
		{

			d = temp->next->next;

			delete(temp->next);
			temp->next = d;
		}

		else {
			temp = temp->next;
		}

	}
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
	insertattail(head, 1);
	insertattail(head, 8);
	insertattail(head, 2);
	insertattail(head, 9);
	insertattail(head, 9);

	print(head);

	//removeduplicate(head);
	head = mergesort(head);
	cout << "\nRemoved"; print(head);
	return 0;
}
