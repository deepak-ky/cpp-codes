#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    /*Find function in the array */
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the element to be found : ";
    int key;
    cin>>key;
    auto it=find(a,a+n,key);
    cout<<it;





}
