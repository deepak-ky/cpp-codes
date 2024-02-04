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
	int is_terminal;
	int times_passed;
	unordered_map<char,node*> mp;

	node(char d){
		data = d;
		is_terminal = 0;
		times_passed = 0;
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
		int len = word.length();
		for(int i=0;i<len;i++){			
			char ch = word[i];
			if(temp->mp.find(ch) != temp->mp.end()){
				temp = temp->mp[ch];
			}else{
				node *n = new node(ch);
				temp->mp[ch] = n;
				temp = temp->mp[ch];
			}
			//pointing to current node having data ch
			temp->times_passed++;
		}
		temp->is_terminal++;
	}

	int countWordsEqualTo(string word){
		node *temp = root;
		int len = word.length();
		for(int i=0;i<len;i++){
			char ch = word[i];
			if(temp->mp.find(ch) != temp->mp.end()){
				temp = temp->mp[ch];
			}else{
				return false;
			}
		}
		return temp->is_terminal;
	}

	int countWordsStartingWith(string prefix){
        node *temp = root;
		int len = prefix.length();
		for(int i=0;i<len;i++){
			char ch = prefix[i];
			if(temp->mp.find(ch) != temp->mp.end()){
				temp = temp->mp[ch];
			}else{
				return 0;
			}
		}

		return temp->times_passed;
    }

    void erase(string word){
		node *temp = root;
		int len = word.length();
		for(int i=0;i<len;i++){
			char ch = word[i];
			temp = temp->mp[ch];
			temp->times_passed--;
		}
		temp->is_terminal--;
	}

	string findShortestUniquePrefix(string word){
		node *temp = root;
		int len = word.length();
		string prefix = "";

		for(int i=0;i<len;i++){
			char ch = word[i];
			temp = temp->mp[ch];
			prefix += ch;
			if(temp->times_passed == 1){
				break;
			}
		}

		if(temp->times_passed > 1) {
			return "-1";
		}
		return prefix;
	}
};



int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		Trie t;
		/*t.insert("coding");
		//cout << t.countWordsEqualTo("co") << endl;
		cout << t.countWordsEqualTo("coding") << endl;
		t.insert("coding");
		cout << t.countWordsEqualTo("coding") << endl;
		t.insert("cod");
		cout << t.countWordsEqualTo("cod") << endl;
		t.insert("co");
		cout << t.countWordsEqualTo("co") << endl;
		cout << t.countWordsStartingWith("co") << endl;
		t.erase("co");
		cout << t.countWordsStartingWith("co") << endl;
		cout << t.countWordsEqualTo("co") << endl;*/

		/*string words[5] = {"zebra", "dog", "dove", "dusk", "zebras"};
		for(int i=0;i<5;i++){
			t.insert(words[i]);
		}
		for(int i=0;i<5;i++){
			cout << t.findShortestUniquePrefix(words[i]) << endl;
		}*/

	


	}
	return 0;
}
