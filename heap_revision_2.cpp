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

class heap
{
	vector<int> v;
	bool is_min_heap;
public:
	heap(bool type)
	{
		v.push_back(-1);
		is_min_heap = type;
	}
	bool compare(int a, int b)
	{
		cout << "a  : " << a << endl;
		cout << "b  : " << b << endl;
		if (is_min_heap)
		{
			if (a <= b)
			{
				return true;
			}
			else return false;
		}
		else if (is_min_heap == false)
		{
			cout << " here : ";
			if (a >= b)
			{
				return true;
			}
			else return false;
		}
		cout << "The control reaches here when : ";
		cout << endl;


	}

	void push(int d)
	{
		if (is_min_heap) cout << "This is a min heap";
		v.push_back(d);
		int n = v.size();
		int idx = n - 1;
		int par_idx = idx / 2;
		while (idx > 1 && v[par_idx] > v[idx])
		{
			swap(v[par_idx], v[idx]);
			idx  = par_idx;
			par_idx = idx;

		}
	}
	void show_heap()
	{
		for (auto x : v)
		{
			cout << x << " ";
		}
	}
};

int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	heap min_heap(true);
	min_heap.push(6);
	min_heap.show_heap();
	cout << endl;

	min_heap.push(4);
	min_heap.show_heap();
	cout << endl;

	min_heap.push(2);
	min_heap.show_heap();
	cout << endl;

	min_heap.push(8);
	min_heap.show_heap();
	cout << endl;


	min_heap.push(5);
	min_heap.show_heap();
	cout << endl;
	return 0;
}
