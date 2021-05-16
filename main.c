#include <stdlib.h>
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    //��ʼ��WSA
    WORD sockVersion = MAKEWORD(2, 2);
    WSADATA wsaData;
    if (WSAStartup(sockVersion, &wsaData) != 0) {
        return 0;
    }

    //�����׽���
    SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (slisten == INVALID_SOCKET) {
        printf("socket error !");
        return 0;
    }

    //��IP�Ͷ˿�
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(8888);
    sin.sin_addr.S_un.S_addr = INADDR_ANY;
    if (bind(slisten, (LPSOCKADDR) &sin, sizeof(sin)) == SOCKET_ERROR) {
        printf("bind error !");
    }

    //��ʼ����
    if (listen(slisten, 5) == SOCKET_ERROR) {
        printf("listen error !");
        return 0;
    }

    //ѭ����������
    SOCKET sClient;
    struct sockaddr_in remoteAddr;
    int nAddrlen = sizeof(remoteAddr);
    //ar revData[255];
    printf("�ȴ�����...\n");
    sClient = accept(slisten, (SOCKADDR *) &remoteAddr, &nAddrlen);
//    for (int i = 0; i < 1000; i++)
    while(1)
    {
        char revData[255] ;
        if (sClient == INVALID_SOCKET) {
            printf("accept error !");
            continue;
        }
        char sendData[225];
        //��������
        int ret = recv(sClient, revData, 255, 0);

        if (ret > 0) {
            revData[ret] = 0x00;
            printf("[�ͻ���]:");
            printf(revData);
            printf("\n");
        }

        //��������
        scanf("%s",sendData);
        send(sClient, sendData, strlen(sendData), 0);

        if(sendData=="�ݰ�"){
            break;
        }
    }
    closesocket(sClient);
    closesocket(slisten);
    WSACleanup();
    return 0;
}