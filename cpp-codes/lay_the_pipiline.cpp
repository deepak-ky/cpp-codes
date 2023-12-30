#include<iostream>
using namespace std;
typedef long long int lli;
int main()
{
    lli n;
    cin>>n;
    lli a[n][n];
    for(lli i=0;i<n;i++)
    {
        for(lli j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"\nThe original city lay out : \n";
    for(lli i=0;i<n;i++)
    {
        for(lli j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    lli small=a[0][0]+a[0][1];
    lli row=0;
    for(int i=1;i<n;i++)
    {
        if((a[i][0]+a[i][1])<small)
        {
            small=a[i][0]+a[i][1];
            row=i;
        }
        else row=row;
    }
    cout<<"\nSmall : "<<small;
    lli cost=0;
    cout<<"\nRow : "<<row;
    lli j=0;
    cost+=a[row][0];
    cout<<"\nSMALL COST ADDED : "<<cost<<endl;
    while((j+1)<n)
    {
        cout<<"\nJ now : "<<j;
        cout<<"\nRow now  : "<<row;
                  lli val1=a[row][j+1];
        cout<<"\nVal1 now  : "<<val1;
                lli pos1=row;

        cout<<"\nAT SAME position Possible next row now  : "<<pos1<<endl;
        lli val2=0;
        lli pos2;
        cout<<endl<<"checking for above : ";
        for(lli k=row-1;k>=0;k--)
        {
            val2+=a[k][j];
            lli val_check=val2+a[k][j+1];
            if(val_check<val1)
            {
                val1=val_check;
                pos1=k;
            }
        }
        cout<<"\nVal1 now  : "<<val1;
        cout<<"\nPossible next row now  : "<<pos1;
        lli val3=0;
                cout<<endl<<"checking for below: ";

        for(lli k=row+1;k<n;k++)
        {
            val3+=a[k][j];
            lli val_check=val3+a[k][j+1];
            if(val_check<val1)
            {
                val1=val_check;
                pos1=k;
            }
        }
        cout<<"\nVal1 now  : "<<val1;
        cout<<"\nPossible next row now  : "<<pos1;
        if(pos1==row)
        {
            cost=cost+a[pos1][j+1];
        }
        else if(pos1!=row)
        {
                    lli sum1=val1;
        cost=cost+sum1;

        }
        row=pos1;
        j++;
        cout<<"\nJ now : "<<j;
        cout<<"\nRow now  : "<<row;
        cout<<"\nCost now : "<<cost;
        cout<<endl<<endl<<endl;

    }
    cout<<"\nTotal Cost : "<<cost<<endl;
    return 0;
}
