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



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int **mat = new int*[n];
		//n->rows
		//m->coloums
		for (int i = 0; i < n; i++)
		{
			mat[i] = new int[m];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> mat[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}


		int rows = n;
		int coloumns = m;

		bool visited[rows][coloumns];
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < coloumns; j++)
			{
				visited[i][j] = 0;
			}
		}

		bool came_from_diagnol = true;
		int i = 0; //current row
		int j = 0; //current coloumn

		while (1)
		{
			//cout << "i : " << i << endl;
			//cout << "j : " << j << endl;
			cout << mat[i][j] << " ";
			//cout << endl;
			visited[i][j] = 1;
			if (i == rows - 1 && j == coloumns - 1)
			{
				break;
				//break;
			}

			if (came_from_diagnol == true)
			{
				//Have three options
				//1. Am I at coloumn end
				if (j == 0)
				{
					if (i + 1 < rows) //moving down
					{
						//cout << "11" << endl;
						i = i + 1;
						j = j;
						came_from_diagnol = false;
					}
					else  //moving right
					{
						if (j + 1 < coloumns)
						{
							//cout << "12" << endl;

							i = i;
							j = j + 1;
							came_from_diagnol = false;
						}
					}
				}
				else if ( j == coloumns - 1)
				{
					//only go down
					//cout << "13" << endl;

					i = i + 1;
					j = j;
					came_from_diagnol = false;
				}
				else if (j > 0 && j < (coloumns - 1) && i == 0)
				{
					//always go right at row ends
					//cout << "14" << endl;

					i = i;
					j = j + 1;
					came_from_diagnol = false;
				}
				else if (j > 0 && j < (coloumns - 1) && i == (rows - 1))
				{
					//always go right at row ends
					///cout << "15" << endl;

					i = i;
					j = j + 1;
					came_from_diagnol = false;
				}
				else
				{
					//move in diagnol
					//if i am at i , j
					//i-1,j+1  //i+1,j-1
					bool can_move = false;
					if ( (i - 1) >= 0 && (j + 1) <= (coloumns - 1))
					{
						if (visited[i - 1][j + 1] == 0)
						{
							//cout << "16" << endl;

							can_move = true;
							i = i - 1;
							j = j + 1;
						}
					}

					if (can_move == false)
					{
						if ( (i + 1) <= (rows - 1) && (j - 1) >= 0)
						{
							if (visited[i + 1][j - 1] == 0)


							{
								//cout << "18" << endl;
								can_move = true;
								i = i + 1;;
								j = j - 1;
							}
						}
					}

					came_from_diagnol = true;
				}



			}

			else if (came_from_diagnol == false)
			{
				//not come from diagnol , then have to move in a diagnol

				bool can_move = false;
				if ( (i - 1) >= 0 && (j + 1) <= (coloumns - 1))
				{
					if (visited[i - 1][j + 1] == 0)
					{
						//cout << "19" << endl;

						can_move = true;
						i = i - 1;
						j = j + 1;
						came_from_diagnol = true;

					}
				}

				if (can_move == false)
				{
					if ( (i + 1) <= (rows - 1) && (j - 1) >= 0)
					{
						if (visited[i + 1][j - 1] == 0)
						{
							//cout << "20" << endl;
							can_move = true;
							i = i + 1;;
							j = j - 1;
							came_from_diagnol = true;

						}
					}
				}


				if (can_move == false)
				{
					if (i + 1 < rows)
					{
						i = i + 1;
						j = j;
						came_from_diagnol = false;
					}
					else
					{
						i = i;
						j = j + 1;
						came_from_diagnol = false;
					}
				}




			}
		}


	}
	return 0;
}
