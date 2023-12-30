#include<bits/stdc++.h>
using namespace std;
class allcons
{
int x;
public:
allcons(){x=0;}
allcons(int m)
{
    x=m;
}
allcons(allcons &n)
{
    x=n.x;
}
void display(void)
{
cout<<x;
}
};
int main()
{
allcons a;
a.display();
cout<<endl;
allcons b(5);
b.display();
cout<<endl;
allcons c=b;
c.display();
return 0;
}
