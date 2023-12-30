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
#define s                            second

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

int gcd, x, y;

//Ax + By = GCD(A,B) = 1 ,
//if(A*B)%M = 1
//after solving a little we can write the above equation as : AB - km = 1 or A(B) + (-k)m = 1
//we are given A and m and we need to find B,therefore we need to find the value of global x

//using this approach to find gcd : gcd(a,b) = gcd(b , a%b)

void solve(int a , int b)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		gcd = a;
		return;
	}

	solve(b, a % b);

	int c_x = y;
	int c_y = x - (a / b) * y;

	x = c_x;
	y = c_y;
}


int32_t main()
{
	init();
	int t; cin >> t; while (t--)
	{
		int n, p;
		cin >> n >> p;
		if (n >= p)
		{
			cout << 0 << endl;
		}
		else
		{
			int ans = p - 1;
			for (int i = n + 1; i <= p - 1; i++)
			{
				gcd = 0;
				x = y = 0;
				solve(i, p);
				ans *= (x + p) % p;
				ans %= p;
			}
			cout << ans << endl;
		}
	}



	return 0;
}
