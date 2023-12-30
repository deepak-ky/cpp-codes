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


int multiply_linked_list(node * head1 , node * head2)
{
	int num1 = 0;
	int num2 = 0;

	node * temp1 = head1;
	while (temp1 != NULL)
	{
		num1 = ((num1 * 10)  % mod + (temp1->data) % mod ) % mod;
		temp1 = temp1->next;

	}

	node * temp2 = head2;
	while (temp2 != NULL)
	{
		num2 = ((num2 * 10) % mod + (temp2->data) % mod) % mod;
		temp2 = temp2->next;
	}


	int ans = ((num1 % mod) * (num2 % mod)) % mod;

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
		// insert_at_tail(head1, 5);
		// insert_at_tail(head1, 9);
		// insert_at_tail(head1, 9);

		node * head2 = NULL;
		insert_at_tail(head2, 3);
		// insert_at_tail(head2, 4);
		// insert_at_tail(head2, 5);
		// insert_at_tail(head2, 6);
		// insert_at_tail(head2, 7);
		// insert_at_tail(head2, 8);


		cout << multiply_linked_list(head1, head2);



	}
	return 0;
}
