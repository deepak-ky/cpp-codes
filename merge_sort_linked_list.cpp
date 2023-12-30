#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
class node
{
public:
	int data;
	node * next;

	node(int d)
	{
		data = d;
		next = NULL;
	}
};
void insertathead(node*&head, int d)
{
	node * n = new node(d);
	n->next = head;
	head = n;
}
void insertattail(node*&head, int d)
{
	node*n = new node(d);
	node * temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = n;
	n->next = NULL;

}
node * midpoint(node * head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	node * slow = head;
	node * fast = head->next; //if we only do node*fast = next we will end up at the upper mid in an even matrix
	while ((fast != NULL) && (fast->next != NULL))
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
void print(node * head)
{
	node*temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}

}

node * mergesort(node*&head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	node * mid = midpoint(head);
	//cout << mid->data << endl;
	node * a = head;
	node * b = mid->next;
	mid->next = NULL;
	a = mergesort(a);
	b = mergesort(b);
	node * c = merge(a, b);
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
	//display head of data what do we get if we cout<<head->data;
	int n;
	cin >> n;
	node * head = NULL;
	for (int i = 0; i < n; i++)
	{
		int d;
		cin >> d;
		if (i == 0)
		{
			insertathead(head, d);
		}
		else insertattail(head, d);
	}
	/*	insertathead(head, 2);
		insertathead(head, 3);
		insertathead(head, 4);
		insertathead(head, 5);
		insertathead(head, 6);
		insertattail(head, 7);
		print(head);*/
	//cout << endl;
	/*node * mid = midpoint(head);
	if (mid != NULL)
		cout << mid->data;
	else cout << "String is empty!";*/
	head = mergesort(head);
	//cout << endl;
	print(head);
	return 0;
}
