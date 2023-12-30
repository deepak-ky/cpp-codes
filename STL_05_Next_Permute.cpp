#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int a[5]={1,2,3,4,5};
    next_permutation(a,a+5);
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;



}
