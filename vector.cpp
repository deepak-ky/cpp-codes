#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
vector<int> v;
int n;
cin>>n;
int i,j;
for(i=0;i<n;i++)
{
int temp;
cin>>temp;
v.push_back(temp);
}
v.pop_back();
sort(v.begin(),v.end());
for(j=0;j<v.size();j++)
{
cout<<" : \n"<<v[j];
}
return 0;
}











