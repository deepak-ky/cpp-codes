#include <iostream>
using namespace std;
int main()
{
   int n;
   cin>>n;

   int j;
   string s[n+1], temp;
   cout<<"The elements..."<<endl;
   int i=0;
   char count='10';
 while(i!=(n+1))
 {
     s[i]=count;
     count++;
     i++;
 }
         /*
   for(i = 0; i < 4; ++i)
   for(j = i+1; j < 5; ++j) {
      if(s[i] > s[j]) {
         temp = s[i];
         s[i] = s[j];
         s[j] = temp;
      }
   }*/
   cout << "The elements in lexicographical order are... " << endl;
   for(int i = 0; i<=n; i++)
   cout << s[i] << endl;

   return 0;
}
