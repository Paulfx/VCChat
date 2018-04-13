//
// Created by Paul on 13/04/2018.
//

#ifndef CPPPROJECT_CHAT_H
#define CPPPROJECT_CHAT_H

#include "UDP.h"
#include "UDPServer.h"
#include "UDPClient.h"
#include <winsock2.h>

class Chat {

private:
    UDP* udp;

public:

    Chat(int argc, char** argv);
    ~Chat();
};


#endif //CPPPROJECT_CHAT_H
