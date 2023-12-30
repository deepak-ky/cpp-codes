#include<iostream>
using namespace std;
class BASE
 {
   public:
   void func1()
   {
    cout<<"\nFunction 1 of BASE class";
   }
   virtual void func2()
   {
    cout<<"\nFunction 2 of BASE class";
   }
 };
class DERIVED : public BASE
 {
  public:
  void func1()
   {
    cout<<"\nFunction 1 of DERIVED class";
   }
  void func2()
   {
    cout<<"\nFunction 2 of DERIVED class";
   }
};
int main()
{
 BASE base;
 DERIVED derived;
 BASE *baseptr;
 cout<<"baseptr points to base class : \n";
 baseptr=&base;
 baseptr->func1();
 baseptr->func2();
 cout<<"\nbaseptr points to derived class : \n";
 baseptr=&derived;
 baseptr->func1();
 baseptr->func2();
return 0;
}
