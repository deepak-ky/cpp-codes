#include<iostream>
#include<string.h>
using namespace std;
int check_and_print(string a,string str)
 {
     int len1=str.length();
     int flag=0;
     for(int i=0;i<len1;i++)
     {
         if(a[i]!=str[i])
         {
             flag=1;
             break;
         }
     }
     return flag;
 }
int main()
{
    int n;
    cin>>n;
    int size=n;
    cout<<"\n Size now : "<<size<<endl;
    string str[3000];
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
    }
    string temp;
    for(int i = 0; i < (n-1); ++i)
       for( int j = i+1; j < n; ++j)
       {
          if(str[i] > str[j])
          {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
          }
    }
    cout<<"\n last element now : "<<str[size-1]<<endl;
    int q;
    cin>>q;
    for(int j=0;j<q;j++)
    {
    string query;
    cin>>query;
    int count=0;
    for(int i=0;i<size;i++)
    {
        int w=check_and_print(str[i],query);
        if(w==0)
        {
            cout<<str[i]<<endl;
            count++;
        }
    }
    if(count==0)
    {
        size++;
        str[size-1]=query;
        cout<<"No Suggestions"<<endl;
    }
    }
    cout<<"\n Size now : "<<size<<endl;
    cout<<"\n last element now : "<<str[size-1]<<endl;
    return 0;
}
