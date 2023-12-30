#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
string a;
cin>>a;
cout<<endl<<a;
// evalutae post fix
stack <float> s;
int l=a.length();
cout<<endl<<"length is : "<<l<<endl;
for(int i=0;i<l;i++)
{
    if(a[i]>='0' && a[i]<='9')
    {
        s.push(a[i]-'0');
        cout<<"\nTop now : "<<(s.top());

    }
    else
    {
        if(a[i]=='+')
        {
            int c=s.top();
            cout<<"\nTop now : "<<c;
            s.pop();
            int w=s.top();
            cout<<"\nTop now : "<<w;
            s.pop();
            int sum=c+w;
            cout<<"\nSum is : "<<sum;
            s.push(sum);
        cout<<"\nTop now : "<<(s.top());

        }
        else if(a[i]=='-')
        {
            int c=s.top();
            cout<<"\nTop now : "<<c;
            s.pop();
            int w=s.top();
            cout<<"\nTop now : "<<w;
            s.pop();
            int sum=w-c;
            cout<<"\nSum is : "<<sum;
            s.push(sum);
        cout<<"\nTop now : "<<(s.top());

        }
               else if(a[i]=='*')
        {
            int c=s.top();
            cout<<"\nTop now : "<<c;
            s.pop();
            int w=s.top();
            cout<<"\nTop now : "<<w;
            s.pop();
            int sum=c*w;
            cout<<"\nSum is : "<<sum;
            s.push(sum);
        cout<<"\nTop now : "<<(s.top());

        }
                    else if(a[i]=='/')
        {
            int c=s.top();
            cout<<"\nTop now : "<<c;
            s.pop();
            int w=s.top();
            cout<<"\nTop now : "<<w;
            s.pop();
            int sum=c/w;
            cout<<"\nSum is : "<<sum;
            s.push(sum);
        cout<<"\nTop now : "<<(s.top());

        }
    }


}
cout<<"\nFINAL ANSWER : "<<s.top();
return 0;
}
