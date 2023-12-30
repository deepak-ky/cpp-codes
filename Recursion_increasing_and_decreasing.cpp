#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void decre(int n)
{
    if(n==0)
    {
        return;
    }
    cout<<n<<",";
    decre(n-1);
}
void incre(int n)
{
    if(n==0)
    {
        return;
    }
    incre(n-1);
    cout<<n<<",";

}
int main()
{
int n;
cin>>n;
decre(n);
cout<<endl;
incre(n);
return 0;
}

