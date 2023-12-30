    #include<bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    #define INF 7

    ll f[100000007];

    ll pow(ll a, ll b, ll MOD)
    {
     ll x=1,y=a;
     while(b > 0)
     	{
     		if(b%2 == 1)
     	{
     		x=(x*y);
     		if(x>MOD) x%=MOD;
     		     	cout<<"\nThe value of x here is : "<<x<<endl;

     	}
     	y = (y*y);
     	if(y>MOD) y%=MOD;
     	b /= 2;
     	     	cout<<"\nThe value of b now : "<<b<<endl;

     	}
     	cout<<"\nThe value returning from here is : "<<x<<endl;
     return x;
    }

    /* Modular Multiplicative Inverse
     Using Euler's Theorem
     a^(phi(m)) = 1 (mod m)
     a^(-1) = a^(m-2) (mod m) */
    ll InverseEuler(ll n, ll MOD)
    {
     return pow(n,MOD-2,MOD);
    }

    ll C(ll n, ll r, ll MOD)
    {

     return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
    }

    int main(){
    	f[0] = 1;
    	ll n;
    	cin>>n;
    	ll r;
        cin>>r;
    	for(ll i = 1 ; i <=n ; i++)
    		f[i] = (f[i-1]*i)%INF;
     	cout << C(n,r,INF) << endl;
    }
