#include <iostream>
#include "Server.h"

void Server::showError(const char *msg)
{
    std ::cout << "에러 : " << msg << std ::endl;
    exit(-1);
}