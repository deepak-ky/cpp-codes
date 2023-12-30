#include<iostream>
using namespace std;
class node{
     public:
     int data;
     node* next;
     node(int d)
      {
         data=d;
         next=NULL;
      }
};
void insertathead(node*&linked,int data)
{
    node*n=new node(data);
    n->next=linked;
    linked=n;
}
void insertattail(node*&linked,int data)
{
     node*temp=linked;
     while(temp->next!=NULL)
     {
         temp=temp->next;
     }
     temp->next=new node(data);
     return;
}
void print(node*linked)
{
node*temp=linked;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}

void srtlinkedlist(node* linked)
{
   node* temp=linked;

   while(temp!=NULL)
   {
       node* min=temp;
       node* r=temp->next;
       while(r!=NULL)
       {
          if(min->data>r->data)
            {

                min=r;

            }
                             r=r->next;

       }
         int x = temp->data;
        temp->data = min->data;
        min->data = x;
        temp = temp->next;

   }
}


int main()
{
node*linked=NULL;
int n;

cin>>n;
for(int i=0;i<n;i++)
{
    int dt;
    cin>>dt;
    if(i==0)
    {
      insertathead(linked,dt);
    }
    else insertattail(linked,dt);
}

srtlinkedlist(linked);

print(linked);
return 0;

}
