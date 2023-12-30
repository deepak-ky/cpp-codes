#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=1;i<n;i++) cout<<a[i]<<" "; cout<<endl
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

void build_tree(int s, int e, string *segment_tree, int idx)
{
  if (s == e)
  {
    segment_tree[idx] = "0";
    return;
  }
  int mid = s + ((e - s) / 2);
  build_tree(s, mid, segment_tree, 2 * idx);
  build_tree(mid + 1, e, segment_tree, 2 * idx + 1);
  segment_tree[idx] = "";
  segment_tree[idx] += segment_tree[2 * idx];
  segment_tree[idx] += segment_tree[2 * idx + 1];
  return;
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
    string *segment_tree = new string[4 * n + 1];
    build_tree(0, n - 1, segment_tree, 1);
    out(segment_tree, 5);
    int q;
    cin >> q;
    int type;
    int qs, qe;
    cin >> type >> qs >> qe;
    update(segment_tree, 0, n - 1, 1, type, qs, qe);


  }
  return 0;
}
