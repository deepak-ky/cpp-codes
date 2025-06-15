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

void rotate(vector<vector<int>>& matrix) {
    // Ideally when we are rotating an matrix, we are switching its rows and columns,
    // What if we switch them earlier only
    // basically transpose the matrix
    int n = matrix.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            // if you are in third column, at 2nd position (2nd row) (top se ek neeche the)
            // you will move to third row, at 2nd position (2nd column) (left se ek aage ho jaaoge)
            swap(matrix[i][j],matrix[j][i]);
        }
    }
        
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            swap(matrix[i][j], matrix[i][n-1-j]);
        }
    }
}

void printMatrix(vector<vector<int>> &matrix){
	int n = matrix.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		vector<vector<int>> matrix = {
			{1,2,3},{4,5,6},{7,8,9}
		};

		printMatrix(matrix);
		rotate(matrix);
		printMatrix(matrix);

		rotate(matrix);
		printMatrix(matrix);

		rotate(matrix);
		printMatrix(matrix);

		rotate(matrix);
		printMatrix(matrix);
	}
	return 0;
}
