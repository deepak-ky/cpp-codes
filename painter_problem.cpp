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

bool is_possible_to_paint(int k, int *a, int n, int m)
{
    int number_of_painters = 1;
    int units_painted_till_now = 0;
    for (int i = 0; i < n; i++)
    {
        if (units_painted_till_now + a[i] <= m)
        {
            units_painted_till_now += a[i];
        }
        else
        {
            number_of_painters++;
            i--;
            units_painted_till_now = 0;
        }

        if (number_of_painters > k)
        {
            return false;
        }
    }
    if (number_of_painters > k)
    {
        return false;
    }
    else  return true;
}

//find the minimum time required to paint all the boards

int min_time_to_paint(int k, int *a, int n)
{
    int l = 0;
    int h = 0;
    for (int i = 0; i < n; i++) h += a[i];
    int ans = -1;
    while (l <= h)
    {
        int m = l + ((h - l) / 2);
        if (is_possible_to_paint(k, a, n, m))
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
    //cin>>t;
    while (t--)
    {
        int k;
        cin >> k;
        int n;
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);

        cout << min_time_to_paint(k, a, n);

    }
    return 0;
}

