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
	node* next;

	node(int n)
	{
		data = n;
		next = NULL;
	}
};

void insert_at_head(node *&head, int d)
{
	node * n = new node(d);
	n->next = head;
	head = n;
}
void insert_at_tail(node *&head, int d)
{
	node * n = new node(d);
	node * temp = head;
	if (head == NULL)
	{
		insert_at_head(head, d);
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = n;
	n->next = NULL;
	return;
}

void print_list(node * head)
{


	node * temp = head;
	while (temp->next != head)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data << " ";
	cout << endl;
}

node * midpoint(node * head)
{


	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	node * slow = head;
	node * fast = head->next;
	while (fast != head && fast->next != head)
	{
		slow = slow->next;
		fast = fast->next->next;

	}

	slow = slow->next;

	return slow;
}


void splitList(node *head)
{

	if (head == NULL || head->next == NULL)
	{
		return;
	}
	node * mid = midpoint(head);
	cout << mid->data << endl;
	node * prev = NULL;
	node * temp = head;
	while (temp != mid)
	{
		prev = temp;
		temp = temp->next;
	}


	while (temp->next != head)
	{
		temp = temp->next;
	}

	cout << "prev->data : " << prev->data << endl;
	cout << "temp->data : " << temp->data << endl;
	cout << "mid->data  : " << mid->data << endl;
	cout << "mid->next->data  : " << mid->next->data << endl;


	prev->next = head;
	temp->next = mid;


	print_list(head);
	print_list(mid);
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		node * head = NULL;
		insert_at_tail(head, 2);
		insert_at_tail(head, 6);
		insert_at_tail(head, 1);
		insert_at_tail(head, 5);

		node * last = head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = head;

		splitList(head);



	}
	return 0;
}
