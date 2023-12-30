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

class Pair_compare
{
public:
	bool operator()(pair<int, int> p1, pair<int, int> p2)
	{
		if (p1.first > p2.first)
		{
			return true;
		}
		else return false;
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
	priority_queue<int> pq_max_heap;
	priority_queue<int, vector<int> , greater<int> > pq_min_heap;
	pq_max_heap.push(7);
	pq_max_heap.push(2);
	pq_max_heap.push(9);
	pq_max_heap.push(5);
	pq_max_heap.push(1);
	pq_min_heap.push(7);
	pq_min_heap.push(2);
	pq_min_heap.push(9);
	pq_min_heap.push(5);
	pq_min_heap.push(1);
	cout << "MAX HEAP : ";
	while (!pq_max_heap.empty())
	{
		cout << pq_max_heap.top() << " ";
		pq_max_heap.pop();
	}
	cout << endl;
	cout << "MIN HEAP : ";
	while (!pq_min_heap.empty())
	{
		cout << pq_min_heap.top() << " ";
		pq_min_heap.pop();
	}
	cout << endl;
	priority_queue < pair<int, int> , vector<pair<int, int> >, Pair_compare > pq;
	pq.push({2, 1});
	pq.push({3, 4});
	pq.push({4, 3});
	pq.push({5, 2});
	pq.push({6, 8});
	//complexity K log n
	for (int i = 0; i < 3; i++)
	{
		pair<int, int> p = pq.top();
		//when we are printing elements we  are printing them in them from the last
		//that is why the printing is in reverse order from what it is expected

		cout << p.first << " " << p.second << endl;
		pq.pop();
	}
	return 0;
}
