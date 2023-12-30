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

void pair_with_given_sum(node * head , int sum)
{
	node * front = head;
	node * temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	while (front != temp)
	{
		int w = front->data + temp->data;
		if (w == sum)
		{
			cout << front->data << " " << temp->data << endl;
			if (temp == front->next)
			{
				break;
			}
			front = front->next;
			temp = temp->prev;
		}
		else if (w > sum)
		{
			temp = temp->prev;
		}
		else
		{
			front = front->next;
		}
	}

	return;
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
		insert_at_tail(head, 3);
		insert_at_tail(head, 4);
		//insert_at_tail(head, 5);
		insert_at_tail(head, 6);
		//insert_at_tail(head, 8);
		//insert_at_tail(head, 9);

		pair_with_given_sum(head, 7);
	}
	return 0;
}
