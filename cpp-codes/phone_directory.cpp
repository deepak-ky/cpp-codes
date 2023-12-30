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
	map<char, node*> children;
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
	string working_with;
	vector<string> ans;

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

	void add_in_ans(vector<char> v)
	{
		string o = "";
		for (auto x : v) o += x;
		o = working_with + o;
		ans.push_back(o);
	}

	void traverse(node * temp, vector<char> &v)
	{
		if (temp->is_terminal == true) add_in_ans(v);
		for (auto x : temp->children)
		{
			v.push_back(x.first);
			traverse(x.second, v);
			v.pop_back();
		}

		return;
	}



	vector<string> find_all_words_with_given_prefix(string w)
	{

		working_with = w;
		ans.clear();
		node * temp = root;
		for (int i = 0; i < w.length(); i++)
		{
			char ch = w[i];
			if (temp->children.find(ch) == temp->children.end())
			{
				ans.push_back("0");
				return ans;
			}
			else temp = temp->children[ch];
		}


		vector<char> v;
		if (temp->is_terminal == true)
		{
			ans.push_back(w);
		}



		//from this point I have to print all the answers;

		for (auto x : temp->children)
		{
			v.push_back(x.first);
			traverse(x.second, v);
			v.pop_back();
		}


		return ans;
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
		vector<string> words = {"cod", "coding", "codding" , "code" ,
		                        "coly"
		                       };
		for (auto x : words) trie.add_word_in_trie(x);

		string given_prefix = "coding";

		for (int i = 0; i < given_prefix.length(); i++)
		{
			string prefix = given_prefix.substr(0, i + 1);

			vector<string> w = trie.find_all_words_with_given_prefix(prefix);

			sort(w.begin(), w.end());

			for (auto x : w) cout << x << " ";
			cout << endl;
		}

	}
	return 0;
}
