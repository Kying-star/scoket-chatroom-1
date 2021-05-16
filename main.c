#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")
int main() {
    WORD sockVersion = MAKEWORD(2, 2);
    WSADATA data;
    if (WSAStartup(sockVersion, &data) != 0) {
        return 0;
    }

    SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sclient == INVALID_SOCKET) {
        printf("invalid socket !");
        return 0;
    }

    struct sockaddr_in serAddr;
    serAddr.sin_family = AF_INET;
    serAddr.sin_port = htons(8888);
    serAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    if (connect(sclient, (struct sockaddr *) &serAddr, sizeof(serAddr)) == SOCKET_ERROR) {
        printf("connect error !");
        closesocket(sclient);
        return 0;
    }
    printf("建立链接成功\n");
    while(1){
        char recData[255] ;
        char sendData[225];
        //发送数据
        scanf("%s",sendData);
        send(sclient, sendData, strlen(sendData), 0);

        //接收数据
        int ret = recv(sclient, recData, 255, 0);
        if (ret > 0) {

            recData[ret] = 0x00;
            printf("[服务端]:");
            printf(recData);
            printf("\n");
        }

    }
    closesocket(sclient);
    WSACleanup();
    return 0;
}
