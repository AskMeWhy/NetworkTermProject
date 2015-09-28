#include <WinSock2.h>
#include <Windows.h>
#include <stdio.h>

// ���� ó�� �Լ�
void ErrorHandling(char *Message){
	fputs(Message, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main(){
	WSADATA wsaData;
	SOCKET listen_sock, connect_sock;
	SOCKADDR_IN listen_addr, connect_addr;
	int sockaddr_in_size;
	int socket_port = 5555;
	char message[100];

	// ������ ���� ���� 2.2
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error");

	// ���ο� ���� ���� �� ����
	listen_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (listen_sock == INVALID_SOCKET)
		ErrorHandling("socket() error");

	// �ּ� ���� ������ ����ü�� �ּ� ����
	memset(&listen_addr, 0, sizeof(listen_addr));
	listen_addr.sin_family = AF_INET;
	listen_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	listen_addr.sin_port = htons(socket_port);

	// ������ �ּҸ� bind�Լ��� ���Ͽ� �Ҵ�
	if (bind(listen_sock, (SOCKADDR*)&listen_addr, sizeof(listen_addr)) == SOCKET_ERROR)
		ErrorHandling("bind() error");

	// Ŭ���̾�Ʈ ���� ��û ������ ���
	if (listen(listen_sock, 5) == SOCKET_ERROR)
		ErrorHandling("listen() error");

	sockaddr_in_size = sizeof(connect_addr);
	connect_sock = accept(listen_sock, (SOCKADDR*)&connect_addr, &sockaddr_in_size);
	if (connect_sock == INVALID_SOCKET)
		ErrorHandling("accept() error");

	/************�����͸� ���� �ְ���� �� �ִ�***************/
	//~source~//
	recv(connect_sock, message, 12, 0);
	printf("�����κ��� �޼��� : %s\n", message);
	/****************************************************/
	closesocket(connect_sock);	//���ϵ��� �������ְ�
	closesocket(listen_sock);
	WSACleanup();	//���� �ʱ�ȭ
	return 0;
}