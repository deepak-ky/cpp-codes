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

const int n = 1008;
int factorial[n];

//Method - 1  : Modular Multiplicative INverse
//a^(p-2) % m = a ^ (-1) % m



//nCr = n! / (r!) * ((n-r)!) => n! * ((r!)^-1) * (((n-r)!)^-1)
// (a * b) % m = (a%m * b%m) % m
// (n! % m * ((r!)^-1) % m * (((n-r)!)^-1) % m) % m
// (n! % m * ((r!)^(m-2)) % m * (((n-r)!)^(m-2)) % m) % m


int fast_power(int a , int b)
{
    if (b == 0)
    {
        return 1;
    }

    if (b == 1)
    {
        return a;
    }


    if (b % 2 == 0)
    {
        int w = fast_power(a, b / 2) % mod;
        return ((w) % mod * (w) % mod) % mod;
    }
    else
    {
        int w = fast_power(a, b / 2) % mod;
        return ((a) % mod * (w) % mod * (w) % mod) % mod;
    }

}



int inverse_modular(int a)
{
    cout << a << endl;
    int w =  fast_power(a, mod - 2);
    cout << "w : " << w;
    cout << endl;
    return w;
}


int cal_n_C_r(int n, int r)
{
    int val1 = factorial[n] % mod;

    int val2 = inverse_modular(factorial[r]) % mod;

    int val3 = inverse_modular(factorial[n - r]) % mod;

    wer(val1);
    wer(val2);
    wer(val3);

    int val4 = ((val2 % mod ) * (val3 % mod)) % mod;

    int ans = (val1 * val4) % mod;

    return (ans + mod ) % mod;

}



int32_t main()
{
    init();
    int t = 1;
    //cin>>t;
    while (t--)
    {

        factorial[0] = 1;
        for (int i = 1; i < 1008; i++)
        {
            factorial[i] = (factorial[i - 1] % mod * i % mod) % mod;
        }



        int n;
        int r;


        cin >> n >> r;



        cout << cal_n_C_r(n, r);

    }
    return 0;
}

