#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define watch(var,x)                 cout <<"\nValue of x here is : "<<(x) << endl
#define mod                          1000000007
class node
{
public:
	int data;
	node* next;
	node(int d)
	{
		data = d;
		next = NULL;
	}
};
void insertathead(node*&head, int d)
{
	node*n = new node(d);
	n->next = head;
	node*temp = head;
	if (head != NULL)
	{
		while (temp->next != head)
		{
			temp = temp->next;
		} temp->next = n;
	}
	else
	{
		n->next = n;
	}
	head = n;
}
void printlist(node*head)
{
	node*temp = head;
	while (temp->next != head)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << temp->data << " END";
}
node* getnode(node *&head,int data)
{
  node*temp=head;
  while(temp->next!=head)
  {
    if(temp->data==data)
    {
       return temp;
    }
    temp=temp->next;
  }
  if(temp->data==data) return temp;
  else return NULL;
}
void deletenode(node *&head,int data)
{
    node *del=getnode(head,data);
    if(del==NULL)
    {
      cout<<"\nThe node is not present in the circular linked list ";
    }
    if(del==head)
    {
      head=head->next;
    }
    node* temp=head;
    while(temp->next!=del)
    {
      temp=temp->next;
    }
    temp->next=del->next;
    delete del;
}
int32_t main()
{

	node* head = NULL;
	insertathead(head, 5);
	insertathead(head, 6);
	insertathead(head, 7);
	insertathead(head, 8);
	insertathead(head,9);
	printlist(head);
	deletenode(head,7);
	cout<<endl;printlist(head);
	return 0;
}
