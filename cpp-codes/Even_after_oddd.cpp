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
	node*curr1 = NULL;
	while ((temp->data) % 2 != 1)
	{
		if (temp->next != NULL)
		{
			temp = temp->next;
		}
		else break;

	}
	cout << "\nThe first odd element is : " << temp->data;

	while (temp != NULL)
	{
		if ((temp->data) % 2 == 1)
		{

			insertattail(curr, (temp->data));
		}
		temp = temp->next;

	}
	cout << "\nThe odd link list is : "; printlist(curr);
	while ((temp1->data) % 2 != 0)
	{
		if (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		else break;
	}
	cout << "\nThe first even element of the list is : " << temp1->data;
	while (temp1 != NULL)
	{
		if ((temp1->data) % 2 == 0)
		{

			insertattail(curr1, (temp1->data));
		}
		temp1 = temp1->next;

	}
	cout << "\nThe even link list is : "; printlist(curr1);
	node*temp2 = curr;
	while (temp2->next != NULL)
	{
		temp2 = temp2->next;
	}
	cout << "\nThe last element of the odd link list is : " << temp2->data;
	temp2->next = curr1;
	head = curr;


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
