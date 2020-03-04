//20.3.3 21:00 정해성 최종 수정
#include <stdio.h>
#include <iostream>
#include <WinSock2.h> //소켓 사용을 위한 헤더파일
#include "Server.h"

#pragma comment(lib, "ws2_32.lib") //위에서 선언한 헤더파일들을 가져다 쓰기 위한 링크

int main()
{
    //Windows의 소켓 초기화 정보를 저장하기위한 구조체 선언
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    //소켓 생성
    SOCKET hListen;
    hListen = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); //(IPV4,연결지향성,TCP)

    //소켓의 구성요소를 담을 구조체 생성 및 값 할당
    SOCKADDR_IN tListenAddr = {};
    tListenAddr.sin_family = AF_INET;
    tListenAddr.sin_port = htons(PORT);              //이걸 거치면 빅엔디안 방식으로 데이터 설정
    tListenAddr.sin_addr.s_addr = htonl(INADDR_ANY); //현재 동작되는 IP주소로 설정

    //소켓에 위에 설정한 주소정보를 묶어주고,
    bind(hListen, (SOCKADDR *)&tListenAddr, sizeof(tListenAddr));
    listen(hListen, SOMAXCONN); //소켓을 수신상태로 변경, 최대 접속승인수로 설정

    //클라이언트 소켓 생성, 정보구조체 생성 및 값 할당
    SOCKADDR_IN tClntAddr = {};
    int iClntSize = sizeof(tClntAddr);
    SOCKET hClinet = accept(hListen, (SOCKADDR *)&tClntAddr, &iClntSize); // 동기화된 방식으로 접속요청 수락
    //(소켓, accept할 client주소 구조체의 주소, 2인자 크기 저장된 변수의 주소)

    //clint 측fdf

    WSACleanup();

    /*
    WSADATA data;
    ::WSAStartup(MAKEWORD(2, 2), &data);

    SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (server == INVALID_SOCKET)
        Server::showError("서버 생성 실패");

    sockaddr_in addr = {0};

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(23000);

    if (bind(server, (sockaddr *)&addr, sizeof(addr)) == SOCKET_ERROR)
        Server::showError("바인딩 실패");

    if (listen(server, SOMAXCONN) == SOCKET_ERROR)
        Server::showError("듣기 실패");

    std ::cout << "클라이언트를 기다립니다.." << std::endl;

    SOCKET client = accept(server, NULL, NULL);
    closesocket(client);

    closesocket(server);
    ::WSACleanup();
    */

    return 0;
}