//
// Created by Paul on 13/04/2018.
//

#include "Chat.h"

Chat::Chat(int argc, char** argv) {

    char* addr = nullptr;
    int port;
    if (argc > 2) {

        if (argc == 3) port = atoi(argv[2]);
        else {
            addr = argv[2];
            port = atoi(argv[3]);
        }

        if (strcmp(argv[1],"-c") == 0) {
            //Client
            std::cout << port << std::endl;
            std::cout << addr << std::endl;
            udp = new UDPClient(addr, port, argv[4], atoi(argv[5]));
        }
        else {
            //Server
            std::cout << port << std::endl;
            udp = new UDPServer(addr, port);
        }


        udp->run();
    }
    else std::cout << "Too few arguments" << std::endl;
}

Chat::~Chat() {
    delete udp;
}