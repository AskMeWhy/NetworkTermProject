#include<WinSock2.h>
#include<Windows.h>
#include<stdio.h>

int main() {
	WSADATA wsa_data;
	SOCKET connect_sock;
	SOCKADDR_IN connect_addr;

	char nickname[16];

	// 서버 접속
	//omok_socket(&wsa_data, &connect_sock, &connect_addr);

	omok_opening(nickname);
	omok_init();



	closesocket(connect_sock);
	WSACleanup();

	return 0;
}