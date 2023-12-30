#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	std::vector<int> v;
	set<int> s;
	s.insert(100);
	s.insert(101);
	for(auto &x : s) cout << x << endl;
	// for(auto &x : s) cout << x << " ";
	// int a[] = {1,2,3,4,5};
	// for(int i=0;i<5;i++){
	// 	cout << a[i] << endl;  
	// }
	// for(auto &x : a){
	// 	cout << x << endl;
	// }
	// cout << "Hello World";

return 0;
}