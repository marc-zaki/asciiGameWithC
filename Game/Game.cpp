#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
void Empty(char game[][120]) {
	for (int r = 0; r < 30; r++)
	{
		for (int c = 0; c < 120; c++)
		{
			game[r][c] = ' ';
		}
	}
}
void drawPlatform(char platform[][120], int platformR, int platformC) {
	for (int i = 0; i < 100; i++)
	{
		platform[platformR][platformC + i] = '=';

	}
}
void drawGame(char game[][120]) {
	system("cls");
	for (int r = 0; r < 30; r++)
	{
		for (int c = 0; c < 120; c++)
		{
			cout << game[r][c];
		}
	}
}
void drawHero(char game[][120], int& rhero, int& chero) {
	game[rhero - 3][chero + 4] = '@';
	game[rhero - 2][chero + 2] = '/';
	game[rhero - 2][chero + 3] = '|';
	game[rhero - 2][chero + 4] = ':';
	game[rhero - 2][chero + 5] = '|';
	game[rhero - 2][chero + 6] = '\\';
	game[rhero - 1][chero + 2] = '_';
	game[rhero - 1][chero + 3] = '/';
	game[rhero - 1][chero + 5] = '\\';
	game[rhero - 1][chero + 6] = '_';
}
void moveHero(int &rhero, int &chero, char move, char game[][120]) 
{
	if (move == 'w')
	{
		rhero-=2;
	}
	if (move == 'a')
	{
		chero--;
	}
	if (move == 's' && game[rhero][chero] != '=')
	{
		rhero++;
	}
	if (move == 'd')
	{
		chero++;
	}
}
void gravity(char game[][120], int& rHero, int&cHero) {
	if (game[rHero][cHero] == ' ')
	{
		rHero++;
	}
}
void main() {
	char game[30][120];
	int rhero = 24, chero = 5, platformR = 27, platformC = 2;
	char move=NULL;
	while(1) {
		while (!_kbhit()) 
		{
			Empty(game);
			drawPlatform(game, platformR, platformC);
			gravity(game, rhero, chero);
			drawHero(game, rhero, chero);
			drawGame(game);
			Sleep(100);
		}
		move = _getch();
		moveHero(rhero, chero, move, game);
	}
	cout << "Hello World!";
	cout << "good job!";
}