#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
int fround(float x)
{
return int(x+0.5);
}
int main()
{
float e,t,s,p,eaf,a;
float values[3][4]={3.2,1.05,2.5,0.38,3.0,1.12,2.5,0.35,2.8,1.20,2.5,0.32};
int KLOC,model_no,rating,i,j;
char model_type[][100]={"Organic","Semi-Detached","Embedded"};
char driver[15][15]={"RELY","DATA","CPLX","TIME","STOR","VIRT","TURN","ACAP","AEXP","PCAP",
  "VEXP","LEXP","MODP","TOOL","SCED"};
 float costdrivers[15][6]={

                {0.75,0.88,1,1.15,1.40,-1},

                {-1,0.94,1,1.08,1.16,-1},

                {0.70,0.85,1,15,1.30,1.65},

                {-1,-1,1,1.11,1.30,1.66},

                {-1,-1,1,1.06,1.21,1.56},

                {-1,0.87,1,1.15,1.30,-1},

                {-1,0.87,1,1.07,1.15,-1},

                {1.46,1.19,1,0.86,0.71,-1},

                {1.29,1.13,1.00,0.91,0.82,-1},

                {1.42,1.17,1,0.86,0.70,-1},

                {1.21,1.10,1,0.90,-1,-1},

                {1.14,1.07,1,0.95,-1,-1},

                {1.24,1.10,1.00,0.91,0.82,-1},

                {1.24,1.10,1,0.91,0.83,-1},

                {1.23,1.08,1,1.04,1.10,-1}

                };
cout<<"Enter size of project  : ";
cin>>KLOC;
if(KLOC>=2 && KLOC<=50)
model_no=0;
else if(KLOC>50 && KLOC<=300)
model_no=1;
else if(KLOC>300)
model_no=2;
cout<<"\nThe mode is :  "<<model_type[model_no];
eaf=1;
cout<<"\n\nRating system : ";
cout<<"\n0 --> Very Low";
cout<<"\n1 --> Low";
cout<<"\n2 --> Nominal";
cout<<"\n3 --> High";
cout<<"\n4 --> Very High";
cout<<"\n5 --> Extra High";
for(i=0;i<15;i++)
{
    do
    {
        cout<<"\nRate the cost driver "<<driver[i]<<" from 0 to 5 : ";
        cin>>rating;
        a=costdrivers[i][rating];
        if(a==-1)
        {
            cout<<"No such value exist \nPlease enter another rating : ";

        }
    }while(a==-1);
    eaf=eaf*a;
    }
cout<<"\nEAF : "<<eaf;
e=values[model_no][0]*pow(KLOC,values[model_no][1])*eaf;
t=values[model_no][2]*pow(e,values[model_no][3]);
s=e/t;
cout<<"\nEffort = "<<e<<" Person-Month";
cout<<"\nDevelopment Time = "<<t<<" Months";
cout<<"\nAverage Staff Required = "<<fround(s)<<" Persons";
return 0;
}
