#include <bits/stdc++.h>
using namespace std;
int check(int a[],int X,int N)
{

		bool flag=false;
		int lb=0,ub=N-1;
		while(lb<=ub)
		{
			int mid=(lb+ub)/2;
			if(a[mid]>X)
				ub=mid-1;
			else if(a[mid]<X)
				lb=mid+1;
			else
			{
				flag=true;
				break;
			}
		}
		if(flag)
			return 1;
		else
			return 2;
}
int main()
{
	int N,Q;
	int t;
	cin>>t;
	while(t!=0)
    {


	cin>>N;
	int a[N];
	for(int i=0;i<N;i++)
		cin>>a[i];
	sort(a,a+N);
	cin>>Q;
	int b[Q];
	for(int i=0;i<Q;i++)
	{
		cin>>b[i];
	}
	for(int j=0;j<Q;j++)
    {
        int m;
         m=check(a,b[j],N);
    if(m==1)
    {
        cout<<"Yes";
    }
    else cout<<"No";
    cout<<endl;
}
t--;
    }
	return 0;
}
