#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            cout<<a[i]<<" ";
        }
        else count++;

    }
    for(int i=0;i<count;i++)
    {

        cout<<"0 ";
    }
   return 0;
}
