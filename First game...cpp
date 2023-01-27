#include <stdio.h>
#include <conio.h>
#include <string.h>

#include "windows.h" //this code is to make gotoxy and system("cls") works.
//system("cls");

void gotoxy(int x, int y) 
{ 
    COORD coord;
    coord.X = x; 
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{	//all level
	char player = '@';
	char block = '#';
	
	level1:
	int level = 1;
	char input;
	int playerX = 11;
	int playerY = 6;
	int speed = 1;
	int Lvl1_X[] = {8,9,10,11,12,13,14,15,16,17,17,17,17,17,17,17,17,16,15,14,13,12,11,10, 9, 8, 8, 8, 8, 8, 8, 8};
	int Lvl1_Y[] = {4,4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 6, 7, 8, 9,10,10,10,10,10,10,10,10,10,10,10, 9, 8, 7, 6, 5};
	int Lvl1_obj = sizeof( Lvl1_X ) / sizeof( Lvl1_X[0] ) - 1 ; //How many blocks?
	int goalX = 16;
	int goalY = 9;

	
	start:
	int blocknum;
		for ( blocknum = 0 ; blocknum <= Lvl1_obj ; ++blocknum)
		{
			gotoxy( Lvl1_X[blocknum] , Lvl1_Y[blocknum] ) ; printf("%c", block);
		}
	
	gotoxy(playerX,playerY);printf("%c",player);
	gotoxy(goalX,goalY);printf("P");
	
	//Player Control
		gotoxy(0,20);printf("Input W,A,S,D: ");
		scanf("%c", &input);
		while( input != 'e' )
		{
			if( input == 'w' )
			{ 
				playerY -= speed;
				gotoxy(playerX,playerY);printf("%c", player);
				gotoxy(playerX,playerY+speed);printf(" ");	
				for ( blocknum = 0 ; blocknum <= Lvl1_obj ; ++blocknum)
				{
					if ( playerX == Lvl1_X[blocknum] && playerY == Lvl1_Y[blocknum] )
					{
						playerY += speed;
						gotoxy(playerX,playerY);printf("%c", player);
					}
				}
			}
			else if( input == 'a' )
			{ 
				playerX -= speed;
				gotoxy(playerX,playerY);printf("%c", player); 
				gotoxy(playerX+speed,playerY);printf(" ");
				for ( blocknum = 0 ; blocknum <= Lvl1_obj ; ++blocknum)
				{
					if ( playerX == Lvl1_X[blocknum] && playerY == Lvl1_Y[blocknum] )
					{
						playerX += speed;
						gotoxy(playerX,playerY);printf("%c", player);
					}
				}
			}
			else if( input == 's' )
			{ 
				playerY += speed;
				gotoxy(playerX,playerY);printf("%c", player);
				gotoxy(playerX,playerY-speed);printf(" ");
				for ( blocknum = 0 ; blocknum <= Lvl1_obj ; ++blocknum)
				{
					if ( playerX == Lvl1_X[blocknum] && playerY == Lvl1_Y[blocknum] )
					{
						playerY -= speed;
						gotoxy(playerX,playerY);printf("%c", player);
					}
				}
			}
			else if( input == 'd' )
			{ 
				playerX += speed;
				gotoxy(playerX,playerY);printf("%c", player);
				gotoxy(playerX-speed,playerY);printf(" ");
				for ( blocknum = 0 ; blocknum <= Lvl1_obj ; ++blocknum)
				{
					if ( playerX == Lvl1_X[blocknum] && playerY == Lvl1_Y[blocknum] )
					{
						playerX -= speed;
						gotoxy(playerX,playerY);printf("%c", player);
					}
				}
			}
			if ( playerX == goalX && playerY == goalY)
			{
				system("cls");
				gotoxy(2,2);printf("Level %d complete!",level);
				gotoxy(2,4);printf("Nice! you beat the Level!\n\n ");
				return 0;
			}	
			goto start;
		}
}
