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

//Every student is assigned to read some consecutive books.
//The task is to assign books in a such a way that the maximum number of pages
//assigned to a student is minimum.


bool max_pages_to_read(int *a, int n, int pages, int students)
{
  // no student is reading more than "pages" pages
  int pages_read_till_now = 0;
  int cnt = 1;
  for (int i = 0; i < n; i++)
  {
    if (pages_read_till_now + a[i] <= pages)
    {
      pages_read_till_now += a[i];
    }
    else
    {
      cnt++;
      i--;
      pages_read_till_now = 0;
    }
    if (cnt > students)
    {
      return false;
    }


  }
  if (cnt > students)
  {
    return false;
  }

  return true;
}

int min_maximum_pages(int *a, int n, int students)
{
  int sum = 0;
  for (int i = 0; i < n; i++) sum += a[i];
  int l = 0; // can read the samllest book
  int h = sum;  // can read all the books
  int ans = -1;

  while (l <= h)
  {
    int m = l + ((h - l) / 2);
    if (max_pages_to_read(a, n, m, students))
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

    int n;
    cin >> n;
    int students;
    cin >> students;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    cout << min_maximum_pages(a, n, students) << endl;


  }
  return 0;
}
