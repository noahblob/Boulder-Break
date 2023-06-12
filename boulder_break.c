/* ENGGEN131 C Project 2022 - Boulder Break */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define CAVE_SIZE 10

/***********************************************************/
/***********************************************************/
/******* ADD THE REQUIRED FUNCTIONS BELOW THIS POINT *******/
/***********************************************************/
/***********************************************************/

void InitialiseStory(char* paragraph)
{
	// The InitialiseStory function takes an empty input string called paragraph and 
	// assigns a string of characters onto the string, returning nothing
	// Author: Noah Hagar-Dent
	strcpy(paragraph, "Welcome to Boulder Break!\nA cowboy man has become stuck in a cave!\nYour job is to help him collect the treasure and escape!");
}

// Task Two: PrintCave
void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
	// The PrintCave function takes a 2D array "cave" or size CAVE_SIZE x CAVE_SIZE 
	// as input and prints out the 2D array onto the terminal
	// Author: Noah Hagar-Dent
	for (int i = 0; i < CAVE_SIZE; i++)
	{
		for (int j = 0; j < CAVE_SIZE; j++)
		{
			if (cave[i][j] == 1)
			{
				printf("#");
			}
			else if (cave[i][j] == 0)
			{
				printf(" ");
			}
			else if (cave[i][j] == 'E')
			{
				printf(" ");
			}
			else if (cave[i][j] == 'X')
			{
				printf("X");
			}
			else if (cave[i][j] == 'O')
			{
				printf("O");
			}
			else if (cave[i][j] == '*')
			{
				printf("*");
			}
			else if (cave[i][j] == '+')
			{
				printf("+");
			}
		}
		printf("\n");
	}
}

// Task Three: InitialiseCave
void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char *layout)
{
	// The InitialiseCave function takes a 2D array "cave" of CAVE_SIZE x CAVE_SIZE as input
	// as well as a 1D character array of 1's, 0's and E's and assigns the values
	// form the 1D layout array to the cave array
	// Author: Noah Hagar-Dent
	int index = 0;
	for (int i = 0; i < CAVE_SIZE; i++)
	{
		for (int j = 0; j < CAVE_SIZE; j++)
		{
			if (layout[index] == '1')
			{
				cave[i][j] = 1;
			}
			else if (layout[index] == '0')
			{
				cave[i][j] = 0;
			}
			else if (layout[index] == 'E')
			{
				cave[i][j] = 'E';
			}
			index++;
		}
	}
}

// As you work on the other tasks, remove the comments below
int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE])
{
	// The IsBorderComplete function takes a 2D array "cave" of CAVE_SIZE x CAVE_SIZE as input
	// and checks that each element of the outside border of the cave is an exit or a solid wall
	// Author: Noah Hagar-Dent
	int count1, count2;
	count1 = 0;
	count2 = 0;
	
	for (int j = 0; j < CAVE_SIZE; j++)
	{
		if (cave[0][j] == 0)
		{
			count1++;
		}
		if (cave[j][0] == 0)
		{
			count1++;
		}
		if (cave[CAVE_SIZE - 1][j] == 0)
		{
			count1++;
		}
		if (cave[j][CAVE_SIZE - 1] == 0)
		{
			count1++;
		}
	}

	for (int i = 0; i < CAVE_SIZE; i++)
	{
		if (cave[0][i] == 'E')
		{
			count2++;
		}
		if (cave[CAVE_SIZE - 1][i] == 'E')
		{
			count2++;
		}
	}

	for (int i = 1; i < CAVE_SIZE - 1; i++)
	{
		if (cave[i][0] == 'E')
		{
			count2++;
		}
		if (cave[i][CAVE_SIZE - 1] == 'E')
		{
			count2++;
		}
	}
	
	if (count1 > 0) {
		return 0;
	}
	return 1;
}

int IsExitUnique(int cave[CAVE_SIZE][CAVE_SIZE])
{
	// the IsExitUnqiue function takes a 2D array "cave" of CAVE_SIZE x CAVE_SIZE as input
	// and checks that there is only one unique exit position
	// in the cave, whether it is inside of the cave or on the border
	// Author: Noah Hagar-Dent
	int count = 0;
	for (int i = 0; i < CAVE_SIZE; i++)
	{
		for (int j = 0; j < CAVE_SIZE; j++)
		{
			if (cave[i][j] == 'E')
			{
				count++;
			}
		}
	}

	if (count == 1)
	{
		return 1;
	}
	return 0;
}

