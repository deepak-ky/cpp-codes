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

bool can_cook(int *a, int n, int pratas, int m)
{
  int total_pratas_cooked = 0;
  for (int i = 0; i < n; i++)
  {
    int rate = a[i];
    int k = 1;
    int current_time = 0;
    while ((current_time + (rate * k)) <= m)
    {
      current_time += rate * k;
      total_pratas_cooked++;
      k++;
    }


    if (total_pratas_cooked >= pratas)
    {

      return true;
    }
  }



  return false;
}

int min_time_to_make(int *a, int n, int pratas)
{
  int w = *max_element(a, a + n);
  int e = pratas + 1;
  int l = 1;
  int h = (e) / 2;
  int c = (w + ((e  - 1) * w));
  h *= c;

  int ans = -1;

  while (l <= h)
  {
    int m = l + ((h - l) / 2);

    if (can_cook(a, n, pratas, m) == true)
    {

      ans = m;
      h = m - 1;
    }
    else
    {
      l = m + 1;
    }
  }

  return ans;
}

int32_t main()
{
  init();
  int t = 1;
  cin >> t;
  while (t--)
  {
    int pratas;
    cin >> pratas;

    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    cout << min_time_to_make(a, n, pratas) << endl;



  }
  return 0;
}

