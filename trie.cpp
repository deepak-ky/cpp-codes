#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
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
class trie
{
public:
	node * root;
	int cnt = 0;

	trie()
	{
		root = new node('\0');
		cnt = 0;
	}

	void insert(char *w)
	{
		node * temp = root;
		for (int i = 0; w[i] != '\0'; i++) //iterate all the character in the word and check character by character if that word is present in the children map or not
		{
			char ch = w[i];
			//if it is present go to the next character and make temp point to the node of the next character
			if (temp -> children.count(ch) != 0)
			{
				temp = temp->children[ch];
			}
			//if the chracter is not present make a new node , insert in the children map of the parent node and make temp point to that new node
			else
			{
				node * n;
				n = new node(ch);
				temp->children[ch] = n;
				temp = n;
			}
		}
		// the last  character will be a terminal node
		temp->is_terminal = true;

	}

	bool find(char *w)
	{
		node * temp = root;
		for (int i = 0; w[i] != '\0'; i++)
		{
			char ch = w[i];
			if (temp->children.count(ch) == 0)
			{
				return false;
			}
			else
			{
				temp = temp->children[ch];
			}
		}
		if (temp->is_terminal == true)
		{
			return true;
		}
		else return false;
	}

};
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	trie t;
	char words[][10] = {"apple", "not", "noew", "news", "hello"};
	for (int i = 0; i < 5; i++)
	{
		t.insert(words[i]);
	}
	char w[10];
	cin >> w;

	if (t.find(w))
	{
		cout << "present";
	}
	else cout << "not present";


	return 0;
}
