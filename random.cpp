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
#define se                           second

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
//EVERY DIMENSION ARRAY PASSED BY REFERENCE ALWAYS
// void pass(int *a)
// {
// 	for (auto x : a)
// 	{
// 		cout << x << " ";
// 	}
// 	cout << endl;
// }

// void pass(int a[][2])
// {
// 	for (int i = 0; i < 3; i++)
// 	{
// 		for (int j = 0; j < 2; j++)
// 		{
// 			a[i][j] *= 2;
// 		}
// 		cout << endl;

// 	}

// }


class custom_compare
{

public:
	bool operator()(pair<string, int> p1, pair<string, int> p2)
	{
		if (p1.second <= p2.second)
		{
			return true;
		}
		else return false;
	}
};

void pass(string passwrods[])
{
	char ch = passwrods[0][0];
	cout << ch << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << passwrods[i] << " ";
	}
}
int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		priority_queue<int> pq;
		pq.push(6);
		pq.push(9);
		pq.push(1);
		pq.push(4);

		pq.erase(9);
		/*int n = 3;

		vector<int> v(n, 5);
		v.push_back(56);
		vector<int> v1(n, 6);


		v.insert(v.end(), v1.begin(), v1.end());
		cout << v.size() << endl;
		cout << v.capacity() << endl;

		for (auto x : v)
		{
			cout << x << " ";
		}*/

		// set< pair<int, int> > s;

		// int a = INT_MAX - 1;
		// cout << a << endl;
		// //a = INT_MAX + 1;
		// if (a == INT_MAX)
		// {
		// 	yes;
		// }
		// string a = "asdfsf";
		// cout << a.substr(0, 3);




		// cout << endl;
		// unordered_map<int, vector<int>> mp;
		// mp[2].push_back(1);
		// mp[2].push_back(2);
		// mp[2].push_back(3);

		// vector<int> g = mp[2];
		// int w = 2;
		// int num;
		// for (int i = 0; i < g.size(); i++)
		// {
		// 	if (g[i] == w)
		// 	{
		// 		num = i;
		// 		break;
		// 	}
		// }
		// g.erase(g.begin() + num);
		// mp[2] = g;

		//mp[2].remove(mp[2].begin(), mp[2].end(), 2);

		// for (auto x : mp[2])
		// {
		// 	cout << x << " ";
		// }
		/*
				double low = -1e6;
				double high = 2e6;
				double e = 1e-6;
				cout << fixed <<  setprecision(5) <<  low << endl;
				cout << fixed <<  setprecision(5) <<  high << endl;
				cout << fixed <<  setprecision(5) <<  e << endl;

		*/		/*string a = "abcde";
cout << a.substr(0, 4) << endl;
cout << a.substr(5) << endl;
*/
		/*
			char  a = '1';
			char b = '1';
			char c = a - '0' + b - '0';
			cout << c  - '0' << endl;
		*/		// int b = -1;
		// cout << b * 10 * -2 << endl;


		// string a = "abc";
		// cout << a << endl;
		/*string b = a.substr(-1, 1);*/


		// set<vector<int> > s;
		// vector<int> v = {1, 2, 3};
		// vector<int> v1(v);
		// //v1 = v;
		// v1.pb(8);

		// for (auto x : v1 ) cout << x << " ";

		/*int a = 7;
		char b = a + 48;
		cout << b << endl;*/
		/*	int dp[2][2];
			memset(dp, -1, sizeof(dp));
			int n = 2;
			dp[1][0] = false;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cout << dp[i][j] << " ";
				}
				cout << endl;
			}*/


		/*set<int> s;
		s.insert(5);
		s.insert(1);
		s.insert(3);
		s.insert(2);
		s.insert(6);
		s.insert(4);
		s.insert(8);
		s.insert(9);
		auto it = s.find(8);
		it++;
		auto it1 = s.find(3);
		s.erase(it1, it);
		for (auto x : s) cout << x << " ";*/
		// int a = 0;
		// int b = -a;
		// cout << a << endl;
		// cout << b << endl;

		// 	vector<int> a = {5, 3, 8, 1, 3};
		// 	sort(a.begin() + 1, a.end());
		// 	for (auto x : a) cout << x << " ";
		// int a[] = {1, 2, 3};
		// int b;
		// cin >> b;
		// cout << a[b];
		// multiset<int, greater<int> > s;
		// s.insert(5);
		// s.insert(4);
		// s.insert(4);
		// s.insert(3);
		// for (auto it = s.begin(); it != s.end(); it++)

		// {
		// 	cout << *it << " ";
		// }		// int **mat = new int*[n];
		// for(int i=0;i<n;i++)
		// {
		// 	mat[i] = new int[m];
		// }
		// for(int i=0;i<n;i++)
		// {
		//    for(int j = 0;j<m;j++)
		//    {
		//       cin >> mat[i][j];
		//       }
		// }
		// for(int i=0;i<n;i++)
		// {
		// 	for(int j=0;j<m;j++)
		// 	{
		// 	   cout << mat[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		// multiset<pair<string, int> , custom_compare > ms;

		// ms.insert({"b", 23});
		// ms.insert({"aa", 25});
		// ms.insert({"a", 52});

		// for (auto x : ms)
		// {
		// 	cout << x.first << " " << x.second << endl;
		// }


		// vector<string> v;
		// v.push_back("deepak");
		// string a = "";
		// char ch = 15 + '0';
		// wer(ch);
		// a += ch;
		// v.pb(a);
		// for (auto x : v)
		// {
		// 	cout << x << " ";
		// }
		// string a;
		// a += '4';
		// cout << a << endl;
		// vector<int> v[2];
		// v[1].push_back(1);
		// v[0].push_back(9);

		// for (int i = 0; i < 2; i++)
		// {
		// 	vector<int> p = v[i];
		// 	cout << p.size() << endl;
		// 	for (auto x : p)
		// 	{
		// 		cout << x << endl;
		// 	}
		// }

		// stack<int> s;
		// s.push(1);
		// s.push(2);
		// s.push(3);
		// s.push(4);
		// s.push(5);
		// while (!s.empty())
		// {
		// 	cout << s.top() << " ";
		// 	s.pop();
		// }
		// unordered_map<int, bool> mp;
		// mp[1] = false;
		// mp[2] = true;
		// if (mp[2])
		// {yes;}
		// else no;
		// 	list<int> l;/* = new list<int>*/;
		// 	l.pb(3);
		// 	l.pb(1);
		// 	l.pb(1);
		// 	l.pb(2);
		// 	l.sort();
		// 	l.push_front(9);
		// 	l.pop_back();
		// 	//cout << l[3] << endl;
		// 	for (auto x = l.begin(); x != l.end(); x++)
		// 	{
		// 		cout << *x << " ";
		// 	}
		// 	cout << endl;
		// 	for (auto x : l)
		// 	{
		// 		cout << x << " " ;
		// 	}
		// double x;
		// int y;
		// for (int i = 0; i < 2; i++)
		// {
		// 	cin >> y;
		// 	x = (32 - x) * (5 / 9);
		// 	cout << setprecision(3) << x << " ";
		// }



		// deque<int> v;
		// int n = 3;
		// for (int i = 0; i < 3; i++)
		// {	int x;
		// 	cin >> x;
		// 	v.pb(x);
		// }
		// for (auto x : v) cout << x << " ";
		// cout << endl;
		// deque<int> d;
		// for (int i = 0; i < 3; i++)
		// {	int x;
		// 	cin >> x;
		// 	d.pb(x);
		// }
		// sort(d.begin(), d.end());
		// for (auto x : d) cout << x << " ";
		// cout << endl;
		// cout << "here";
		// if (v == d)
		// {
		// 	yes;
		// }
		// else

		// 	no;







		// queue<int> q;
		// q.push(4);
		// q.push(5);
		// q.push(6);
		// int w = send(q);
		// if (q.empty())
		// {
		// 	yes;
		// }
		// else
		// {
		// 	cout << q.front() << endl;
		// 	cout << q.back();
		// }

		// unordered_set<int> s;
		// s.insert(1);
		// s.insert(3);
		// s.insert(2);
		// for (auto x : s)
		// {
		// 	cout << x << " ";
		// }
		// priority_queue<int> p;
		// p.push(5);
		// p.push(4);
		// p.push(1);
		// p.push(3);
		// p.push(2);
		// p.clear():
		// 	while (!p.empty())
		// {
		// 	cout << p.top() << endl;
		// 	p.pop();
		// }
		// float a = 5;
		// float p = 2;   // p number of decimal places
		// int n = 35;

		// float b = 0.1;

		// //decreasing p beacuse starting from 0.1 // one decimal place is already taken care of
		// p--;
		// float copy_a;

		// while (p >= 0)
		// {
		// 	for (float j = b; j <= (b * 10); j += b)
		// 	{
		// 		float c = a;
		// 		c = c + j;
		// 		if ( (c * c ) <= n)
		// 		{
		// 			copy_a = c;
		// 		}
		// 		else
		// 		{
		// 			break;
		// 		}
		// 	}
		// 	a = copy_a;
		// 	//Here decimal digits will be keep on adding to a;
		// 	b = b / 10;
		// 	p--;
		// }


		// cout << a << endl;

		// int a[2][2] = {{1, 2}, {2, 3}};
		// pass(a);
		// for (int i = 0; i < 2; i++)
		// {
		// 	for (int j = 0; j < 2; j++)
		// 	{
		// 		cout << a[i][j] << " ";
		// 	}
		// 	cout << endl;

		// }

		// vector<int> v{1, 2, 3, 4, 5};
		// auto it = find(v.begin(), v.end() , 9);
		// if (it != v.end())
		// {
		// 	cout << "present " << "at index : " << it - v.begin();
		// }
		// else cout << "Not present";
		// string s1 = "vidhi";
		// string s2 = "vidhia";

		// if (s1.find(s2) != string::npos)
		// {
		// 	cout << "S2 is present in s1";
		// }
		// else cout << "s2 is not present in s1";
		// // int a = 5;
		// cout << a * 2;





		// char keypad[10][10] = {"" , "" , "ABC" , "DEF" , "GHI" , "JKL" , "MNO" , "PQRS" , "TUV" , "WXYZ"};
		// cout << keypad[2];
		// cout << endl;
		// char curr[2];
		// // string curr = keypad[2];
		// // cout << curr;






		// //For printing an character array it is necessary to add '\0' at the end
		// /*
		// 		string a = "abc";
		// 		//a = a + '\0';
		// 		cout << a << " ";

		// 		cout << endl;

		// 		char b[] = "abc";
		// 		cout << b << " ";

		/*string a = "deepak";
		int idx = 2;
		char ch =  a[idx];
		string c = "";
		c += a[idx];
		cout << c << " ";
		cout << endl;
		string b = "";
		b += a[idx] + a[idx + 1];
		cout << b << " ";
		*/


		/*char w[][3] = { "ab" , "cd"};
		cout << w[0] << endl;

		char w1[][2] = { {'a', 'b'} , {'c', 'd'}};
		cout << w1[0] << endl;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout  << w1[i][j] << " ";
			}
			cout << endl;
		}*/
	}
	return 0;
}

