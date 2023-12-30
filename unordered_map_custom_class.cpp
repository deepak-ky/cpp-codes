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
class student
{
public:
	string fname;
	string lname;
	int roll;
	student(string f, string l, int r)
	{
		fname = f;
		lname = l;
		roll = r;
	}
	bool operator==(const student &s) const
	{
		return roll == s.roll ? true : false;
	}
};
class hashfn
{
public:
	operator ()(const student&s) const {
		return s.fname.length() + s.lname.length();
	}
};
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	unordered_map<student, int, hashfn> student_map;
	student s1("deepak", "kumar", 51);
	student s2("dhruv", "kumar", 56);
	student s3("divya", "kumar", 59);
	student s4("deepak", "kumar", 52);

	student_map[s1] = 40;
	student_map[s2] = 37;
	student_map[s3] = 38;
	student_map[s4] = 39;

	cout << endl << student_map[s3] << endl;

	for (auto x : student_map)
	{
		cout << endl << x.first.fname << " " << x.first.roll << " : " << x.second;
	}
	return 0;
}
