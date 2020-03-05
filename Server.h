#include <iostream>
#include <string>

#define PORT 4578
#define PACKET_SIZE 1024
#define SERVER_IP "192.168.219.101" //해성 PC IP, 웹서버로 넣을시엔..?

class Server
{
private:
public:
    void DB_init();      //연결
    void DB_send();      //쿼리
    void awaiting();     //변경사항(메세지 발신, 정보수정, 공지) 대기
    void Notification(); //알림발송
    void serverSocket(); //
    void clientSocket();

    Server();  //DB, 소켓 연결
    ~Server(); //DB, 소켓 해제
};

/*
데이터 베이스 함수
1. DB접속 코드
2. 쿼리 전달
3. 알림 확인 후 전송
*/