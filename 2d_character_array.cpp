#include<iostream>
using namespace std;
int main()
{
    char a[][10]={{'a','b','c','\0'},{'a','b','c','d','e','\0'}};
    cout<<a[0]<<endl;
    cout<<a[1]<<endl;
       char b[][10]={"what","are","you","doing"};
    cout<<b[1]<<endl;
    cout<<b[2]<<endl;
    b[2][1]='d';

    cout<<b[2]<<endl;
    char c[5][10];
    for(int i=0;i<5;i++)
    {
        cin>>c[i];
    }
    cout<<"\nThe list of strings are : "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<c[i]<<endl;
    }
        return 0;
}
