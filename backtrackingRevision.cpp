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



void findPermutations(string s, int l, int r)
{
	if (l == r)
	{
		cout << s << " ";
		cout << endl;
		return;
	}

	for (int i = l; i <= r; i++)
	{
		swap(s[l], s[i]);
		findPermutations(s, l + 1, r);
		swap(s[l], s[i]); // This is only required if the string is passed by reference, else it is not required
						  // https://leetcode.com/submissions/detail/962547880/
						  // https://leetcode.com/submissions/detail/962547946/
						  // Without swapping againg 👇
						  // https://leetcode.com/submissions/detail/962546950/
	}
	return;
}

bool canPlaceQueen(vector<string> v, int i, int j, int n)
{
	// no queen in the same row
	//  no need to check for cells after j, because the way I have implemented this, they cannot have been filled
	//  similiarly for all the checks below also
	for (int d = 0; d < j; d++)
	{
		if (v[i][d] == 'Q')
		{
			return false;
		}
	}

	// no queen in the same coloumn
	for (int d = 0; d < i; d++)
	{
		if (v[d][j] == 'Q')
		{
			return false;
		}
	}

	// no queen in left to right diagonal
	int a = i;
	int b = j;
	while (a >= 0 && b >= 0)
	{
		if (v[a][b] == 'Q')
		{
			return false;
		}
		else
		{
			a--;
			b--;
		}
	}

	// no queen in right to left diagonal
	a = i;
	b = j;
	while (a >= 0 && b < n)
	{
		if (v[a][b] == 'Q')
		{
			return false;
		}
		else
		{
			a--;
			b++;
		}
	}

	return true;
}

void placeNQueens(int n, int i, int j, vector<vector<string>> &ans, vector<string> &v)
{
	if (i == n)
	{
		ans.push_back(v);
		return;
	}

	if (j == n)
	{
		return;
	}

	for (int k = 0; k < n; k++)
	{
		if (canPlaceQueen(v, i, k, n))
		{
			v[i][k] = 'Q';
			placeNQueens(n, i + 1, 0, ans, v);
			v[i][k] = '.';
		}
	}

	return;
}

vector<vector<string>> solveNQueens(int n)
{
	// This approch can be optimized using hashing
	// Whether this row has been filled or not
	// Whether this coloumn has been filled or not
	// Diagnoal can be done using some of i + j , as sum of i+j is always constant in left diagonal
	// right diagonal : (n-1) + (i-j);
	// https://takeuforward.org/data-structure/n-queen-problem-return-all-distinct-solutions-to-the-n-queens-puzzle/

	vector<vector<string>> ans;
	string s = "";
	for (int i = 0; i < n; i++)
		s += ".";
	vector<string> v(n, s);
	placeNQueens(n, 0, 0, ans, v);
	return ans;
}

bool canPlaceKValue(vector<vector<char>> &board,int i,int j,int n,int k){
	for(int col=0;col<n;col++){
		if(board[i][col] == char(k+48)){
			return false;
		}
	}

	for(int row=0;row<n;row++){
		if(board[row][j] == char(k+48)){
			return false;
		}
	}

	int start_x = (i/3)*3;
	int start_y = (j/3)*3;

	for(int x=start_x; x < (start_x+3);x++){
		for(int y=start_y; y < (start_y+3);y++){
			if(board[x][y] == char(k+48)){
				return false;
			}
		}
	}

	return true;
}

bool sudokuSolver(vector<vector<char>> &board,int i,int j,int n){
	if(i == n){
		return true;
	}

	if(j == n){
		return sudokuSolver(board,i+1,0,n);
	}

	if(board[i][j] != '.'){
		return sudokuSolver(board,i,j+1,n);
	}

	for(int k=1;k<=9;k++){
		if(canPlaceKValue(board,i,j,n,k)){
			board[i][j] = char(k+48);
			bool canSolve = sudokuSolver(board,i,j,n);
			if(canSolve){
				return true;
			}else{
				board[i][j] = '.';
			}
			
		}
	}

	return false;
}

void solveSudoku(vector<vector<char>> &board){
	bool x = sudokuSolver(board,0,0,9);
	return;
}

void breakString(int idx,string &s,map<string,bool> &mp,vector<string> &ans,string &current_string){
	if(idx == s.length()){
		current_string.pop_back()
		ans.push_back(current_string);
		return;
	}

	for(int i=idx;i<s.length();i++){
		string word = s.substr(idx,(i-idx)+1);
		if(mp[word]){
			string w = current_string;
			current_string = current_string + word + " ";
			breakString(i+1,s,mp,ans,current_string);
			current_string = w;
		}
	}

	return;
}

vector<string> wordBreak(int n,vector<string> &dict,string s){
	map<string,bool> mp;
	for(auto &x : dict) mp[x] = true;
	vector<string> ans;
	string current_string = "";
	breakString(0,s,mp,ans,current_string);
	return ans;
}



int32_t main()
{
	init();
	int t = 1;
	// cin >> t;
	while (t--)
	{
		// string s = "ABC";
		// findPermutations(s,0,2);

		// vector<vector<string>> v = solveNQueens(4);
		// cout << v.size() << endl;
		// for (auto &x : v)
		// {
		// 	for (auto &y : x)
		// 	{
		// 		cout << y << endl;
		// 	}
		// 	cout << endl;
		// }

		// vector<vector<char>> board = {
		// 	{'5','3','.','.','7','.','.','.','.'},
		// 	{'6','.','.','1','9','5','.','.','.'},
		// 	{'.','9','8','.','.','.','.','6','.'},
		// 	{'8','.','.','.','6','.','.','.','3'},
		// 	{'4','.','.','8','.','3','.','.','1'},
		// 	{'7','.','.','.','2','.','.','.','6'},
		// 	{'.','6','.','.','.','.','2','8','.'},
		// 	{'.','.','.','4','1','9','.','.','5'},
		// 	{'.','.','.','.','8','.','.','7','9'}};

		// solveSudoku(board);

		// for(auto &x : board){
		// 	for(auto &y : x){
		// 		cout << y << " ";
		// 	}
		// 	cout << endl;
		// }

		vector<string> dict = { "i", "like", "sam", "sung", "samsung", "mobile", "ice", 
  "and","cream", "icecream", "man", "go", "mango"};

		vector<string> v = wordBreak(13,dict,"ilikeicecreamandmango");
		//cout << v.size() << endl;
		for(auto &x : v) {
			cout << x << endl;
		}

	}
	return 0;
}
