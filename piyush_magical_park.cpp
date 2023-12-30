#include<iostream>
using namespace std;
void magicalpark(char a[][100],int m,int n,int k,int s)
{
 bool success=true;
 for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
     {
         int ch=a[i][j];
         if(s<k)
         {
             success=false;
             break;
         }
         else if(ch=='*')
         {
             s=s+5;
         }
         else if(ch=='.')
         {
             s=s-2;
         }
         else if(ch=='#')
         {
             break;
         }
         if(j!=(n-1))
         {
             s--;
         }
     }


  }


if(success)
{
    cout<<"Yes"<<endl;
    cout<<s;
}
else
{
    cout<<"No";
}

}
int main()
{
int n,m,k,s;
cin>>m>>n>>k>>s;
char park[100][100];
for(int i=0;i<m;i++)
{
  for(int j=0;j<n;j++)
    {
     cin>>park[i][j];
    }
}
magicalpark(park,m,n,k,s);
return 0;
}
