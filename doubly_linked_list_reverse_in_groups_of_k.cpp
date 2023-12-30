#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define se                            second

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}

class node
{
public:
	int data;
	node * next;
	node * prev;

	node(int d)
	{
		data = d;
		next = NULL;
		prev = NULL;
	}
};

void insert_at_head(node *& head, int d)
{
	node * n = new node(d);
	n->next = head;
	if (head != NULL)
		head->prev = n;
	n->prev = NULL;
	head = n;
}

void insert_at_tail(node *& head, int d)
{
	if (head == NULL)
	{
		insert_at_head(head, d);
		return;
	}

	node * last = head;
	while (last->next != NULL)
	{
		last = last->next;
	}

	node * n = new node(d);

	last->next = n;
	n->next = NULL;
	n->prev = last;
	return;

}

void print_list(node * head)
{

	cout << "Forward  : ";

	node * temp = head;
	while (temp->next != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data << " ";

	cout << endl;
	cout << "Backward : ";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->prev;
	}

	cout << endl;
}

node *reverse (node *head, int k)
{
	node * p = NULL;
	node * curr = head;
	int jump = 0;
	while (curr != NULL && jump < k)
	{
		node * n = curr->next;
		curr->next = p;
		curr->prev = n;
		p = curr;
		curr = n;
		jump++;
	}

	if (curr != NULL)
	{
		head->next = reverse(curr, k);
		head->next->prev = head;
	}

	p->prev = NULL;

	return p;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		node * head = NULL;
		insert_at_tail(head, 1);
		insert_at_tail(head, 2);
		insert_at_tail(head, 3);
		insert_at_tail(head, 4);
		insert_at_tail(head, 5);
		insert_at_tail(head, 6);
		insert_at_tail(head, 7);
		insert_at_tail(head, 7);

		print_list(head);

		head = reverse(head, 4);

		print_list(head);
	}
	return 0;
}
