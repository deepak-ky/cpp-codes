#include<iostream>
#include<bits/stdc++.h>
#include <string.h>
#include <ctype.h>
using namespace std;
char opnds[50][80],oprs[50];
int  topr=-1,topd=-1;
pushd(char *opnd)
{
    strcpy(opnds[++topd],opnd);
}
char *popd()
{
    return(opnds[topd--]);
}

pushr(char opr)
{
    oprs[++topr]=opr;
}
char popr()
{
    return(oprs[topr--]);
}
int empty(int t)
{
    if( t == 0) return(1);
    return(0);
}

main()
{
    char prfx[50],ch,str[50],opnd1[50],opnd2[50],opr[2];
    int i=0,k=0,opndcnt=0;
    gets(prfx);
    printf(" Given Prefix Expression : %s\n",prfx);
    while( (ch=prfx[i++]) != '\0')
    {
        if(isalnum(ch))
        {
            str[0]=ch; str[1]='\0';
            pushd(str); opndcnt++;
            if(opndcnt >= 2)
            {
                strcpy(opnd2,popd());
                strcpy(opnd1,popd());
                strcpy(str,opnd1);
                strcat(str,opnd2);
                ch=popr();
                opr[0]=ch;opr[1]='\0';
                strcat(str,opr);
                pushd(str);
                opndcnt-=1;
            }
        }
        else
        {
            pushr(ch);
            if(opndcnt==1)opndcnt=0;  /* operator followed by single operand*/
        }
    }
    if(!empty(topd))
    {
        strcpy(opnd2,popd());
        strcpy(opnd1,popd());
        strcpy(str,opnd1);
        strcat(str,opnd2);
        ch=popr();
        opr[0]=ch;opr[1]='\0';
        strcat(str,opr);
        pushd(str);
    }
    printf(" Postfix Expression: ");
    puts(opnds[topd]);
}
