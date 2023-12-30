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

		if (is_min_heap)
		{

			if (a <= b)
			{
				return true;
			}
			else return false;
		}
		else if (!is_min_heap)
		{

			if (a >= b)
			{
				return true;
			}
			else return false;
		}
	}
	void heapify(int idx)
	{
		int left = 2 * idx;
		int right = 2 * idx + 1;
		int last_idx = v.size() - 1;
		int min_idx = idx;
		if (left <= last_idx && compare(v[left], v[min_idx]))
		{
			min_idx = left;
		}
		if (right <= last_idx && compare(v[right], v[min_idx]))
		{

			min_idx = right;
		}
		if (idx != min_idx)
		{
			swap(v[idx], v[min_idx]);
			heapify(min_idx);
		}
	}
	void push(int d)
	{
		//if (is_min_heap) cout << "This is a min heap";
		v.push_back(d);
		int n = v.size();
		int idx = n - 1;
		int par_idx = idx / 2;
		while (idx > 1 && compare( v[idx], v[par_idx]))
		{
			swap(v[par_idx], v[idx]);
			idx  = par_idx;
			par_idx = par_idx / 2;

		}
	}
	void pop()
	{
		int n = v.size();
		swap(v[1], v[n - 1]);
		v.pop_back();
		heapify(1);
	}
	void show_heap()
	{
		for (auto x : v)
		{
			cout << x << " ";
		}
	}
};
void build_max_heap(vector<int> &arr)
{
	for (int i = 2; i < arr.size(); i++)
	{
		int idx = i;
		int par = i / 2;
		while (idx > 1 && arr[par] < arr[idx])
		{
			swap(arr[par], arr[idx]);
			idx = par;
			par = par / 2;
		}
	}
}
void heapiffy(int idx , vector<int> &v)
{
	int left = 2 * idx;
	int right = 2 * idx + 1;
	int last_idx = v.size() - 1;
	int min_idx = idx;
	if (left <= last_idx && v[left] > v[idx])
	{
		min_idx = left;
	}
	if (right <= last_idx && v[right] > v[min_idx])
	{
		min_idx = right;
	}
	if (idx != min_idx)
	{
		swap(v[min_idx], v[idx]);
		heapiffy(min_idx, v);
	}
}
void heapifffy(int idx , vector<int> &v, int n)
{
	int left = 2 * idx;
	int right = 2 * idx + 1;
	int last_idx = n - 1;
	int min_idx = idx;
	if (left <= last_idx && v[left] > v[idx])
	{
		min_idx = left;
	}
	if (right <= last_idx && v[right] > v[min_idx])
	{
		min_idx = right;
	}
	if (idx != min_idx)
	{
		swap(v[min_idx], v[idx]);
		heapifffy(min_idx, v, n);
	}
}
void buildd_max_heap(vector<int> &a)
{
	int n = a.size();
	for (int i = (n / 2); i >= 1; i--)
	{

		heapifffy(i, a , n);


	}
}
void heap_sort(vector<int> &v)
{
	buildd_max_heap(v);
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;
	int n  = v.size();
	while (n > 1)
	{
		swap(v[1], v[n - 1]);

		n--;
		heapifffy(1, v, n);
	}
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
	// heap min_heap(true);
	// min_heap.push(6);
	// min_heap.show_heap();
	// cout << endl;

	// min_heap.push(4);
	// min_heap.show_heap();
	// cout << endl;

	// min_heap.push(2);
	// min_heap.show_heap();
	// cout << endl;

	// min_heap.push(8);
	// min_heap.show_heap();
	// cout << endl;


	// min_heap.push(5);
	// min_heap.show_heap();
	// cout << endl;
	// cout << "After removing an element : \n";
	// min_heap.pop();
	// min_heap.show_heap();
	// cout << endl;

	// //Build heap from array in N Log N
	// vector<int> arr{ -1, 7, 4, 3, 1, 8};
	// for (auto x : arr)
	// {
	// 	cout << x << " ";
	// }
	// cout << "\nAfter Building MAX HEAP : \n";
	// build_max_heap(arr);
	// for (auto x : arr)
	// {
	// 	cout << x << " ";
	// }
	// cout << endl;
	//Build MAX heap from array in N
	// vector<int> a{ -1,   7, 4, 3, 1, 8};
	// for (auto x : a)
	// {
	// 	cout << x << " ";
	// }
	// cout << "\nAfter Building MAX HEAP : \n";
	// buildd_max_heap(a);
	// for (auto x : a)
	// {
	// 	cout << x << " ";
	// }


	//Heap SORT -> Complexity is N LOG N
	vector<int> d{ -1, 4, 1, 3, 9, 7};
	heap_sort(d);
	for (auto x : d)
	{
		cout << x << " ";
	}
	// cout << endl;
	// for (auto x : d )
	// 	cout << x << " ";
	return 0;
}
