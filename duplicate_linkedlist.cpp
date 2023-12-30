#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
    data=d ;
    next=NULL;
    }
};
void insertathead(node*&head,int data)
{
node*n= new node(data);
n->next=head;
head=n;
}
void insertattail(node*&head,int data)
{

        node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;

    }
    temp->next=new node(data);
    return;
}
void removeallocc(node*&head)
{
    node *temp=head;
    while(temp->next!=NULL)
    {
        if((temp->data)==(temp->next->data))
        {
            node *t=temp->next;
            temp->next=t->next;
            delete(t);
        }
        else
        {
            temp=temp->next;
        }
    }
}
void print(node*head)
{
node*temp=head;
while(temp!=NULL)
{
cout<<temp->data<<"->";
temp=temp->next;
}
}
int main()
{
   node *head=NULL;
   int n;
   cout<<"Enter the number of integers : ";
   cin>>n;
   int no;
   for(int i=0;i<n;i++)
    {
      cin>>no;
      if(i==0)
      {
          insertathead(head,no);
      }
       else insertattail(head,no);
    }
    cout<<"\nInitially the list is : ";
print(head);

    removeallocc(head);
    cout<<"\nNow the list is : ";
   print(head);
    return 0;
}
