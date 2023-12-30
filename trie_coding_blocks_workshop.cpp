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

class node
{
public:
	char data;
	//store the address of children of current node
	unordered_map<char, node*> mp;
	bool is_terminal;
	node(char d)
	{
		data = d;
		is_terminal = false;
	}
};
class trie
{
public:
	node * root;
	trie()
	{
		root = new node('\0');
	}
	//1.Add word in a string
	void add_word_to_trie(string w)
	{
		//keep a temporary pointer in the temp node
		node * temp = root;
		for (int i = 0; i < w.length(); i++)
		{
			char ch = w[i];
			//the character is already present in the hashmap of temp node;
			if (temp->mp.count(ch) != 0)
			{
				temp = temp->mp[ch];
			}
			else
			{
				node * n = new node(ch);
				temp->mp[ch] = n;
				temp = temp->mp[ch];
			}
		}
		temp->is_terminal = true;
	}
	//2.Search for a given string
	bool find_word(string w)
	{
		//keep a temporary pointer in the temp node
		node * temp = root;
		for (int i = 0; i < w.length(); i++)
		{
			char ch = w[i];

			if (temp->mp.find(ch) == temp->mp.end())
			{
				return false;
			}
			else temp = temp->mp[ch];
		}
		if (temp->is_terminal)
		{
			return true;
		}
	}

};

int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	trie t;
	string keys[8] = {"the", "a", "there",
	                  "answer", "any", "by",
	                  "bye", "their"
	                 };
	for (auto x : keys)
	{
		t.add_word_to_trie(x);
	}
	if (t.find_word("the"))
	{
		cout << "Word present";
	}
	else cout << "word not present";
	cout << endl;
	if (t.find_word("these"))
	{
		cout << "Word present";
	}
	else cout << "word not present";
	return 0;
}
