#include <iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
int maxi(int alphabet[])
{
    int maxx=alphabet[0];
    int loc=0;
    for(int i=1;i<26;i++)
    {
        if(alphabet[i]>maxx)
        {
            maxx=alphabet[i];
            loc=i;
        }
    }

    return loc;
}
int main()
    {
      int k;
      cin>>k;
      string s;
      cin>>s;
      int len=s.length();
      int i = 0, alphabet[26] = {0}, j;
      while (s[i] != '\0')
      {
            j = s[i] - 'a';
            alphabet[j]++;
      i++;
    }
   cout<<"Frequency of all alphabets in the string is:"<<endl;
   for (i = 0; i < 26; i++)
   {
       cout<< char(i+'a' )<<" : "<< alphabet[i]<< endl;
   }
   while(k!=0)
   {
   int w=maxi(alphabet);
   alphabet[w]--;
   k--;
  }
  cout<<"\nK now : "<<k<<endl;
  cout<<"Frequency now of all alphabets in the string is:"<<endl;
   for (i = 0; i < 26; i++)
   {
       cout<< char(i+'a' )<<" : "<< alphabet[i]<< endl;
   }
cout<<endl;
int ans=0;
for(i=0;i<26;i++)
{
    ans=ans+(alphabet[i]*alphabet[i]);
}
cout<<"\nThe final answer : "<<ans;
   return 0;
}
