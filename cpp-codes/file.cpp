#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>
using namespace std;
int main()
{
string currenthigh,currentscore,highscore;
ifstream fin;
ofstream fout;
fin.open("sample1.txt" , ios::app);
while(fin)
{
    getline(fin,currenthigh);
}
fin.close();
cout<<" asdf : "<<currenthigh;
cout<<"\nEnter the points now  : ";
cin>>currentscore;
cout<<"\n asdf : "<<currentscore;
if(currentscore>currenthigh)
{
    ofstream fout;
    fout.open("sample1.txt",ios::app);
    getline(cin,currentscore);
    fout<<currentscore;
}
fout.close();




return 0;
}
