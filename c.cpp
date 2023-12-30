#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    int a[n];
    asdf(a, n);
    k = k % n;
    if (k != 0)
    {

        int s = 0;
        int e = s + k - 1;
        while (e < n)
        {
            if ((e - s) & 1)
            {
                int mid = ( e + s) / 2;
                int i, j;
                for ( i = s, j = e; i <= mid, j >= (mid + 1); i++, j--)
                {
                    // cout << s << endl;
                    // cout << e << endl;
                    swap(a[i], a[j]);
                    //asdff(a, n);

                }
            }
            else
            {
                int mid = (e + s) / 2;
                int i, j;
                for ( i = s, j = e; i<mid, j>(mid); i++, j--)
                {
                    // cout << s << endl;
                    // cout << e << endl;
                    swap(a[i], a[j]);
                }
            }
            s = e + 1;
            e = s + k - 1;
        }




    }
    for (auto x : a)
    {
        cout << x << " ";
    }
    return 0;
}
