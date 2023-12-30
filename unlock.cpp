#include<bits/stdc++.h>
using namespace std;
bool is_sorted(int *a, int n)
{
    if (n == 1 || n == 0)
    {
        return true;
    }
    if (a[0] > a[1] && is_sorted(a + 1, n - 1))
    {
        return true;
    }
    else return false;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    int n;
    int k;
    cin >> n >> k;
    // cout << endl;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // if (is_sorted(a, n))
    // {
    //     cout << "The array is sorted";
    // }
    // else cout << "NOT sorted";
    int j = 0;
    while (k != 0)
    {
        if (is_sorted(a, n))
        {
            break;
        }
        else
        {
            if (a[j] == (*max_element(a + j, a + n)))
            {
                j++;
            }
            else if (a[j] != (*max_element(a + j, a + n)))
            {
                swap(a[j], (*max_element(a + j, a + n)));
                j++;
                k--;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {cout << a[i] << " ";}
    return 0;
}
