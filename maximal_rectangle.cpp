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

int Largest_rectangular_area(int *a, int n)
{
	int *left_nse = new int[n];
	int *right_nse = new int[n];
	stack<int> s;
	s.push(0);
	for (int i = 1; i < n; i++)
	{
		if (s.empty())
		{
			s.push(i);
		}
		else
		{
			while (!s.empty() && a[s.top()]  > a[i])
			{
				right_nse[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
	}

	while (!s.empty())
	{
		right_nse[s.top()] = n;
		s.pop();
	}

	s.push(n - 1);
	for (int i = n - 2; i >= 0; i--)
	{
		if (s.empty())
		{
			s.push(i);
		}
		else
		{
			while (!s.empty() && a[s.top()] > a[i])
			{
				left_nse[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
	}

	while (!s.empty())
	{
		left_nse[s.top()] = -1;
		s.pop();
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int area = (right_nse[i] - left_nse[i] - 1) * a[i];
		if (area > ans)
		{
			ans = area;
		}
	}
	//out(left_nse, n);
	//out(right_nse, n);
	return ans;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int **mat = new int*[n];
		for (int i = 0; i < n; i++)
		{
			mat[i] = new int[m];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> mat[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}




		//cout << endl << endl;

		int ans  =  0;

		//We have to find the largest rectangular area row , by row
		//int i = 1;
		for (int i = 0; i < n; i++)
		{
			int *arr = new int[m];
			for (int j = 0; j < m; j++)
			{
				if (mat[i][j] == 0)
				{
					arr[j] = 0;
				}
				else if ((i - 1) >= 0)
				{

					mat[i][j] = mat[i][j] + mat[i - 1][j];
					arr[j] = mat[i][j];
				}
				else
				{

					//This is the first row // O'th row
					arr[j] = 1;
				}
			}
			int temp_area = Largest_rectangular_area(arr, m);
			//wer(temp_area);
			ans = max(temp_area, ans);
			//cout << endl;
		}


		wer(ans);

	}
	return 0;
}
