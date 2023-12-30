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

//MAX SIZE OF THE VECTOR CAN BE 2

vector<int> find_candidates(int *a, int n)
{
	int cand_1 = INT_MAX;
	int cand_2 = INT_MAX;
	int cnt_1 = 0;
	int cnt_2 = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i] == cand_1)
		{
			cnt_1++;
		}
		else if (a[i] == cand_2)
		{
			cnt_2++;
		}
		else if (cnt_1 == 0)
		{
			cand_1 = a[i];
			cnt_1 = 1;
		}
		else if (cnt_2 == 0)
		{
			cand_2 = a[i];
			cnt_2 = 1;
		}
		else
		{
			//both the candidates have been assigned and the current element is a new one
			cnt_1--;
			cnt_2--;

		}
	}


	vector<int> ans;
	ans.push_back(cand_1);
	ans.push_back(cand_2);
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

		vector<int> p = find_candidates(a, n);
		int cand_1 = p[0];
		int cand_2 = p[1];
		wer(cand_1);
		wer(cand_2);
		int cnt_1 = 0;
		int cnt_2 = 0;

		bool no_element = true;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == cand_1)
			{
				cnt_1++;
			}
		}


		if (cnt_1 > n / 3)
		{
			no_element = false;
			cout << cand_1 << " ";
		}

		for (int i = 0; i < n; i++)
		{
			if (a[i] == cand_2)
			{
				cnt_2++;
			}
		}

		if (cnt_2 > n / 3)
		{
			no_element = false;
			cout << cand_2 << " ";
		}






		if (no_element)
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
