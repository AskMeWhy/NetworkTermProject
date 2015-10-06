#include<stdio.h>
#include<conio.h>
#include"Omok.h"

void omok_playing(char board[][BOARD_SIZE], coordinate *stone) {
	int isstone = -1;
	char key;

	gotoxy((*stone).x * 2, (*stone).y);
	while (isstone != 0 && isstone != 1) {
		if (_kbhit()) {
			key = _getch();
			switch (key) {
			case RIGHT_KEY:
				if ((*stone).x + 1 < BOARD_SIZE) {
					(*stone).x += 1;
					gotoxy((*stone).x * 2, (*stone).y);
				}
				break;
			case LEFT_KEY:
				if ((*stone).x - 1 >= 0) {
					(*stone).x -= 1;
					gotoxy((*stone).x * 2, (*stone).y);
				}
				break;
			case DOWN_KEY:
				if ((*stone).y + 1 < BOARD_SIZE) {
					(*stone).y += 1;
					gotoxy((*stone).x * 2, (*stone).y);
				}
				break;
			case UP_KEY:
				if ((*stone).y - 1 >= 0) {
					(*stone).y -= 1;
					gotoxy((*stone).x * 2, (*stone).y);
				}
				break;
			case SPACEBAR_KEY:
				isstone = omok_algotirhm(board, *stone);
				break;
			}
		}
	}

	board[(*stone).x][(*stone).y] = (*stone).color;

	if ((*stone).color == BLACK_STONE) {
		TC(D_YELLOW, BLACK);
		printf("¡Ü");
		TC(BLACK, WHITE);
	}
	else {
		TC(D_YELLOW, WHITE);
		printf("¡Ü");
		TC(BLACK, WHITE);
	}

	// ½Â¸® ÇßÀ» ¶§
	if (isstone == 1) {
		gotoxy(0, BOARD_SIZE + 1);
		printf("Black Stone Win!\n");
		printf("Retry? (y/n)");
		while (1) {
			key = _getch();
			if (key == 'y' || key == 'Y') {
				omok_init(board, stone);
				omok_playing(board, stone);
				break;
			}
			else if (key == 'n' || key == 'N')
				exit(0);
		}
	}
}