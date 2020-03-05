#include <iostream>
#include "Server.h"
#include <WinSock2.h>              //소켓 사용을 위한 헤더파일
#pragma comment(lib, "ws2_32.lib") //위에서 선언한 헤더파일들을 가져다 쓰기 위한 링크

/*
...참고용...
void Server::showError(const char *msg)
{
    std ::cout << "에러 : " << msg << std ::endl;
    exit(-1);
}
*/

void Server::DB_init()
{
}

void Server::DB_send()
{
}

void Server::awaiting()
{
}

void Server::Notification()
{
}

void serverSocket()
{
    //Windows의 소켓 초기화 정보를 저장하기위한 구조체 선언
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    //소켓 생성
    SOCKET hListen;
    hListen = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); //(IPV4,연결지향성,TCP)

    if (hListen == INVALID_SOCKET)
        std::cout << "서버 생성 실패" << std::endl;

    //소켓의 구성요소를 담을 구조체 생성 및 값 할당
    SOCKADDR_IN tListenAddr = {};
    tListenAddr.sin_family = AF_INET;
    tListenAddr.sin_port = htons(PORT);              //이걸 거치면 빅엔디안 방식으로 데이터 설정
    tListenAddr.sin_addr.s_addr = htonl(INADDR_ANY); //현재 동작되는 IP주소로 설정

    //소켓에 위에 설정한 주소정보를 묶어줌
    bind(hListen, (SOCKADDR *)&tListenAddr, sizeof(tListenAddr));
    if (bind(hListen, (SOCKADDR *)&tListenAddr, sizeof(tListenAddr)) == SOCKET_ERROR)
        std::cout << "바인딩 실패" << std::endl;

    //소켓을 수신상태로 변경, 최대 접속승인수로 설정
    listen(hListen, SOMAXCONN);

    if (listen(hListen, SOMAXCONN) == SOCKET_ERROR)
        std::cout << "접속대기 모드 실패" << std::endl;
    else
        std ::cout << "클라이언트를 기다립니다.." << std::endl;

    //클라이언트 소켓 생성, 정보구조체 생성 및 값 할당
    SOCKADDR_IN tClntAddr = {};
    int iClntSize = sizeof(tClntAddr);
    SOCKET hClient = accept(hListen, (SOCKADDR *)&tClntAddr, &iClntSize); // 동기화된 방식으로 접속요청 수락
    //(소켓, accept할 client주소 구조체의 주소, 2인자 크기 저장된 변수의 주소)

    //clint 정보 출력
    char cBuffer[PACKET_SIZE] = {};
    recv(hClient, cBuffer, PACKET_SIZE, 0); //대상 소켓의 정보 받는 함수
    std::cout << "Recv Msg : " << cBuffer << std::endl;

    char cMsg[] = "Server Send";
    send(hClient, cMsg, strlen(cMsg), 0);

    closesocket(hClient);
    closesocket(hListen);

    WSACleanup();
}

void clientSocket()
{
    //Windows의 소켓 초기화 정보를 저장하기위한 구조체 선언
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    //소켓 생성
    SOCKET hSocket;
    hListen = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); //(IPV4,연결지향성,TCP)

    if (hListen == INVALID_SOCKET)
        std::cout << "서버 생성 실패" << std::endl;

    //소켓의 구성요소를 담을 구조체 생성 및 값 할당
    SOCKADDR_IN tAddr = {};
    tAddr.sin_family = AF_INET;
    tAddr.sin_port = htons(PORT);                 //이걸 거치면 빅엔디안 방식으로 데이터 설정
    tAddr.sin_addr.s_addr = inet_addr(SERVER_IP); //서버의 IP주소로 설정

    connect(hSocket, (SOCKADDR *)&tAddr, sizeof(tAddr));

    //clint 정보 출력
    char cMsg[] = "Client Send";
    send(hSocket, cMsg, strlen(cMsg), 0);

    char cBuffer[PACKET_SIZE] = {};
    recv(hSocket, cBuffer, PACKET_SIZE, 0); //대상 소켓의 정보 받는 함수
    std::cout << "Recv Msg : " << cBuffer << std::endl;

    closesocket(hSocket);

    WSACleanup();
}

Server::Server()
{
}

Server::~Server()
{
}