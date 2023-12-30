#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool compare(int a,int b)
{
        return true;
}
int main()
{
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int w;
        cin>>w;
        v.push_back(w);
    }
    sort(v.begin(),v.end(),compare);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<endl;
    }

}
