#include<iostream>
#include "myvector.h"
using namespace std;
int main()
{
    myvector<int> v;
    v.push_back(72);
    v.push_back(73);
    v.push_back(74);
    v.push_back(75);
    v.push_back(79);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<",";
    }
    cout<<"\nCapacity : "<<v.capacity();
    cout<<endl;
     myvector<char> v1;
    v1.push_back(72);
    v1.push_back(73);
    v1.push_back(74);
    v1.push_back(75);
    v1.push_back(79);
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<",";
    }
    cout<<"\nCapacity : "<<v1.capacity();
    return 0;
}
