//20.3.3 21:00 정해성 최종 수정
#include <iostream>
#include "Server.h"

int main()
{
    Server host;
    Server client;
    int a;

    std::cout << "서버면 1, 클라이언트면 2를 누르세요." << std::endl;
    std::cin >> a;

    if (a == 1)
    {
        std::cout << "서버 모드 확인" << std::endl;
        host.serverSocket();
    }
    else if (a == 2)
    {
        std::cout << "클라이언트 모드 확인" << std::endl;
        client.clientSocket();
    }
    else
    {
        std::cout << "서버(1), 클라이언트(2) 중에 선택하세요." << std::endl;
        std::cin >> a;
    }
    return 0;
}