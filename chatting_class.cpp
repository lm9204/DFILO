#include <iostream>
#include <string>

#define id_Eugene 980914

using namespace std;

/*---------------------------------------------------------------------------------- */

class chatting_room
{
private:
    int my_id;
    string chatting_room_id;

public:
    int read_time;                //어디까지 읽었는데 확인 20200305248 년도월날짜시간 순
    char chatting_room_name[100]; //채팅방 이름 100자 제한
    string chatting_room_member[100];

    chatting_room(int _my_id, int _chatting_room_id)
    {
        my_id = _my_id;
        chatting_room_id = _chatting_room_id;
    }
};

/*---------------------------------------------------------------------------------- */

void get_chatting_room_name(char);
string get_chatting_room_name();

/*---------------------------------------------------------------------------------- */

int main()
{

    chatting_room test(id_Eugene, get_chatting_room_id());

    return 0;
}

/*---------------------------------------------------------------------------------- */

int get_chatting_room_id() //아직 안만듬 ???
{
    ;
}

string get_chatting_room_name()
{
    string tmp;

    getline(cin, tmp);

    return tmp;
}