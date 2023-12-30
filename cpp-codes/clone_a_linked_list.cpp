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
	node * rand;

	node(int d)
	{
		data = d;
		next = NULL;
		rand = NULL;
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

//O[N] space and O[N] time

void clone_list_method_1(node * head)
{

	node * clone_head = NULL;

	unordered_map<node*, node*> mp;

	node * temp = head;
	while (temp != NULL)
	{
		node * n = new node(temp->data);
		mp[temp] = n;
		temp = temp->next;
	}



	temp = head;
	while (temp != NULL)
	{
		node * org_next = temp->next;
		node * org_rand = temp->rand;
		node * curr_point = mp[temp];
		curr_point->next = mp[org_next];
		curr_point->rand = mp[org_rand];
		temp = temp->next;
	}


	temp = head;

	clone_head = mp[head];



	print_list(clone_head);

	return;
}


//O[N] space and O[1] time
void clone_list_method_2(node * head)
{

	node * temp = head;

	while (temp != NULL)
	{
		node * n = new node(temp->data);
		node * org_next = temp->next;
		temp->next = n;
		n->next = org_next;
		temp = temp->next->next;
	}


	temp = head;



	while (temp != NULL)
	{
		node * curr_point = temp->next;
		node * org_rand = temp->rand;
		if (org_rand != NULL)
		{
			node * arf = org_rand->next;
			curr_point->rand = arf;
		}
		temp = temp->next->next;
	}

	temp = head;

	node * clone_head = temp->next;

	while (temp != NULL)
	{
		node * n = temp->next;
		temp->next = n->next;
		if (temp->next != NULL)
		{
			n->next = temp->next->next;
		}
		else
		{
			n->next = temp->next;
		}

		temp = temp->next;
	}


	print_list(head);
	print_list(clone_head);

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

		node * temp1 = head;
		node * temp2 = head->next->next;

		temp1->rand = temp2;
		temp2->rand = temp1;

		node * temp3 = head->next;
		node * temp4 = head->next->next->next;

		temp3->rand = temp4;

		//clone_list_method_1(head);
		clone_list_method_2(head);
	}
	return 0;
}
