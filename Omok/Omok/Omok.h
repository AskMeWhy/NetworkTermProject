#include<WinSock2.h>
#include<Windows.h>

// 바둑판의 크기
#define BOARD_SIZE	15
// 바둑판의 상태
#define EMPTY_STONE	0
#define WHITE_STONE	1
#define BLACK_STONE	2

// 키 정의
#define RIGHT_KEY		77
#define LEFT_KEY		75
#define DOWN_KEY		80
#define UP_KEY			72
#define SPACEBAR_KEY	32

// 색 정의
enum
{
	BLACK,
	D_BLUE,
	D_GREEN,
	D_SKYBLUE,
	D_RED,
	D_VIOLET,
	D_YELLOW,
	GRAY,
	D_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};

// 좌표 구조체
typedef struct _coordinate {
	char color;
	char x;
	char y;
}coordinate;

void gotoxy(int x, int y);
void TC(int back, int font);

void omok_socket(WSADATA *wsa_data, SOCKET *connect_sock, SOCKADDR_IN *connect_addr);

void omok_opening(char *nickname);
void omok_init(char board[][BOARD_SIZE], coordinate *stone);

void omok_playing(char board[][BOARD_SIZE], coordinate *stone);

int omok_algotirhm(char board[][BOARD_SIZE], coordinate stone);
void surrounding_stone(char board[][BOARD_SIZE], coordinate stone, char *up, char *rightup, char *right, char *rightdown, char *down, char *leftdown, char *left, char *leftup);
int iswin(char color, char up, char rightup, char right, char rightdown, char down, char leftdown, char left, char leftup);