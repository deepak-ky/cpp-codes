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
	int cnt;
	node(char d)
	{
		data = d;
		is_terminal = false;
		cnt = 0;
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

	void insert(char *w)
	{

		node * temp = root;
		for (int i = 0; w[i] != '\0'; i++) //iterate all the character in the word and check character by character if that word is present in the children map or not
		{
			char ch = w[i];
			//wer(ch);
			//if it is present go to the next character and make temp point to the node of the next character
			if (temp -> children.count(ch) != 0)
			{


				temp = temp->children[ch];

				temp->cnt++;



			}
			//if the chracter is not present make a new node , insert in the children map of the parent node and make temp point to that new node
			else
			{
				//cout << "in else";
				node * n;
				n = new node(ch);
				temp->children[ch] = n;
				temp = n;
				//cout << "\ntemp has data of : " << temp->data << endl;

				(temp->cnt) = 1;



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

	void print_unique_prefix(char *w)
	{
		//cout << w << endl;
		node *temp = root;
		int till_here = -2;
		char ch1 = w[0];
		temp = temp->children[ch1];
		int i = 0;
		{
			for (i = 1; w[i] != '\0'; i++)
			{
				char ch = w[i];

				//cout << endl << w[i - 1] << endl;

				//cout << "temp->data here is : " << temp->data << endl;
				//cout << "temp->cnt is : " << temp->cnt;
				if (temp->cnt == 1 )
				{

					till_here = i - 1;
					break;
				}
				else
				{
					temp = temp->children[ch];
				}

			}
			/*

						cout << "checking for the last character which is : " << w[i - 1];
						cout << "its count is : " << temp -> cnt;*/

			if (temp->cnt == 1) till_here = i - 1;

			if (till_here == -2)
			{
				cout << -1;
			}
			else
			{
				//wer(till_here);
				for (int i = 0; i <= till_here; i++)
				{
					cout << w[i];
				}
			}
			cout << endl;
		}
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
	char words[][10] = {"zebra", "dog", "dusk", "dove", "zebras"};
	for (int i = 0; i < 5; i++)
	{
		t.insert(words[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		t.print_unique_prefix(words[i]);
	}



	return 0;
}
