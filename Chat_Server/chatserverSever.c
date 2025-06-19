#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <unistd.h>  // For close() on MinGW (optional; comment if using MSVC)

int main() {
    WSADATA wsa;
    SOCKET sd, cd;
    struct sockaddr_in sad, cad;
    int cadl;
    char str[50];

    // Initialize Winsock
    WSAStartup(MAKEWORD(2, 2), &wsa);

    // Create socket
    sd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // Configure server address
    sad.sin_family = AF_INET;
    sad.sin_port = htons(9995);
    sad.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Bind socket
    bind(sd, (struct sockaddr*)&sad, sizeof(sad));

    // Listen for connections
    listen(sd, 1);
    printf("Server is waiting for client connection on port 9995...\n");

    // Accept client
    cadl = sizeof(cad);
    cd = accept(sd, (struct sockaddr*)&cad, (int*)&cadl);
    printf("Client connected.\n");

    // Communication loop
    while (1) {
        int n = recv(cd, str, sizeof(str) - 1, 0);
        if (n <= 0) {
            printf("Client disconnected or error.\n");
            break;
        }
        str[n] = '\0'; // Null terminate the string

        if (strcmp(str, "quit") == 0) {
            printf("Client ended the chat.\n");
            break;
        }

        printf("Client says: %s\n", str);
    }

    // Close sockets
    close(cd);
    close(sd);
    WSACleanup();

    return 0;
}
