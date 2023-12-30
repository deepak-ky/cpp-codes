#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define se                            second

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

int cnt_set_bit(int n)
{
	int cnt = 0;
	while (n != 0)
	{
		n = n & (n - 1);
		cnt++;

	}

	return cnt;
}


//n1 is usually the element that comes later in the array
// in array = > n2 , n1
//that is why returning false in equal condition

bool compare(int n1, int n2)
{
	int w1 = cnt_set_bit(n1);
	int w2 = cnt_set_bit(n2);
	if (w1 < w2)
	{
		return false;
	}
	else if (w1 == w2)
	{
		return false;
	}
	else return true;
}

void merge(int *a, int l, int mid, int h, int n)
{

	int *c = new int[h - l + 1];
	int n1 = mid - l + 1;
	int *c1 = new int[n1];
	int n2 = h - mid;
	int *c2 = new int[n2];

	int j = 0;
	for (int i = l; i <= mid; i++)
	{
		c1[j] = a[i];
		j++;
	}


	j = 0;
	for (int i = mid + 1; i <= h; i++)
	{
		c2[j] = a[i];
		j++;
	}



	int i = 0;
	j = 0;
	int k = 0;
	while (i < n1 && j < n2)
	{
		if (cnt_set_bit(c1[i]) >= cnt_set_bit(c2[j]))
		{
			c[k] = c1[i];
			k++;
			i++;
		}
		else
		{
			c[k] = c2[j];
			k++;
			j++;

		}
	}

	while (i < n1)
	{
		c[k] = c1[i];
		k++;
		i++;
	}

	while (j < n2)
	{
		c[k] = c2[j];
		k++;
		j++;
	}

	j = 0;
	for (int u = l; u <= h; u++)
	{
		a[u] = c[j];
		j++;
	}







}


void  merge_sort(int *a, int l, int h, int n)
{
	if (l == h)
	{
		return;
	}
	int mid = l + ((h - l) / 2);
	merge_sort(a, l, mid, n);
	merge_sort(a, mid + 1, h, n);
	merge(a, l, mid, h, n);
	return;

}



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		int a[] = {1, 2, 3, 4, 5, 6};
		int n = sizeof(a) / sizeof(int);

		merge_sort(a, 0, n - 1, n);
		for (auto x : a) cout << x << " ";

		cout << endl;

		sort(a, a + n , compare);
		for (auto x : a) cout << x << " ";

	}
	return 0;
}
