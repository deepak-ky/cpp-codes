#include<iostream>
using namespace std;
#define varname(name)                #name
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define asdff(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int main()
{
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    // int t;
    // cin >> t;
    // while (t--)
    // {
    int n, k;
    cin >> n >> k;
    wer(n);
    //wer(k1);
    // int k = k1 % n;
    //wer(k);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

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


    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    // }
    return 0;

}