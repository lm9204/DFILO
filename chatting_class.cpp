#include <iostream>
#include <string>

using namespace std;

/*---------------------------------------------------------------------------------- */

class chatting_room
{
private:
    string chatting_room_id; //채팅방 고유 id

public:
    int read_time;             //어디까지 읽었는데 확인 20200305248 년도월날짜시간 순 기능 미구현
    string chatting_room_name; //채팅방 이름 100자 제한
    string chatting_room_member[100];

    chatting_room(int _chatting_room_id)
    {
        chatting_room_id = _chatting_room_id;
    }
};

/*---------------------------------------------------------------------------------- */

string get_chatting_room_name(); //서버 클라이언트 기능
int get_chatting_room_id();      //서버 클라이언트 기능

/*---------------------------------------------------------------------------------- */

int main()
{

    return 0;
}

/*---------------------------------------------------------------------------------- */

int get_chatting_room_id()
{
    ;
}

string get_chatting_room_name()
{
    ;
}