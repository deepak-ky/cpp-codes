#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{
 public:
 int data;
 node* left;
 node* right;
 node(int d)
 {
  data=d;
  left=NULL;
  right=NULL;
 }
};
node* buildtree()
{
   string left,right;
   int d;
   cin>>d;
   node* root= new node(d);
   cin>>left;
   if(left=="true")
   {
      root->left=buildtree();
   }
   cin>>right;
   if(right=="true")
   {
      root->right=buildtree();
   }
   return root;
}
void print_preorder(node *root)
{
if(root==NULL)
 {
 return;
 }
cout<<root->data<<" ";
print_preorder(root->left);
print_preorder(root->right);
}
class hbpair
{
public:
    int height;
    bool balance;
};
int print_height(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ls=print_height(root->left);
    int rs=print_height(root->right);
    return (max(ls,rs)+1);

}
hbpair isheightbalance (node*root)
{
    hbpair p;
    if(root==NULL)
    {
        p.height=0;
        p.balance=true;
        return p;
    }
    hbpair left=isheightbalance(root->left);
    hbpair right=isheightbalance(root->right);
    p.height=max(left.height,right.height)+1;
    if(abs(left.height-right.height)<=1 && left.balance==true && right.balance==true)
    {
        p.balance=true;
    }
    else{
        p.balance=false;
    }
    return p;
}
int main()
{
node* root=buildtree();

if(isheightbalance(root).balance)
{
    cout<<"true";
}
else{
    cout<<"false";
}
return 0;
}
