#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
class salary
{
	public:
	string name;
	lli amt;
};
bool compare(pair<string,int> a,pair<string,int> b)
{
  if(a.second!=b.second)
	  return a.second>b.second;
	  else if(a.second==b.second)
      {
          return a.first<b.first;
      }

}
int main() {
	lli min_amt;
	cin>>min_amt;
	lli n;
	cin>>n;
	vector<pair<string,int> > v;
	lli size=0;
	for(lli i=0;i<n;i++)
	{
		string w;
		cin>>w;
		lli s;
		cin>>s;
		if(s>=min_amt)
		{
	v.push_back(make_pair(w,s));
		}
	}

	sort(v.begin(),v.end(),compare);
	for(lli i=0;i<v.size();i++)
	{
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}
	return 0;
}
