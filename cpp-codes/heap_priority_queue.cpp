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
	priority_queue<int, std::vector<int> , greater<int> > pq_min_heap;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int w;
		cin >> w;
		pq_max_heap.push(w);
		pq_min_heap.push(w);
	}
	cout << "Max heap : \n";
	while (!pq_max_heap.empty())
	{
		cout << pq_max_heap.top() << endl;
		pq_max_heap.pop();
	}
	cout << "Min heap : \n";
	while (!pq_min_heap.empty())
	{
		cout << pq_min_heap.top() << endl;
		pq_min_heap.pop();
	}
	return 0;
}
