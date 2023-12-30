#include<iostream>
#include<math.h>
using namespace std;
int power_optimised(int a,int n)
{
    int ans=1;
    while(n>0)
    {
        int last_bit=(n&1);
        if(last_bit)
        {
            ans=ans*a;
        }
        a*=a;
        n=n>>1;

    }
    return ans;
}
bool isodd(int n)
{
    return (n&1);
}
int getbit(int n,int i)
{
    int mask=(1<<i);
    int bit=(mask&n)>0?1:0;
    return bit;
}
int setbit(int n,int i)
{
    int mask=(1<<i);
    int ans=n|mask;
    return ans;
}
void clearbit(int &n,int i)
{
    int mask=~(1<<i);
    n=n&mask;
}
void updatebit(int &n,int i,int v)
{
    clearbit(n,i);
    int mask=(v<<i);
    n=n|mask;
}
int clearlastbits(int n,int i)
{
    int mask=(-1<<(i+1));
    return n&mask;
}
int clearbitsinrange(int n,int i,int j)
{
    int mask1=(-1<<(j+1));
    int mask2=pow(2,i)-1;
    int mask3=mask1|mask2;
    return (n&mask3);
}
int binary(int n)
{  int ans=0;
int p=1;
    while(n>0)
    {
        int last=getbit(n,0);
        ans+=p*last;
        p*=10;
        n=n>>1;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int b;
    cin>>b;
    cout<<"\nThe naswer is : "<<power_optimised(n,b);
    /*
    int no;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        ans^=no;
    }

    cout<<ans;
    */
    cout<<"\nThe number of set bits in the number : "<<__builtin_popcount(n)<<endl;
    cout<<"\nThe binary representation of the number is : "<<binary(n)<<endl;
    cout<<isodd(n);
    int i;
    cin>>i;
    int j;
    cin>>j;
    cout<<endl<<clearbitsinrange(n,i,j)<<endl;
    cout<<endl<<clearlastbits(n,i);
    cout<<getbit(n,i);
    cout<<endl<<setbit(n,i);
    /*clearbit(n,i);*/
    cout<<endl<<n;
    int v;
    cin>>v;
    updatebit(n,i,v);
    cout<<endl<<n;


return 0;
}
