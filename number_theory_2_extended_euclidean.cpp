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

//Solving values for this equation
//=> A(x) + B(y) = GCD(A,B);
//     ^      ^
//     |      |
//   These values are declared globally and the user only inputs A and B

int x;  //-> x that will satisfy the original equation
int y;  //-> y that will saitsfy the original equation
int GCD;

void extended_euclid(int a, int b)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		GCD = a;
		return;
	}

	extended_euclid(b, a % b);

	int c_x = y;                //if I change x here , then when I am finding the value of y in
	int c_y = x - (a / b) * y;  //in the next line , the changed value of x would be used which would give me wrong answer.

	x = c_x;
	y = c_y;
	cout << a << "( " << x << " ) + " << b << "(" << y << ") = " << GCD << endl;

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
	//int A,B;
	//cin >> A >> B;
	int A = 35;
	int B = 15;
	extended_euclid(A, B);
	cout << A << "( " << x << " ) + " << B << "(" << y << ") = " << GCD;
	return 0;
}