int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE])
{
	// The IsExitAccessible function takes a 2D array "cave" of CAVE_SIZE x CAVE_SIZE as input
	// and checks that the exit is not within the cave, and is not in
	// one of the four corners of the cave, hence accessible to the player
	// Author: Noah Hagar-Dent
	int count1 = 0;

	for (int i = 1; i < CAVE_SIZE - 1; i++)
	{
		if (cave[0][i] == 'E')
		{
			count1++;
		}
		if (cave[i][0] == 'E')
		{
			count1++;
		}
		if (cave[CAVE_SIZE - 1][i] == 'E')
		{
			count1++;
		}
		if (cave[i][CAVE_SIZE -1] == 'E')
		{
			count1++;
		}
	}
	
	if (count1 > 0) {
		return 1;
	}
	return 0;
}

void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char *element)
{
	// The AddItem function takes four inputs, a 2D array named "cave" of CAVE_SIZE x CAVE_SIZE,
	// an integer "row" and integer "col", which represent the row and column that the item will be added
	// and a character "element" which represents the type of item to be added. The function adds
	// the type of "element" into the 2D cave array
	// Author: Noah Hagar-Dent


	// One player displayed as X
	// Zero or more holes as *
	// Zero or more treasure as +
	// Zero or more boulders as O

	if (row < CAVE_SIZE && col < CAVE_SIZE && cave[row][col] == 0)
	{
		if (strcmp(element, "player") == 0)
		{
			cave[row][col] = 'X';
		}
		else if (strcmp(element, "hole") == 0)
		{
			cave[row][col] = '*'; 
		}
		else if (strcmp(element, "treasure") == 0)
		{
			cave[row][col] = '+'; 
		}
		else if (strcmp(element, "boulder") == 0)
		{
			cave[row][col] = 'O'; 
		}
	}

	// count the number of players in the cave
	int player = 0;
	for (int i = 0; i < CAVE_SIZE; i++)
	{
		for (int j = 0; j < CAVE_SIZE; j++)
		{
			if (cave[i][j] == 'X')
			{
				player++;
			}
		}
	}
	
	// if there is more than one, remove the extra player
	if (player > 1)
	{
		cave[row][col] = 0;
	}
}

void RotateCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
	// The function RotateCave takes a 2D array "cave" of CAVE_SIZE x CAVE_SIZE as input
	// It then rotates all the elements in the array clockwise by 90 degrees
	// Author: Noah Hagar-Dent
	int temp[CAVE_SIZE][CAVE_SIZE];

	for (int i = 0; i < CAVE_SIZE; i++)
	{
		for (int j = 0; j < CAVE_SIZE; j++)
		{
			temp[i][j] = cave[i][j];
		}
	}

	for (int i = 0; i < CAVE_SIZE; i++)
	{
		for (int j = 0; j < CAVE_SIZE; j++)
		{
			cave[j][CAVE_SIZE-(i+1)] = temp[i][j];
		}
	}
}

