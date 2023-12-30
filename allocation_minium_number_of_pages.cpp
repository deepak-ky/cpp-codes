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

bool can_allocate(int *a, int n, int student_cnt, int m)
{

	//wer(m);


	int current_num_of_pages = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > m)
		{
			return false;
		}

		if (current_num_of_pages + a[i] <= m)
		{
			current_num_of_pages += a[i];
			continue;
		}
		else
		{
			//I have to start allocating pages to a new student
			student_cnt--;
			if (student_cnt == 0)
			{
				return false;
			}
			current_num_of_pages = a[i];

		}
	}


	return true;
}

int find_min_pages(int *a, int n, int student_cnt)
{
	//If I allocate each book , to individual student , then one student will get
	//the book with the maximum number of pages
	int l = *max_element(a, a + n);

	//Maximum number of pages that a person can read is ; sum of all pages
	int h = 0;
	for (int i = 0; i < n; i++) h = h + a[i];

	int ans = -1;
	while (l <= h)
	{
		int m = l + ((h - l) / 2);

		if (can_allocate(a, n, student_cnt, m) == true)
		{
			ans = m;
			h = m - 1;
		}
		else
		{
			l = m + 1;
		}
	}

	return ans;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		int m;
		cin >> m;

		cout << find_min_pages(a, n, m);

	}
	return 0;
}
