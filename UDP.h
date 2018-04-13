//
// Created by Paul on 13/04/2018.
//

#ifndef CPPPROJECT_UDP_H
#define CPPPROJECT_UDP_H

#include <winsock2.h>
#include <iostream>
#include <string>

class UDP {
protected:
    WSADATA wsaData;
    SOCKET  sock, backupSock, acceptSock;
    SOCKADDR_IN sockAddr;

    void sendTextMessage(char* sendBuffer, sockaddr_in addr);

public:
    UDP();
    UDP(char* addr, int port);
    void exitWSA(std::string serr, int err);
    void getAutoSin_Addr();

    virtual void run();
};


#endif //CPPPROJECT_UDP_H
