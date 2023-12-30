#include<iostream>
using namespace std;
typedef long long int ll;
int main()
{
ll k;
ll flag=1;
cin>>k;
ll a[k];
ll r[k];
for(ll i=0;i<k;i++)
{
    cin>>a[i];
}
for(ll i=0;i<k;i++)
{
    cin>>r[i];
}
ll x=2;
while(flag!=2)
{
    if((x%a[0])==r[0])
    {
        for(ll i=1;i<k;i++)
        {
            if(x%a[i]!=r[i])
            {
                flag=1;
                break;
            }
            else flag=2;
        }
    }
    if(flag==1)
    {
       x++;
    }
    else if(flag==2)
    {
        cout<<x;
        break;
    }

}
return 0;
}
while(q!=0)
{
   int a[q];
   for(int i=0;i<q;i++)
   {
       cin>>a[q];
   }
   char ch;
   cin>>ch;
   for(int i=0;i<q;i++)
   {
       str[a[i]]=ch;
   }
   cout<<"\nString now : "<<str;
   if(check(str))
   {
       cout<<"YES"<<endl;
   }
   else cout<<"NO";
}
