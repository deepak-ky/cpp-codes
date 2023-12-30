#include<iostream>
#include<bits/stdc++.h>
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
    int total_water=0;
    int left[n];
    int right[n];
    left[0]=a[0];
    right[n-1]=a[n-1];
    for(int i=1;i<n;i++)
    {
        left[i]=max(left[i-1],a[i]);
    }
    cout<<"\nLeft array : ";
        for(int i=0;i<n;i++)
    {
        cout<<left[i]<<" ";
    }

    for(int i=n-2;i>=0;i--)
    {
        right[i]=max(right[i+1],a[i]);
    }
        cout<<"\nRight array : ";
        for(int i=0;i<n;i++)
    {
        cout<<right[i]<<" ";
    }


    for(int i=0;i<=(n-1);i++)
    {

      total_water+=(min(left[i],right[i])-a[i]);
            cout<<"\ntotal water till here : "<<total_water;


    }






}
