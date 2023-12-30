#include<iostream>
#include <string.h>
using namespace std;
typedef long long ll;

ll combine(ll a, ll b) {
   ll times = 1;
   while (times <= b)
      times *= 10;
   return a*times + b;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
    int count=0;
    ll a1,b1;
    cin>>a1>>b1;
    ll a=1;
    ll b=1;
    for(a=1;a<=a1;a++)
    {
        for(b=1;b<=b1;b++)
        {
            ll w =a*b;
            ll q = combine(a,b);
            if((w+a+b)==q)
            {
                count++;
            }
        }
    }
    cout<<count;

        }
  return 0;






}
