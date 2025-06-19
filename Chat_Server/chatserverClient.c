#include<stdio.h>
#include<string.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include<unistd.h>

int main(){
    int sd;
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);
    struct sockaddr_in sad;
    char str[50];

    sd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    sad.sin_family = AF_INET;
    sad.sin_port = htons(9995);
    sad.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sd, (struct sockaddr *)&sad, sizeof(sad));

    while (1) {
        printf("Enter your Mess : (enter quit to exit): ");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0'; // remove newline

        send(sd, str, strlen(str)+1, 0); // send including '\0'

        if (strcmp(str, "quit") == 0)
            break;
    }

    close(sd);
    WSACleanup();
    return 0;
}
