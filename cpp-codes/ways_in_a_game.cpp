#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int table[n+1]={0};
    table[0]=1;
    for(int i=3;i<=n;i++)
    {
        table[i]+=table[i-3];
    }
    for(int i=5;i<=n;i++)
    {
        table[i]+=table[i-5];
    }
    for(int i=10;i<=n;i++)
    {
        table[i]+=table[i-10];
    }

   cout<<table[n];






    return 0;
}
