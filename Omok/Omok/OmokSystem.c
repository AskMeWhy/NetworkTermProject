#include<Windows.h>

// ��ǥ �̵�
void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// �ؽ�Ʈ �� ����
void TC(int back, int font)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back * 16 + font);
}