#include"Omok.h"

/*
	�¸�							1
	�̹� ���� ������ ���� ��		-1
	33(���� ��쿡�� �ݼ�)			-2
	44(���� ��쿡�� �ݼ�)			-3
	���� �̻�(���� ��쿡�� �ݼ�)	-4
	���� ���� �� ���� ��			0
*/
int omok_algotirhm(char **board, coordinate piece) {
	char stone = piece.stone;
	char row = piece.row, col = piece.col;

	if (board[row][col] == EMPTY_STONE) {
		// �ݼ����� Ȯ��
		if (stone == BLACK) {
			
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