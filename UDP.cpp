//
// Created by Paul on 13/04/2018.
//

#include "UDP.h"

UDP::UDP() {}

UDP::UDP(char* addr, int port) {

    //Create socket
    if (WSAStartup(MAKEWORD(2,0), &wsaData) != NO_ERROR) {
        exitWSA("Socket init: Error with WSAStartup\n", 10);
    }
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == INVALID_SOCKET) {
        exitWSA("Socket init: Error creating socket\n", 11);
    }
    //Backup
    backupSock = sock;
    //Bind
    if (addr == nullptr) { getAutoSin_Addr(); }
    else sockAddr.sin_addr.s_addr    = inet_addr(addr);
    sockAddr.sin_family              = AF_INET;
    sockAddr.sin_port                = htons(port);

    if (bind(sock, (SOCKADDR *) &sockAddr, sizeof(sockAddr)) == SOCKET_ERROR) {
        exitWSA("Bind: Failed to connect\n", 14);
    }
}

void UDP::exitWSA(std::string serr, int err) {
    std::cerr << serr;
    system("pause");
    WSACleanup();
    exit(err);
}

void UDP::getAutoSin_Addr() {
    std::cout << "AUTO ADDR" << std::endl;
    char hostname[255];
    gethostname(hostname, sizeof(hostname));
    auto host = gethostbyname(hostname);
    if (host == nullptr) {
        closesocket(sock);
        exitWSA("AutoAddr: Could not get hostname", 0);
    }
    //std::cout << host->h_addr_list[0][0] << std::endl;
    sockAddr.sin_addr.S_un.S_un_b.s_b1 = (u_char) host->h_addr_list[0][0];
    sockAddr.sin_addr.S_un.S_un_b.s_b2 = (u_char) host->h_addr_list[0][1];
    sockAddr.sin_addr.S_un.S_un_b.s_b3 = (u_char) host->h_addr_list[0][2];
    sockAddr.sin_addr.S_un.S_un_b.s_b4 = (u_char) host->h_addr_list[0][3];
}

void UDP::sendTextMessage(char* sendBuffer, sockaddr_in addr) {
    if (sendto(sock, sendBuffer, (int) strlen(sendBuffer) + 1, 0, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        closesocket(sock);
        exitWSA("Client: Error transmitting the data\n", 0);
    }
}

void UDP::run() {}

