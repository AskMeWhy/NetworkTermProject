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
			switch (forbidden_rule(up, rightup, right, rightdown, down, leftdown, left, leftup)) {
			case 0:
				return iswin(color, up, rightup, right, rightdown, down, leftdown, left, leftup);
			case -2:
				return -2;
			case -3:
				return -3;
			case -4:
				return -4;
			}
		}
		else
			return iswin(color, up, rightup, right, rightdown, down, leftdown, left, leftup);
	}
	else {
		// ���� ���� ���� ��
		return -1;
	}
}

// �ֺ� ���� ����
void surrounding_stone(char board[][BOARD_SIZE], coordinate stone, char *up, char *rightup, char *right, char *rightdown, char *down, char *leftdown, char *left, char *leftup) {
	char stone_x, stone_y;
	
	*up = 0;
	*rightup = 0;
	*right = 0;
	*rightdown = 0;
	*down = 0;
	*leftdown = 0;
	*left = 0;
	*leftup = 0;

	// up
	stone_x = stone.x;
	stone_y = stone.y;
	while (--stone_y >= 0) {
		if (board[stone_x][stone_y] == stone.color)
			(*up)++;
		else
			break;
	}
	
	// right up
	stone_x = stone.x;
	stone_y = stone.y;
	while (++stone_x < BOARD_SIZE && --stone_y >= 0) {
		if (board[stone_x][stone_y] == stone.color)
			(*rightup)++;
		else
			break;
	}

	// right
	stone_x = stone.x;
	stone_y = stone.y;
	while (++stone_x < BOARD_SIZE) {
		if (board[stone_x][stone_y] == stone.color)
			(*right)++;
		else
			break;
	}

	// right down
	stone_x = stone.x;
	stone_y = stone.y;
	while (++stone_x < BOARD_SIZE && ++stone_y < BOARD_SIZE) {
		if (board[stone_x][stone_y] == stone.color)
			(*rightdown)++;
		else
			break;
	}

	// down
	stone_x = stone.x;
	stone_y = stone.y;
	while (++stone_y < BOARD_SIZE) {
		if (board[stone_x][stone_y] == stone.color)
			(*down)++;
		else
			break;
	}

	// left down
	stone_x = stone.x;
	stone_y = stone.y;
	while (--stone_x >= 0 && ++stone_y < BOARD_SIZE) {
		if (board[stone_x][stone_y] == stone.color)
			(*leftdown)++;
		else
			break;
	}

	// left
	stone_x = stone.x;
	stone_y = stone.y;
	while (--stone_x >= 0) {
		if (board[stone_x][stone_y] == stone.color)
			(*left)++;
		else
			break;
	}

	// left up
	stone_x = stone.x;
	stone_y = stone.y;
	while (--stone_x >= 0 && --stone_y >= 0) {
		if (board[stone_x][stone_y] == stone.color)
			(*leftup)++;
		else
			break;
	}
}

// �ݼ�
// ���� ����
int forbidden_rule(char up, char rightup, char right, char rightdown, char down, char leftdown, char left, char leftup) {
	return 0;
}

// �¸����� Ȯ��
int iswin(char color, char up, char rightup, char right, char rightdown, char down, char leftdown, char left, char leftup) {
	if (color == BLACK_STONE) {
		if (up + down == 4 || rightup + leftdown == 4 || right + left == 4 || rightdown + leftup == 4)
			return 1;
		else
			return 0;
	}
	else {
		if (up + down >= 4 || rightup + leftdown >= 4 || right + left >= 4 || rightdown + leftup >= 4)
			return 1;
		else
			return 0;
	}
}