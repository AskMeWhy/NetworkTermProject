// �ٵ����� ũ��
#define BOARD_SIZE	15
// �ٵ����� ����
#define EMPTY_STONE	0
#define WHITE_STONE	1
#define BLACK_STONE	2

// Ű ����
#define RIGHT_KEY	77
#define LEFT_KEY	75
#define DOWN_KEY	80
#define UP_KEY		72

// �� ����
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

// ��ǥ ����ü
typedef struct _coordinate {
	// �ٵϵ� ��
	char stone;
	char row;
	char col;
}coordinate;