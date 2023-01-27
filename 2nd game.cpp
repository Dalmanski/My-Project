#include <stdio.h>
#include <conio.h>   // This header is to make clrscr(); works but clrscr(); only works in android c compilier.
#include <stdlib.h>  // This header is to make rand() % num works.
#include <string.h>  // This header is to work strlen (Identifiy the length of the string) and strcpy (copy from var1 to var2)
#include <stdbool.h> // This header is to make bolean (True or False) works.
#include <ctype.h>   // This header is to make the letter capital or not toupper(var_name), and it detect if it's capital or not isupper(var_name).
#include "windows.h" // This header is to make system("cls"); works. system("cls") clears all the screen. Only works in windows pc.

int main()
{
	char word[100] , hid_word[100] , hintfix[100] ;                         // Variables.
	char letter[] = "abcdefghijklmnopqrstuvwxyz";
	char readletter , input , mode , wrong_letter[100]  ;   
	int read , length_word ;
	int level = 1 , text1by1 = 0 , life = 3 ;
	bool win , check , check2 ;

	printf("\n\tGUESS THE WORD!\n");
	printf("\n\tMade by Dalmanski.\n");
	printf("\n\tInput any key to continue: ");
	char enter;
	scanf("%d", &enter);
	fflush(stdin);                                      //This code is to refresh the scan variables.
	
	next:     
	int wrong_letter_num = 0 ;  
	for ( wrong_letter_num = 0 ; wrong_letter_num <= 100 ; wrong_letter_num++ )
	{ wrong_letter[wrong_letter_num] = ' ' ; }  
	wrong_letter_num = 0 ;        
	                        
	if ( level == 1 )
	{
		char word_show[] = "may the force be with you." ;
		strcpy( word , word_show );
		char hint[] = "Quote from Star Wars." ;
		strcpy( hintfix , hint ); 
	}
	else if ( level == 2 )
	{
		char word_show[] = "jesus wept." ;
		strcpy( word , word_show );
		char hint[] = "Shortest verse in John 11:35." ;
		strcpy( hintfix , hint ); 
	}
	else if ( level == 3 )
	{
		char word_show[] = "the strongest, and the loneliest." ;
		strcpy( word , word_show ); 
		char hint[] = "Line from Hanzo (Mobile Legends)." ;
		strcpy( hintfix , hint );
	}
	else if ( level == 4 ) 
	{
		char word_show[] = "were not just telling stories, were changing lives." ;
		strcpy( word , word_show );
		char hint[] = "Line from Dhar Mann." ;
		strcpy( hintfix , hint );       
	}
	else if ( level == 5 ) 
	{
		char word_show[] = "do not judge a book by its cover." ;
		strcpy( word , word_show );
		char hint[] = "Line from George Eliot." ;
		strcpy( hintfix , hint );       
	}
	else if ( level == 6 )
	{
		char word_show[] = "the process or activity of writing computer programs." ;
		strcpy( word , word_show ); 
		char hint[] = "What is programming?" ;
		strcpy( hintfix , hint );
	}
	else if ( level == 7 )
	{
		char word_show[] = "if you do not take risks, you can not create a future." ;
		strcpy( word , word_show );
		char hint[] = "Line from Monkey D. Luffy (One Piece)." ;
		strcpy( hintfix , hint ); 
	}
	else if ( level == 8 )
	{
		char word_show[] = "life is like riding a bicycle. to keep your balance, you must keep moving." ;
		strcpy( word , word_show ); 
		char hint[] = "Famous Quote by Albert Einstein." ;
		strcpy( hintfix , hint );
	}
	else if ( level == 9 )
	{
		char word_show[] = "is a tool used by engineers to determine such quantities as rates of change and areas" ;
		strcpy( word , word_show ); 
		char hint[] = "What's the purpose of Calculus?" ;
		strcpy( hintfix , hint );
	}
	else if ( level == 10 )
	{
		char word_show[] = "because challenges and failures are part of life." ;
		strcpy( word , word_show ); 
		char hint[] = "This is the last level, why did you not give up solving this?" ;
		strcpy( hintfix , hint );
	}
	else if ( level >= 11 )
	{
		printf("\n\n\n\tOmg! You beat all 10 levels. Your unbelievable! \n\n");
		return 0;
	}
	length_word = strlen(word);                          // Find a length of a string.
	strcpy( hid_word, word );                            // Copy from variable 1 string to variable 2 string.
	for ( read = 0 ; read < length_word ; read++ )       // Read a letter one by one and convert it to underline, space and period.
	{ 
		if ( word[read] != ' ' && word[read] != '.' && word[read] != ',' )
		{ hid_word[read] = '_'; }
		else if ( word[read] == ' ' )
		{ hid_word[read] = ' '; }
		else if ( word[read] == '.' )
		{ hid_word[read] = '.'; }
		else if ( word[read] == ',' )
		{ hid_word[read] = ','; }
	}
	int repeat = 0;
	while ( repeat < 5 )
	{
	 	int rand_num = (rand() % 25);                             // This code is for random numbers.
		for ( read = 0 ; read < length_word ; read++ )
	 	{
			if ( letter[rand_num] == word[read] )
			{  
				hid_word[read] = letter[rand_num]; 
				++repeat;
			}	
	 	}
	}
	system("cls");
	
	printf("\n\tGuess the word. \t Level: %d/10   Life: %d\n", level, life);   // Start of a program.
	
	start:                                                   // This part will repeat until you win.
	check = false;
	check2 = false;
	win = true;
		if (isupper(input))                                           // Detect if it's capital letter.
		{ printf("\n\tBtw, we don't accept capital letter. \n" );  }
	printf("\n\n\t %s",hid_word);
	printf("\n\n\n\tHint: %s",hintfix);
	printf("\n\n\n\tWrong letter/input: %s",wrong_letter);
	printf("\n\n\tInput your letter: ");
	scanf("%c", &input);
	 for ( read = 0 ; read < length_word ; read++ )
	 {
		if ( input == word[read] )
		{
			if ( input == hid_word[read] )
				{ check2 = true ; }
			system("cls");
			hid_word[read] = input;
			printf("\n\t\t%s",hid_word);
			check = true ;
		}
		else if ( hid_word[read] == '_' )
		{ win = false; }
	 }
	system("cls");
	if ( win == true )
	{
		printf("\n\tGuess the word. \t Level: %d/10   Life: %d\n", level, life);
		printf("\n\n\t %s",hid_word);
		printf("\n\n\n\tCongrats you solve it! ");
			if (life < 3)
			{ life = 3; }
			else
			{ ++life; }
		printf("\n\tInput any key to continue: ");
		++level;
		char enter;
		scanf("%d", &enter);
			fflush(stdin);                                      // This code is to refresh the scan variables.
			system("cls");
			goto next; 	                                        // This code is to go back to "next:".
	}
	else if ( win == false )
	{
			if ( check == false )
			{ --life; }
		printf("\n\tGuess the word. \t Level: %d/10   Life: %d\n", level, life);
			if ( check == true )
			{ 
				if ( check2 != true )
				{
					++text1by1;
					if ( text1by1 == 1 )
					{ printf("\n\tNice!\n ");  }
					else if ( text1by1 == 2 )
					{ printf("\n\tCorrect!\n ");  }
					else if ( text1by1 == 3 )
					{ printf("\n\tGood guess...\n ");  }
					else if ( text1by1 == 4 )
					{ printf("\n\tLetter %c is a good choice! \n ", input );  }
					else
					{ 
					printf("\n\tCool!\n");
					text1by1 = 0 ;  
					}
				}
				else if ( check2 == true )
				{
					if ( input != ' ' && input != '.' && input != ',' )
					{
						++text1by1;
						if ( text1by1 == 1 )
						{ printf("\n\tUmm... letter %c is done...\n ", input );  }
						else if ( text1by1 == 2 )
						{ printf("\n\tI think you repeated the letter...\n ");  }
						else if ( text1by1 == 3 )
						{ printf("\n\tFind another letter...\n ");  }
						else if ( text1by1 == 4 )
						{ printf("\n\tEh? Why you repeated this letter %c? \n", input );  }
						else
						{ 
						printf("\n\tYou forgot that you done choosing this letter.\n");
						text1by1 = 0 ;  
						}
					}
					else if ( input == ' ' )
					{ printf("\n\tBro, why you put spacebar?\n ");  }
					else if ( input == '.' )
					{ printf("\n\tHuh? What did you do with this period?\n ");  }
					else if ( input == ',' )
					{ printf("\n\tComma is not a letter lol.\n ");  }	
				}
		}
			else if ( check == false )
			{ 
				if ( life > 3 )
				{ printf("\n\tWrong but bro you got more than 3 life. Lucky!\n" );  }
				else if ( life == 3 )
				{ printf("\n\tWrong but It's fine since you add 1 life before.\n" );  }
				else if ( life == 2 )
				{ printf("\n\tOoops wrong... minus 1 life.\n ");  }
				else if ( life == 1 )
				{ printf("\n\tWrong! You have 1 life left...\n ");  }
				else if ( life == 0 )
				{ 
					printf("\n\tGame over! Better luck next time!\n "); 
					printf("\n\tYou beat %d levels.\n ", level-1); 
					return 0;                                               // The game ends when Game Over!
				}
				wrong_letter[wrong_letter_num] = input;	
				wrong_letter_num++;
			}		
		fflush(stdin);                                          // This code is to refresh the scan variables.
		goto start;                                             // This code is to go back to "start:".
	}
}
