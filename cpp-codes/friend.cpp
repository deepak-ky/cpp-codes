#include<iostream>
using namespace std;
class test
{
public:
int a;
int b;
test(int x,int y)
{
a=x;
b=y;
}
friend void show(test);
};
void show( test t)
{
 cout<<"a : "<<t.a<<endl;
 cout<<"b : "<<t.b<<endl;
 }
int main()
{
 test t1(8,9);
 show(t1);
return 0;
}
