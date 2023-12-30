//very complex logic needs to be optimized
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
class cuboid
{
public:
	int h;
	int l;
	int b;
};
int searchararray(int k, cuboid c[], int n, int j)
{
	if (k == 1)
	{
		int iddx = 0;
		int minvalue = INT_MIN;
		int flag = 0;
		for (int q = (j + 1); q < n; q++)
		{

			if ((c[q].h == c[j].h) && (c[q].b == c[j].b))
			{
				float mini = c[j].l + c[q].l;
				mini = mini / 2;
				if (mini > minvalue)
				{
					wer(q);
					flag = 1;
					minvalue = mini;
					iddx = q;
				}

			}
		}
		if (flag == 1)
		{
			return iddx;
		}
		else return -1;

	}
	else return -1;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int  n;
	cin >> n;
	cuboid c[n];
	for (int i = 0; i < n; i++)
	{
		cin >> c[i].h >> c[i].l >> c[i].b;
	}
	for (int i = 0; i < n; i++)
	{
		cout << endl << "Cuboid " << i << " : " << c[i].h << " " << c[i].l << " " << c[i].b;
	}
	//case of considering a single blocks can form the sphere of maximum radius
	float rad1 = INT_MIN;
	float idxrad1 = 0;
	for (int i = 0; i < n; i++)
	{
		float w = min((min(c[i].h, c[i].l)), c[i].b);
		w = w / 2;
		cout << "\nCuboid " << i << " min dimension : " << w;
		if (w > rad1)
		{
			rad1 = w;
			idxrad1 = i;
		}
	}
	cout << endl << rad1 << " : " << idxrad1;
	//case of considering two boxes can make a box of maximum length
	float rad2 = INT_MIN;
	float idxrad2 = 0;
	float idxrad3 = 0;
	for (int i = 0; i < n; i++)
	{
		float w = min((min(c[i].h, c[i].l)), c[i].b);
		if (w == c[i].h)
		{
			searchararray(1, c, n, i);
		}
		else if (w == c[i].l)
		{

		}
		else if (w == c[i].b)
		{

		}
	}

	int idx = searchararray(2, c, n, 0);
	cout << endl << idx;
	return 0;
}
