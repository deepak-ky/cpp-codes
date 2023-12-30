#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
//int getbit(int n,int i)
//{
//    int mask=(1<<i);
//    int bit=(mask&n)>0?1:0;
//    return bit;
//}
//int binary(int n)
//{  int ans=0;
//int p=1;
//    while(n>0)
//    {
//        int last=getbit(n,0);
//        ans+=p*last;
//        p*=10;
//        n=n>>1;
//    }
//    return ans;
//}
int main()
{
 lli n;
 cin>>n;
// int w=binary(n);
// cout<<w;
// int i=0;
// int tomult=1;
 vector<lli> v;
// while(w>0)
// {
//    int value=0;
//    int n1=getbit(w,0);
//    cout<<"\nn1 here : "<<n1;
//    value+=(n1*tomult);
//    tomult*=2;
//    cout<<"\nValue now : "<<value;
//    cout<<"\nto mult now : "<<tomult;
//    int n2=getbit(w,1);
//    cout<<"\nn2 here : "<<n2;
//    value+=(n2*tomult);
//    tomult*=2;
//    cout<<"\nValue now : "<<value;
//    cout<<"\nto mult now : "<<tomult;
//    int n3=getbit(w,2);
//    cout<<"\nn3 here : "<<n3;
//    value+=(n3*tomult);
//    tomult*=2;
//    cout<<"\nValue now : "<<value;
//    cout<<"\nto mult now : "<<tomult;
//    v.push_back(value);
// }
// cout<<endl;
// for(auto x:v)
// {
//   cout<<x<<endl;
// }
while(n>0)
{
    lli r=n%8;
    v.push_back(r);
    n=n/8;
}
for(lli i=v.size()-1;i>=0;i--)
{
    cout<<v[i];
}
 return 0;
}
