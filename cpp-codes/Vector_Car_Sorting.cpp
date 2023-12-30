#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class car
{
public:
string name;
int x;
int y;

car(string n,int pos1,int pos2)
{
    name=n;
    x=pos1;
    y=pos2;
}
int distance()
{
    return x*x + y*y;
}
};
bool compare(car a,car b)
{
    int da=a.distance();
    int db=b.distance();
    if(da==db)
    {
        return a.name<b.name;
    }
    return da<db;
}
int main()
{
   int n;
   cin>>n;
   vector<car> v;
   for(int i=0;i<n;i++)
   {
       string s;
       int pos1;
       int pos2;
       cin>>s>>pos1>>pos2;
       car temp(s,pos1,pos2);
       v.push_back(temp);
   }
   sort(v.begin(),v.end(),compare);
   for(auto i:v)
   {
       cout<<i.name<<","<<i.x<<","<<i.y<<endl;
   }
return 0;
}

