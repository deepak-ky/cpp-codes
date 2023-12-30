#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long int lli;
class run
{
    public:
    lli odi;
    lli test;
    lli t20;
};
lli findKthSmallest(vector<lli> v, int k)
{

	priority_queue<lli, vector<lli> > pq(v.begin(), v.begin() + k);
	lli pos=0;
    for (lli i = k; i < v.size(); i++)
	{
		if (v[i] < pq.top())
		{
			pq.pop();
			pq.push(v[i]);
			cout<<"\nThe position of the element is : "<<i;
		}
	}
	return pq.top();
}

int main()
{
lli n;
cin>>n;
run runs[n];
for(lli i=0;i<n;i++)
{
    cin>>runs[i].odi;
}
for(lli i=0;i<n;i++)
{
    cin>>runs[i].test;
}
for(lli i=0;i<n;i++)
{
    cin>>runs[i].t20;
}
vector<lli> v;
for(lli i=0;i<n;i++)
{
   lli a=runs[i].odi+runs[i].test+runs[i].t20;
   cout<<a<<endl;
   v.push_back(a);
}
cout<<"\nThe elements of the vector are : ";
for(lli i=0;i<v.size();i++)
{
    cout<<v[i]<<" ";
}
lli q;
cin>>q;
while(q--)
{
    lli t;
    cin>>t;
    if(t<v.size())
    {
    lli pos=findKthSmallest(v,t);
    cout<<pos<<endl;
    vector<lli>::iterator lb;
    lb = find(v.begin(),v.end(),pos);
    lli w=lb-v.begin();
    cout<<"\nThe position of the kth smallest element is : "<<w<<endl;
    v.erase(v.begin()+w);
    cout<<"\nVector now : ";
    for(lli i=0;i<v.size();i++)
    {
    cout<<v[i]<<" ";
    }
    }
    else cout<<-1<<endl;


}
return 0;
}
