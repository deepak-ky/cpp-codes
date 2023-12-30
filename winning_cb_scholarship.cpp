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

bool is_possible_to_give(int m, int disc_coup, int x, int y, int n)
{
  //total number of discount coupons needed = students * x
  //discount coupons already present = disc_coup
  //If I assume the children whom I have not seleceted to give discount coupons , all perform badly
  if (m * x <= (disc_coup) + (n - m) * (y))
  {
    return true;
  }
  else return false;
}

int num_students(int n, int disc_coup, int x, int y)
{
  int l = 1;
  int h = n;
  int ans = -1;
  while (l <= h)
  {
    int m = l + ((h - l) / 2);
    if (is_possible_to_give(m, disc_coup, x, y, n))
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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    cout << num_students(n, m, x, y);
  }
  return 0;
}
