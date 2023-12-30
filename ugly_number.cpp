#include<iostream>
using namespace std;
typedef long long int lli;
void prime_sieve(lli p[], lli n)
{
  for (lli i = 3; i <= n; i += 2)
  {
    p[i] = 1;
  }

  for (lli i = 3; i <= n; i += 2)
  {


    if (p[i] == 1)
    {

      for (lli j = (i * i); j <= n; j = j + i)
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
  lli n;
  cin >> n;
#ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for writing output to output.txt
  freopen("output.txt", "w", stdout);
#endif


  lli p[n + 3] = {0};
  prime_sieve(p, n);
  for (lli i = 0; i <= n; i++)
  {
    if (p[i] == 1)
    {
      cout << endl << i;
    }
  }
  return 0;
}

