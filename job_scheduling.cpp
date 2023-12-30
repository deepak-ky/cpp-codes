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

class job
{
public:
  int id;
  int dead;
  int profit;
};

bool compare(job j1, job j2)
{
  if (j1.profit > j2.profit)
  {
    return true;
  }
  else if (j1.profit == j2.profit)
  {
    if (j1.dead < j2.dead)
    {
      return true;
    }
    else return false;
  }
  return false;
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
    job * j = new job[n];
    for (int i = 0; i < n; i++)
    {
      cin >> j[i].id >> j[i].dead >> j[i].profit;
    }

    sort(j, j + n, compare);

    int ids_used = 0;
    int ans = 0;

    bool mp[102];
    for (int i = 0; i < 102; i++) mp[i] = false;


    int i = 0;
    while (i < n)
    {

      //We need to find if there is a slot available before the current deadline
      for (int k = j[i].dead; k >= 1; k--)
      {
        if (mp[k] == false)
        {
          //there is an empty slot
          mp[k] = true;
          ids_used++;
          ans += j[i].profit;
          break;
        }
      }
      i++;
    }

    cout << ids_used << endl;
    cout << ans << endl;
  }
  return 0;
}
