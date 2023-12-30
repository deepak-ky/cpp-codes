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

bool game(string s)
{
	int n = s.length();

	int mid = (n - 1) / 2;

	int left_blank = 0;
	int right_blank = 0;
	int left_sum = 0;
	int right_sum = 0;

	for (int i = 0; i <= mid; i++)
	{
		if (s[i] == '?')
			left_blank++;
		else
			left_sum += s[i] - '0';
	}

	for (int i = mid + 1; i < n; i++)
	{
		if (s[i] == '?')
			right_blank++;
		else
			right_sum += s[i] - '0';
	}


	wer(left_sum);
	wer(right_sum);
	wer(left_blank);
	wer(right_blank);

	if (left_blank + right_blank == 0)
	{
		if (left_sum == right_sum)
		{
			return false;
		}
		else return true;
	}
	else if ( (left_blank + right_blank) & 1)
	{
		return true;
	}
	else if ( left_blank == right_blank)
	{
		if (left_sum == right_sum)
		{
			return false;
		}
		else return true;
	}
	else
	{
		int w = min(left_blank, right_blank);
		left_blank -= w;
		right_blank -= w;

		if (left_blank > 0)
		{

			cout << "here";

			int alice_chances = left_blank / 2;
			int bob_chance    = left_blank / 2;

			if (left_blank & 1)
			{
				alice_chances = left_blank / 2 + 1;
				bob_chance    = left_blank / 2;
			}

			bob_chance *= 9;

			if ((left_sum + bob_chance) < right_sum) return true;

			alice_chances *= 9;
			if ((left_sum + alice_chances) > right_sum) return true;


			return false;



		}
		else if (right_blank > 0)
		{

			int alice_chances = right_blank / 2;
			int bob_chance    = right_blank / 2;

			if (right_blank & 1)
			{
				alice_chances = right_blank / 2 + 1;
				bob_chance    = right_blank / 2;
			}

			bob_chance *= 9;

			if ((right_sum + bob_chance) < left_sum) return true;

			alice_chances *= 9;
			if ((right_sum + alice_chances) > left_sum) return true;


			return false;


		}


	}
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		string s;
		cin >> s;

		if (game(s))
		{
			yes;
		}
		else no;



	}
	return 0;
}
