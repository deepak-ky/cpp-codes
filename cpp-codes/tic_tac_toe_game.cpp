#include <iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
char square[9] = {'0','1','2','3','4','5','6','7','8'};
int checkwin()
{
		if (square[0] == square [1]  && square[1] == square[2] )
		{	if ( square [0] == 'X' )
			return 1;
			else
			return 2;
		}
		else
		if (square[3] == square [4]  && square[4] == square[5] )
			{	if ( square [3] == 'X' )
			return 1;
			else
			return 2;
		}
		else
		if (square[6] == square [7]  && square[7] == square[8] )
			{	if ( square [6] == 'X' )
			return 1;
			else
			return 2;
		}
		else
		if (square[0] == square [3]  && square[3] == square[6] )
			{	if ( square [0] == 'X' )
			return 1;
			else
			return 2;
		}
		else
		if (square[1] == square [4]  && square[4] == square[7] )
			{	if ( square [1] == 'X' )
			return 1;
			else
			return 2;
		}
	else
		if (square[2] == square [5]  && square[5] == square[8] )
			{	if ( square [2] == 'X' )
			return 1;
			else
			return 2;
		}
else
		if (square[0] == square [4]  && square[4] == square[8] )
			{	if ( square [0] == 'X' )
			return 1;
			else
			return 2;
		}
	else
		if (square[2] == square [4]  && square[4] == square[6] )
			{	if ( square [2] == 'X' )
			return 1;
			else
			return 2;
		}
	else
		if (square[0] == square [3]  && square[3] == square[6] )
			{	if ( square [0] == 'X' )
			return 1;
			else
			return 2;
		}
	else
		return 0;
}

void mark(int player, int box)
{
	if (player == 1 )
	{

		square[box] = 'X';
	}
	else
		square[box] = 'O';
}

void display()
{

                     cout<<"                                                         |     |       ";
                     cout<<endl;
                     cout<<"                                                      "<<square[0]<<"  |  "<<square[1]<<"  |  "<<square[2];
                     cout<<endl;
                     cout<<"                                                         |     |       ";
                     cout<<endl;
                     cout<<"                                                    -----------------";
                     cout<<endl;
                      cout<<"                                                         |     |       ";
                     cout<<endl;
                     cout<<"                                                      "<<square[3]<<"  |  "<<square[4]<<"  |  "<<square[5];
                     cout<<endl;
                     cout<<"                                                         |     |       ";
                     cout<<endl;
                     cout<<"                                                    -----------------";
                     cout<<endl;
                      cout<<"                                                         |     |       ";
                     cout<<endl;
                     cout<<"                                                      "<<square[6]<<"  |  "<<square[7]<<"  |  "<<square[8];
                     cout<<endl;
                     cout<<"                                                         |     |       ";
                     cout<<endl;
                     cout<<endl;



}
int main()
{
        cout<<endl<<endl<<endl<<endl<<endl;
        cout<<"                                                Welcome To TIC TAC TOE ";
        cout<<endl<<endl;
        cout<<"                                                Symbol for Player 1 : "<<"X";cout<<endl;
        cout<<"                                                Symbol for Player 2 : "<<"O";
        cout<<endl<<endl;
        display();


		int player1 = 1, player2 =2 ;

		int box, result = 0, flag = 0;

		for(int i=1;i<5;i++)
	{
        cout<<endl;
        label:


		cout<< "\n                                            Player 1 Mark Your Move : ";
		cin >> box;
		if(square[box] == 'X' || square[box] == 'O')
        {
            cout<<"\n                                                     INVALID MOVE!!!";
            cout<<endl<<"                                                 Player 1 Try AGAIN!!\n";
            goto label;
        }
		mark( player1, box);
		system("cls");
		display();

		result =checkwin();
		if (result == 1 )
		{	cout<<"\n Congratualtions! Player " << player1 << " has Won ";
			flag = 1;
			break;
		}
		else
		if (result == 2 )
		{	cout<<"\n Congratualtions! Player " << player2 << " has Won ";
			flag = 1;
			break;
		}
        cout<<endl;
        label1:
        cout<< "\n                                            Player 2 Mark Your Move : ";
		cin>> box;
		if(square[box] == 'X' || square[box] == 'O')
        {
            cout<<"\n                                                     INVALID MOVE!!!";
            cout<<endl<<"                                                 Player 2 Try AGAIN!!\n";
            goto label1;
        }
		mark ( player2, box);
		system("cls");
		display();

		result =checkwin();
		if (result == 1 )
		{	cout<<"\n Congratualtions! Player " << player1 << " has Won ";
			flag = 1;
			break;
		}
		else
		if (result == 2 )
		{	cout<<"\n Congratualtions! Player " << player2 << " has Won ";
			flag = 1;
			break;
		}
}
		if (flag == 0 )
		cout<<" \n Sorry, The game is a draw ";

	return 0;
}
