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

int length(node * head)
{
	if (head == NULL)
	{
		return 0;
	}
	node * temp = head;
	int len = 0;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	return len;
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

node * intersection_point(node * head1, node * head2)
{
	if (length(head1) < length(head2))
	{
		node * temp = head1;
		head1 = head2;
		head2 = head1;
	}
	int d = length(head1) - length(head2);
	node * temp1 = head1;
	node * temp2 = head2;
	int jump = 0;
	while (jump < d)
	{
		temp1 = temp1->next;
		jump++;
	}



	while (temp1 != NULL && temp2 != NULL)
	{

		if (temp1->data == temp2->data)
		{
			return temp1;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	return NULL;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		node * head1 = NULL;
		insert_at_tail(head1, 3);
		insert_at_tail(head1, 6);
		insert_at_tail(head1, 9);
		insert_at_tail(head1, 15);
		insert_at_tail(head1, 30);

		node * head2 = NULL;
		insert_at_tail(head2, 10);
		insert_at_tail(head2, 15);
		insert_at_tail(head2, 30);



		//Actually both the nodes should be the same here , I am only making the data same

		node * ans = intersection_point(head1, head2);

		if (ans == NULL)
		{
			cout << -1 << endl;
		}
		else cout << ans->data << endl;


	}
	return 0;
}
