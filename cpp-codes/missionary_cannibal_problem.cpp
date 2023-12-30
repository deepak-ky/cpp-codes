#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : \n"<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back

//Our initial state is => L : [3 , 3 , 1] ::  R : [0 ,0 ,0]
//Our final state is   => R : [0 , 0 , 0] ::  L : [3 ,3 ,1]
//To determine the nature string = "left" or "right"

vector<string> ans;
void fill_state_in_vector(int l1, int l2, int r1, int r2, string s)
{
	string l1_s = to_string(l1);
	string l2_s = to_string(l2);
	string r1_s = to_string(r1);
	string r2_s = to_string(r2);
	if (s == "left")
	{
		ans.push_back("L : [" + l1_s + " , " + l2_s + " , " + "1 ] :: R : [" + r1_s + "," + r2_s + ", 0 ]" );
	}
	else
	{
		ans.push_back("L : [" + l1_s + " , " + l2_s + " , " + "0 ] :: R : [" + r1_s + "," + r2_s + ", 1 ]" );

	}

}


//Move no
//1 -> one cannibal
//2 -> two cannibal
//3 -> one missionary
//4 -> two missionary
//5 -> one cannibal and missionary

/*int dp[4][4][4][4];*/
string all_string(int l1, int l2, int r1, int r2, string w)
{
	string l1_s = to_string(l1);
	string l2_s = to_string(l2);
	string r1_s = to_string(r1);
	string r2_s = to_string(r2);
	return l1_s + l2_s + r1_s + r2_s + w;
}
unordered_map<string, bool> mp;

bool solve(int left_missionary , int left_canibal , int right_missionary , int right_cannibal , string boat_bank, int move_no)
{

	cout << endl <<  boat_bank << endl;
	wer(left_missionary);
	wer(left_canibal);
	wer(right_missionary);
	wer(right_cannibal);
	cout << endl;
	string c = all_string(left_missionary, left_canibal, right_missionary, right_cannibal, boat_bank);

	if (mp.find(c) != mp.end())
	{
		if (mp[c] == false)
		{
			return mp[c];
		}
	}
	else
	{
		if (left_missionary > 3 || left_canibal > 3 || right_missionary > 3 || right_cannibal > 3)
		{
			mp[c] = false;
			return false;
		}
		//Define some break case
		if (left_canibal != 0 && left_missionary != 0 && left_canibal > left_missionary)
		{
			cout << "HERE\n";
			mp[c] = false;
			return false;
		}
		if (right_cannibal != 0 && right_missionary != 0 && right_cannibal > right_missionary)
		{
			cout << "HERE\n";
			mp[c] = false;
			return false;
		}
		if (right_cannibal == 3 && right_missionary == 3 /*&& (boat_bank == "right")*/)
		{
			fill_state_in_vector(left_missionary, left_canibal, right_missionary, right_cannibal, boat_bank);
			mp[c] = true;
			return true;
		}
		if (boat_bank == "left")
		{
			if (move_no != 1)
			{
				if (left_canibal > 0)
				{
					if (solve(left_missionary, left_canibal - 1, right_missionary, right_cannibal + 1, "right", 1))
					{
						fill_state_in_vector(left_missionary, left_canibal - 1, right_missionary, right_cannibal + 1, "right");
					}
				}
			}
			if (move_no != 2)
			{
				if (left_canibal > 1)
				{
					if (solve(left_missionary, left_canibal - 2, right_missionary, right_cannibal + 2, "right", 2))
					{
						fill_state_in_vector(left_missionary, left_canibal - 2, right_missionary, right_cannibal + 2, "right");
					}
				}
			}
			if (move_no != 3)
			{
				if (left_missionary > 0)
				{
					if (solve(left_missionary - 1, left_canibal, right_missionary + 1, right_cannibal, "right", 3))
					{
						fill_state_in_vector(left_missionary - 1, left_canibal, right_missionary + 1, right_cannibal, "right");
					}
				}
			}
			if (move_no != 4)
			{
				if (left_missionary > 1)
				{
					if (solve(left_missionary - 2, left_canibal, right_missionary + 2, right_cannibal, "right", 4))
					{
						fill_state_in_vector(left_missionary - 2, left_canibal, right_missionary + 2, right_cannibal, "right");
					}
				}
			}
			if (move_no != 5)
			{
				if (left_canibal > 0 && left_missionary > 0)
				{
					if (solve(left_missionary - 1, left_canibal - 1, right_missionary + 1, right_cannibal + 1, "right", 5))
					{
						fill_state_in_vector(left_missionary - 1, left_canibal - 1, right_missionary + 1, right_cannibal + 1, "right");
					}
				}
			}

		}
		else if (boat_bank == "right")
		{
			if (move_no != 1)
			{
				if (right_cannibal > 0)
				{
					if (solve(left_missionary, left_canibal + 1, right_missionary, right_cannibal - 1, "left", 1))
					{
						fill_state_in_vector(left_missionary, left_canibal + 1, right_missionary, right_cannibal - 1, "left");
					}
				}
			}
			if (move_no != 2)
			{
				if (right_cannibal > 1)
				{
					if (solve(left_missionary, left_canibal + 2, right_missionary, right_cannibal - 2, "left", 2))
					{
						fill_state_in_vector(left_missionary, left_canibal + 2, right_missionary, right_cannibal - 2, "left");
					}
				}
			}
			if (move_no != 3)
			{
				if (right_missionary > 0)
				{
					if (solve(left_missionary + 1 , left_canibal, right_missionary - 1, right_cannibal, "left", 3))
					{
						fill_state_in_vector(left_missionary + 1 , left_canibal, right_missionary - 1, right_cannibal, "left");
					}
				}
			}
			if (move_no != 4)
			{
				if (right_missionary > 1)
				{
					if (solve(left_missionary + 2, left_canibal, right_missionary - 2, right_cannibal, "left", 4))
					{
						fill_state_in_vector(left_missionary + 2, left_canibal, right_missionary - 2, right_cannibal, "left");
					}
				}
			}
			if (move_no != 5)
			{
				if (right_cannibal > 0 && right_missionary > 0)
				{
					if (solve(left_missionary + 1, left_canibal + 1, right_missionary - 1, right_cannibal - 1, "left", 5))
					{
						fill_state_in_vector(left_missionary + 1, left_canibal + 1, right_missionary - 1, right_cannibal - 1, "left");
					}
				}

			}
		}
		cout << endl << "returning from here !!\n";
		mp[c] = false;
		return false;
	}
}

int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	cout << "here";
	bool check = solve(3, 3, 0, 0, "left", -1);
	if (check)
	{
		cout << "The step wise solution is : \n";
		for (auto x : ans)
		{
			cout << x << endl;
		}
	}

	return 0;
}
