#include<bits/stdc++.h>
// #define forn(i,n) for(int i = 0; i<int(n); i++)
using namespace std;
/*using ll = long long;
using ld = long double;
using pr = pair<int, int>;
using prll = pair<long, long>;
using V = vector<int>;
using Vll = vector<long long>;
template<typename T,typename TT> pr operator +(pair<T, TT> a, pair<T, TT> b){return {a.first+b.first, a.second+b.second};}
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){for(auto itr:t) s<<itr<<" ";return s; }
*/
struct coor
{
	int l, r, u, d;
	void init()
	{
		l = -1;
		r = -1;
		u = -1;
		d = -1;
	}
};

int r, c;

int right(int i, int j, vector<vector<int>> a, vector<vector<coor>> &b)
{
	//cout<<"right: "<<make_pair(i,j)<<"\n";
	int x, y;
	x = i;
	y = j;
	int ans = 0;
	while (j < c && a[i][j] == 1)
	{
		ans++;
		j++;
	}

	int temp = 1;
	while (temp <= ans)
	{
		j--;
		b[i][j].r = temp;
		b[i][j].l = b[x][y].l + ans - temp;
		temp++;
	}
	return ans;
}

int left(int i, int j, vector<vector<int>> a, vector<vector<coor>> &b)
{
	//cout<<"left: "<<make_pair(i,j)<<"\n";
	int ans = 0;
	while (j >= 0 && a[i][j] == 1)
	{
		ans++;
		j--;
	}

	int temp = 1;
	while (temp <= ans)
	{
		j++;
		b[i][j].l = temp;
		temp++;
	}
	return ans;
}

int up(int i, int j, vector<vector<int>> a, vector<vector<coor>> &b)
{
	//cout<<"up: "<<make_pair(i,j)<<"\n";
	int ans = 0;
	while (i >= 0 && a[i][j] == 1)
	{
		ans++;
		i--;
	}

	int temp = 1;
	while (temp <= ans)
	{
		i++;
		b[i][j].u = temp;
		temp++;
	}
	return ans;
}

int down(int i, int j, vector<vector<int>> a, vector<vector<coor>> &b)
{
	//cout<<"down: "<<make_pair(i,j)<<"\n";
	int x = i;
	int y = j;
	int ans = 0;
	while (i < r && a[i][j] == 1)
	{
		ans++;
		i++;
	}

	int temp = 1;
	while (temp <= ans)
	{
		i--;
		b[i][j].d = temp;
		b[i][j].u = b[x][y].u + ans - temp;
		temp++;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int T;
	cin >> T;
	int cnt = 0;
	while (T--)
	{
		cin >> r >> c;
		vector<vector<int>> a(r, vector<int>(c));
		vector<vector<coor>> b(r, vector<coor>(c));

		forn(i, r)
		{
			forn(j, c)
			{
				cin >> a[i][j];
				b[i][j].init();
			}
		}

		int ans = 0;
		forn(i, r)
		{
			forn(j, c)
			{
				if (a[i][j] == 1)
				{
					if (b[i][j].l == -1)
						left(i, j, a, b);
					if (b[i][j].r == -1)
						right(i, j, a, b);
					if (b[i][j].u == -1)
						up(i, j, a, b);
					if (b[i][j].d == -1)
						down(i, j, a, b);

					int l = b[i][j].l;
					int r = b[i][j].r;
					int u = b[i][j].u;
					int d = b[i][j].d;

					ans += max(0, min(l, u / 2) - 1) + max(0, min(u, l / 2) - 1) + max(0, min(d, l / 2) - 1) + max(0, min(l, d / 2) - 1);
					ans += max(0, min(r, u / 2) - 1) + max(0, min(r, d / 2) - 1) + max(0, min(u, r / 2) - 1) + max(0, min(d, r / 2) - 1);
					//cout<<make_pair(i,j)<<l<<" "<<r<<" "<<u<<" "<<d<<"\n";
				}
			}
		}
		cout << "Case #" << cnt + 1 << ": " << ans << "\n";
		cnt++;
	}
	return 0;
}