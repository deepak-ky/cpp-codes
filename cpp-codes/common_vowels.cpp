#include<iostream>
using namespace std;
int vowel_searchfora(char *a[][15])
{
    for(int i=0;i<15;i++)
    {
        if(a[i]=='a')
            return 1;
    }
    else return 2;
}
int main()
{
int n;
cin>>n;
char a[n][15];
for(int i=0;i<n;i++)
{cin>>a[i];}
for(int i=0;i<n;i++)
{cout<<a[i]<<" : ";}
int w=vowel_search(a[1],d);
cout<<w;
return 0;

}
