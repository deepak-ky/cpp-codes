#include<iostream>
using namespace std;
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
	int i = 0;
	int n1 = 0;
	int n2 = 0;
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
	cout << n1 << endl << n2;
	return 0;
}