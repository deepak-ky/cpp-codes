#include<iostream>
#include<vector>
using namespace std;
int main()
{
int n;
cin>>n;
vector<int> v;
for(int i=0;i<n;i++)
{
  int w;
  cin>>w;
  v.push_back(w);
}
int m;
cin>>m;
vector<int> v1;
for(int i=0;i<m;i++)
{
  int w;
  cin>>w;
  v1.push_back(w);
}
if(n==m)
{
  vector<int> v2;
int carry=0;
for(int i=(n-1);i>=0;i--)
{
    int sum=v[i]+v1[i]+carry;
    int r=sum%10;
    int q=sum/10;
    carry=q;
    v2.push_back(r);
}
cout<<endl;
if(carry!=0)
{
    cout<<carry<<" ,";
}
for(int j=(v2.size()-1);j>=0;j--)
{
    cout<<v2[j]<<", ";
}
cout<<"END";


}
else if(m>n)
{
int diff=m-n;
for(int i=0;i<diff;i++)
{
  v.insert(v.begin(),0);
  n++;
}
vector<int> v2;
int carry=0;
for(int i=(n-1);i>=0;i--)
{
    int sum=v[i]+v1[i]+carry;
    int r=sum%10;
    int q=sum/10;
    carry=q;
    v2.push_back(r);
}
cout<<endl;
if(carry!=0)
{
    cout<<carry<<" ,";
}
for(int j=(v2.size()-1);j>=0;j--)
{
    cout<<v2[j]<<", ";
}
cout<<"END";
}
else if(n>m)
{
int diff=n-m;
for(int i=0;i<diff;i++)
{
  v1.insert(v1.begin(),0);
  m++;
}

vector<int> v2;
int carry=0;
for(int i=(n-1);i>=0;i--)
{
    int sum=v[i]+v1[i]+carry;
    int r=sum%10;
    int q=sum/10;
    carry=q;
    v2.push_back(r);
}
cout<<endl;
if(carry!=0)
{
    cout<<carry<<" ,";
}
for(int j=(v2.size()-1);j>=0;j--)
{
    cout<<v2[j]<<", ";
}
cout<<"END";
}



return 0;
}
