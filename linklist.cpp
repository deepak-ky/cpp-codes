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
void insertathead(node*&head, int data)
{
	node*n = new node(data);
	n->next = head;
	head = n;

}
int length(node*head)
{
	int len = 0;
	while (head != NULL)
	{
		head = head->next;
		len++;
	}
	return len;

}
void insertattail(node*&head, int data)
{
	if (head == NULL)
	{
		head = new node(data);
		return;
	}

	node*temp = head;
	node*n = new node(data);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	n->next = NULL;
	temp->next = n;
}
void insertatpos(node*&head, int data, int pos)
{
	if (head == NULL || pos == 0)
	{
		insertathead(head, data);
	}
	if (pos > length(head))
	{
		insertattail(head, data);
	}
	node*temp = head;
	node*n = new node(data);
	int jump = 0;
	while (jump < (pos - 1))
	{
		temp = temp->next;
		jump++;
	}
	n->next = temp->next;
	temp->next = n;

}
void deleteathead(node*&head)
{
	node* temp = head;
	head = head->next;
	delete temp;

}
void deleteattail(node*&head)
{
	node* temp = head;
	node* prev = NULL;
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	delete temp;
}
void deleteatp(node*&head, int pos)
{
	int jump = 1;
	node* prev = NULL;

	node* temp = head;
	while (jump <= (pos))
	{
		prev = temp;
		temp = temp->next;
		jump++;
	}
	delete temp;
	prev->next = temp->next;

}
void printlist(node* head)
{
	node*temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}

}
bool searchrecursive(node*head, int d)
{
	if (head == NULL)
	{
		return false;
	}
	if (head->data == d)
	{
		return true;
	}
	else return searchrecursive(head -> next, d);
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
	insertattail(head, 11);
	insertatpos(head, 99, 2);
	printlist(head);
	cout << endl << length(head);
	deleteathead(head);
	cout << endl; printlist(head);
	deleteatp(head, 2);
	cout << endl; printlist(head);
	deleteattail(head);
	cout << endl; printlist(head);
	cout << endl;
	insertathead(head, 7);
	insertathead(head, 8);
	insertathead(head, 9);
	if (searchrecursive(head, 999))
	{
		cout << "Present";
	}
	else cout << "Absent";
	return 0;
}
