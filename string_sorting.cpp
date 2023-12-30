#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool compare(string x,string y)
{
    return x.length()>y.length();
}
int main()
{
    cout<<"Enter the number of strings : ";
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    cout<<"The strings are : ";
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<endl;
    }
    cout<<"Lexographically Sorting the strings : ";
    cout<<endl;
    sort(s,s+n);
    cout<<"\n\nThe strings are : ";
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<endl;
    }

    sort(s,s+n,compare);
    cout<<"\nSorting on the basis of length in descending order : ";

  cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<endl;
    }
    return 0;
}
