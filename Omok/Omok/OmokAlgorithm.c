#include"Omok.h"

/*
	승리							1
	이미 돌이 놓여져 있을 때		-1
	33(흑의 경우에만 금수)			-2
	44(흑의 경우에만 금수)			-3
	육목 이상(흑의 경우에만 금수)	-4
	돌을 놓을 수 있을 때			0
*/
int omok_algotirhm(char board[][BOARD_SIZE], coordinate stone) {
	char color = stone.color;
	char x = stone.x, y = stone.y;

	if (board[x][y] == EMPTY_STONE) {
		return 0;
		// 금수인지 확인
		if (color == BLACK_STONE) {
			
		}
		else {
			// 승리인지 확인
			if (1)
				return 1;
			else
				return 0;
		}
	}
	else {
		// 돌이 놓여 있을 때
		return -1;
	}
}