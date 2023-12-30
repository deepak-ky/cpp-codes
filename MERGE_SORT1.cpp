#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void merge(int a[], int s, int e)
{
	int mid = (s + e) / 2;
	int i = s;
	int j = mid + 1;
	int k = s;
	int temp[1000];
	while (i <= mid &&  j <= e)
	{
		if (a[i] <= a[j])
		{
			temp[k++] = a[i++];
		}
		else
			temp[k++] = a[j++];
	}
	while (i <= mid)
	{
		temp[k++] = a[i++];
	}
	while (j <= e)
	{
		temp[k++] = a[j++];
	}
	for (int d = s; d <= e; d++)
	{
		a[d] = temp[d];
	}



}
void mergesort(int a[], int s, int e)
{
	if (s >= e)
	{
		return;
	}
	int mid = (s + e) / 2;
	mergesort(a, s, mid);
	mergesort(a, mid + 1, e);
	merge(a, s, e);
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
	mergesort(a, 0, n - 1);
	cout << "The sorted array is : ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
