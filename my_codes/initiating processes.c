#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/* unistd e sys/wait.h sao headers do sistema operacional 


   O codigo abaixo cria 3 processos filhos, cada um executando um comando diferente 
   (ls, date e brave-browser) usando a função execve. O processo pai espera cada filho terminar 
   antes de continuar para o próximo.

   int main tem 3 argumentos: argc (número de argumentos),
   argv (vetor de argumentos) e envp (vetor de variáveis de ambiente).

   Em englês, o código pode ser descrito como:
   The code below creates 3 child processes, each executing a different command
   (ls, date, and brave-browser) using the execve function. The parent process waits
   for each child to finish before continuing to the next.
*/

int main(int argc, char **argv, char* envp[]) {

    int pid, i;
    
    // Loop to create 3 child processes
    // Loop para criar 3 processos filhos
    for (i=1; i<=3; i++) {
    
        pid = fork();
         // check if fork() failed

    if (pid < 0) {
        // Fork failed
        // Fork falhou
        printf("Algo deu errado!!!\n");
    return 0;
    
    
    }

    if (pid == 0) { // Processo filho
        // Child process
        
        if (i == 1)
        // Execute the "ls" command
        // Executa o comando "ls" do terminal tradicional do Linux
        execve("/usr/bin/ls", argv, envp);
    if (i == 2)
        // Execute the "date" command
        // Executa o comando "date" do terminal tradicional do Linux
        execve("/usr/bin/date", argv, envp);
    if (i == 3)
        // Execute the "brave-browser" command
        // Executa o comando "brave-browser" do terminal tradicional do Linux
        execve("/usr/bin/brave-browser", argv, envp);
    }
    else // Processo pai
    {
        // Parent process
        printf("Processo pai aguardando o filho %d terminar...\n", i);
        waitpid(pid, NULL, 0);
        printf("Filho %d terminou.\n", i);
        
    }

}