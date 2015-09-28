#include <WinSock2.h>
#include <Windows.h>
#include <stdio.h>

// 에러 처리 함수
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

	// 윈도우 소켓 버전 2.2
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error");

	// 새로운 소켓 생성 후 대입
	listen_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (listen_sock == INVALID_SOCKET)
		ErrorHandling("socket() error");

	// 주소 저장 가능한 구조체에 주소 설정
	memset(&listen_addr, 0, sizeof(listen_addr));
	listen_addr.sin_family = AF_INET;
	listen_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	listen_addr.sin_port = htons(socket_port);

	// 설정된 주소를 bind함수로 소켓에 할당
	if (bind(listen_sock, (SOCKADDR*)&listen_addr, sizeof(listen_addr)) == SOCKET_ERROR)
		ErrorHandling("bind() error");

	// 클라이언트 접속 요청 때까지 대기
	if (listen(listen_sock, 5) == SOCKET_ERROR)
		ErrorHandling("listen() error");

	sockaddr_in_size = sizeof(connect_addr);
	connect_sock = accept(listen_sock, (SOCKADDR*)&connect_addr, &sockaddr_in_size);
	if (connect_sock == INVALID_SOCKET)
		ErrorHandling("accept() error");

	/************데이터를 이제 주고받을 수 있다***************/
	//~source~//
	recv(connect_sock, message, 12, 0);
	printf("서버로부터 메세지 : %s\n", message);
	/****************************************************/
	closesocket(connect_sock);	//소켓들을 정리해주고
	closesocket(listen_sock);
	WSACleanup();	//윈속 초기화
	return 0;
}