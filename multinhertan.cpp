#include<iostream>
using namespace std;
class base1
{
protected:
int var1;
public:
void get_var1(int);
};
class base2
{
protected:
int var2;
public:
void get_var2(int);
};
class derived : public base1,public base2
{
public:
void display(void);
};
void base1 :: get_var1(int x)
{
 var1=x;
}
void base2 :: get_var2(int x)
{
 var2=x;
}
void derived :: display(void)
{
  cout<<"VARIABLE 1 : "<<var1<<endl;
  cout<<"VARIABLE 2 : "<<var2<<endl;
  cout<<"VARIABLE 1 * VARIABLE 2 : "<<(var1*var2)<<endl;
}
int main()
{
derived D;
D.get_var1(5);
D.get_var2(6);
D.display();
return 0;
}
