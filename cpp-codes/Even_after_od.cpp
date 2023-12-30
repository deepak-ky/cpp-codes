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
void evenafterodd(node*&head)
{
	node*temp = head;
	node*temp1 = head;
	node*curr = NULL;
	while ((temp->data) % 2 != 1)
	{
		temp = temp->next;
	}
	cout << "\nThe first odd element is : " << temp->data;

	while (temp->next != NULL)
	{
		if ((temp->data) % 2 == 1)
		{
			insertattail(curr, (temp->data));
		}
	}
	cout << "\nThe odd link list is : "; printlist(curr);
	while ((temp1->data) % 2 != 0)
	{
		temp1 = temp1->next;
	}
	cout << "\nThe first even element of the list is : " << temp1->data;

}
int32_t main()
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
	evenafterodd(head);
	cout << endl; printlist(head);
	return 0;
}
