#include<Windows.h>

// 좌표 이동
void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 텍스트 색 설정
void TC(int back, int font)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back * 16 + font);
}