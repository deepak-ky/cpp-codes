#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findsmallest(int a[][1000],int i,int row_value,int k)
{
    if(a[i][row_value]<=a[row_value][k] && a[i][row_value]<=a[i][k])
    {
        return 9;
    }
    else if(a[row_value][k]<=a[i][row_value] && a[row_value][k]<=a[i][k])
    {
        return 10;
    }
    else if(a[i][k]<=a[i][row_value] && a[i][k]<=a[row_value][k])
    {
        return 11;
    }
}
int main()
{
    int v;
    cin>>v;
    int a[v][v]={0};
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            a[i][j]=0;
        }
    }
for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
           cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int cnts;
    cin>>cnts;
    int init_cost;
    cin>>init_cost;
    int rest_cost=0;
    int count=0;
    while(cnts--)
    {
      int k,l;
      cin>>k>>l;
      int parti_cost;
    cin>>parti_cost;
     a[k-1][l-1]=parti_cost;
    }
    cout<<"\nThe graph now : \n";
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
           cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
           if(a[i][j]!=0)
           {
               int row_value=j;
              for(int k=0;k<v;k++)
              {
                  if(a[row_value][k]!=0 && a[i][k]!=0)
                  {
                      count++;
                      cout<<"\nCycle exists between "<<i+1<<" "<<row_value+1<<" "<<k+1;
                      if((a[i][row_value]<=a[row_value][k]) &&(a[i][row_value]<=a[i][k]))
                      {
                        if(rest_cost<=init_cost && a[i][row_value]<=init_cost)
                        {
                            rest_cost+=a[i][row_value];
                            a[i][row_value]=0;
                        }

                      }
                      else if((a[row_value][k]<=a[i][row_value]) && (a[row_value][k]<=a[i][k]))
                      {
                        if(rest_cost<=init_cost && a[row_value][k]<=init_cost)
                        {
                            rest_cost+=a[row_value][k];
                            a[row_value][k]=0;
                        }

                      }

                      else if((a[i][k]<=a[i][row_value]) && (a[i][k]<=a[row_value][k]))
                      {
                        if(rest_cost<=init_cost && a[i][k]<=init_cost)
                        {
                            rest_cost+=a[i][k];
                            a[i][k]=0;
                        }

                      }
                  }
              }
           }
        }
    }
    cout<<"\nThe count is : "<<count;
    cout<<"\nThe resulting sum is : "<<rest_cost;
  return 0;
}
