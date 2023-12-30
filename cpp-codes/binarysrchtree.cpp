#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;
class node
{
public:
int data;
node* left;
node* right ;
 node(int d)
 {
  data=d;
  left=NULL;
  right=NULL;
 }
};
node *insertbst(node *root,int data)
{
if(root==NULL)
 {
 return new node(data);
 }
if(data<=root->data)
{root->left=insertbst(root->left,data);}
else
{root->right=insertbst(root->right,data);}
return root;
}
node *build()
{
int d;
cin>>d;
node *root=NULL;
while(d!=-1)
{
root=insertbst(root,d);
cin>>d;
}
return root;
}
void inorder(node *root)
{
 if(root==NULL)
 {return;}
 inorder(root->left);
 cout<<root->data;
 inorder(root->right);
}
bool srch(node *root,int data)
{
    if(root==NULL)
    {
        return false;
    }
  if(root->data==data)
  {
      return true;
  }
   if(data<=root->data)
   {
       return srch(root->left,data);
   }

   else
   {
       return srch(root->right,data);
   }
}
int main()
{
node *root=build();
inorder(root);
cout<<endl;
int s;
cin>>s;
if(srch(root,s))
{
    cout<<"PRESENT";
}
else cout<<"NOT PRESENT";
return 0;
}
