#include<iostream>
#include<string.h>
using namespace std;
class complexnum
{
    float x;
    float y;
public :
    complexnum(){};
    complexnum(float a, float b)
    {
        x=a;
        y=b;
    }
    complexnum operator+(complexnum);
    void display();
};
complexnum complexnum :: operator+(complexnum c1)
{
    complexnum t1;
    t1.x=x+c1.x;
    t1.y=y+c1.y;
    return(t1);
}
void complexnum :: display(void)
{
     cout<<x<<" + j"<<y<<endl;
}
int main()
{
complexnum c1(4,3.4),c2(3.5,4.5),c3;
c3=c1+c2;
cout<<"C1 : ";c1.display();
cout<<"C2 : ";c2.display();
cout<<"C3 : ";c3.display();
return 0;
}
