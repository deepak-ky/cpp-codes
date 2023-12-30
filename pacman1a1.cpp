#include <cstdlib>              // Header Files
#include<conio.h>               // for getch() function
#include <iostream>
#include<windows.h>             // Necessary when treating consoles
using namespace std;
void gotoxy (int x, int y)
    {
         COORD coordinates;     // coordinates is declared as COORD
         coordinates.X = x;     // defining x-axis
         coordinates.Y = y;     //defining  y-axis
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
    }
int main()
{
    int x;
    int y;

    cout<<"Enter x: ";
    cin>>x;
    cout<<"Enter y: ";
    cin>>y;

    gotoxy(x,y);     // function call
    cout<<"C++ Clan Umair Sajid"<<endl;
    getch();
    return EXIT_SUCCESS;
}
