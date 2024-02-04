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

class DSU{
    vector<int> parent;
    public:
    DSU(int v){
        parent.resize(v+2);
        for(int i=1;i<=v+1;i++){
            parent[i] = i;
        }
    }

    int findSuperParent(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = findSuperParent(parent[x]);
    }

    void unite(int a,int b){
        int spA = findSuperParent(a);
        int spB = findSuperParent(b);
        if(spA != spB){
            parent[spA] = max(spA,spB);
            parent[spB] = max(spA,spB);
        }
    }
};

int32_t main()
{
    init();
    int t = 1;
    //cin >> t;
    while (t--)
    {
       int n;
       cin >> n;
       
       DSU dsu(n);
        vector<int> color(n+1,0);

       int q;
       cin >> q;

       vector<vector<int>> queries;
       for(int i=0;i<q;i++){
            int l,r,c;
            cin >> l >> r >> c;
            queries.push_back({l,r,c});
       }

       for(int i=q-1;i>=0;i--){
            int l = queries[i][0];
            int r = queries[i][1];
            int c = queries[i][2];
            int indexToColor = dsu.findSuperParent(l);
            while(indexToColor <= r) {
                color[indexToColor] = c;
                dsu.unite(indexToColor,indexToColor+1);
                indexToColor = dsu.findSuperParent(indexToColor);
            }
       }

       for(int i=1;i<=n;i++){
        cout << color[i] << endl;
       }
    }
    return 0;
}
