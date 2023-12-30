#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
bool isPrime(int n)
{
	if (n <= 1)
		return false;
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;
    return true;
}
int main()
{
	lli n;
	cin>>n;
	lli p;
	cin>>p;
	vector<lli> v;
    v.push_back(1);
	for(int i=2;i<=n;i++)
    {
        if(isPrime(i))
        {
            v.push_back(i);
        }

    }
    cout<<"Vector now : ";
    for(int i=0;i<v.size();i++)
    {
       cout<<v[i]<<" ";
    }
    lli friction=0;
    for(int i=0;(i+1)<v.size();i++)
    {
        friction+=((v[i]*v[i+1])%p);
    }
    cout<<endl<<friction;
    while(next_permutation(v.begin(),v.end()))
    {
        cout<<"\nPermutation now : ";
        for(int i=0;i<v.size();i++)
         {
          cout<<v[i]<<" ";
         }
        lli value=0;
         for(int i=0;(i+1)<v.size();i++)
    {
        value+=((v[i]*v[i+1])%p);
    }
       friction=min(friction,value);
    }
    cout<<"\nFinal answer : "<<friction;
}
