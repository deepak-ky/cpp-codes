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

void kthfromtheend(node*&head, int k)
{
	node*fast = head;
	node*slow = head;
	int jump = 1;
    int flag=0;
	while (jump <= k)
	{
	    if(fast->next!=NULL)
        {


        fast = fast->next;
		jump++;
        }
        else
        {

            fast=head;

            flag=1;
            break;
        }
	}
	if(flag==0)
    {
	while (fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
    fast->next=head;
    head=slow->next;
    slow->next=NULL;
    }



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


	int k,k1;
	cin >> k1;
	if(k1<n)
    {
        k=k1;
    }
    else if(k1==n)
    {
     k=n;
    }
    else if(k1>n)
    {
        k=(k1%n);
    }
	kthfromtheend(head, (k));
		printlist(head);

	return 0;
}
