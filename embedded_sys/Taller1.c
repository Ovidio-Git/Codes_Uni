

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> // socket library
#include <netinet/in.h>

// SOCK_STREAM -> TCP 
// SOCK_DGRAM -> UDP




int main(){
    
    int connection = 0;
    int socket_id = 0;
    char buffer[500];
    char msg[] ="GET /index.html HTTP/1.1\n\r";
    socket_id = socket(PF_INET, SOCK_STREAM, 0);

    // Server parameters   AWS IP Public= 18.222.148.97
    struct sockaddr_in server;
    server.sin_family = AF_INET ;  // protocol
    server.sin_addr.s_addr = inet_addr("172.217.173.196"); // server ip
    server.sin_port = htons(443); // connection port
    // htons(port number) convert to 6 bit format 
    
    
    // Make connection
    connection = connect(socket_id, (struct sockaddr*)&server, sizeof(server));
    if (connection < 0){
        printf("[ERROR] connection failed\r\n");
        return(-1);
    }
    printf("[CONNECTION SUCCESS]\r\n");
    send(socket_id, msg, sizeof(msg), 0); 
    recv(connection,buffer,sizeof(buffer),0);
    for (int i = 0; i < 5; i++)
    {
         printf(recv(connection,buffer,sizeof(buffer),0));
         printf(buffer[i]);
    }
    
   
    close(socket_id);

    return (0);

}