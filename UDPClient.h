//
// Created by Paul on 13/04/2018.
//

#ifndef CPPPROJECT_UDPCLIENT_H
#define CPPPROJECT_UDPCLIENT_H


#include "UDP.h"
#include <winsock2.h>

class UDPClient: public UDP {
private:
    char* _addr;
    int _port;

    sockaddr_in sockServer;

    void sendTextMessage(char* sendBuffer);
    void receiveTextMessage(char* res, int size);
public:
    UDPClient(char* addr, int , char* addrServer, int portServer);
    void run();

};


#endif //CPPPROJECT_UDPCLIENT_H