int MakeMove(int cave[CAVE_SIZE][CAVE_SIZE], char move)
{
	// The function MakeMove takes two inputs, a 2D array "cave" of CAVE_SIZE x CAVE_SIZE
	// and a character "move" which represents the direction the player in the cave will be moved
	// by characters "w" for up, "a" for left, "s" for down and "d" for right
	// The player will then be moved in that direction on the cave if there are no obstacles
	// in that direction
	// Author: Noah Hagar-Dent
	int x, y, dir, sit;

	if (move == 'w')
	{
		dir = 1;
	}
	else if (move == 'a')
	{
		RotateCave(cave);
		dir = 2;
	}
	else if (move == 's')
	{
		RotateCave(cave);
		RotateCave(cave);
		dir = 3;
	}
	else if (move == 'd')
	{
		RotateCave(cave);
		RotateCave(cave);
		RotateCave(cave);
		dir = 4;
	}

	// find the position of the character in row x, column y
	for (int i = 0; i < CAVE_SIZE; i++)
	{
		for (int j = 0; j < CAVE_SIZE; j++)
		{
			if (cave[i][j] == 'X')
			{
				x = i;
				y = j;
			}
		}
	}

	if (cave[x-1][y] == 0)
	{
		cave[x-1][y] = cave[x][y];
		cave[x][y] = 0;
		sit = 0;
	}
	else if (cave[x-1][y] == 'E')
	{
		cave[x-1][y] = cave[x][y];
		cave[x][y] = 0;
		sit = 2;
	}
	else if (cave[x-1][y] == '+')
	{
		cave[x-1][y] = cave[x][y];
		cave[x][y] = 0;
		sit = 0;
	}
	else if (cave[x-1][y] == '*')
	{
		cave[x][y] = 0;
		sit = 1;
	}
	else if (cave[x-1][y] == 'O')
	{
		int stop = 0;
		for (int z = x - 2; z >= 0 && !stop; z--)
		{
			if (cave[z][y] == 1 || cave[z][y] == '+' || cave[z][y] == 'O')
			{
				cave[x - 1][y] = cave[z + 1][y];
				cave[z + 1][y] = 'O';
				stop = 1;
			}
			else if (cave[z][y] == '*')
			{
				cave[z][y] = 0;
				cave[x - 1][y] = 0;
				stop = 1;
			}
		}
		sit = 0;
	}

	if (dir == 2)
	{
		RotateCave(cave);
		RotateCave(cave);
		RotateCave(cave);
	}
	else if (dir == 3)
	{
		RotateCave(cave);
		RotateCave(cave);
	}
	else if (dir == 4)
	{
		RotateCave(cave);
	}

	return sit;
}

/***********************************************************/
/***********************************************************/
/********* DO NOT MODIFY ANY CODE BELOW THIS POINT *********/
/***********************************************************/
/***********************************************************/

/* GetMove() returns the entered character. Invalid characters ignored */
char GetMove(void)
{
	char move;
	printf("\nEnter move: ");
	scanf("%c", &move);
	// Ignore any characters that are invalid
	while ((move != 'w') && (move != 'a') && (move != 's') && (move != 'd')) {
		scanf("%c", &move);
	}
	return move;
}

/* The Boulder Break simulation */
int main(void)
{
	int gameOver = 0;
	char story[2000];
	char layout[200] = "1111111111100000000110000000011000000001100000000E10000000011000000001100000000110000000011111111111"; 
  int cave[CAVE_SIZE][CAVE_SIZE] = {0}; 
 
  	InitialiseCave(cave, layout); 
 
  	AddItem(cave, 7, 3, "player"); 
 
  	AddItem(cave, 2, 1, "boulder"); 
  	AddItem(cave, 2, 3, "boulder"); 
  	AddItem(cave, 4, 6, "boulder"); 
  	AddItem(cave, 5, 7, "boulder"); 
  	AddItem(cave, 6, 8, "boulder"); 
 
  	AddItem(cave, 7, 1, "hole"); 
  	AddItem(cave, 8, 3, "hole"); 
 
  	AddItem(cave, 6, 4, "treasure"); 
  	AddItem(cave, 3, 5, "treasure"); 
  	AddItem(cave, 1, 1, "treasure"); 
  

	printf("ENGGEN131 - C Project 2022\n");
	printf("                          ... presents ...\n");
	printf("______   _____  _     _        ______  _______  ______\n");
	printf("|_____] |     | |     | |      |     \\ |______ |_____/\n");
	printf("|_____] |_____| |_____| |_____ |_____/ |______ |    \\_\n");
	printf("______   ______ _______ _______ _     _\n");
	printf("|_____] |_____/ |______ |_____| |____/ \n");
	printf("|_____] |    \\_ |______ |     | |    \\_\n");
	printf("\n");
	printf("%s\n", story);
	printf("\nMove the player (X) using the keys 'w', 'a', 's', 'd'\n");
	printf("Good luck!\n\n\n");

	/* Main game loop */
	PrintCave(cave);
	while (!gameOver) {
		gameOver = MakeMove(cave, GetMove());
		PrintCave(cave);
		if (gameOver == 1) {
			printf("\n\nGAME OVER!! \nYou died!\n\n");
		} else if (gameOver == 2) {
			printf("\n\nCONGRATULATIONS!! \nYou escaped!\n\n");
		}
	}

	return 0;
}