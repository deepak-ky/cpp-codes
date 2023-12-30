#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> a;
    vector<int> b(4,9);
    vector<int> c(b.begin(),b.end());
    vector<int> d{1,2,3,4,5,6};
    for(int i=0;i<b.size();i++)
    {
        cout<<b[i]<<",";
    }
    cout<<endl;

    for( vector<int>::iterator it=d.begin();it!=d.end();it++)
    {
        cout<<*it<<",";
    }
    cout<<endl;
    for(auto x:c)
    {
        cout<<x<<",";
    }
    vector<int> e;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int w;
        cin>>w;
      e.push_back(w);
    }

cout<<endl<<d.size();

cout<<endl<<d.capacity();
cout<<endl<<d.max_size();
cout<<endl<<e.size();
cout<<endl<<e.capacity();
cout<<endl<<e.max_size();
vector<int> f;
f.reserve(1000);
int n1;
cin>>n1;
for(int i=0;i<n1;i++)
{
    int w;
    cin>>w;
    f.push_back(w);
    cout<<"\nCapacity now : "<<f.capacity()<<endl;
}
    return 0;
}
