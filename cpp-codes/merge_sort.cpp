#include<iostream>
using namespace std;
int* merge(int *a,int *b,int m,int n)
{
    int i=0;
    int j=0;
    int k=0;
    int c[m+n];
    while(i<m && j<n)
     {
        if(a[i]<b[j])
        {
            c[k++]=a[i++];
        }
        else
        c[k++]=b[j++];
     }
     for(;i<m;i++)
     {
         c[k++]=a[i++];
     }
     for(;j<n;j++)
     {
         c[k++]=b[j++];
     }
     return c;
}
int main()
{
    int a[4],b[4];
    for(int d=0;d<4;d++)
    {
        cin>>a[d]>>b[d];
    }
    int *ptr=merge(a,b,4,4);
    cout<<"\nThe merged sorted array : ";
    /*for(int i=0;i<8;i++)
    {
        cout<<ptr[i]<<" ";
    }*/
    cout<<endl<<ptr[0]<<ptr[1];
    return 0;
}
