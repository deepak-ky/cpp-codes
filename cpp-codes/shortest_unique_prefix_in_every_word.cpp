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

class node
{
public:
	int data;
	unordered_map<char, node*> children;
	int cnt;
	bool is_terminal;

	node(int d)
	{
		data = d;
		cnt = 1;
		is_terminal = false;
	}
};

class TRIE
{

public:
	node * root;
	TRIE()
	{
		root = new node('\0');
	}

	void add_word_in_trie(string w)
	{
		node * temp = root;
		for (int i = 0; i < w.length(); i++)
		{
			char ch = w[i];
			if (temp->children.find(ch) != temp->children.end())
			{
				temp = temp->children[ch];
				temp->cnt += 1;
			}
			else
			{
				node * n = new node(ch);
				temp->children[ch] = n;
				temp = temp->children[ch];
			}

		}
		temp->is_terminal = true;
	}


	string find_unique_prefix(string w)
	{
		node * temp = root;
		string ans = "";
		for (int i = 0; i < w.length(); i++)
		{
			char ch = w[i];
			temp = temp->children[ch];
			ans += ch;
			if (temp->cnt == 1) return ans;

		}

		return "-1";
	}
};

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		TRIE trie;
		vector<string> words = {"geeksgeeks", "geeksquiz",
		                        "geeksforgeeks"
		                       };
		for (auto x : words) trie.add_word_in_trie(x);

		for (auto x : words) cout << trie.find_unique_prefix(x) << endl;
	}
	return 0;
}
