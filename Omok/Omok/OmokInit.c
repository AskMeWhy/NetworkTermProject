#include<stdio.h>
#include<stdlib.h>
#include"Omok.h"

void omok_opening(char *nickname) {
	puts("");
	puts("�������������������ââââââ�");
	puts("�����ââââá����á�����������");
	puts("���á����������á��ââââââ�");
	puts("���á����������á���������");
	puts("�����ââââá����ââââââ�");
	puts("����������");
	puts("���ââââââá��ââââââ�");
	puts("��������������������������������");
	puts("");
	printf("Nickname: ");
	scanf("%s", nickname);
}

void omok_init(char board[][BOARD_SIZE], coordinate *stone) {
	int i, j;

	system("cls");
	// �ٵ��� �׸���
	TC(D_YELLOW, BLACK);
	printf("��");
	for (i = 0; i < BOARD_SIZE - 2; i++) {
		printf("��");
	}
	printf("��\n");
	for (i = 0; i < BOARD_SIZE - 2; i++) {
		printf("��");
		for (j = 0; j < BOARD_SIZE - 2; j++) {
			printf("��");
		}
		printf("��\n");
	}
	printf("��");
	for (i = 0; i < BOARD_SIZE - 2; i++) {
		printf("��");
	}
	printf("��\n");
	TC(BLACK, WHITE);

	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++) {
			board[i][j] = EMPTY_STONE;
		}
	}

	(*stone).x = BOARD_SIZE / 2;
	(*stone).y = BOARD_SIZE / 2;
}