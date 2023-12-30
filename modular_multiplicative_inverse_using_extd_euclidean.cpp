#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : \n"<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back

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
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int A;
	cin >> A;
	int m;
	cin >> m;

	solve(A, m);

	if (gcd != 1)
	{
		cout << "Does not exist!!";
	}
	else
	{
		cout << "Modular multiplicative inverse  of " << A << " w.r.t to " << m << " is : " << (x + m) % m << "\n" << endl;
		cout <<  A << "^(-1) mod " << m << " : " << (x + m) % m << endl;
	}

	return 0;
}
