#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int count=1;
    int count1=n-2;
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
         {
             cout<<"*"<<'\t';
         }
        for(k=2;k<=n-1;k++)
        {
            if(count==count1)
                count=count-2;




        }
       cout<<endl;
    }
    return 0;
}
