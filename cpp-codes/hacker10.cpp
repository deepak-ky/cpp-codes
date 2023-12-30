#include<iostream>
using namespace std;
int checktype(char c)
{
    if(c=='A' || c=='a' || c=='E' || c=='e' || c=='I' || c=='i' || c=='O' || c=='o' || c=='U' || c=='u')
        return 1;
    else return 2;
}
int main()
{
int i,j,l,m,n,check,check1,check2,check3,flag,value;
char a[100000];
int b[100000];
int k=0;
cin>>a;
int count=0;
for(i=0;a[i]!='\0';i++)
{
    count++;
}
cout<<"\nLength of string : "<<count<<endl;
cout<<"\nlast chARAC : "<<a[count-1]<<endl;
for(i=0;a[i]!='\0';i++)
{
  check=checktype(a[i]);
  if(check==1)
  {
      cout<<a[i]<<" : VOWEL";

  }
    else if(check==2)
    {
        cout<<a[i]<<" : CONSTANT";
    }
    cout<<endl;
}
for(j=0;a[j]!='\0';j++)
{
    check1=checktype(a[j]);
    check2=checktype(a[j-1]);
    check3=checktype(a[j+1]);

    if(j==0)
    {
        if(check1==2 && check3==1)
        {
        cout<<a[j]<<": YES";
        flag=1;
        }
        else if(check1==2 && check3==2)
        {
        cout<<a[j]<<": NO";
        flag=2;
        }
        else if(check1==1)
        {
        cout<<a[j]<<": YES";
        flag=1;
        }
        b[k++]=flag;
    }
    else if(j>0 && j<(count-1))
    {

    if(check1==2 && check2==1 && check3==1)
  {
      cout<<a[j]<<": YES";
      flag=1;
  }
   else if(check1==2 && check2==2 )
  {
      cout<<a[j]<<": NO";
      flag=2;
  }
   else if(check1==2 && check3==2 )
  {
      cout<<a[j]<<": NO";
      flag=2;
  }
   else if(check1==2 && check3==2 && check2==2 )
  {
      cout<<a[j]<<": NO";
      flag=2;
  }
  b[k++]=flag;
    }
    else if(j==(count-1))
    {
        if(check1==2 && check2==1)
        {
        cout<<a[j]<<": YES";
        flag=1;
        }
        else if(check1==2 && check2==2)
        {
        cout<<a[j]<<": NO";
        flag=2;
        }
       b[k++]=flag;
    }

  cout<<endl;
}
cout<<endl;
for(int d=0;d<j;d++)
{
    cout<<"Flag value : "<<b[d];
    cout<<endl;
}

cout<<endl;
int d;
 for (d = 0; d < j; d++){
       if (b[d] == b[0])
          value=3;
       else
          value=4;
    }
    cout<<"\nvalue : "<<value<<endl;
    if(value==3)
    {
        cout<<"YES";
    }
    else if(value==4)
    {
        cout<<"NO";
    }
return 0;
}
