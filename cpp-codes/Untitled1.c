#include<iostream>
using namespace std;
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
int main()
{



}
