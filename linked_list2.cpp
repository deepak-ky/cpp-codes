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
void deleteathead(node*&head)
{
    if(head==NULL)
    {
        return;
    }
    else
      {
          node*temp=head;
          head=head->next;
          delete temp;

        return;
      }
}
void deleteattail(node*&head)
{
    node*prev=NULL;
    node*temp=head;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    delete temp;
    prev->next=NULL;
}
deleteatmiddle(node*&head,int p)
{
    node*prev=NULL;
    node*temp=head;
    int jump=1;
    while(jump<=p)
    {
        prev=temp;
        temp=temp->next;
        jump++;
    }
    delete temp;
    prev->next=temp->next;

}
bool searchrecursive(node*&head,int key)
{
    if(head==NULL)
    {
        return false;
    }
    else if(head->data==key)
    {
        return true;
    }
    else{ return searchrecursive(head->next,key);}
}
bool searchiterative(node*&head,int key)
{

    node*temp=head;
    while(temp!=NULL)
    {
    if(temp->data==key)
    {
        return true;
    }
    temp=temp->next;
    }

    return false;
}
void buildlist(node*&head)
{
int data;
cin>>data;
while(data!=-1)
{
insertattail(head,data);
cin>>data;
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
node*head=NULL;
buildlist(head);
print(head);

return 0;
}
