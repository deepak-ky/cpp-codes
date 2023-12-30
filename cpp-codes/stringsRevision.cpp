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

//1. Reverse Words
string reverseWords(string s) {
   int n = s.length();
   int j = n-1;
   int i = n-1;

   string ans = "";

   while(j >= 0){
    while(j >= 0 && s[j] == ' '){
        j--;
    }
    if(j < 0) break;
        //cout << "j : " << j << endl;
    i = j;
    while(i>=0 && s[i] != ' '){
        i--;
    }
        //cout << i << endl;
    string w = s.substr(i+1,(j-(i+1)+1));
        //cout << w << endl;
    ans += w + " ";
    j = i;
}
ans.pop_back();
        //cout << "ans" << ans << endl;
return ans;
}

//2. Longest Palindromic Substring - Approach - 1
string longestPalindromApproach1(string s){
    int n = s.length();
    int ans = 0;
    string ansS = "";
    // Make longest odd length palindrome
    for(int i=0;i<n;i++){
        int j = i-1;
        int k = i+1;
        while(j >= 0 && k < n && s[j] == s[k]){
            j--;
            k++;
        }

        if((k-j-1) > ans){
            ans = k-j-1;
            ansS = s.substr(j+1,(k-j-1));
        }
    }

    // Make longest even length palindrome
    for(int i=0;i<n-1;i++){
        if(s[i] == s[i+1]){
            int j = i-1;
            int k = i+2;

            while(j >= 0 && k < n && s[j] == s[k]){
                j--;
                k++;
            }

            if((k-j-1) > ans){
                ans = k-j-1;
                ansS = s.substr(j+1,(k-j-1));
            }

        }
    }

    return ansS;
}


//3. Longest Palindromic Substring - Approach - 2
string longestPalindromApproach2(string s){
    int n = s.length();
    int ans = 1;
    string ansS = "";
    ansS += s[0];
    
    vector<vector<bool>> v(n,vector<bool>(n,false));

    for(int i=0;i<n;i++){
       v[i][i] = true;
    }

    for(int i=0;i<n-1;i++){
        if(s[i] == s[i+1]){
           v[i][i+1] = true;
           if(2 > ans){
            ans = 2;
            ansS = s.substr(i,2);
        }
        }

        
    }

    for(int gap = 2;gap<n;gap++){
        int i = 0;
        for(int j=gap;j<n;j++){
            if(s[i] == s[j] && v[i+1][j-1]){
                v[i][j] = true;
                if((j-i+1) > ans){
                    ans = j-i+1;
                    ansS = s.substr(i,(j-i+1));
                }
            }
            i++;
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout << v[i][j] << " ";
    //     }
    //                 cout << endl;
    // }

    return ansS;
}

//4. Roman Number to Integer and Vice Versa

//5. Implement ATOI

//6. Longest Common Prefix
string longestCommonPrefix(vector<string> &strs){
    // Instead for checking in all the strings 
    // sort the array and check for what's common in first and last string
    int n = strs.size();
    sort(strs.begin(),strs.end());
    string s1 = strs[0];
    string s2 = strs[n-1];

    int i = 0;
    
    while(1){
        if(s1[i] == s2[i]){
            i++;
        }else{
            break;
        }

        if(i > s1.length()) {
            break;
        }
        if(i > s2.length()) {
            break;
        }
    }

    return s1.substr(0,i);
}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
        // string s = "  hello world  ";
        // string s1 = reverseWords(s);
        // cout << s1 << endl;


        //cout <<longestPalindromApproach1("cbbd");
      /*  cout <<longestPalindromApproach2("qwabad");*/

        vector<string> s = {"flower","flow","flight","fs"};
        cout << longestCommonPrefix(s);

    }
    return 0;
}
