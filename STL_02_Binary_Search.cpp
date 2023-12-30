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
    bool ispresent=binary_search(a,a+n,key);
    int* lb=lower_bound(a,a+n,key);
    int index=lb-a;
    if(ispresent)
    {
        cout<<endl<<"Element is present at index "<<index;
    }
    else
    {
        cout<<endl<<"Element is not present ";
    }
    int* ub=upper_bound(a,a+n,key);
    cout<<endl<<"Number of occurence of the element is : "<<ub-lb;
return 0;
}
