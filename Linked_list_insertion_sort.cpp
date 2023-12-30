#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define w111  cout<<1
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
// int length(node *head)
// {
// 	int len = 0;
// 	node* temp = head;
// 	while (temp != NULL)
// 	{
// 		len++;
// 		temp = temp->next;
// 	}
// 	return len;
// }
void insert_in_sorted_linklist(node*&head, int d)
{
	node*n = new node(d);
	if (head == NULL || ((head->data) >= (n->data)))
	{
		insertathead(head, d);
	}
	else {
		node* temp = head;
		while (temp->next != NULL && ((n->data) >= (temp->next->data)))
		{
			temp = temp->next;
		}
		n->next = temp->next;
		temp->next = n;

	}
}
node* insrtsort(node*&head)
{
	node *head1 = NULL;
	node *temp = head;
	while (temp != NULL)
	{
		insert_in_sorted_linklist(head1, (temp->data));
		temp = temp->next;
	}
	return head1;

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
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int w;
		cin >> w;
		insertattail(head, w);
	}
	int d;
	cin >> d;
	cout << "\nBefore Sorting : ";
	printlist(head);
	head = insrtsort(head);
	cout << "\nAfter inserting the new node : ";
	printlist(head);
	return 0;
}
