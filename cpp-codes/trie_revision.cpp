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
	unordered_map<char,node*> mp;
	node(char d){
		data = d;
		is_terminal = false;
	}
};

class trie{
public:
	node *root;
	int cnt;

	trie(){
		root = new node('\0');
		cnt = 0;
	}

	void insert(char *w){
		node *temp = root;
		for(int i=0;w[i] != '\0'; i++){
			char ch = w[i];		
			if(temp->mp.find(ch) != temp->mp.end()){
				temp = temp->mp[ch];
			}else{
				node *n = new node(ch);
				temp->mp[ch] = n;
				temp = temp->mp[ch];
			}
		}
		temp->is_terminal = true;
	}

	bool find(char *w){
		node *temp = root;
		for(int i=0;w[i] != '\0'; i++){
			char ch = w[i];
			if(temp->mp.find(ch) != temp->mp.end()){
				temp = temp->mp[ch];
			}else{
				return false;
			}
		}
		return temp->is_terminal == true;
	}
};



int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		trie t;
		char w[][10] = {"not","news","hello","apple"};
		for(int i=0;i<4;i++){
			t.insert(w[i]);
		}

		char word[] = {'n','e','w','s','s','\0'};

		if(t.find(word)){
			yes;
		}else{
			no;
		}	
	}
	return 0;
}


