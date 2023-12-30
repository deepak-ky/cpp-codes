#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
bool index_matches(string s, string pat, int idx)
{
    int len1 = s.length();
    int len2 = pat.length();
    string str = s.substr(idx, len2); //reducing our work to o(1)
    if (str == pat)
    {
        return true;
    }
    else return false;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    string s;
    getline(cin, s);
    string pat;
    cin >> pat;
    int len1 = s.length();
    int len2 = pat.length();
    vector<int> v;
    for (int i = 0; i <= (len1 - len2); i++)
    {
        if (index_matches(s, pat, i))
        {
            v.push_back(i);
        }
    }
    for (auto x : v)
    {
        cout << x << endl;
    }

    return 0;
}
