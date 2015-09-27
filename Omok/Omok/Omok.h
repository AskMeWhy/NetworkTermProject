// 바둑판의 크기
#define BOARD_SIZE	15
// 바둑판의 상태
#define EMPTY_STONE	0
#define WHITE_STONE	1
#define BLACK_STONE	2

// 키 정의
#define RIGHT_KEY	77
#define LEFT_KEY	75
#define DOWN_KEY	80
#define UP_KEY		72

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
	// 바둑돌 색
	char stone;
	char row;
	char col;
}coordinate;