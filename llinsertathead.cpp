#include<iostream>
using namespace std;
class node{
  public:
  int data;
  node*next;
  node(int d)
  {
  data=d;
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

void insertatmiddle(node*&head,int data,int p)
{
        node*temp=head;
        int jump=1;
        while(jump<=p-1)
        {
            temp=temp->next;
            jump++;
        }
        node*n=new node(data);
        n->next=temp->next;
        temp->next=n;

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
node*head=NULL;
insertathead(head,5);
insertathead(head,6);
insertathead(head,7);
print(head);
cout<<endl;
insertattail(head,8);
print(head);
cout<<endl;
insertatmiddle(head,4,2);
print(head);
return 0;
}
