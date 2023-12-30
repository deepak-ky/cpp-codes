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


void shuffle(int *a, int low, int high)
{
  srand(time(NULL));
  int j;
  for (int i = high; i > low; i--)
  {
    j = rand() % (i + 1); /* %i => this can also be used */
    swap(a[i], a[j]);
  }

  return;
}

int partition(int *a, int low, int high)
{
  int pivot = a[high];
  int i = low - 1;
  for (int j = low; j <= high - 1; j++)
  {
    if (a[j] <= pivot)
    {
      i++;
      swap(a[i], a[j]);
    }
  }

  swap(a[i + 1], a[high]);
  return i + 1;
}

void quicksort(int *a, int low, int high)
{
  if (low < high)
  {
    int pi = partition(a, low, high);
    quicksort(a, low, pi - 1);
    quicksort(a, pi + 1, high);
  }
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
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    out(a, n);

    cout << "Randomized : ";
    shuffle(a, 0, n - 1);


    out(a, n);
    quicksort(a, 0, n - 1);
    out(a, n);

  }
  return 0;
}
