#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
void prime_sieve(lli p[])
{
  for (lli i = 3; i <= 100000; i += 2)
  {
    p[i] = 1;
  }

  for (lli i = 3; i < 100000; i += 2)
  {


    if (p[i] == 1)
    {

      for (lli j = (i * i); j < 100000; j = j + i)
      {

        p[j] = 0;
      }

    }
  }

  p[2] = 1;

  p[1] = p[0] = 0;


}

int main()
{
    cout<<"the program is working fine till here:";

  lli p[100005] = {0};
  prime_sieve(p);
  lli ans[100005];
  ans[0] = 1;
  ans[1] = 2;
  ans[2] = 3;
  ans[3] = 4;
  ans[4] = 5;
  lli i = 5;
  lli val = 6;
  while (i <= 100005)
  {
    if (p[val] == 0)
    {
      ans[i] = val;
      i++;
      val++;
    }
    else if (p[val] == 1)
    {
      val++;
    }
  }
  cout << "The array till the tenth number is : ";
  for (lli i = 0; i <= 10; i++)
  {
    cout << ans[i] << " ";
  }
  return 0;
}
