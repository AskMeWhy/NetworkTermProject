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

	if (board[x][y] == EMPTY_STONE) {
		return 0;
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