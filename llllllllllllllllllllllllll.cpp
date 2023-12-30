#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if(n<=3)
        {
       		cout<<1<<" "<<endl<<n<<" ";
            for(int k=1;k<=n;k++)
            {
              cout<<k<<" ";
            }
            cout<<endl;
        }
        else
        {
            int i = 1;
			int j = 4;
			while (j<=n)
			{
				i++;
				j = j + 2;
			}
			cout<<i;
            cout<<endl<<3<<" "<<1<<" "<<2<<" "<<3;
            int value=4;
            int day=1;
            while(day<=(i-1))
            {
              ++day;
              if(value<=n && (value+1)<=n)
              {
              cout<<endl<<2<<" ";
              cout<<value<<" ";
              cout<<value+1<<" ";
              }
              else if(value<=n && (value+1)>n)
              {
              cout<<endl<<1<<" ";
              cout<<value<<" ";
              }
              value=value+2;
            }
            cout<<endl;
        }
    }
	return 0;
}
