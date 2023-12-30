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

int msbPos(int n)
{
    int msb_p = -1;
    while (n)
    {
        n = n>>1;
        msb_p++;
    }
    return msb_p;
}
 
// Function to find Bit-wise & of all numbers from x
// to y.
int andOperator(int  x, int y)
{
    int res = 0; // Initialize result
 
    while (x && y)
    {
        // Find positions of MSB in x and y
        int msb_p1 = msbPos(x);
        int msb_p2 = msbPos(y);
 
        // If positions are not same, return
        if (msb_p1 != msb_p2)
            break;
 
        // Add 2^msb_p1 to result
        int msb_val =  (1LL << msb_p1);
        res = res + msb_val;
 
        // subtract 2^msb_p1 from x and y.
        x = x - msb_val;
        y = y - msb_val;
    }
 
    return res;
}

int32_t main()
{
	init();
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n,x;
		cin >> n >> x;
		if(x > n) cout << -1 << endl;
		else if(n == x) cout << n << endl;
		else {

			int l = n;
			int h = 5e18;
			//wer(h);
			int ans = -1;
			int val;
			while(l <= h){
				int m = l + (h-l)/2;
				//wer(m);
				val = andOperator(n,m);
				//wer(val);
				if(val == x){
					ans = m;
					h = m-1;
				}else if(val > x){
					l = m+1;
				}else{
					h = m-1;
				}
			}
			cout << ans << endl;
			}
	}
	return 0;
}
