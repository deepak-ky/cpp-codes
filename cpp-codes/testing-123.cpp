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
#define s                            second

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

class student{
public:
	int rollNo;
};

class customCompare{
public:
	bool operator()(const pair<int,int> &p1, const pair<int,int> &p2){
		return p1.first > p2.first;
	}
};

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		set<pair<int,int>, customCompare> s;
		int nums[] = {1,2,3,4};
		int k = 2;
        for(int i=0;i<k;i++){
        	 
            pair<int,int> p;
            p.first = nums[i];
            p.second = i;
            s.insert(p);
        }


		for(auto &x : s){
			cout << x.first << " " << x.second << endl;
		}
		/*int a = 8;
		cout << a << endl;
		cout << (a >> 4) << endl;		

		int b = 1;
		cout << b << endl;
		cout << (b << 0) << endl; 

		int c = a & 1;
		cout << c << endl;

		//binary representation
		for(int i=31;i>=0;i--){
			if((a>>i)&1){
				cout << "1";
			}else{
				cout << "0";
			}
		}*/


		/*vector<int> a = {1,2,3};
		out(a,3);
		vector<int> b = {4,5,6};
		out(b,3);
		a.insert(a.end(),b.begin(),b.end());
		out(a,6);*/
		// student s1,s2;
		// s1.rollNo = 1;
		// s2.rollNo = 2;
		// cout << s1.rollNo <<" " << s2.rollNo << endl;

		// if (s1 == s2){
		// 	yes;
		// }

		// vector<int> v = {1 , 6 ,19, 24 , 100 ,150};

		// auto itr = upper_bound(v.begin(), v.end(), 175);

		// cout << itr - v.begin();

		// char cch = '9';
		// int w = cch - '0';
		// wer(w);

		// int i = 3;
		// char ch = char(i + 48);
		// string s = "";
		// s += ch;
		// cout << s << endl;

		// int x = 1000000000000000000;
		// cout << x << endl;

		// char s = '10000';
		// s += 1;
		// cout << s << endl;

		// cout << i - '0';

		// int w = 9;
		// cout << char(w + 48) << endl;

		// char a = 'A';
		// cout << char(a+32) << endl;



		// vector<string> b;
		// b.push_back("abc");
		// b.push_back("def");
		// b.push_back("ghi");

		// cout << b[1][1];

		// priority_queue<int> pq;
		// pq.push(1);
		// pq.push(2);
		// pq.push(3);


		// priority_queue<int,vector<int>,greater<int>> pq1;
		// pq1.push(1);
		// pq1.push(2);
		// pq1.push(3);

		// cout << pq1.top() << " ";

		/*map<string,int> mp = {
			{"Hey" , 1}
		};

		for(auto &x : mp){
			cout << x.first << "," << x.second << endl;
		}*/

		/*vector<map<string,int>> v(2);
		v[0] = {
			{"Abhishek",1},
			{"Upmanyu",2}
		};
		v[0]["Karn"] = 3;

		v[1] = {
			{"Suyash",3},
			{"Prabhudesai",4}
		};

		for(auto &x : v){
			for(auto &y : x){
				cout << y.first <<","<< y.second << endl;
			}

			cout << endl;
		}*/

		// int n = 1000000000;

		// int *dp = new int[n];

		

	}
	return 0;
}
