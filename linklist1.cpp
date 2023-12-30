#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define watch(x)                 cout <<"\nValue of x here is : "<<(x) << endl
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
void buildlist(node*&head)
{
	int data;
	cin >> data;
	while (data != -1)
	{
		insertattail(head, data);
		cin >> data;
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
istream& operator>>(istream &is, node *&head)
{
	buildlist(head);
	return is;
}
ostream& operator<<(ostream &os, node *head)
{
	printlist(head);
	return os;
}
void reverse(node*&head)
{
	node*C = head;
	node*P = NULL;
	node*N;
	while (C != NULL)
	{
		N = C->next;
		C -> next = P;
		P = C;
		C = N;
	}
	head = P;
}
node* recreverse(node*&head)
{
	//Base Case
	if (head->next == NULL || head == NULL)
	{
		return head;
	}
	//Rec Case
	node* smallhead = recreverse(head->next);
	node* C = head;
	C->next->next = C;
	C->next = NULL;
	return smallhead;
}
node* midpoint(node*head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	node* fast = head->next;

	node* slow = head;


	while (fast != NULL && fast->next != NULL)
	{

		fast = fast->next->next;

		slow = slow->next;

	}
	return slow;
}
node* kthnodefromend(node*&head, int k)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
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
node* merge(node*a, node*b)
{
	if (a == NULL)
	{
		return b;
	}
	else if (b == NULL)
	{
		return a;
	}
	node *c;
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
node *mergesort(node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	node *mid = midpoint(head);
	node *a = head;
	node *b = mid->next;
	mid->next = NULL;
	a = mergesort(a);
	b = mergesort(b);
	node* c = merge(a, b);
	return c;
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
	buildlist(head);
	printlist(head);
	cout << endl;
	node* head1 = NULL;
	node* head2 = NULL;
	cin >> head1 >> head2;
	cout << head1 << endl << head2;
	//reverse(head2);
	cout << endl << head2;
	cout << endl << head1;
	cout << endl << endl;
	node* head3 = NULL;
	cin >> head3;
	cout << "\nThe link list is : " << head3;
	node*m = midpoint(head3);
	cout << "\nMid point of the linked list : " << "  is  : " ;
	cout << m->data;
	node* ke = kthnodefromend(head3, 3);
	cout << "\nKth node from the end is : ";
	cout << ke->data;
	cout << "\nmerging two linked list  : ";
	node*head4 = merge(head2, head3);
	cout << endl << head4;
	node* head5 = NULL;
	cin >> head5;
	cout << endl << "The unsorted linked list : ";
	cout << head5;
	head5 = mergesort(head5);
	cout << "\nThe sorted linked list : ";
	cout << head5;
	return 0;
}
