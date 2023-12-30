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
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

node * partition(node *& head, node * temp)
{
	if (head == NULL || head == temp)
	{
		return head;
	}
	node * i = NULL;
	node * i1 = head;
	node * j = head;

	while (j != temp)
	{

		if (j->data <= temp->data)
		{
			i = i1;
			int a = j->data;
			j->data = i->data;
			i->data = a;
			i1 = i1->next;
		}


		j = j->next;
	}

	int a = temp->data;
	temp->data = i1->data;
	i1->data = a;


	return i1;
}

void quick_sort(node *& head, node * temp)
{
	if (head == NULL)
	{
		return;
	}

	if (temp == head)
	{
		return;
	}



	if (head != temp)
	{

		node * mid = partition(head, temp);


		if (mid != head)
		{
			node * prev = head;
			while (prev->next != mid)
			{
				prev = prev->next;
			}

			quick_sort(head, prev);
		}



		if (mid != temp)
		{
			mid = mid->next;


			quick_sort(mid, temp);
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
		// insert_at_tail(head, -1);
		// insert_at_tail(head, 5);
		insert_at_tail(head, 3);
		insert_at_tail(head, 4);
		insert_at_tail(head, 1);
		//insert_at_tail(head, 0);
		//insert_at_tail(head, 60);

		node * last = head;
		while (last->next != NULL)
		{
			last = last->next;
		}



		print_list(head);
		quick_sort(head, last);
		print_list(head);

	}
	return 0;
}
