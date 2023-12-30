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
#define se                            second

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

string add_string(string num1 , string num2)
{
	int carry = 0;
	int i = num1.length() - 1;
	int j = num2.length() - 1;

	string ans = "";

	while (i >= 0 && j >= 0)
	{
		int x = num1[i] - '0';
		int y = num2[j] - '0';

		i--;
		j--;

		int z = x + y + carry;

		carry = z / 10;
		int val = z % 10;

		ans += val + 48;
	}


	while (i >= 0)
	{
		int x = num1[i] - '0';
		i--;
		int z = x + carry;

		carry = z / 10;
		int val = z % 10;

		ans += val + 48;
	}

	while (j >= 0)
	{
		int x = num2[j] - '0';
		j--;
		int z = x + carry;

		carry = z / 10;
		int val = z % 10;

		ans += val + 48;
	}


	if (carry != 0)
	{
		ans += carry + 48;
	}



	reverse(ans.begin(), ans.end());



	for (int i = 0; i < ans.length(); i++)
	{
		if (ans[i] != '0')
		{
			ans = ans.substr(i, ans.length() - i);
			break;
		}
	}
	return ans;


}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		//to minimize the sum try minimizing the most significant bit first;

		priority_queue<int, vector<int> , greater<int>> pq;

		string num1 = "";
		string num2 = "";

		for (int i = 0; i < n; i++)
		{
			pq.push(a[i]);
		}

		bool num1_turn = true;
		while (!pq.empty())
		{
			int w = pq.top();
			pq.pop();

			if (num1_turn == true)
			{
				num1 += w + 48;
				num1_turn = false;

			}
			else
			{
				num2 += w + 48;
				num1_turn = true;
			}
		}



		cout << add_string(num1, num2);


	}
	return 0;
}
