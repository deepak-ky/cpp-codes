#include<iostream>
using namespace std;
int reverse(int n)
{
	int n2 = 0;
	while (n > 0)
	{
		int r = n % 10;
		n2 = n2 + r;
		n2 = n2 * 10;
		n = n / 10;

	}
	return (n2 / 10);
}
int number_of_digits(int n)
{
	int count = 0;
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return count;
}
int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int w = number_of_digits(n);
	cout << "\n Number of digits in n is : " << w << endl;

	int n1 = 0;
	int n2 = 0;
	int i = 0;
	while (n > 0)
	{
		if (i == 0)
		{
			int r = n % 10;
			n1 = n1 + r;
			n1 = n1 * 10;
			n = n / 10;
			i = 1;
		}
		else
		{
			int r = n % 10;
			n2 = n2 + r;
			n2 = n2 * 10;
			n = n / 10;
			i = 0;
		}
	}
	cout << "n1 : " << reverse(n1 / 10) << endl;
	cout << "n2 : " << reverse(n2 / 10) << ":";
	if (w % 2 == 0)
	{
		cout << reverse(n2 / 10);
	}
	else if (w % 2 == 1)
	{
		cout << reverse(n1 / 10);
	}
	return 0;
}