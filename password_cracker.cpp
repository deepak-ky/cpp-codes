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

bool flag = false;
string s_ans;
void can_string_be_formed(string login_attempt, string passwords[], int size, int attempt_idx, string curr_string, vector<int> ans)
{
	if (curr_string.compare(login_attempt) == 0)
	{
		//return a string here
		if (flag == false)
		{
			for (int i = 0; i < ans.size(); i++)
			{
				if (i != ans.size() - 1)
				{
					s_ans += passwords[ans[i]];
					s_ans += " ";
				}
				else
				{
					s_ans += passwords[ans[i]];
				}
			}
			flag = true;
		}
		return;
	}
	if (curr_string.length() > login_attempt.length())
	{
		return;
	}
	char ch = login_attempt[attempt_idx];
	for (int i = 0; i < size; i++)
	{
		char ch1 = passwords[i][0];
		int len = passwords[i].length();
		if (ch == ch1)
		{
			ans.pb(i);
			can_string_be_formed(login_attempt, passwords, size, attempt_idx + len, curr_string + passwords[i], ans);
			ans.pop_back();
		}
	}

	return;
}

int32_t main()
{
	init();
	int t = 1;
	cin >> t;
	while (t--)
	{
		flag = false;
		int n;
		cin >> n;
		string passwords[n];
		for (int i = 0; i < n; i++)
		{
			cin >> passwords[i];
		}
		string login_attempt;
		cin >> login_attempt;

		unordered_set<char> all_character_check;
		bool flag1 = true;
		for (int i = 0; i < n; i++)
		{
			for (auto  c : passwords[i])
			{
				all_character_check.insert(c);
			}
		}
		for (auto c : login_attempt)
		{
			if (all_character_check.find(c) == all_character_check.end())
			{
				flag1 = false;
				break;
			}
		}


		if (flag1)
		{
			string curr_string = "";
			vector<int> ans;
			s_ans = "";
			can_string_be_formed(login_attempt, passwords, n, 0, curr_string, ans);
		}

		if (!flag)
		{
			cout << "WRONG PASSWORD";
		}
		else
		{
			cout << s_ans;
		}
		cout << endl;
	}
	return 0;
}
