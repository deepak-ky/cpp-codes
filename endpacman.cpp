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
	"|#  ##### ##### #### ######## |",
	"|   #                       # |",
	"|#   # ######## ##### ##### # |",
	"|  #                      # # |",
	"|#   # # ### ######## ####  # |",
	"|   #   #               # # # |",
	"|#      #  ##      ###  # # # |",
	"|   # # #               # # # |",
	"|#  # # # ######## ###### # # |",
	"|                          # #|",
	"|#  # ##### ############## #  |",
	"|   #                       # |",
	"|   ####### ######## ######## |",
	"|                             |",
	"+#############################+"
	};
char map1[18][32] = {
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

char map2[18][32] = {
	"+#############################+",
	"|                             |",
	"|                             |",
	"|   ##### ##### #### #########|",
	"|   #                         |",
	"|   #####|  |#######  #   #   |",
	"|        |  |#      | #   #   |",
	"|   #####|       # |  #####   |",
	"|# #        |#####|           |",
	"|    #### #         ##        |",
	"|          ######  ####### ###|",
	"|          #                  |",
	"| #####   #    ###   #######  |",
	"|     #    #                  |",
	"|     #    #     ######       |",
	"|     #    #           #      |",
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
void ShowMap1()
{
	for(int i = 0; i < 18; i++) {
    cout<<map1[i]<<"\n";
   }
}
void ShowMap2()
{
	for(int i = 0; i < 18; i++) {
    cout<<map2[i]<<"\n";
   }
}
struct walk2 {
	short walk_count2;
	short x2;
	short y2;
	short back;

};
struct walk {
	short walk_count;
	short x;
	short y;
	short back;
};
struct target2 {
	short x2;
	short y2;
};
struct target {
	short x;
	short y;
};
vector<target2> walk_queue2;
vector<target> walk_queue;
vector<walk2> BFSArray2;
vector<walk> BFSArray;
void AddArray2( int x, int y, int wc , int back ){
	if( tmp_map[y][x] == ' ' || tmp_map[y][x] == '.' ){
		tmp_map[y][x] = '#';
		walk2 tmp2;
		tmp2.x2 = x;
		tmp2.y2 = y;
		tmp2.walk_count2 = wc;
		tmp2.back = back;
		BFSArray2.push_back( tmp2 );
	}
}
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
void FindPath2( int sx, int sy, int x, int y ,int n){
  if(n==1) {memcpy( tmp_map, map, sizeof(map) );}
   else if(n==2){memcpy( tmp_map, map1, sizeof(map1) );}
   else if(n==3){memcpy( tmp_map, map2, sizeof(map2) );}
	BFSArray2.clear();
	walk2 tmp2;
	tmp2.x2 = sx;
	tmp2.y2 = sy;
	tmp2.walk_count2 = 0;
	tmp2.back = -1;
	BFSArray2.push_back( tmp2 );

	int i = 0;
	while( i < BFSArray2.size() ){
		if( BFSArray2[i].x2 == x && BFSArray2[i].y2 == y ){
			walk_queue2.clear();
			target2 tmp3;
			while( BFSArray2[i].walk_count2 != 0 ){
				tmp3.x2 = BFSArray2[i].x2;
				tmp3.y2 = BFSArray2[i].y2;
				walk_queue2.push_back( tmp3 );

				i = BFSArray2[i].back;
			}


			break;
		}

		AddArray2( BFSArray2[i].x2+1, BFSArray2[i].y2, BFSArray2[i].walk_count2+1, i );
		AddArray2( BFSArray2[i].x2-1, BFSArray2[i].y2, BFSArray2[i].walk_count2+1, i );
		AddArray2( BFSArray2[i].x2, BFSArray2[i].y2+1, BFSArray2[i].walk_count2+1, i );
		AddArray2( BFSArray2[i].x2, BFSArray2[i].y2-1, BFSArray2[i].walk_count2+1, i );


		i++;
	}

	BFSArray2.clear();
}
void FindPath( int sx, int sy, int x, int y,int n){
   if(n==1) {memcpy( tmp_map, map, sizeof(map) );}
   else if(n==2){memcpy( tmp_map, map1, sizeof(map1) );}
   else if(n==3){memcpy( tmp_map, map2, sizeof(map2) );}
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
	int e2x=28;
	int e2y=1;
	int pts = 0;

	cout<<" Welcome to PACMAN! \nInstruction:\n1. Arrow Keys to move your hero\n2. Eat the dots produced by the Eater to gain poins\n3. Don't get caught by the Eater\n\n";
	cout<<" \nSelect your map :  \n";
	cout<<"1-> +#############################+    2->  +#############################+   3-> +#############################+ \n";
    cout<<"    |                             |         |                             |       |                             | \n";
 	cout<<"    |                             |         |                             |       |                             | \n";
	cout<<"    |#  ##### ##### #### ######## |         |## ########### ##   #########|       |   ##### ##### #### #########| \n";
	cout<<"    |   #                       # |         |   |                         |       |   #                         | \n";
    cout<<"    |#   # ######## ##### ##### # |         | | |### |  |           |     |       |   #####|  |#######  #   #   | \n";
    cout<<"    |  #                      # # |         | |      |  | |###  |   |  |  |       |        |  |#      | #   #   | \n";
    cout<<"    |#   # # ### ######## ####  # |         | | #####|  | |      ## |     |       |   #####|       # |  #####   | \n";
    cout<<"    |   #   #               # # # |         | |           |###  |      |  |       |# #        |#####|           | \n";
    cout<<"    |#      #  ##      ###  # # # |         | |##### ###         ##       |       |    #### #         ##        | \n";
    cout<<"    |   # # #               # # # |         |          ######  ####### ###|       |          ######  ####### ###| \n";
    cout<<"    |#  # # # ######## ###### # # |         |                             |       |          #                  | \n";
    cout<<"    |                          # #|         |# ### ####      ###   #######|       | #####   #    ###   #######  | \n";
    cout<<"    |#  # ##### ############## #  |         |                             |       |     #    #                  | \n";
    cout<<"    |   #                       # |         |                             |       |     #    #     ######       | \n";
    cout<<"    |   ####### ######## ######## |         |                             |       |     #    #           #      | \n";
    cout<<"    |                             |         |                             |       |                             | \n";
    cout<<"    +#############################+         +#############################+       +#############################+ \n";
    int g;
    cin>>g;

cout<<"\nCHOSSE THE LEVEL : \nH -> Hard\nN -> Normal\nE -> Easy\n\nInput : ";

	char diffi;
	int speedmod = 3;

	cin >> diffi;

	if( diffi == 'N' ){
		speedmod = 2;
	}else if( diffi == 'H' ){
		speedmod = 1;
	}

	system("cls");
if(g==1)
    {ShowMap();
    }
else if(g==2)
{
    ShowMap1();

}
else if(g==3)
{
    ShowMap2();

}
	gotoxy( hx, hy ); cout << "H";

	int frame = 0;
FindPath2( e2x,e2y,hx,hy,g );
	FindPath( ex,ey,hx,hy,g);

	while( running ){
		gotoxy( hx, hy ); cout << " ";

		old_x = hx;
		old_y = hy;

if(g==1)
{

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
			FindPath( ex,ey,hx,hy,g);
		}
}
else if(g==2)
{

		if ( GetAsyncKeyState( VK_UP ) ){
			if( map1[hy-1][hx] == '.' ){ hy--; pts++; } else
			if( map1[hy-1][hx] == ' ' ) hy--;
		}
		if ( GetAsyncKeyState( VK_DOWN ) ){
			if( map1[hy+1][hx] == '.' ){ hy++; pts++; } else
			if( map1[hy+1][hx] == ' ' ) hy++;
		}
		if ( GetAsyncKeyState( VK_LEFT ) ){
			if( map1[hy][hx-1] == '.' ){ hx--; pts++; } else
			if( map1[hy][hx-1] == ' ' ) hx--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) ){
			if( map1[hy][hx+1] == '.' ){ hx++; pts++; } else
			if( map1[hy][hx+1] == ' ' ) hx++;
		}

		if( old_x != hx || old_y != hy ){
			FindPath( ex,ey,hx,hy,g);
		}
}
if(g==3)
{


		if ( GetAsyncKeyState( VK_UP ) ){
			if( map2[hy-1][hx] == '.' ){ hy--; pts++; } else
			if( map2[hy-1][hx] == ' ' ) hy--;
		}
		if ( GetAsyncKeyState( VK_DOWN ) ){
			if( map2[hy+1][hx] == '.' ){ hy++; pts++; } else
			if( map2[hy+1][hx] == ' ' ) hy++;
		}
		if ( GetAsyncKeyState( VK_LEFT ) ){
			if( map2[hy][hx-1] == '.' ){ hx--; pts++; } else
			if( map2[hy][hx-1] == ' ' ) hx--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) ){
			if( map2[hy][hx+1] == '.' ){ hx++; pts++; } else
			if( map2[hy][hx+1] == ' ' ) hx++;
		}

		if( old_x != hx || old_y != hy ){
			FindPath( ex,ey,hx,hy,g);
		}
}

		gotoxy( hx,hy ); cout << "H";
if(g==1)
{
    map[e2y][e2x] = '.';
		gotoxy( e2x, e2y ); cout << ".";
		map[ey][ex] = '.';
		gotoxy( ex, ey ); cout << ".";
}
else if(g==2)
{
    map1[e2y][e2x] = '.';
		gotoxy( e2x, e2y ); cout << ".";
     map1[ey][ex] = '.';
		gotoxy( ex, ey ); cout << ".";
}
else if(g==3)
{
map2[e2y][e2x] = '.';
		gotoxy( e2x, e2y ); cout << ".";
    map2[ey][ex] = '.';
		gotoxy( ex, ey ); cout << ".";

}

        	if ( frame%speedmod == 0 && walk_queue2.size() != 0 ){
			e2x = walk_queue2.back().x2;
			e2y = walk_queue2.back().y2;
			walk_queue2.pop_back();
		}
		if( frame%speedmod == 0 && walk_queue.size() != 0 ){
			ex = walk_queue.back().x;
			ey = walk_queue.back().y;
			walk_queue.pop_back();
		}
	    gotoxy( e2x, e2y ); cout << "E";
		gotoxy( ex, ey ); cout << "E";

		if( e2x == hx && e2y == hy ){
			break;
		}
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


