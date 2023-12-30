#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define s                            second

void init()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for writing output to output.txt
  freopen("output.txt", "w", stdout);
#endif
}

int first_occ(int *a, int n, int k)
{
  if ( n == 0)
  {
    return -1;
  }
  if (a[0] == k)
  {
    return 0;
  }
  int i = first_occ(a + 1, n - 1, k);
  if ( i == -1)
  {
    return -1;
  }
  else return 1 + i;

}
int first_occ_2(int *a, int n, int k, int idx)
{
  if (idx == n)
  {
    return -1;
  }
  if (a[idx] == k) return idx;
  else return first_occ_2(a, n, k, idx + 1);
}

int32_t main()
{
  init();
  int t = 1;
  //cin>>t;
  while (t--)
  {
    int a[] = {1, 2, 3, 7, 4, 5, 6, 7, 10};
    int key = 7 + 1;
    int n = sizeof(a) / sizeof(int);
    cout << first_occ(a, n, key);
    cout << endl <<  first_occ_2(a, n, key, 0);

  }
  return 0;
}
