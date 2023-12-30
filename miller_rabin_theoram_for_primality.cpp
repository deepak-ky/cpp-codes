

//THIS METHOD WORKS CORRECT FOR ALL NUMBERS STRICTLY LESS THAN :  3825123056546413051 ~ 3 * 10^18;


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
int modular_multiplication(int a, int b, int n)
{
	int res = 0;
	while (b > 0)
	{
		if (b & 1) res += a;
		a *= 2;
		b /= 2;
		res %= n;
		a %= n;
	}
	return res;
}

int modular_exponentiation(int a, int b, int n)
{
	int res = 1;
	while (b > 0)
	{
		if (b & 1)
		{
			res = modular_multiplication(res, a, n);
		}
		a = modular_multiplication(a, a, n);
		a %= n;
		b = b >> 1;
	}
	return res;
}

//miller_rabin -> return true => number is prime
//miller_rabin -> return false => number is not prime
bool miller_rabin(int n)
{
	if (n == 1)  return false;
	if (n == 2)  return true;
	if (n % 2 == 0) return false;
	//now n is odd , therefore n-1 is even
	int d = n - 1;
	int s = 0;
	while ( d % 2 == 0)
	{
		d = d / 2;
		s++;
	}

	// n-1 = (2 ^ s) * d // d is an odd number

	//now want to check whether
	// (a^d) % n = 1   or (a ^ (d * (2^i)))%n == ( -1 or n-1)
	// if we find any a which does not satisfy any of the above equation then , a is composite
	// for choosing a we would form a vector
	vector<int> a({2, 3, 5, 7, 11, 13, 17, 19, 23, 29});
	for (int i = 0; i < a.size(); i++)
	{
		if ( a[i] > n - 2 ) continue;
		// a^d == ad
		int ad = modular_exponentiation(a[i], d, n);
		if (ad % n == 1) continue;
		bool prime = false;
		for (int r = 0; r <= s - 1; r++)
		{
			int two_r = modular_exponentiation(2, r, n);
			int two_r_d = modular_multiplication(two_r, d, n);
			int a_two_r_d = modular_exponentiation(a[i], two_r_d, n);
			if (a_two_r_d % n == n - 1)
			{
				prime = true;
				break;
			}

		}
		if (prime == false)
		{
			return false;
		}
	}
	return true;
}


int32_t main()
{
	init();
	//int i = 3825123056546413051;

	for (int i = 1; i < 31; i++)
	{
		cout << i << " : ";
		if (miller_rabin(i) == true) // miller rabin returns true if a number is prime
		{
			cout << "prime" << endl;
		}
		else cout << "not prime" << endl;
	}

	//THIS METHOD WORKS CORRECT FOR ALL NUMBERS STRICTLY LESS THAN :  3825123056546413051 ~ 3 * 10^18;

	return 0;
}
