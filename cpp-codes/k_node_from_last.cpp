#include<iostream>
#include<list>
#include <iterator>
typedef long long int lli;
using namespace std;
int main()
{
    list<int> intlist;
    list<int>::iterator ptr;
    list <int> :: iterator it;

        int w;
    for(int i=0;w!=-1;i++)
    {
        cin>>w;
        if(w!=-1)
        {intlist.push_back(w);}
    }
    ptr=intlist.begin();
    it=intlist.begin();
    int k;
    cout<<"\nEnter k :";
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        ptr++;
    }
    while(ptr!=intlist.end())
    {
        it++;
        ptr++;
    }
cout<<"\nValue is : "<<*it;
    return 0;
}
