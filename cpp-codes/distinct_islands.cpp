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

void dfs(int **arr, vector<vector<bool>> &visited,int n,int m,int i,int j,string &shape){
	if(i < 0 || j<0 || i>=n || j>=m){
		return;
	}

	if(arr[i][j] == 0){
		return;
	}

	visited[i][j] = true;
	if(i+1 < n && arr[i+1][j] ==  1 && !visited[i+1][j]) {
		shape += 'D';
		dfs(arr,visited,n,m,i+1,j,shape);
	}

	if(i-1 >= 0 && arr[i-1][j] ==  1 && !visited[i-1][j]) {
		shape += 'U';
		dfs(arr,visited,n,m,i-1,j,shape);
	}

	if(j+1 < m && arr[i][j+1] ==  1 && !visited[i][j+1]) {
		shape += 'R';
		dfs(arr,visited,n,m,i,j+1,shape);
	}

	if(j-1 >= 0 && arr[i][j-1] ==  1 && !visited[i][j-1]) {
		shape += 'L';
		dfs(arr,visited,n,m,i,j-1,shape);
	}

	shape += 'X';
	return;
}

int distinctIslands(int **arr,int n,int m){
	map<string,bool> shapeTracker;
	vector<vector<bool>> visited(n,vector<bool>(m,false));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j] == 1 && !visited[i][j]){
				string shape = "";
				dfs(arr,visited,n,m,i,j,shape);
				cout << "shape: " << shape << endl;;
				shapeTracker[shape] = true;
			}
		}
	}

	return shapeTracker.size();
}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		int n = 4;
		int m = 5;
		   int **arr = new int*[n];
        for (int i = 0; i < n; i++) {
            arr[i] = new int[m];
        }

        // Initialize the array
         int values[4][5] = {{1, 1, 0, 0, 0},
                            {1, 1, 0, 0, 0},
                            {0, 0, 0, 1, 1},
                            {0, 0, 0, 1, 1}};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = values[i][j];
            }
        }

		cout << distinctIslands(arr,n,m);

	}
	return 0;
}
