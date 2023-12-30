#include<iostream>
#include<string>
using namespace std;
int main()
{
    string d;
    cout<<d<<endl;
    if(strcmp(d,false)==0)
    {
        cout<<"Works:";
    }
    else if(d==true)
    {
        cout<<"Does not work ";
    }
    return 0;
}
