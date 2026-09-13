#include <stdio.h> // Biblioteca padrao de entradada e saida 
#include <stdlib.h> // Para o uso do free, ou allocar memoria
#include <string.h> // Para uso de funçoes para strings
#include <unistd.h> // Para uso de sistemas unix, linux 
#include <sys/socket.h> // Para configurar socket 
#include <arpa/inet.h> // Para traduzir endereços 

// Porta padrão deste uso e a 8080, póis nao e necessario permisssao de super usuiario por hora !
#define PORTA 8080
// Tamnho do buffer de caracters é 1024, isso é 1023, para caracters do cliente !
#define TAM_BUFFER  1024

int main(){
    int fd_serve, fd_cliente;
    char buffer[TAM_BUFFER];
    struct sockaddr_in endereco;
    int tamanho_endereco = sizeof(endereco);
    char *msg_boas_vinda = "Ola, Você esta concetado";

    fd_serve = socket(AF_INET, SOCK_STREAM, 0);
    // Cria um espaço em mémoria para armazenar o endereco e a porta e o buffer 
    // É retorna um "FILE DESCRIPTO", do tipo inteiro.
    if (fd_serve < 0)
    {
        printf("Erro ao Criar socket\n");
        exit(EXIT_FAILURE);
    }

    endereco.sin_family = AF_INET; // Para ipv4
    endereco.sin_addr.s_addr = INADDR_ANY; // Para aceitar qualquer Ip
    endereco.sin_port = htons(PORTA); // Para 

    // Faz o BIND do socket com o endereço/porta configurados
    if (bind(fd_serve, (struct sockaddr *)&endereco, sizeof(endereco)) < 0)
    {
        perror("Erro ao fazer o bind\n");
        close(fd_serve);
        exit(EXIT_FAILURE);
    }

    // Listen para aceitar conexoes, socket em modo de escuta
    // No total, apenas 5 conexoes
    if (listen(fd_serve, 5) < 0)
    {
        perror("Erro no listen");
        close(fd_serve);
        exit(EXIT_FAILURE);
    }
    
    printf("Servidor escutando na porta %d...\n", PORTA);

    while (1)
    {
        fd_cliente = accept(fd_serve, (struct sockaddr *) &endereco, (socklen_t*)&tamanho_endereco);
        if (fd_cliente < 0)
        {
            perror("Erro de accept");
            continue;
        }
        printf("Cliente conectado com sucesso\n");
        send(fd_cliente, msg_boas_vinda, strlen(msg_boas_vinda), 0);

        memset(buffer, 0, TAM_BUFFER);
        
    }
    

    
    

}