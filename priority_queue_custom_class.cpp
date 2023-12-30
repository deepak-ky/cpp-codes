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
class person
{
public:
	string name;
	int age;
	person(string s, int a)
	{
		name = s;
		age = a;
	}
};

class person_compare
{
public:
	bool operator()(person A, person B)
	{
		if (A.age > B.age)
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

	priority_queue<person, vector<person>, person_compare> pq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string a; int a1;
		cin >> a >> a1;
		person p(a, a1);
		pq.push(p);
	}

	int k = 3;
	while (k > 0)
	{
		person q = pq.top();
		cout << q.name << " :: " << q.age << endl;
		pq.pop();
		k--;
	}
	return 0;
}
