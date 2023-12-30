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

bool is_safe_to_connect(int v, int graph1 [][5], int *path, int pos)
{
	if (graph1[path[pos - 1]][v] == 0)
	{
		return false;
	}
	for (int i = 0; i < pos; i++)
	{
		if (path[i] == v)
		{
			return false;
		}
	}
	return true;
}
bool ham_cycle_util(int graph1[][5], int *path, int pos)
{
	//if all the vertices have been covered
	if (pos == 5)
	{
		if (graph1[path[pos - 1]][path[0]] == 1)
		{
			return true;
		}
		else return false;
	}

	for (int v = 1; v < 5; v++)
	{
		if (is_safe_to_connect(v, graph1, path, pos))
		{
			path[pos] = v;
			bool connect = ham_cycle_util(graph1, path, pos + 1);
			if (connect)
				return true;

			path[pos] = -1;
		}
	}

	return false;
}


bool hamiltonian_cycle_present(int graph1[][5])
{
	int *path = new int[5];
	for (int i = 0; i < 5; i++)
	{
		path[i] = -1;
	}
	path[0] = 0;

	if (ham_cycle_util(graph1, path, 1) == false)
	{
		return false;
	}
	else return true;

}

int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int graph1[5][5] = {
		{0, 1, 0, 1, 0},
		{1, 0, 0, 1, 1},
		{0, 0, 0, 0, 1},
		{1, 1, 0, 0, 1},
		{0, 1, 1, 1, 0}
	};

	if (hamiltonian_cycle_present(graph1))
	{
		cout << "true";
	}
	else cout << "false";
	return 0;
}
