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
node* buildtree()
{
int d;
cin>>d;
if(d==-1)
{
return NULL;
}
node*root = new node(d);
root->left=buildtree();
root->right=buildtree();
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
void print_inorder(node *root)
{
if(root==NULL)
 {
 return;
 }
print_inorder(root->left);
cout<<root->data<<" ";
print_inorder(root->right);
}
void print_postorder(node *root)
{
if(root==NULL)
 {
 return;
 }
print_postorder(root->left);
print_postorder(root->right);
cout<<root->data<<" ";
}
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
void printkthlevel(node*root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==1)
    {
        cout<<root->data<<" ";
        return;
    }
    printkthlevel(root->left,k-1);
    printkthlevel(root->right,k-1);
}
void printalllevel(node*root)
{
    int h=print_height(root);
    for(int i=1;i<=h;i++)
    {
        printkthlevel(root,i);
        cout<<endl;
    }
}
void printbfs(node* root)
{
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        node*f=q.front();
        cout<<f->data<<",";
        q.pop();
    if(f->left){q.push(f->left);}
     if(f->right){q.push(f->right);}
    }
    return;
}
    void printlinebfs(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
{
        node*f=q.front();
        if(f==NULL)
        {
            cout<<endl;
            q.pop();
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
           cout<<f->data<<",";
           q.pop();
           if(f->left){q.push(f->left);}
           if(f->right){q.push(f->right);}
    }
}

return;
}
int count(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+count(root->left)+count(root->right);

}
int diameter(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int h1=print_height(root->left);
    int h2=print_height(root->right);
    int op1=h1+h2;
    int op2=diameter(root->left);
    int op3=diameter(root->right);
    return max(op1,max(op2,op3));
}
class h_and_d
{
public:
    int h;
    int d;

};
h_and_d fastd(node *root)
{
    h_and_d hd;
    if(root==NULL)
    {
        hd.h=hd.d=0;
        return hd;
    }
    h_and_d left_hd=fastd(root->left);
    h_and_d right_hd=fastd(root->right);
    hd.h=max(left_hd.h,right_hd.h)+1;
    hd.d=max(left_hd.h+right_hd.h,max(left_hd.d,right_hd.d));
    return hd;
}
int replacesum(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return root->data;
    }
    int leftsum=replacesum(root->left);
    int rightsum=replacesum(root->right);
    int temp=root->data;
    root->data=leftsum+rightsum;
    return temp+root->data;
}
class hbpair
{
public:
    int height;
    bool balance;
};
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
node *buildtreefromarray(int *a,int s,int e)
{
    if(s>e)
        {return NULL;}
int   mid=(s+e)/2;
  node *root=new node(a[mid]);
  root->left=buildtreefromarray(a,s,mid-1);
  root->right=buildtreefromarray(a,mid+1,e);
  return root;

}
node *createtreefromtrav(int *in,int *pre,int s,int e)
{
    static int i=0;
    if(s>e)
    {
        return NULL;
    }
    node *root=new node(pre[i]);
    int index=-1;
    for(int j=s;j<=e;j++)
    {
        if(in[j]==pre[i])
        {
            index=j;
            break;
        }
    }
    i++;
    root->left=createtreefromtrav(in,pre,s,index-1);
    root->right=createtreefromtrav(in,pre,index+1,e);
    return root;
}
int main()
{

//node* root=buildtree();
/*
print_preorder(root);
cout<<endl;
print_inorder(root);
cout<<endl;
print_postorder(root);
cout<<endl;
int w=print_height(root);
cout<<w;
*/
//printlinebfs(root);
//cout<<endl<<count(root);
//cout<<endl<<diameter(root);
//h_and_d hd1=fastd(root);
//cout<<hd1.h<<endl;
//cout<<hd1.d<<endl;
//replacesum(root);
//printlinebfs(root);
//if(isheightbalance(root).balance)
//{
  //  cout<<"BALANCED";
//}
//else{
  //  cout<<"NOt a balanced tree";
//}
//int a[]={1,2,3,4,5,6};
//int n=6;
//node *root=buildtreefromarray(a,0,n-1);
int in[]={3,2,8,4,1,6,7,5};
int pre[]={1,2,3,4,8,5,6,7};
int n=sizeof(in)/sizeof(int);
node *root=createtreefromtrav(in,pre,0,n-1);
printlinebfs(root);
return 0;
}
