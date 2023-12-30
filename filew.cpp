#include<iostream>
#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define MAX_FILE_NAME 100
int main()
{
    FILE *fp;
    int count = 0;
    char filename[MAX_FILE_NAME];
    char c;
    cout << "Enter file name: ";
    cin >> filename;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        cout << "Could not open file ";
        return 0;
    }
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n')
            count = count + 1;
    fclose(fp);
    cout << "The file contains " << count +1 << " lines ";
    return 0;

}
