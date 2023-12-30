#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool compare(string x,string y)
{
    string xy=x.append(y);
    string yx=y.append(x);
    if(xy>yx)
    {
        return 1;
    }
    else return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
     int n;
     cin>>n;
     vector<string> v;
    for(int i=0;i<n;i++)
    {
  string w;
  cin>>w;
  v.push_back(w);
    }
  sort(v.begin(),v.end(),compare);
    for(int i=0;i<n;i++)
    {
cout<<v[i];
    }
    cout<<endl;
}


return 0;
}
