#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// a*a + b*b = c*c;
// a
int main() {
	ll b; cin>>b;
	ll a = 0;
	for(int i=1; i<b; i++)
	{
		ll n = (b*b) -(i*i);
		ll d = 2*i;
		if((n%d)==0)
		{
			a = n/d;
			cout<<a<<" "<<a+i;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
