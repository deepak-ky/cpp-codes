#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>
int edges=4;

void dcircle(int x,int y,int r,int color)
{
 float x1,y1,e,sx,sy,i=0,v,x2,y2;
 x1=r;
 y1=0;

 sx=x1;
 sy=y1;

 do
 {
  v=pow(2,i);
  i++;
 }
 while(v<r);

 e=(1/v);

 do
 {
  x2=x1+(y1*e);
  y2=y1-(e*x2);

  putpixel(x1+x,y1+y,color);

  x1=x2;
  y1=y2;
 }
 while((y1-sy)<e ||(sx-x1)>e);
}



void flood_fill(int x,int y,int f_color,int b_color)
{
 if(getpixel(x,y)==b_color)
 {
  putpixel(x,y,f_color);

  flood_fill(x+1,y,f_color,b_color);
  flood_fill(x,y+1,f_color,b_color);
  flood_fill(x-1,y,f_color,b_color);
  flood_fill(x,y-1,f_color,b_color) ;
 }
}


int sign(int );
void bres_circle(int,int,int);
void bres_ghost(int,int,int,int);
void bres_circle1(int,int,int);
//void boundary(int x, int y, int f_color, int b_color);
//using namespace std;
class algorithm
 {
  int dx,dy,len,x,y,e,i;
  float input[20][2];
 public:
  void ddall(int x1,int y1,int x2,int y2);
  void brel(int x1,int y1,int x2,int y2);
  void boundary(int x, int y, int f_color, int b_color);
  void rotate(float,int);
  void plot(float[20][2]);
  void accept(int,int,int,int,int,int,int,int);
  void translate(int,int,int);
  void multiply(float [20][2],float[2][2]);
  void scale(int ,int);
  void scanline(int [10],int[10],int,int);
  };


void algorithm::scanline(int xx[10],int yy[10],int col,int n)
{
 int i,k,inter_x[50],temp,y,ymax=0,ymin=480;
 float m[50],dx,dy;
 for(i=0;i<n;i++)
 {
  if(yy[i]>=ymax)ymax=yy[i];
  if(yy[i]<=ymin)ymin=yy[i];

  dx=xx[i+1]-xx[i];
  dy=yy[i+1]-yy[i];
  if(dx==0)m[i]=0;
  if(dy==0)m[i]=1;
  if(dx!=0 && dy!=0)
  m[i]=(float)dx/dy;

  }
 int cnt;
 setcolor(col);

 for(y=ymax;y>=ymin;y--)
 {
  cnt=0;
  for(i=0;i<n;i++)
  {
   if((yy[i]>y&&yy[i+1]<=y)||(yy[i]<=y&&yy[i+1]>y))
   {
   inter_x[cnt]=(xx[i]+(m[i]*(y-yy[i])));

   cnt++;

   }

  }
  for(k=0;k<cnt-1;k++)
  {
   for(i=0;i<cnt-1;i++)
   {
    if(inter_x[i]>inter_x[i+1])
    {
     temp=inter_x[i];
     inter_x[i]=inter_x[i+1];
     inter_x[i+1]=temp;

    }
   }
  }
       for(i=0;i<cnt-1;i+=2)
       {
  line(inter_x[i],y,inter_x[i+1]+1,y);
       delay(10);
       }


 }

       getch();

}




