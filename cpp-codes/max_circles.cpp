#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(pair<int,int> p1,pair<int,int> p2)
{
    return p1.second<p2.second;
}
int main()
{
int n;
cin>>n;
vector<pair<int,int> > v;
for(int i=0;i<n;i++)
{
    int c;
    cin>>c;
    int r;
    cin>>r;
    int s=c-r;
    int e=c+r;
    v.push_back(make_pair(s,e));
}
int count=1;
sort(v.begin(),v.end(),compare);
int fin=v[0].second;
for(int i=1;i<n;i++)
{
    if(v[i].first>=fin)
            {
              fin=v[i].second;
              count++;
            }
}
cout<<count;
return 0;
}
