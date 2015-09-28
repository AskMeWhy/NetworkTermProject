#include<stdio.h>
#include<stdlib.h>
#include"Omok.h"

void omok_opening(char *nickname) {
	puts("");
	puts("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¢Ã¢Ã¢Ã¢Ã¢Ã¢Ã¢Ã");
	puts("¡¡¡¡¢Ã¢Ã¢Ã¢Ã¢Ã¡¡¡¡¢Ã¡¡¡¡¡¡¡¡¡¡¢Ã");
	puts("¡¡¢Ã¡¡¡¡¡¡¡¡¡¡¢Ã¡¡¢Ã¢Ã¢Ã¢Ã¢Ã¢Ã¢Ã");
	puts("¡¡¢Ã¡¡¡¡¡¡¡¡¡¡¢Ã¡¡¡¡¡¡¡¡¢Ã");
	puts("¡¡¡¡¢Ã¢Ã¢Ã¢Ã¢Ã¡¡¡¡¢Ã¢Ã¢Ã¢Ã¢Ã¢Ã¢Ã");
	puts("¡¡¡¡¡¡¡¡¢Ã");
	puts("¡¡¢Ã¢Ã¢Ã¢Ã¢Ã¢Ã¢Ã¡¡¢Ã¢Ã¢Ã¢Ã¢Ã¢Ã¢Ã");
	puts("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¢Ã");
	puts("");
	printf("Nickname: ");
	scanf("%s", nickname);
}

void omok_init(char board[][BOARD_SIZE], coordinate *stone) {
	int i, j;

	system("cls");
	// ¹ÙµÏÆÇ ±×¸®±â
	TC(D_YELLOW, BLACK);
	printf("¦£");
	for (i = 0; i < BOARD_SIZE - 2; i++) {
		printf("¦¨");
	}
	printf("¦¤\n");
	for (i = 0; i < BOARD_SIZE - 2; i++) {
		printf("¦§");
		for (j = 0; j < BOARD_SIZE - 2; j++) {
			printf("¦«");
		}
		printf("¦©\n");
	}
	printf("¦¦");
	for (i = 0; i < BOARD_SIZE - 2; i++) {
		printf("¦ª");
	}
	printf("¦¥\n");
	TC(BLACK, WHITE);

	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++) {
			board[i][j] = EMPTY_STONE;
		}
	}

	(*stone).x = BOARD_SIZE / 2;
	(*stone).y = BOARD_SIZE / 2;
}