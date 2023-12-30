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
	char data;
	unordered_map<char, node*> children;
	bool is_terminal;

	node(char d)
	{
		data = d;
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

	bool search_word_in_trie(string w)
	{
		node * temp = root;
		for (int i = 0; i < w.length(); i++)
		{
			char ch = w[i];
			if (temp->children.find(ch) == temp->children.end())
			{
				return false;
			}
			else
			{
				temp = temp->children[ch];
			}
		}
		if (temp->is_terminal == false) return false;
		else return true;
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
		vector<string> words = {"not" , "news" , "hello" , "apple" , "no"};
		for (auto x : words) trie.add_word_in_trie(x);

		if (trie.search_word_in_trie("newsd"))
		{
			yes;
		}
		else
		{
			no;
		}

	}
	return 0;
}
