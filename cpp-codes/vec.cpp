#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long int lli;
class run
{
    public:
    lli odi;
    lli test;
    lli t20;
};
int main()
{
lli n;
cin>>n;
run runs[n];
for(lli i=0;i<n;i++)
{
    cin>>runs[i].odi;
}
for(lli i=0;i<n;i++)
{
    cin>>runs[i].test;
}
for(lli i=0;i<n;i++)
{
    cin>>runs[i].t20;
}
vector<lli> v;
for(lli i=0;i<n;i++)
{
   lli a=runs[i].odi+runs[i].test+runs[i].t20;
   cout<<a<<endl;
   v.push_back(a);
}
cout<<"\nThe elements of the vector are : ";
for(lli i=0;i<v.size();i++)
{
    cout<<v[i]<<" ";
}
lli q;
cin>>q;
while(q--)
{
    sort(v.begin(),v.end());
    lli t;
    cin>>t;
    if(t<v.size())
    {
    cout<<v[t-1]<<endl;
    v.erase(v.begin()+t-1);
    }
    else
        {
            cout<<-1<<endl;
        }
}
return 0;
}
