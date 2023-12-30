#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define watch(var,x)                 cout <<"\nValue of x here is : "<<(x) << endl
#define mod                          1000000007
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
	node*n = new node(d);
	n->next = head;
	node*temp = head;
	if (head != NULL)
	{
		while (temp->next != head)
		{
			temp = temp->next;
		} temp->next = n;
	}
	else
	{
		n->next = n;
	}
	head = n;
}
void printlist(node*head)
{
	node*temp = head;
	while (temp->next != head)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << temp->data << " END";
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	node* head = NULL;
	insertathead(head, 5);
	insertathead(head, 6);
	insertathead(head, 7);
	insertathead(head, 8);
	printlist(head);
	return 0;
}
