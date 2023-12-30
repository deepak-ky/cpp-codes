


#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;
char tmp_map[18][32];

char map[18][32] = {
	"+#############################+",
	"|                             |",
	"|                             |",
	"|## ########### ##   #########|",
	"|   |                         |",
	"| | |### |  |           |     |",
	"| |      |  | |###  |   |  |  |",
	"| | #####|  | |      ## |     |",
	"| |           |###  |      |  |",
	"| |##### ###         ##       |",
	"|          ######  ####### ###|",
	"|                             |",
	"|# ### ####      ###   #######|",
	"|                             |",
	"|                             |",
	"|                             |",
	"|                             |",
	"+#############################+"
	};



void gotoxy( short x, short y )
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x, y } ;

    SetConsoleCursorPosition( hStdout, position ) ;
}
void ShowMap()
{
	for(int i = 0; i < 18; i++) {


	cout<<map[i]<<"\n";

	}
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
    bool running = true;
	int hx = 15;
	int hy = 16;
	int old_x;
	int old_y;

	int ex = 1;
	int ey = 1;

	int pts = 0;

	cout<<" Welcome to PACMAN! \nInstruction:\n1. Arrow Keys to move your hero\n2. Eat the dots produced by the Eater to gain poins\n3. Don't get caught by the Eater\n\n";
	cout<<"H -> Hard\nN -> Normal\nE -> Easy\n\nInput : ";

	char diffi;
	int speedmod = 3;

	cin >> diffi;

	if( diffi == 'N' ){
		speedmod = 2;
	}else if( diffi == 'H' ){
		speedmod = 1;
	}

	system("cls");

    ShowMap();

	gotoxy( hx, hy ); cout << "H";

	int frame = 0;

	FindPath( ex,ey,hx,hy );

	while( running ){
		gotoxy( hx, hy ); cout << " ";

		old_x = hx;
		old_y = hy;

		if ( GetAsyncKeyState( VK_UP ) ){
			if( map[hy-1][hx] == '.' ){ hy--; pts++; } else
			if( map[hy-1][hx] == ' ' ) hy--;
		}
		if ( GetAsyncKeyState( VK_DOWN ) ){
			if( map[hy+1][hx] == '.' ){ hy++; pts++; } else
			if( map[hy+1][hx] == ' ' ) hy++;
		}
		if ( GetAsyncKeyState( VK_LEFT ) ){
			if( map[hy][hx-1] == '.' ){ hx--; pts++; } else
			if( map[hy][hx-1] == ' ' ) hx--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) ){
			if( map[hy][hx+1] == '.' ){ hx++; pts++; } else
			if( map[hy][hx+1] == ' ' ) hx++;
		}

		if( old_x != hx || old_y != hy ){
			FindPath( ex,ey,hx,hy );
		}

		gotoxy( hx,hy ); cout << "H";

		map[ey][ex] = '.';
		gotoxy( ex, ey ); cout << ".";

		if( frame%speedmod == 0 && walk_queue.size() != 0 ){
			ex = walk_queue.back().x;
			ey = walk_queue.back().y;
			walk_queue.pop_back();
		}

		gotoxy( ex, ey ); cout << "E";

		if( ex == hx && ey == hy ){
			break;
		}


		gotoxy( 32, 1 ); cout << pts;
		Sleep( 100 );
		frame++;
	}

	system("cls");
	cout<<"You Lose and your score is : "<< pts ;
	cin.get();
	cin.get();

	return 0;
}


4
