#include<iostream>
using namespace std;
int main()
{
    int n1,n2;
cout<<"Enter the size of the matrix : ";
cin>>n1>>n2;
cout<<endl<<"Sorted Entries ONLY:\n";
int k,l;
int a[n1][n2];
for(int i=0;i<n1;i++)
{
 for(int j=0;j<n2;j++)
 {
  cin>>a[i][j];
 }
}
cout<<"\nThe original matrix is : \n";
for(int i=0;i<n1;i++)
{
 for(int j=0;j<n2;j++)
 {
  cout<<" "<<a[i][j];
 }
 cout<<endl;
}
int key;
cout<<"Enter the element to be found : ";
cin>>key;
int left=n1-1;
int down=0;
int pos1;
int pos2;
int flag=0;
cout<<"\nStarting element : "<<a[left][down];
cout<<endl;
while(left>=0 && down<n2)
{
    if(a[left][down]==key)
    {
        pos1=left;
        pos2=down;
        flag=1;

        break;
    }
    else if(a[left][down]>key)
    {
        left--;
    }
    else if(a[left][down]<key)
    {
        down++;
    }
}
if(flag==0)
{
    cout<<"\nElement not present in the matrix " ;
}
else{
    cout<<"Element found at : "<<pos1<<" "<<pos2;
        cout<<endl;}
return 0;
}

