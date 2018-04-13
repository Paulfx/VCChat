//
// Created by Paul on 13/04/2018.
//

#ifndef CPPPROJECT_UDPSERVER_H
#define CPPPROJECT_UDPSERVER_H

#include "UDP.h"
#include <winsock2.h>
#include <vector>

class UDPServer: public UDP {
private:
    char* _addr;
    int _port;
    std::vector<sockaddr_in> tabClient;

    void sendTextMessage(char* sendBuffer);
    bool receiveTextMessage(char* res, int size);
public:
    UDPServer(char* addr, int port);
    void run();

};


#endif //CPPPROJECT_UDPSERVER_H
