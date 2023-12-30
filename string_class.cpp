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



int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

////////////////0->       1->       2->
	//012345678901234567890123456
	string s = "I want to have apple Juice!";
	int idx = s.find("have");
	cout << idx << endl;
	cout << s << endl;
	string erasing_word = "have";
	int len = erasing_word.length();
	s.erase(idx, len + 1);
	cout << s << endl;



	cout << endl;
	char s1[100] = "This is my,string tokenizer ,implementation!!";
	char * ptr = strtok(s1, " ");
	cout << ptr << endl;
	//This function is basically replace every occurence of dimilimiter with a endl
	while (ptr  != NULL)
	{
		ptr = strtok(NULL, " ");
		cout << ptr << endl;
	}
	cout << endl;

	cout << "here";



	return 0;
}
