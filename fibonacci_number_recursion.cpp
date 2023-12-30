#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int fibo(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return fibo(n - 1) + fibo(n - 2);
	}
}
int main()
{

	int n;
	cin >> n;
	cout << "The nth fibonacci number is : " << fibo(n);
	return 0;
}
