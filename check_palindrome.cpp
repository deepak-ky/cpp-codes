#include<iostream>
#include<string>
using namespace std;
class needtouse
{
public:
    char ch;
    int pos1;
    int pos2;
};
bool check(string str)
{
   int l=str.length();
   int i,j;
for(int i=0,j=l-1;i<l,j>=0;i++,j--)
{
    if(str[i]!=str[j])
    {
        return false;
        break;
    }
    else return true;
}
}
int main()
{
string str;
cin>>str;
cout<<endl;
cout<<"\nEnter the number of queries : ";
int q;
cin>>q;
char qq;
needtouse query[q];
for(int i=0;i<q;i++)
{
    cin>>query[i].pos1;
    cin>>query[i].pos2;
    cin>>query[i].ch;
    qq=query[i].ch;
    str[query[i].pos1]=qq;
    str[query[i].pos2]=qq;
    cout<<"\nThe changed string now is : "<<str;
    if(check(str))
    {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;

}
return 0;
}
