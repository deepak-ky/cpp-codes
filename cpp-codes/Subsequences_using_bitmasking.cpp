#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
void filter(int a, string s)
{
    int j = 0;
    while (a > 0)
    {
        int last_bit = (a & 1);
        if (last_bit)
        {
            cout << s[j];
        }
        j++;
        a = a >> 1;
    }
}
int main()
{
    string s;
    cin >> s;
    //cin.get();
    int n = s.length();
    for (int i = 0; i < (1 << n); i++)
    {
        filter(i, s);
        cout << endl;
    }
    return 0;
}
