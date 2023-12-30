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
void intersectionpoint(int d, node*head, node*head1)
{
	node* temp = head;
	node* temp1 = head1;
	int jump = 1;
	while (jump <= d)
	{
		temp = temp->next;
		jump++;
	}

	int flag = 0;
	while ((temp != NULL) && (temp1 != NULL))
	{
		if ((temp->data) == (temp1->data))
		{
			cout << temp->data;
			flag = 1;
			break;
		}
		temp = temp->next;
		temp1 = temp1->next;
	}
	if (flag == 0)
		cout << -1;
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
