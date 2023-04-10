#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>

int hilo(int socket_desc, int new_socket, int c, struct sockaddr_in server, struct sockaddr_in client){
    char client_message[2000];
    int movimiento ;
    while (true)
    {
    
        // Listen
        listen(socket_desc, 3);

        // Accept and incoming connection
        puts("Waiting for incoming connections...");
        c = sizeof(struct sockaddr_in);
        new_socket = accept(socket_desc, (struct sockaddr *)& client, (socklen_t *)&c);
        if (new_socket < 0) {
            perror("Accept failed");
            return 1;
        }
        puts("Connection accepted");

        // Receive data from Flask app
        memset(client_message, '\0', sizeof(client_message));
        if (recv(new_socket, client_message, sizeof(client_message), 0) < 0) {
            puts("Receive failed");
            return 1;
        }

        printf("Data received from Flask app: %s\n", client_message);

    }
}


int main(int argc, char *argv[]) {

    int socket_desc, new_socket, c;
    struct sockaddr_in server, client;
    char *message;
    

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(5002);

    // Bind
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        return 1;
    }
    puts("Bind done");

    hilo(socket_desc,new_socket, c, server, client );

    close(socket_desc);
    close(new_socket);
    return 0;
}