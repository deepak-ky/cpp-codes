#include<bits/stdc++.h>
using namespace std;
class string1
{
 char a[10];
  public:
      static int count;
      string1()
      {
          count=0;
      }
  void getstr(void)
  {
   cout<<"Enter the String : ";
   gets(a);
  }
  void retlen(void)
  {
  int i,j,k,l;
   for(i=0;a[i]!='\0';i++)
   {
    count++;
   }
  cout<<"String length : "<<count;
 }
};
int string1 :: count;
int main()
{
string1 s,w;
s.getstr();
s.retlen();
cout<<endl;
w.getstr();
w.retlen();
return 0;
}
