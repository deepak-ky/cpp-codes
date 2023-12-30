// C++ program to find minimum value that can
// be assigned to all elements so that product
// becomes greater than current product.
#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll findMinValue(ll arr[], ll n)
{
	// sort the array to apply Binary search
	sort(arr, arr + n);

	// using log property add every logarithmic
	// value of element to val
	ld val = 0; // where ld is long double
	for (int i = 0; i < n; i++)
		val += (ld)(log((ld)(arr[i])));

	// set left and right extremities to find
	// min value
	ll left = arr[0], right = arr[n - 1] + 1;

	ll ans;
	while (left <= right)
	{
		ll mid = (left + right) / 2;

		// multiplying n to mid, to find the
		// correct min value
		ld temp = (ld)n * (ld)(log((ld)(mid)));
		if (val < temp)
		{
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return ans;
}
18, 518, 700, 000, 000‬
1, 684, 839, 733, 489, 800, 000, 000
1, 684, 907, 571, 007, 029, 215, 232
6, 187, 723, 638, 561, 170, 432

// Driver code
int main()
{
	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << findMinValue(a, n) << endl;
	return 0;
}
