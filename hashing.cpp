#include<iostream>
#include"hashtable.h"
using namespace std;

int main(){
///Fruit, 100 Key = string, price= int

    Hashtable<int> h(11);
    h.insert("Mango",100);
    h.insert("Apple",170);
    h.insert("Guava",140);
    h.insert("Banana",130);
    h.insert("Chiku",120);

    h.print();
/*string f;
cin>>f;
int *price=h.search(f);
if(price==NULL)
{
    cout<<"NOT FOUND";
}
else cout<<"PRICE IS : "<<*price;*/
string g;
cin>>g;
h.delet(g);
cout<<endl;
h.print();
return 0;
}
