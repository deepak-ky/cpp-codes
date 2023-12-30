#include<iostream>
#include<algorithm>
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
void printonlyrequired(node *root,int low,int high)
{
     if(root==NULL)
    {
     return;
    }
      if(root->data>low)
    {
    printonlyrequired(root->left,low,high);
    }
  if(root->data>=low && root->data<=high)
    {
    cout<<root->data<<" ";
    }
   if(root->data<high)
    {
    printonlyrequired(root->right,low,high);
    }
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    node* root=buildtreefromarray(a,0,n-1);

    int low,high;
    cin>>low;
    cin>>high;

	cout<<"# Preorder : ";
    print_preorder(root);
    cout<<endl;
	cout<<"# Nodes within range are : ";
    printonlyrequired(root,low,high);
	cout<<endl;

}
    char ch;
     cin >>ch;
    return 0;
}
