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
#define s                            second

//Prints
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "}"; }

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

class node{
public:
	char data;
	bool is_terminal;
	node* mp[26]; // can be done with map also
	node(char d){
		data = d;
		is_terminal = false;
		for(int i=0;i<26;i++){
			mp[i] = NULL; // very important step
		}
	}
};

class Trie{
	node *root;
public:
	Trie(){
		root = new node('\0');
	}

	int insert(string w){
		node *temp = root;
		int len = w.length();
		for(int i=0;i<len;i++){
			int ch = (w[i]-'a');
			if(temp->mp[ch] != NULL){
			 	temp = temp->mp[ch];
			}else{
			 	node * n = new node(w[i]);
			 	temp->mp[ch] = n;
				temp = temp->mp[ch];
			}
		}

		if(temp->is_terminal){
			return 0;
		}
		temp->is_terminal = true;
		return 1;
	}
};

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		string s = "abab";
		int ans = 1;
		Trie t;
		
		for(int i=0;i<s.length();i++){
			string str = "";
			for(int j=i;j<s.length();j++){
				str += s[j];
				cout << str << endl;
				int w = t.insert(str);
				wer(w);
				ans += w;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
