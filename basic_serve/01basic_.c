/*Para iniciar este servidor basico e necessario o uso de outro terminal 
  Para compilar - gcc 01basic.c -o run
  ./run -> Um terminal ser aberto !
  Para o lado do cliente e necessario rodar este comando em outro terminal -> nc 127.0.0.1 8080

  EN:
    To start this basic server, it is necessary to use another terminal
    To compile - gcc 01basic.c -o run
    ./run -> A terminal will be opened!
    For the client side, it is necessary to run this command in another terminal -> nc 127.0.0.1 8080

*/




#include <stdio.h> // Biblioteca padrao de entradada e saida 
// for use of printf, scanf, etc.

#include <stdlib.h> // Para o uso do free, ou allocar memoria
// For use of free, or allocate memory

#include <string.h> // Para uso de funçoes para strings
// For use of functions for strings

#include <unistd.h> // Para uso de sistemas unix, linux 
// For use of unix, linux systems

#include <sys/socket.h> // Para configurar socket 
// For socket configuration

#include <arpa/inet.h> // Para traduzir endereços 
// For address translation

// Porta padrão deste uso e a 8080, póis nao e necessario permisssao de super usuiario por hora !
// The default port for this use is 8080, as superuser permission is not required for now!
#define PORTA 8080
// Tamnho do buffer de caracters é 1024, isso é 1023, para caracters do cliente !
// The size of the character buffer is 1024, that is 1023, for client characters!
#define TAM_BUFFER  1024

int main(){
    // Cria o socket do servidor e do cliente, aqui e apenas variavel do tipo inteiro, que vai armazenar o "FILE DESCRIPTOR" do socket
    int fd_serve, fd_cliente;
    // Buffer para armazenar a mensagem do cliente, os dados que o cliente enviar para o servidor, e armazenado nesse buffer
    char buffer[TAM_BUFFER];
    // Estrutura de dados para armazenar o endereco do cliente, e o tamanho do endereco, na memoria,
    // para que o servidor possa se comunicar com o cliente, e necessario armazenar o endereco do cliente, 
    //e o tamanho do endereco, para que o servidor possa se comunicar com o cliente

    // Data structure to store the client's address, and the size of the address, in memory,
    // so that the server can communicate with the client, it is necessary to store the client's
    // address, and the size of the address, so that the server can communicate with the client

    // Estrutura de dados para armazenar o endereco do cliente, e o tamanho do endereco, na memoria,
    // para que o servidor possa se comunicar com o cliente, e necessario armazenar o endereco do cliente,
    //e o tamanho do endereco, para que o servidor possa se comunicar com o cliente

    // Data structure to store the client's address, and the size of the address, in memory,
    // so that the server can communicate with the client, it is necessary to store the client's
    // address, and the size of the address, so that the server can communicate with the client
    struct sockaddr_in endereco;
    int tamanho_endereco = sizeof(endereco);
    char *msg_boas_vinda = " Ola, Você esta conectado no SerVe basic ";

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

    // Loop infinito para aceitar conexoes de clientes
    while (1)
    {
        // Aceita a conexao do cliente, e retorna um "FILE DESCRIPTOR" do tipo inteiro, 
        // para o socket do cliente
        // Accepts the client's connection, and returns a "FILE DESCRIPTOR" of type integer,
        // for the client's socket
        fd_cliente = accept(fd_serve, (struct sockaddr *) &endereco, (socklen_t*)&tamanho_endereco);
        if (fd_cliente < 0)
        {
            perror("Erro de accept");
            continue;
        }
        printf("Cliente conectado com sucesso\n");

        // Envia uma mensagem de boas-vindas para o cliente
        // Send a welcome message to the client
        send(fd_cliente, msg_boas_vinda, strlen(msg_boas_vinda), 0);


        // Limpa o buffer para receber a mensagem do cliente
        // Clear the buffer to receive the client's message
        memset(buffer, 0, TAM_BUFFER);
        
        // Lê a mensagem do cliente e armazena no buffer
        // Read the client's message and store it in the buffer
        int bytes_lido = read(fd_cliente, buffer, TAM_BUFFER - 1);
        if (bytes_lido > 0)
        {
            printf("Mensagem do cliente: %s\n", buffer);
        }
        // Fecha o socket do cliente
        // Close the client socket
        close(fd_cliente);
        printf("Sessao terminada para cliente\n");
        
    }
    

    // Fecha o socket do servidor
    // Close the server socket
    close(fd_serve);
    printf("Servidor terminado com sucesso\n");

    
 return 0;
}