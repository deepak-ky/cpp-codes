#include<iostream>
using namespace std;
int main()
{
int a[4],m;
for(m=0;m<4;m++)
{
    cin>>a[m];
}
cout<<endl;
int sum=0;
int largesum=0;

int i,j,k;
for(i=0;i<4;i++)
{
    for(j=i;j<4;j++)
    {
        sum=0;
        for(k=i;k<=j;k++)
        {
            sum=sum+a[k];
            cout<<a[k]<<",";
        }
        if(sum>largesum)
        {
            largesum=sum;
        }
        cout<<endl;
    }

}
cout<<endl<<endl<<"::"<<largesum;
return 0;
}












