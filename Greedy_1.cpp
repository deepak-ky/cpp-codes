#include<iostream>
#include<algorithm>
using namespace std;
int make_change(int coins[],int n,int money)
{
    int ans=0;
    while(money>0)
    {
          int idx=upper_bound(coins,coins+10,money)-1-coins;
          money=money-coins[idx];
          ans++;
    }
    return ans;
}
int main()
{
    int money;
    cin>>money;
    int coins[]={1,2,5,10,20,50,100,200,500,2000};
    int t=10;
    cout<<"Coins needed are : "<<make_change(coins,t,money);
    return 0;

}
