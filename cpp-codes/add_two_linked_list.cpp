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

void reverse(node *& head)
{
	node * p = NULL;
	node * c = head;
	node * n = head->next;
	while (n != NULL)
	{
		c->next = p;
		p = c;
		c = n;
		n = n->next;

	}
	c->next = p;
	head = c;
	return;
}


node *  add_linked_list(node * head1 , node * head2)
{
	reverse(head1);
	reverse(head2);
	node * temp1 = head1;
	node * temp2 = head2;
	node * ans = NULL;
	int carry = 0;
	int a, b, c, r;
	while (temp1 != NULL && temp2 != NULL)
	{
		a = temp1->data;
		b = temp2->data;
		c = a + b + carry;
		r = c % 10;
		insert_at_tail(ans, r);
		carry = c / 10;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	while (temp1 != NULL)
	{
		c = temp1->data + carry;
		r = c % 10;
		carry = c / 10;
		insert_at_tail(ans, r);
		temp1 = temp1->next;
	}

	while (temp2 != NULL)
	{
		c = temp2->data + carry;
		r = c % 10;
		carry = c / 10;
		insert_at_tail(ans, r);
		temp2 = temp2->next;
	}


	while (carry != 0)
	{
		insert_at_tail(ans, carry % 10);
		carry = carry / 10;
	}

	reverse(ans);


	return ans;



}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		node * head1 = NULL;
		insert_at_tail(head1, 4);
		insert_at_tail(head1, 5);
		insert_at_tail(head1, 9);
		insert_at_tail(head1, 9);

		node * head2 = NULL;
		insert_at_tail(head2, 3);
		insert_at_tail(head2, 4);
		insert_at_tail(head2, 5);
		insert_at_tail(head2, 6);
		insert_at_tail(head2, 7);
		insert_at_tail(head2, 8);


		node * ans = add_linked_list(head1, head2);


		print_list(ans);

	}
	return 0;
}
