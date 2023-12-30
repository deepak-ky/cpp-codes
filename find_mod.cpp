#include<iostream>
using namespace std;
int findmaxocc(int w, int n)
{
	int count = 0;
	while (n > 0)
	{
		int r = n % 10;
		if (r == w)
		{
			count++;
		}
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
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int w;
	cin >> w;

	int maxocc = INT_MIN;
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		if ((findmaxocc(w, a[i])) > maxocc)
		{
			maxocc = findmaxocc(w, a[i]);
			num = a[i];
		}
	}
	cout << endl << maxocc << endl << num;
	return 0;
}