void algorithm::accept(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{


 input[1][1]=x1;
 input[1][2]=y1;
 input[2][1]=x2;
 input[2][2]=y2;
 input[3][1]=x3;
 input[3][2]=y3;
 input[4][1]=x4;
 input[4][2]=y4;


 plot(input);
      // rectangle(0,0,200,200);


       // getch();

}
void algorithm::plot(float mat[20][2])
{
 int i;

       // line(0,240,639,240);
       // line(320,0,320,479);
       // outtextxy(295,243,"0,0");
 setcolor(YELLOW);
 for(i=1;i<edges;i++)


  line(mat[i][1],mat[i][2],mat[i+1][1],mat[i+1][2]);


  line(mat[1][1],mat[1][2],mat[i][1],mat[i][2]);


}
void algorithm::translate(int tx,int ty ,int num)
{
      // int tx,ty;
       // cout<<"Enter translate factor for x\n";
       // cin>>tx;
       // cout<<"Enter translate factor for y\n";
       // cin>>ty;

 for(int i=1;i<=edges;i++)
 {
  input[i][1]=input[i][1]+tx;
  input[i][2]=input[i][2]+ty;
 }
       // cleardevice();
 plot(input);
 if(num==1)
 rotate(90,1);
 if(num==-1)
 rotate(90,-1);

}

void algorithm::multiply(float a[20][2],float b[2][2])
{
 int i;
 float c[20][2];
 for(i=1;i<=edges;i++)
 {
  c[i][1]=(a[i][1]*b[1][1])+(a[i][2]+b[2][1]);
  c[i][2]=(a[i][1]*b[1][2])+(a[i][2]*b[2][2]);

 }
 plot(c);


}

void algorithm::scale(int scx,int scy)
{
 int i;
       // int scalex=10;
 //int scaley=20;
 float scalemat[2][2];
 scalemat[1][1]=scx;
 scalemat[2][2]=scy;
 scalemat[1][2]=scalemat[2][1]=0;
 multiply(input,scalemat);

}

void algorithm::rotate(float theta,int clockoranti)
{
 float theta1=((3.14*theta)/180);
 float rot[20][2];
 if(clockoranti==1)
       { rot[1][1]=rot[2][2]=cos(theta1) ;
  rot[1][2]=sin(theta1);
  rot[2][1]=-sin(theta1);
  multiply(input,rot);
 }
      else
       { rot[1][1]=rot[2][2]=cos(theta1) ;
  rot[1][2]=-sin(theta1);
  rot[2][1]=sin(theta1);
  multiply(input,rot);
 }


}



void algorithm::brel(int x1,int y1,int x2,int y2)
{

 //if(x1==x2 && y1==y2)
 // {
   //  putpixel(x1,y1,4);
     // }
      // else
  {
   dx=abs(x2-x1);
   dy=abs(y2-y1);
   x=x1;
   y=y1;
   putpixel(x,y,13);
   e=2*sign(dy)-dx;
   i=1;
 l2:
  putpixel(x,y,13);
  while(e>=0)
   {
    y=y+1;
    e=e-2*sign(dx);
   }
  x=x+1;
  e=e+2*sign(dy);
  i++;
   if(i<=dx)
   {
 goto l2;
   }

   else
 putpixel(x,y,13);
}

}
void algorithm::ddall(int x1,int y1,int x2,int y2)
{    dx=x2-x1;
     dy=y2-y1;
     if(dx>=dy)
     {
 len=abs(dx);
     }
     else
     {
 len=abs(dy);
     }
 dx=(x2-x1)/len;
 dy=(y2-y1)/len;
 x=x1+0.5*sign(dx);
 y=y1+0.5*sign(dy);
 putpixel(x,y,13);
      i=1;
 while(i<=len)
 {
  putpixel(x,y,13);
  x=x+dx;
  y=y+dy;
  i++;
 }

}


int main()

{
 int e,ch;
 int i=1;
 char u,key;
 algorithm p,rot;

 int gd = DETECT, gm = 0;
 initgraph(&gd, &gm,"c:\\TC\\BGI");

 rot.accept(240,340,248,340,248,348,240,348);
 float r=0;
//floodfill(12,12,15);
for(int k=0;k<20;k++ )
{

for(int i=0;i<=6;i++)
{

 //translate(12,0);

       // translate(13,0);
       // translate(20,0);
       rot.rotate(10+r,1);
 rot.rotate(12-r,-1);
 rot.rotate(14+r,-1);
 rot.rotate(16-r,1);
 rot.rotate(18+r,-1);
 rot.rotate(20-r,-1);
 outtextxy(0,0,"Welcome To PACMAN");
 outtextxy(0,10,"Please Wait..");
 outtextxy(0,20,"Preparing your Layout...");
 delay(180);
 cleardevice();
 r+=10.25;

}
//scale();
if(k!=19)
{
rot.accept(240,340,248,340,248,348,240,348);
cleardevice();
}
else
break;
}


int choice;
 while(choice!=3)
 {
 menu:cout<<"\n\n\n\n1.PLAY\n2.HELP\n\n";
 cin>>choice;

 switch(choice)
 {
 case 1:goto intermediate;
  break;
 case 2: goto help;
  break;

 //default:cout<<"Enter a valid choice !!\n";
 }
 }


 help:
 cout<<"This is a single-player game called pacman!\nThe objective of the game is to collect all the coins,\nEXTRA points are given for coloured coins!\nIf you wanna quit during gameplay hit 'q'!\nIt has one minute countdown timer hidden to make the game more competetive !!\nMove using 'w' for up 'a' for left 'd' for right and 's' for down\nDouble press any key for movement !!Double tapping makes accuracy a must \nSound enabled , movement of pacman results in sounds!Press any key to play!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" ;
 char key1;
 getch();

 intermediate:
       initgraph(&gd, &gm,"c:\\TC\\BGI");
       // cout<<"Loading";
 //for(int k=0;k<25;k++)
 //{
       // delay(100);cout<<".";
 //}
 bres_circle(250,250,10);
 flood_fill(250,250,10,BLACK);
 delay(500);dcircle(250,250,15,100);
 flood_fill(250,250,100,BLACK);
 delay(500);dcircle(350,250,15,100);
 flood_fill(350,250,100,BLACK);
 delay(500);dcircle(150,250,15,100);
 flood_fill(150,250,100,BLACK);

 delay(500);dcircle(450,250,15,100);
 flood_fill(450,250,100,BLACK);

 delay(500);dcircle(50,250,15,100);
 flood_fill(50,250,100,BLACK);
 algorithm trans1,trans2,trans3,trans4;
 trans1.accept(0,0,4,0,4,4,0,4);
 trans2.accept((getmaxx()-4),0,getmaxx(),0,getmaxx(),4,(getmaxx()-4),4);
 trans3.accept((getmaxx()-4),(getmaxy()-4),getmaxx(),(getmaxy()-4),getmaxx(),getmaxy(),(getmaxx()-4),getmaxy());
 trans4.accept(0,(getmaxy()-4),4,(getmaxy()-4),4,getmaxy(),0,getmaxy());
 int getmaxxx=getmaxy();
 for(int z=0;z<=150;z+=2)
 {
 trans1.translate(10,0,0);
       // cleardevice();
 trans2.translate(0,10,0);
 trans3.translate(-10,0,0);
 trans4.translate(0,-10,0);
 delay(20);
 outtextxy(200,200,"Loading....") ;
 delay(20);
 }

 //delay(500);cout<<"PACMAN!";
 outtextxy(300,200,"Complete press any key! :p");

 char quitl=getch();closegraph();
 if(quitl=='q')
 exit(1);
 goto play;

 if(key1==getch())
 {
 goto menu;
 }
 play:

 initgraph(&gd, &gm,"c:\\TC\\BGI");

 p.ddall(40,10,40,30);
 p.ddall(40,10,50,10);
 p.ddall(50,10,50,20);
 p.ddall(40,20,50,20);
 p.ddall(55,10,55,30);
 p.ddall(55,10,65,10);
 p.ddall(65,10,65,30);
 p.ddall(55,20,65,20);
 p.ddall(70,10,80,10);
 p.ddall(70,30,80,30);
 p.ddall(70,10,70,30);
 p.ddall(85,10,85,30);
 p.ddall(85,10,95,20);
 p.ddall(95,20,104,9);
 p.ddall(105,10,105,30);
 p.ddall(110,10,110,30);
 p.ddall(110,10,120,10);
 p.ddall(120,10,120,30);
 p.ddall(110,20,120,20);
 p.ddall(125,10,125,30);
 p.ddall(135,30,125,10);
 p.ddall(135,10,135,30);


 for(int v=0;v<=5;v++)
 {
 p.ddall(35+v,35+v,35+v,445-v);
 p.ddall(35+v,445-v,385-v,445-v);
 p.ddall(385-v,35+v,385-v,445-v);
 p.ddall(35+v,35+v,385-v,35-v);
 }//p.boundary(35,385,13,WHITE);

 p.ddall(40,40,40,440);
 p.brel(40,440,380,440);
 p.ddall(380,40,380,440);
 p.brel(40,40,380,40);

 p.ddall(60,60,100,60);
 p.ddall(100,60,100,100);
 p.ddall(60,60,60,100);
 p.ddall(60,100,100,100);
 //p.boundary(80,80,13,3);
 p.ddall(120,60,180,60);
 p.ddall(180,60,180,100);
 p.ddall(120,100,180,100);
 p.ddall(120,60,120,100);
 //p.boundary(150,80,13,3);
 p.ddall(200,40,220,40);
 p.ddall(200,40,200,100);
 p.ddall(200,100,220,100);
 p.ddall(220,40,220,100);
 //p.boundary(210,70,13,3);



 p.ddall(320,60,360,60);
 p.ddall(360,60,360,100);
 p.ddall(320,60,320,100);
 p.ddall(320,100,360,100);
 //p.boundary(340,80,13,3);
 p.ddall(240,60,300,60);
 p.ddall(240,60,240,100);
 p.ddall(240,100,300,100);
 p.ddall(300,60,300,100);
 //p.boundary(250,80,13,3);
 p.ddall(60,120,100,120);
 p.ddall(60,120,60,140);
 p.ddall(60,140,100,140);
 p.ddall(100,120,100,140);
 //p.boundary(80,130,13,3);
 p.ddall(120,120,140,120);
 p.ddall(140,120,140,160);
 p.ddall(140,160,180,160);
 p.ddall(180,160,180,180);
 p.ddall(140,180,180,180);
 p.ddall(140,180,140,220);
 p.ddall(120,220,140,220);
 p.ddall(120,120,120,220);
 //p.boundary(126,170,13,3);
 p.ddall(40,160,100,160);
 p.ddall(100,160,100,220);
 p.ddall(40,220,100,220);
 //p.boundary(60,170,13,3);

 p.ddall(40,240,100,240);
 p.ddall(100,240,100,300);
 p.ddall(40,300,100,300);
 //p.boundary(60,260,13,3);

 p.ddall(320,160,380,160);
 p.ddall(320,160,320,220);
 p.ddall(320,220,380,220);
 //p.boundary(340,182,13,3);

 p.ddall(320,240,380,240);
 p.ddall(320,240,320,300);
 p.ddall(320,300,380,300);
 //p.boundary(340,260,13,3);

 p.ddall(280,120,300,120);
 p.ddall(280,120,300,160);
 p.ddall(240,160,280,160);
 p.ddall(240,180,280,200);
 p.ddall(240,160,240,180);
 p.ddall(280,180,280,220);
 p.ddall(280,220,300,220);
 p.ddall(300,120,300,220);
 //p.boundary(289,140,13,3);

 p.ddall(160,120,260,120);
 p.ddall(160,120,160,140);
 p.ddall(260,120,260,140);
 p.ddall(220,140,260,140);
 p.ddall(160,140,200,140);
 p.ddall(200,140,200,180);
 p.ddall(220,140,220,180);
 p.ddall(200,180,220,180);
 //p.boundary(180,130,13,3);

 p.ddall(320,120,360,120);
 p.ddall(320,120,320,140);
 p.ddall(320,140,360,140);
 p.ddall(360,120,360,140);
 //p.boundary(340,130,13,3);
//center
 p.ddall(160,220,200,220);
 p.ddall(220,220,260,220);
 p.ddall(260,220,260,280);
 p.ddall(160,280,260,280);
 p.ddall(160,220,160,280);

 p.ddall(160,300,260,300);
 p.ddall(160,300,160,320);
 p.ddall(260,300,260,320);
 p.ddall(220,320,260,320);
 p.ddall(160,320,200,320);
 p.ddall(200,320,200,360);
 p.ddall(220,320,220,360);
 p.ddall(200,360,220,360);
 //p.boundary(220,310,13,3);

 p.ddall(200,400,220,400);
 p.ddall(200,400,200,440);
 p.ddall(220,400,220,440);
 //p.boundary(210,420,13,3);

 p.ddall(180,400,180,420);
 p.ddall(60,420,180,420);
 p.ddall(60,400,60,420);
 p.ddall(60,400,120,400);
 p.ddall(120,360,120,400);
 p.ddall(120,360,140,360);
 p.ddall(140,360,140,400);
 p.ddall(140,400,180,400);
 //p.boundary(100,410,13,3);

 p.ddall(360,400,360,420);
 p.ddall(240,420,360,420);
 p.ddall(240,400,240,420);
 p.ddall(240,400,280,400);
 p.ddall(300,360,300,400);
 p.ddall(280,360,300,360);
 p.ddall(280,360,280,400);
 p.ddall(300,400,360,400);
 //p.boundary(250,410,13,3);

 p.ddall(40,380,60,380);
 p.ddall(40,360,60,360);
 p.ddall(60,360,60,380);
 //p.boundary(50,370,13,3);


 p.ddall(360,380,380,380);
 p.ddall(360,360,380,360);
 p.ddall(360,360,360,380);
 //p.boundary(370,370,13,3);

 p.ddall(80,380,100,380);
 p.ddall(80,340,80,380);
 p.ddall(60,340,80,340);
 p.ddall(60,320,60,340);
 p.ddall(60,320,100,320);
 p.ddall(100,320,100,380);
 //p.boundary(90,350,13,3);

 p.ddall(320,380,340,380);
 p.ddall(340,340,340,380);
 p.ddall(340,340,360,340);
 p.ddall(360,320,360,340);
 p.ddall(320,320,360,320);
 p.ddall(320,320,320,380);
 //p.boundary(330,360,13,3);

 p.ddall(120,320,140,320);
 p.ddall(120,260,120,320);
 p.ddall(140,260,140,320);
 p.ddall(120,260,140,260);
 //p.boundary(130,290,13,3);

 p.ddall(280,320,300,320);
 p.ddall(280,260,280,320);
 p.ddall(300,260,300,320);
 p.ddall(280,260,300,260);
 //p.boundary(290,280,13,3);

 p.ddall(160,380,180,380);
 p.ddall(160,340,160,380);
 p.ddall(160,340,180,340);
 p.ddall(180,340,180,380);
 //p.boundary(170,360,13,3);



 p.ddall(240,380,260,380);
 p.ddall(260,340,260,380);
 p.ddall(240,340,260,340);
 p.ddall(240,340,240,380);
 //p.boundary(250,350,13,3);
 p.boundary(80,80,13,BLUE);
 p.boundary(150,80,13,BLUE);
 p.boundary(210,70,13,BLUE);
 p.boundary(340,80,13,BLUE);
 p.boundary(250,80,13,BLUE);
 p.boundary(80,130,13,BLUE);
 p.boundary(126,170,13,BLUE);
 p.boundary(60,170,13,BLUE);
 p.boundary(60,260,13,BLUE);
 p.boundary(340,182,13,BLUE);
 p.boundary(340,260,13,BLUE);
 p.boundary(289,140,13,BLUE);
 p.boundary(180,130,13,BLUE);
 p.boundary(340,130,13,BLUE);
 p.boundary(220,310,13,BLUE);
 p.boundary(210,420,13,BLUE);
 p.boundary(100,410,13,BLUE);
 p.boundary(250,410,13,BLUE);
 p.boundary(50,370,13,BLUE);
 p.boundary(370,370,13,BLUE);
 p.boundary(90,350,13,BLUE);
 p.boundary(330,360,13,BLUE);
 p.boundary(130,290,13,BLUE);
 p.boundary(290,280,13,BLUE);
 p.boundary(170,360,13,BLUE);
 p.boundary(250,350,13,BLUE);



int c=210;
int g=390;
int c1=110;
int g1=110;
int c2=310;
int g2=110;
int c3=110;
int g3=390;
int c4=310;
int g4=390;
long double score=0;
bres_circle(210,390,7);
bres_ghost(c1,g1,4,53);
bres_ghost(c2,g2,4,135);
bres_ghost(c3,g3,4,163);
bres_ghost(c4,g4,4,213);

for(int h=0;h<400;h=h+20)
{
if(BLUE==getpixel(50,50+h))
continue;
bres_ghost(50,50+h,4,WHITE);
}
for( h=0;h<400;h=h+20)
{
if(BLUE==getpixel(70,50+h))
continue;
bres_ghost(70,50+h,4,WHITE);
}
for( h=0;h<400;h=h+20)
{
if(BLUE==getpixel(90,50+h))
continue;
bres_ghost(90,50+h,4,WHITE);
}
for( h=0;h<400;h=h+20)
{
if(BLUE==getpixel(110,50+h))
continue;
bres_ghost(110,50+h,4,WHITE);
}

for( h=0;h<400;h=h+20)
{
if(BLUE==getpixel(130,50+h))
continue;
bres_ghost(130,50+h,4,WHITE);
}
for( h=0;h<400;h=h+20)
{
if(BLUE==getpixel(150,50+h))
continue;
bres_ghost(150,50+h,4,WHITE);
}
for( h=0;h<400;h=h+20)
{
if(BLUE==getpixel(170,50+h)||((h>170) && (h<240)))
continue;
bres_ghost(170,50+h,4,WHITE);
}
for( h=0;h<400;h=h+20)
{
if(BLUE==getpixel(190,50+h)||((h>170) && (h<240)))
continue;
bres_ghost(190,50+h,4,WHITE);
}
for( h=0;h<400;h=h+20)
{
if(BLUE==getpixel(210,50+h)||((h>170) && (h<240)))
continue;
bres_ghost(210,50+h,4,WHITE);
}
for( h=0;h<400;h=h+20)
{
if(BLUE==getpixel(230,50+h)||((h>170) && (h<240)))
continue;
bres_ghost(230,50+h,4,WHITE);
}
for( h=0;h<400;h=h+20)
{
if(BLUE==getpixel(250,50+h)||((h>170) && (h<240)))
continue;
bres_ghost(250,50+h,4,WHITE);
}
for( h=0;h<400;h=h+20)
{
if(BLUE==getpixel(270,50+h))
continue;
bres_ghost(270,50+h,4,WHITE);
}
for( h=0;h<400;h=h+20)
{
if(BLUE==getpixel(290,50+h))
continue;
bres_ghost(290,50+h,4,WHITE);
}
for( h=0;h<400;h=h+20)
{
if(BLUE==getpixel(310,50+h))
continue;
bres_ghost(310,50+h,4,WHITE);
}
for( h=0;h<400;h=h+20)
{
if(BLUE==getpixel(330,50+h))
continue;
bres_ghost(330,50+h,4,WHITE);
}
for( h=0;h<400;h=h+20)
{
if(BLUE==getpixel(350,50+h))
continue;
bres_ghost(350,50+h,4,WHITE);
}
for( h=0;h<400;h=h+20)
{
if(BLUE==getpixel(370,50+h))
continue;
bres_ghost(370,50+h,4,WHITE);
}

bres_ghost(c1,g1,4,53);
bres_ghost(c2,g2,4,135);
bres_ghost(c3,g3,4,163);
bres_ghost(c4,g4,4,213);

p.boundary(c-1,g-1,13,YELLOW);
key =getch();
delay(5);sound(50);delay(5);nosound();

clock_t endwait;
endwait=clock()+60*CLK_TCK;
while(clock()<endwait)
{


if(c<40 || c>380 ||g>440 || g<40)
{
goto menu;
}



 while(key=='w')
 {
 for(int v=0;13!=getpixel(c,g-8) ;v++)
 {
 //clrscr();
 // key =getch();
 delay(5);sound(50);delay(5);nosound();
       // bres_ghost(c1,g1=g1-1,7,13);
 //bres_ghost(c2,g2=g2-1,7,135);
 //bres_ghost(c3,g3=g3-1,7,163);
 //bres_ghost(c4,g4=g4-1,7,213);

 delay(5);bres_circle(c,g=g-1,7);
 delay(5);p.boundary(c-1,g-1,13,YELLOW);
 delay(5);
 bres_circle1(c,g,7);
 delay(5);p.boundary(c-2,g-2,BLACK,YELLOW);
 if(kbhit())
  {
  key=getch();
  break;
  }

 //bres_ghost(c1,g1=g1-1,7,BLACK);
 //bres_ghost(c2,g2=g2-1,7,BLACK);
 //bres_ghost(c3,g3=g3-1,7,BLACK);
       // bres_ghost(c4,g4=g4-1,7,BLACK);

if(c<40 || c>380 ||g>440 || g<40)
{
goto x2;
}

}key =getch();
 }
 //bres_circle(c,g,7);
 //key =getch();
 while(key=='a')
 {for(int v=0;13!=getpixel(c-8,g);v++)
 {
 delay(5);sound(50);delay(5);nosound();

       // bres_ghost(c1=c1-1,g1,7,13);
 //bres_ghost(c2=c2-1,g2,7,135);
       // bres_ghost(c3=c3-1,g3,7,163);
 //bres_ghost(c4=c4-1,g4,7,213);
 //clrscr();
 // key =getch();
 delay(5);bres_circle(c=c-1,g,7);
 delay(5);p.boundary(c-1,g-1,13,YELLOW);


 delay(5);bres_circle1(c,g,7);
 delay(5);p.boundary(c-2,g-2,BLACK,YELLOW);

  if(kbhit())
  {
  key=getch();
  break;
  }
if(c<40 || c>380 ||g>440 || g<40)
{
goto x2;
} }
 key =getch();

 }
 //bres_circle(200,200,7);
 //key =getch();
 while(key=='d')
 {
 for(int v=0;13!=getpixel(c+8,g);v++)
 {//clrscr();
  //key =getch();
 delay(5);sound(50);delay(5);nosound();

       // bres_ghost(c1=c1+1,g1,7,13);
 //bres_ghost(c2=c2+1,g2,7,135);
 //bres_ghost(c3=c3+1,g3,7,163);
       // bres_ghost(c4=c4+1,g4,7,213);
 delay(5);bres_circle(c=c+1,g,7);
 delay(5);p.boundary(c-1,g-1,13,YELLOW);

 delay(5) ;
 bres_circle1(c,g,7);
 delay(5);p.boundary(c-2,g-2,BLACK,YELLOW);
  if(kbhit())
  {
  key=getch();
  break;
  }

if(c<40 || c>380 ||g>440 || g<40)
{
goto x2;
}
 }key =getch();
 }
  //bres_circle(200,200,7);
 key =getch();
 while(key=='s')
 {
 for(int v=0;13!=getpixel(c,g+8);v++)
 {
 //clrscr();
  //key =getch();
 delay(5);sound(50);delay(5);nosound();

       // bres_ghost(c1,g1=g1+1,7,13);
 //bres_ghost(c2,g2=g2+1,7,135);
 //bres_ghost(c3,g3=g3+1,7,163);
 //bres_ghost(c4,g4=g4+1,7,213);
 delay(5);bres_circle(c,g=g+1,7);
 delay(5);p.boundary(c-1,g-1,13,YELLOW);
 delay(5);
 bres_circle1(c,g,7);
 delay(5);
 p.boundary(c-2,g-2,BLACK,YELLOW);
  if(kbhit())
  {
  key=getch();
  break;
  }

if(c<40 || c>380 ||g>440 || g<40)
{
goto x2;
}
 }
 key =getch();
 }

for(int h=0;h<400;h=h+20)
{
if(BLACK==getpixel(53,50+h))
score=score+20;
}
for( h=0;h<400;h=h+20)
{
if(BLACK==getpixel(73,50+h))
score=score+20     ;
}
for( h=0;h<400;h=h+20)
{
if(BLACK==getpixel(93,50+h))
score=score+20    ;
}
for( h=0;h<400;h=h+20)
{
if(BLACK==getpixel(113,50+h))
score=score+20   ;
}
for( h=0;h<400;h=h+20)
{
if(BLACK==getpixel(133,50+h))
score=score+20  ;
}
for( h=0;h<400;h=h+20)
{
if(BLACK==getpixel(153,50+h))
score=score+20 ;
}
for( h=0;h<400;h=h+20)
{
if(BLACK==getpixel(173,50+h)||((h>170) && (h<240)))
score=score+20;
}
for( h=0;h<400;h=h+20)
{
if(BLACK==getpixel(193,50+h)||((h>170) && (h<240)))
score=score+20;
}
for( h=0;h<400;h=h+20)
{
if(BLACK==getpixel(213,50+h)||((h>170) && (h<240)))
score=score+20;
}
for( h=0;h<400;h=h+20)
{
if(BLACK==getpixel(233,50+h)||((h>170) && (h<240)))
score=score+20;
}
for( h=0;h<400;h=h+20)
{
if(BLACK==getpixel(253,50+h)||((h>170) && (h<240)))
score=score+20;
}
for( h=0;h<400;h=h+20)
{
if(BLACK==getpixel(273,50+h))
score=score+20;
}
for( h=0;h<400;h=h+20)
{
if(BLACK==getpixel(293,50+h))
score=score+20;
}
for( h=0;h<400;h=h+20)
{
if(BLACK==getpixel(313,50+h))
score=score+20;
}
for( h=0;h<400;h=h+20)
{
if(BLACK==getpixel(333,50+h))
score=score+20;
}
for( h=0;h<400;h=h+20)
{
if(BLACK==getpixel(353,50+h))
score=score+20;
}
for( h=0;h<400;h=h+20)
{
if(BLACK==getpixel(373,50+h))
score=score+20;
}
if(BLACK==getpixel(c1+3,g1))
score=score+500;
if(BLACK==getpixel(c2+3,g2))
score=score+500;
if(BLACK==getpixel(c3+3,g3))
score=score+500;
if(BLACK==getpixel(c4+3,g4))
score=score+500;





if(key=='q')
{
goto x2;
}

} getch();
 closegraph();


x2:
closegraph();cout<<"\n\n\n\n\n\n\n-----------------------------------THANK YOU!!!------------------------------\n";
cout<<"Score = "<<score;
cout<<"\n\n\t\t----------------Highest scores------------------\n\n\n";
cout<<"\n\nPrerna Meshram----------98576\nSwapnil Anand----------97098\nSushant Dani----------97001\nVJ----------88909\n";


getch();
clrscr();
return 0;
}

int sign(int a)
{
if (a<0)
return -1;
else if(a>0)
return 1;
else
return 0;
}



//Boundary fill for filling the blocks
void algorithm::boundary(int x, int y, int f_color, int b_color){


 if(getpixel(x,y)!=b_color && getpixel(x,y)!=f_color){

  putpixel(x,y,b_color);
  //algorithm p1;
  //p1.ddall(x,y,x+1,y+1);
  boundary(x+1, y, f_color, b_color);
  boundary(x-1, y, f_color, b_color);
  boundary(x, y-1, f_color, b_color);
  boundary(x, y+1, f_color, b_color);



 }

}



void bres_circle(int x1,int y1,int r)
 {
  int d,x,y;
  d=3-2*r;
  x=0;
  y=r-1;
   do
   { //putpixel(x1+7,y1,YELLOW);
    //putpixel(x1,y1+7,YELLOW);
    //putpixel(x1-7,y1,YELLOW);
    //putpixel(x1,y1-7,YELLOW);
    putpixel(x1+x,y1+y,YELLOW);
    putpixel(x1-x,y1+y,YELLOW);
    putpixel(x1+x,y1-y,YELLOW);
    putpixel(x1-x,y1-y,YELLOW);
    putpixel(x1-y,y1+x,YELLOW);
    putpixel(x1+y,y1-x,YELLOW);
    putpixel(x1-y,y1-x,YELLOW);
    putpixel(x1+y,y1+x,YELLOW);

     if(d<0)
      d=d+4*x+6;
     else
     {
      d=d+4*(x-y)+10;
      y=y-1;
     }
    x=x+1;
   }while(x<y);
 }


void bres_circle1(int x1,int y1,int r)
 {
  int d,x,y;
  d=3-2*r;
  x=0;
  y=r-1;
   do
   { //putpixel(x1+7,y1,YELLOW);
    //putpixel(x1,y1+7,YELLOW);
    //putpixel(x1-7,y1,YELLOW);
    //putpixel(x1,y1-7,YELLOW);
    putpixel(x1+x,y1+y,BLACK);
    putpixel(x1-x,y1+y,BLACK);
    putpixel(x1+x,y1-y,BLACK);
    putpixel(x1-x,y1-y,BLACK);
    putpixel(x1-y,y1+x,BLACK);
    putpixel(x1+y,y1-x,BLACK);
    putpixel(x1-y,y1-x,BLACK);
    putpixel(x1+y,y1+x,BLACK);

     if(d<0)
      d=d+4*x+6;
     else
     {
      d=d+4*(x-y)+10;
      y=y-1;
     }
    x=x+1;
   }while(x<y);
 }


void bres_ghost(int x1,int y1,int r,int col)
 {
  int d,x,y;
  d=3-2*r;
  x=0;
  y=r-1;
   do
   { //putpixel(x1+7,y1,YELLOW);
    //putpixel(x1,y1+7,YELLOW);
    //putpixel(x1-7,y1,YELLOW);
    //putpixel(x1,y1-7,YELLOW);
    putpixel(x1+x,y1+y,col);
    putpixel(x1-x,y1+y,col);
    putpixel(x1+x,y1-y,col);
    putpixel(x1-x,y1-y,col);
    putpixel(x1-y,y1+x,col);
    putpixel(x1+y,y1-x,col);
    putpixel(x1-y,y1-x,col);
    putpixel(x1+y,y1+x,col);

     if(d<0)
      d=d+4*x+6;
     else
     {
      d=d+4*(x-y)+10;
      y=y-1;
     }
    x=x+1;
   }while(x<y);
 }
