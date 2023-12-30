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

string xor_cal(string a, string b, int n)
{

	if (a.length() == b.length() && b.length() != n)
	{
		cout << "here";
		return "";
	}
	string result = "";
	for (int i = 0; i < n; i++)
	{
		if (a[i] == b[i])
		{
			result += "0";
		}
		else result += "1";
	}
	return result;
}

string find_rem(string data , string key, bool flag)
{
	int n = key.length();
	string x = "";
	for (int i = 0; i < n - 1; i++)
	{
		x += "0";
	}
	if (flag)
	{
		data += x;
	}
	x += "0";
	string all_zeroes = x;
	string quot_curr = data.substr(0, n);
	string  quotient = "";
	string curr_rem;
	if (data[0] == '1')
	{
		quotient += "1";
		curr_rem = xor_cal(quot_curr, key, n);
	}
	else
	{
		quotient += "0";
		curr_rem = xor_cal(quot_curr, all_zeroes, n);
	}
	int j = n;
	while (j < data.length())
	{
		string temp = curr_rem;
		temp += data[j];
		j++;
		curr_rem = temp.substr(1, n);
		if (curr_rem[0] == '1')
		{
			quotient += "1";
			curr_rem = xor_cal(curr_rem, key, n);

		}
		else
		{
			quotient += "0";
			curr_rem = xor_cal(curr_rem, all_zeroes, n);
		}


	}
	wer(curr_rem);
	return curr_rem;
}


bool is_data_correct(string data, string key)
{
	string res = find_rem(data, key, false);
	wer(res);
	for (int i = 0; i < key.length(); i++)
	{
		if (res[i] != '0')
		{
			return false;
		}

	}
	return true;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		string data;
		string key;
		cin >> data >> key;

		//we need the crc bits or we need the remainder
		string rem = find_rem(data, key, true);
		string temp = rem;
		rem = temp.substr(1, key.length() - 1);
		cout << rem << endl;

		data += rem;
		cout << data << endl;

		bool flag = is_data_correct(data, key);
		if (flag)
		{
			yes;
		}
		else no;


	}
	return 0;
}
