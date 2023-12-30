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
	w111;
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
bool ispalindrome(int n, node*head)
{
	int i = 1;
	int k = 1;
	node* temp = head;
	while (i <= n)
	{
		cout << "\nvalue of i here : " << i;
		cout << "\nvalue of k here : " << k;
		node*m = kthnodefromend(head, k);
		if ((temp->data) != (m->data))
		{
			return false;
		}
		temp = temp->next;
		k++;
		i++;
	}
	return true;
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

	if (ispalindrome(n, head))
	{
		cout << "\nTrue";
	}
	else cout << "\nFalse";


	return 0;
}
