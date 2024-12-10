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
void main() {
	char game[30][120];
	int rhero = 24, chero = 5;
	while(1) {
		while (!_kbhit()) 
		{
			Empty(game);
			drawHero(game, rhero, chero);
			drawGame(game);
			Sleep(100);
		}
	}
}