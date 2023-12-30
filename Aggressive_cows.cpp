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

bool can_place(int cows, int min_dist, int *a, int n)
{
  int cnt = 1;
  int last_value = a[0];

  for (int i = 1; i < n; i++)
  {
    if (last_value + min_dist <= a[i])
    {
      cnt++;
      last_value = a[i];
      if (cnt == cows)
      {
        return true;
      }

    }
  }
  return false;
}

int max_min_distance(int cows, int *a, int n)
{
  //what is the minimum distance that we can have between the cows = 0; // both cows in same stall
  //what is the maximum distance that we can have between the cows  = n // cows are further apart
  int l = 0;
  int h = a[n - 1] - a[0];
  int ans = 0;
  while (l <= h)
  {
    int m = l + ((h - l) / 2);
    if (can_place(cows, m, a, n))
    {
      ans = m;
      l = m + 1;
    }
    else
    {
      h = m - 1;
    }

  }
  return ans;
}

int32_t main()
{
  init();
  int t = 1;
  //cin>>t;
  while (t--)
  {
    int n, c;
    cin >> n >> c;

    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    sort(a, a + n);
    cout << max_min_distance(c, a, n) << endl;
  }
  return 0;
}
