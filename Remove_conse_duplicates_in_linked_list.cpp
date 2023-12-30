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
	if (head == NULL)
	{
		return;
	}
	node*temp = head;
	while (temp->next != NULL)
	{
		if ((temp->data) == (temp->next->data))
		{

			node*d = temp->next->next;




			cout << ":" << d->data << endl;

			delete(temp->next);
			temp->next = d;
		}

	}
	temp = temp->next;
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
	insertattail(head, 8);
	insertattail(head, 8);
	insertattail(head, 5);
	print(head);
	removeduplicate(head);
	cout << "\nRemoved"; print(head);
	return 0;
}
