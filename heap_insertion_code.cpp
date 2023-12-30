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
	bool minheap;
	bool compare(int a, int b)
	{
		if (minheap)
		{
			return a < b;
		}
		else
		{
			return a > b;
		}
	}

	void heapify(int idx)
	{
		int left = idx * 2;
		int right = left + 1;

		int last_idx = v.size() - 1;
		int min_idx = idx;

		if ((left <= last_idx) && compare(v[left], v[idx]))
		{
			min_idx = left;
		}
		if ((right <= last_idx) && compare(v[right], v[min_idx]))
		{
			min_idx = right;
		}

		if (idx != min_idx)
		{
			swap(v[idx], v[min_idx]);
			heapify(min_idx);
		}
	}
public:
	heap(int default_size = 14, bool type = true)
	{
		v.reserve(default_size);
		v.push_back(-1);
		minheap = type;
	}

	void push(int d)
	{
		v.push_back(d);
		int idx = v.size() - 1;
		int par_index = idx / 2;

		while ( compare(v[idx], v[par_index]) && idx > 1) //if our current idx is one then we cannot move forward
		{	//this line does not mean that our index cannot be one but once our index is one that we cannot move forward
			swap(v[idx], v[par_index]);                   //when idx = 2 , then this loop will run and index will become equal to parent which is 1 and then swap will happen and after that loop will not run
			idx = par_index;
			par_index = par_index / 2;
		}
	}

	int top()
	{
		return v[1];
	}

	void pop()
	{
		int last_idx = v.size() - 1;
		swap(v[1], v[last_idx]);
		v.pop_back();
		heapify(1);
	}

	bool is_empty()
	{
		if (v.size() == 1)
		{
			return true;
		}
		else return false;
	}

	void show_vector()
	{
		cout << "Heap Array Now : \n";
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
	heap h(12 , false);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		/* code */cin >> a[i];
		h.push(a[i]);
	}
	//h.push(0);
	//h.pop();
	//h.show_vector();
	while (!h.is_empty())
	{
		cout << h.top() << " ";
		h.pop();
	}
	return 0;
}
