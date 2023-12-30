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
#define se                            second

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

int search(int *a, int n, int key)
{
  int l = 0;
  int h = n - 1;
  while (l <= h)
  {
    int m = l + ((h - l) / 2);
    if ( a[m] == key)
    {
      return m;
    }
    else if (a[l] <= a[m]) //The first part of the array is sorted
    {
      if (key >= a[l] && key <= a[m])
      {
        h = m;
      }
      else
      {
        l = m + 1;
      }
    }
    else if (a[m + 1] <= a[h])
    {
      if (key >= a[m + 1] && key <= a[h])
      {
        l = m + 1;
      }
      else
      {
        h = m;
      }
    }

  }
  return -1;
}


int32_t main()
{
  init();
  int t = 1;
  //cin>>t;
  while (t--)
  {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    int pivot = *max_element(a, a + n);

    cout << search(a, n, pivot);
  }
  return 0;
}

















