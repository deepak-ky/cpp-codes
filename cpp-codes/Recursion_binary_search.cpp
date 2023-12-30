#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// int binsrch(int a[], int key, int low, int high)
// {
//   int mid = (low + high) / 2;

//   if (low > high)
//   {
//     return -1;
//   }
//   else if (a[mid] == key)
//   {
//     return mid;
//   }
//   else if (a[mid] < key)
//   {
//     return binsrch(a, key, mid + 1, high);
//   }
//   else if (a[mid] > key)
//   {
//     return binsrch(a, key, low, mid - 1);

//   }
// }
int main()
{



  int n, i, key;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cin >> key;
  int o;
  sort(a, a + n);
  // o = binsrch(a, key, 0, n - 1);
  // cout << o;
  cout << "Till here the program in runnning smoothly";
  return 0;
}
