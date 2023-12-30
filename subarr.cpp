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
int i,j,k;
for(i=0;i<4;i++)
{
    for(j=i;j<4;j++)
    {
        for(k=i;k<=j;k++)
        {
            cout<<a[k]<<",";
        }
        cout<<endl;
    }

}
return 0;
}












