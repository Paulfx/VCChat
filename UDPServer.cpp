//
// Created by Paul on 13/04/2018.
//

#include <iostream>
#include "UDPServer.h"

UDPServer::UDPServer(char* addr, int port) {
    UDP(addr, port);
    _addr = addr;
    _port = port;
}

void UDPServer::run() {

    std::cout << "Server is running" << std::endl;
    std::cout << "Addr : " << _addr << "   Port : " << _port << std::endl;
    char res[255];
    while (1) {
        if (receiveTextMessage(res, sizeof(res))) {
            sendTextMessage("Bonjour toi !");
            break;
        }
    }

}

bool UDPServer::receiveTextMessage(char* res, int size) {
    sockaddr_in sockAddrClient;
    int sizeOfClient;
    int bytes = recvfrom(sock, res, size, 0, (struct sockaddr *)&sockAddrClient, &sizeOfClient);
    if (bytes < 0) {
        //closesocket(sock);
        //exitWSA("Server: Could not receive datagram.\n", 0);
    }
    else if(bytes > 0) {
        tabClient.push_back(sockAddrClient);
        return true;
    }
    return false;
}

void UDPServer::sendTextMessage(char* sendBuffer) {
    for (sockaddr_in s : tabClient) {
        UDP::sendTextMessage(sendBuffer, s);
    }
}