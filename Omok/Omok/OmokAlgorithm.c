#include"Omok.h"

/*
	�¸�							1
	�̹� ���� ������ ���� ��		-1
	33(���� ��쿡�� �ݼ�)			-2
	44(���� ��쿡�� �ݼ�)			-3
	���� �̻�(���� ��쿡�� �ݼ�)	-4
	���� ���� �� ���� ��			0
*/
int omok_algotirhm(char board[][BOARD_SIZE], coordinate stone) {
	char color = stone.color;
	char x = stone.x, y = stone.y;
	char up, rightup, right, rightdown, down, leftdown, left, leftup;

	if (board[x][y] == EMPTY_STONE) {
		surrounding_stone(board, stone, &up, &rightup, &right, &rightdown, &down, &leftdown, &left, &leftup);

		
		// �ݼ����� Ȯ��
		if (color == BLACK_STONE) {
			
		}
		else {
			// �¸����� Ȯ��
			if (1)
				return 1;
			else
				return 0;
		}
	}
	else {
		// ���� ���� ���� ��
		return -1;
	}
}

// �ֺ� ���� ����
void surrounding_stone(char board[][BOARD_SIZE], coordinate stone, char *up, char *rightup, char *right, char *rightdown, char *down, char *leftdown, char *left, char *leftup) {
	*up = 0;
	*rightup = 0;
	*right = 0;
	*rightdown = 0;
	*down = 0;
	*leftdown = 0;
	*left = 0;
	*leftup = 0;

	
}