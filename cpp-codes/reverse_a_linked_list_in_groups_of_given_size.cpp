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




node * reverse_in_groups(node * head , int k)
{
	node * prev = NULL;


	//That is why not using n in the while statement instead of NULL
	node * n = NULL;
	//That is why not using n in the while statement instead of NULL

	node * curr = head;
	int jump = 0;
	while (jump < k &&  curr != NULL)
	{


		n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n;

		jump++;
	}

	if (curr != NULL)
	{
		head->next = reverse_in_groups(curr, k);
	}

	return prev;


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



		print_list(head);
		head = reverse_in_groups(head, 1);
		print_list(head);

	}
	return 0;
}
