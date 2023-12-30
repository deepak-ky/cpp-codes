#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool issorted(int a[],int n)
{
    cout<<"\nHere n is : "<<n;
	if(n==1)
	{
	            cout<<"\nReturn true from n =1 ";

		return true;

	}
	else if(n>1)
	{
		if(a[0]<a[1] && issorted(a+1,n-1))
		{
		    	            cout<<"\nReturn true from is sorted ";

			return true;
		}

		else
        {
            				    	            cout<<"\nReturn false from the else condition ";

            return false;

        }
	}
}
int main()
{

	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
      cin>>a[i];
	}
	if(issorted(a,n))
	{
		cout<<"\nThe array is sorted";
	}
	else
	{
		cout<<"\nThe array is not sorted ";
	}
return 0;
}

