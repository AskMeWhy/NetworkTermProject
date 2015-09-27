#include<WinSock2.h>
#include<Windows.h>
#include<stdio.h>

// ���� ó�� �Լ�
void ErrorHandling(char *Message) {
	fputs(Message, stderr);
	fputc('\n', stderr);
	exit(1);
}

void omok_socket(WSADATA *wsa_data, SOCKET *connect_sock, SOCKADDR_IN *connect_addr) {
	char *socket_ip = "123.123.123.123";
	int socket_port = 1;

	// ������ ���� ���� 2.2
	if (WSAStartup(MAKEWORD(2, 2), wsa_data) != 0)
		ErrorHandling("WSAStartup() error");

	(*connect_sock) = socket(PF_INET, SOCK_STREAM, 0);
	if ((*connect_sock) == INVALID_SOCKET)
		ErrorHandling("socket() error");

	memset(connect_addr, 0, sizeof((*connect_addr)));
	(*connect_addr).sin_family = AF_INET;
	(*connect_addr).sin_addr.S_un.S_addr = inet_addr(socket_ip);
	(*connect_addr).sin_port = htons(socket_port);

	// �ش� �ּҷ� ����
	if (connect((*connect_sock), (SOCKADDR*)connect_addr, sizeof((*connect_addr))))
		ErrorHandling("connect() error");

	/************�����͸� ���� �ְ���� �� �ִ�***************/
	//~source~//
	send((*connect_sock), "Hello World", 12, 0);	//���ڿ� ����
	/****************************************************/
}