// C++ implementation of the above approach
#include <algorithm>
#include <iostream>
using namespace std;

struct circle {
	int start, end;
};

// Comparison function modified
// according to the end value
bool comp(circle a, circle b)
{
	if (a.end == b.end)
		return a.start < b.start;
	return a.end < b.end;
}

// Fucntion to return the count
// of non intersecting circles
void CountCircles(int c[], int r[], int n)
{
	// structure with start and
	// end of diameter of circles
	circle diameter[n];

	for (int i = 0; i < n; ++i) {
		diameter[i].start = c[i] - r[i];

		diameter[i].end = c[i] + r[i];
	}

	// sorting with smallest finish time first
	sort(diameter, diameter + n, comp);

	// count stores number of
	// circles to be removed
	int count = 0;

	// cur stores ending of first circle
	int cur = diameter[0].end;
	for (int i = 1; i < n; ++i) {

		// non intersecting circles
		if (diameter[i].start >= cur) {
			cur = diameter[i].end;
		}

		// intersecting circles
		else
			count++;
	}

	cout << count;
}

// Driver Code
int main()
{
	// centers of circles
	int n;
	cin>>n;
	int c[n];
	int r[n];
	for(int i=0;i<n;i++)
    {
        cin>>c[i]>>r[i];
    }
    CountCircles(c, r, n);

	return 0;
}

