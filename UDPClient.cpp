//
// Created by Paul on 13/04/2018.
//

#include <iostream>
#include "UDPClient.h"

UDPClient::UDPClient(char* addr, int port, char* addrServer, int portServer) {
    UDP(addr, port);
    _addr = addr;
    _port = port;

    sockServer.sin_addr.s_addr    = inet_addr(addrServer);
    sockServer.sin_family         = AF_INET;
    sockServer.sin_port           = htons(portServer);
}

void UDPClient::run() {

    std::cout << "Client is running" << std::endl;
    std::cout << "Addr : " << _addr << "   Port : " << _port << std::endl;

    sendTextMessage("Salut\n");

    char rec[255];
    while(1) {
        receiveTextMessage(rec, sizeof(rec));
        if (sizeof(rec) > 0) {
            std::cout<<rec<<std::endl;
            break;
        }
    }

}

void UDPClient::receiveTextMessage(char* res, int size) {
    sockaddr_in sockAddrServ;
    int sizeOfServ;
    int bytes = recvfrom(sock, res, size, 0, (struct sockaddr *)&sockAddrServ, &sizeOfServ);
    if (bytes < 0) {
        closesocket(sock);
        exitWSA("Server: Could not receive datagram.\n", 0);
    }
}

void UDPClient::sendTextMessage(char* sendBuffer) {
    UDP::sendTextMessage(sendBuffer, sockServer);
}