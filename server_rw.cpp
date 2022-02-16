#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
//#include <sys/types.h>
#include <stdlib.h>
#include <netinet/in.h>
//#include <netdb.h>
//#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>

#define PORT 8244

void process_connection(int client_socket);

int main(int argc, char const *argv[])
{   
    int server_rw, new_socket, read_val;
    struct socketaddr_in address;
    int opt=1;
    int addrlen = sizeof(address);
    char buffer[1024]={0};
    char *Greeting = "Hello you are connected to Raylon and Will's server"
    

    if((server_rw = socket(AF_INET, SOCK_STREAM,0))==0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if(bind(server_rw,(struct sockaddr*)&address,sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if(listen(server_rw,100)<0)
    {
        perror("cannot listen for connections");
        exit(EXIT_FAILURE);
    }

    if(new_socket=accept(server_rw,(struct socketaddr *)&address,(socketlen*)&addrlen)<0){
        perror("client accept failure");
        exit(EXIT_FAILURE);
    }

    process_connection(new_socket);

    pthread_t thread;
    int *client_pthread = malloc(sizeof(int));
    *client_pthread = new_socket;
    pthread_create(&thread, NULL, threadfunction,client_pthread);

    send(new_socket,Greeting,strlen(Greeting),0);
    printf("Greeting sent\n");

    read_val= read(new_socket,buffer,buffeer.size());
    printf("%s/n",buffer);
    
    return 0;


}
void process_connection(int client_socket){
    
}
