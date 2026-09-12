#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORTA 8080
#define TAM_BUFFER  1024

int main(){
    int fd_serve, fd_cliente;
    char buffer[TAM_BUFFER];
    int tamanho_endereco = sizeof(tamanho_endereco);
    char *msg_boas_vinda = "Ola, Você esta concetado";
    
}