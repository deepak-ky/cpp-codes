#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000007

ll f[100001];

ll pow(ll a, ll b, ll MOD)
{
    ll x = 1, y = a;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x * y);
            if (x > MOD) x %= MOD;
        }
        y = (y * y);
        if (y > MOD) y %= MOD;
        b /= 2;
    }
    return x;
}

/* Modular Multiplicative Inverse
 Using Euler's Theorem
 a^(phi(m)) = 1 (mod m)
 a^(-1) = a^(m-2) (mod m) */
ll InverseEuler(ll n, ll MOD)
{
    //cout << n << endl;
    int w =  pow(n, MOD - 2, MOD);
    //cout << "w : " << w;
    //cout << endl;
    return w;
}

ll C(ll n, ll r, ll MOD)
{
    int w1 = f[n];
    int w2 = InverseEuler(f[r], MOD);
    int w3 = InverseEuler(f[n - r], MOD);
    return (w1 * ((w2 * w3) % MOD)) % MOD;

}

int main() {

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif



    f[0] = 1;
    for (int i = 1 ; i <= 100000 ; i++)
        f[i] = (f[i - 1] * i) % INF;
    cout << C(5, 2, INF) << endl;
}