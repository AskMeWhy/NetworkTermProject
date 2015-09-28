#include<stdio.h>
#include"Omok.h"

int main() {
	WSADATA wsa_data;
	SOCKET connect_sock;
	SOCKADDR_IN connect_addr;

	char nickname[16];
	char board[BOARD_SIZE][BOARD_SIZE];
	coordinate stone;

	// 辑滚 立加
	//omok_socket(&wsa_data, &connect_sock, &connect_addr);

	omok_opening(nickname);

	// 规 立加

	omok_init(board, &stone);

	while (1) {
		stone.color = BLACK_STONE;
		omok_playing(board, &stone);
		stone.color = WHITE_STONE;
		omok_playing(board, &stone);
	}


	//closesocket(connect_sock);
	//WSACleanup();

	return 0;
}