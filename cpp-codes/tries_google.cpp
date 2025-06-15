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
	char ch;
	int is_terminal;
	int prefix_count;
	unordered_map<char,node*> mp;

	node(char ch){
		this->ch = ch;
		is_terminal = 0;
		prefix_count = 0;
	}
};

class Trie{
	node *root;
public:
	Trie(){
		root = new node('\0');
	}
	void insert(string word){
		node *temp = root;
		for(int i=0;i<word.length();i++){
			char ch = word[i];
			if(temp->mp.find(ch) != temp->mp.end()){
				temp = temp->mp[ch];
			}else{
				node *n = new node(ch);
				temp->mp[ch] = n;
				temp = temp->mp[ch];
			}
			temp->prefix_count++;
		}

		temp->is_terminal++;
	}

	bool search(string word){
		node *temp = root;
		for(int i=0;i<word.length();i++){
			char ch = word[i];
			if(temp->mp.find(ch) == temp->mp.end()){
				return false;
			}else{
				temp = temp->mp[ch];
			}
		}

		return temp->is_terminal > 0;
	}

	int countWordsEqualTo(string word){
		node *temp = root;
		for(int i=0;i<word.length();i++){
			char ch = word[i];
			if(temp->mp.find(ch) == temp->mp.end()){
				return 0;
			}else{
				temp = temp->mp[ch];
			}
		}

		return temp->is_terminal;
	}


	int countWordsStartingWith(string word){
		node * temp = root;
		for(int i=0;i<word.length();i++){
			char ch = word[i];
			if(temp->mp.find(ch) == temp->mp.end()){
				return 0;
			}else{
				temp = temp->mp[ch];
			}
		}

		return temp->prefix_count;
	}


	void erase(string word){
		node * temp = root;
		for(int i=0;i<word.length();i++){
			char ch = word[i];
			if(temp->mp.find(ch) == temp->mp.end()){
				return;
			}else{
				temp = temp->mp[ch];
			}
			temp->prefix_count--;
		}
		temp->is_terminal--;
	}


	string shortestUniqueWord(string word){
		// Assuming always exist
		node * temp = root;
		string unique = "";
		for(int i=0;i<word.length();i++){
			char ch = word[i];
			unique += ch;
			if(temp->mp.find(ch) == temp->mp.end()){
				return "";
			}else{
				temp = temp->mp[ch];
			}
			if(temp->prefix_count == 1){
				return unique;
			}
		}

		return "-1";
	}
};

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		/*Trie t;
		t.insert("dog");
		t.insert("dog");
		t.insert("dou");
		t.insert("dig");
		t.insert("diu");


		if(t.search("do")){
			cout << "yes";
		}else{
			cout << "no";
		}

		cout << endl;
		cout << t.countWordsEqualTo("dig");

		cout << endl;
		cout << t.countWordsStartingWith("diu");


		// t.erase("diu");

		// cout << endl << "after erasing : " << endl;
		// cout << t.countWordsStartingWith("d") << endl;
		// cout << t.countWordsStartingWith("di") << endl;
		// cout << t.countWordsStartingWith("diu") << endl;
		// cout << t.countWordsStartingWith("diug") << endl;


		t.erase("dog");

		cout << endl << "after erasing : " << endl;
		cout << t.countWordsStartingWith("d") << endl;
		cout << t.countWordsStartingWith("do") << endl;
		cout << t.countWordsStartingWith("dog") << endl;
		cout << t.countWordsStartingWith("dogu") << endl;


		cout << t.countWordsEqualTo("dog");*/

		/*Trie t;

		t.insert("coding");
		t.insert("ninja");
		cout << t.countWordsEqualTo("coding") << endl;
		cout << t.countWordsStartingWith("nin") << endl;
		t.erase("coding");
		cout << t.countWordsEqualTo("coding") << endl;
		cout << t.countWordsStartingWith("c") << endl;*/


		vector<string> s = {"many", "mango", "mad"};
		Trie t;
		for(auto &x : s){
			t.insert(x);
		}

		vector<string> ans;
		for(auto &x : s){
			ans.push_back(t.shortestUniqueWord(x));
		}

		for(auto &x : ans) cout << x << endl;

	}
	return 0;
}
