#include<iostream>
using namespace std;
int main()
{
   int n;
   cin>>n;
   int w=n+1;
   int k=w/2;
   cout<<"*";
   for(int i=1;i<=(n-3)/2;i++)
   {
       cout<<" ";
   }
   for(int i=1;i<=k;i++)
   {
       cout<<"*";
   }
   cout<<endl;
   for(int rows=1;rows<=(n-3)/2;rows++)
   {
       cout<<"*";
       for(int i=1;i<=(n-3)/2;i++)
       {
       cout<<" ";
       }
       cout<<"*";
       cout<<endl;
   }
     for(int i=1;i<=n;i++)
   {
       cout<<"*";
   }
   cout<<endl;
   for(int rows=1;rows<=(n-3)/2;rows++)
   {
        for(int i=1;i<=((n-3)/2)+1;i++)
       {
       cout<<" ";
       }
       cout<<"*";
       for(int i=1;i<=(n-3)/2;i++)
       {
       cout<<" ";
       }
       cout<<"*";
       cout<<endl;
   }
 for(int i=1;i<=k;i++)
       {
       cout<<"*";
       }
       for(int i=1;i<=(n-3)/2;i++)
       {
       cout<<" ";
       }
   cout<<"*";
   cout<<endl;











    return 0;
}
