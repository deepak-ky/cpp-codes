#include<iostream>
#include<cstring>
using namespace std;
int main()
{
char s1[]=" hey , I am coding ";
char *ptr;
ptr=strtok(s1," ");
while(ptr!=NULL)
{
cout<<ptr<<endl;
ptr = strtok(NULL," ");
}
return 0;
}
