#include<iostream>
using namespace std;
typedef long long int lli;
int power_optimised(int a,int n)
{
    int ans=1;
    while(n>0)
    {
        int last_bit=(n&1);
        if(last_bit)
        {
            ans=ans*a;
        }
        a*=a;
        n=n>>1;

    }
    return ans;
}
int main() {
	int a,b;
	int w=power_optimised(a,b);
	cout<<w;
	return 0;
}
