#include<iostream>
#include<windows.h>
#include<vector>
#include<string>
#include<conio.h>
using namespace std;
char tmp_map[18][32];
char map[18][32]={ "+#############################+",
                   "|                             |",
                   "|                             |",
                   "|## ########### ##   #########|",
                   "|   |                         |",
                   "| | |### |  |           |     |",
	               "| |      |  | |###  |   |  |  |",
                   "| | #####|  | |      ## |     |",
                   "| |         | |###  |      |  |",
	               "| |##### ###         ##       |",
                   "|          ######  ####### ###|",
                   "|                             |",
                   "|# ### ####      ###   #######|",
                   "|                             |",
                   "|                             |",
	               "|                             |",
                   "|                             |",
	               "+#############################+" };
void showmap()
{
for(int i=0;i<18;i++)
{
cout<<map[i]<<endl;
}
}
void gotoxy( int  x, int  y )
{
    COORD Position;
    Position.X=x;
    Position.Y=y;
    SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), Position ) ;
}

struct walk {
	short walk_count;
	short x;
	short y;
	short back;
};

struct target {
	short x;
	short y;
};

vector<target> walk_queue;

vector<walk> BFSArray;

void AddArray( int x, int y, int wc , int back ){
	if( tmp_map[y][x] == ' ' || tmp_map[y][x] == '.' ){
		tmp_map[y][x] = '#';
		walk tmp;
		tmp.x = x;
		tmp.y = y;
		tmp.walk_count = wc;
		tmp.back = back;
		BFSArray.push_back( tmp );
	}
}
void FindPath( int sx, int sy, int x, int y ){
	memcpy( tmp_map, map, sizeof(map) );
	BFSArray.clear();
	walk tmp;
	tmp.x = sx;
	tmp.y = sy;
	tmp.walk_count = 0;
	tmp.back = -1;
	BFSArray.push_back( tmp );

	int i = 0;
	while( i < BFSArray.size() ){
		if( BFSArray[i].x == x && BFSArray[i].y == y ){
			walk_queue.clear();
			target tmp2;
			while( BFSArray[i].walk_count != 0 ){
				tmp2.x = BFSArray[i].x;
				tmp2.y = BFSArray[i].y;
				walk_queue.push_back( tmp2 );

				i = BFSArray[i].back;
			}

			break;
		}
        AddArray( BFSArray[i].x+1, BFSArray[i].y, BFSArray[i].walk_count+1, i );
		AddArray( BFSArray[i].x-1, BFSArray[i].y, BFSArray[i].walk_count+1, i );
		AddArray( BFSArray[i].x, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
		AddArray( BFSArray[i].x, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );
		i++;
	}
  BFSArray.clear();
}
int main()
{
bool Isgamerunning = true;
cout<<"Welcome to  PACMAN "<<endl;
cout<<"Instructions : \n1)Use the arrow keys to move your hero 'H'\n2)Don't get caught by the eater 'E'\n3)Eat the dots produced by the eater to gain points\n";
cout<<"\nChoose the level : \n1)EASY - > 'E'\n2)NORMAL-> 'N'\n3)HARD - > 'H'\n";
int points=0,speed;
char level;
cin>>level;
if(level=='H')
{
    speed=1;
}
else if(level=='N')
{
    speed=2;
}
else if(level=='E')
{
    speed=3;
}
system("cls");
showmap();
cout<<endl<<endl;
int hx,hy;
hx=15;
hy=16;
gotoxy(hx,hy);
cout<<"H";
int ex,ey;
ex=1;
ey=1;
gotoxy(ex,ey);
cout<<"E";
getch();
int frame=0;
FindPath(ex,ey,hx,hy);
while(Isgamerunning)
{
    gotoxy(hx,hy);
    cout<<" ";
    int old_hx=hx;
    int old_hy=hy;
    if (GetAsyncKeyState(VK_UP))
    {
        if(map[hy-1][hx]=='.')
        {
            hy--;
            points++;
        }
        else if(map[hy-1][hx]==' ')
        {
            hy--;
        }
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        if(map[hy+1][hx]=='.')
        {
            hy++;
            points++;
        }
        else if(map[hy+1][hx]==' ')
        {
            hy++;
        }
    }
     if (GetAsyncKeyState(VK_RIGHT))
    {
        if(map[hy][hx+1]=='.')
        {
            hx++;
            points++;
        }
        else if(map[hy][hx+1]==' ')
        {
            hx++;
        }
    }
     if (GetAsyncKeyState(VK_LEFT))
    {
        if(map[hy][hx-1]=='.')
        {
            hx--;
            points++;
        }
        else if(map[hy][hx-1]==' ')
        {
            hx--;
        }
    }
    if(old_hx!=hx || old_hy!=hy)
    {
        FindPath(ex,ey,hx,hy);
    }
    gotoxy(hx,hy);
    cout<<"H";
    map[ey][ex]='.';
    gotoxy(ex,ey);
    cout<<".";
    if( frame%speed == 0 && walk_queue.size() != 0 ){
			ex = walk_queue.back().x;
			ey = walk_queue.back().y;
			walk_queue.pop_back();
		}
    gotoxy(ex,ey);cout<<"E";
    if(ex==hx && ey==hy)
    {
        break;
    }
    gotoxy(32,18);
    gotoxy(32,1);cout<<points;
    Sleep(100);
    frame++;
}
system("cls");
cout<<"YOUR SCORE IS : "<<points;
cin.get();
cin.get();
cin.get();
cin.get();
cin.get();
return 0;
}


































