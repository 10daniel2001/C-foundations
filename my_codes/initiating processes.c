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

for (i=1; i<=3; i++) {

    pid = fork();
    // check if fork() failed
if (pid < 0) {

    printf("Algo deu errado!!!\n");
return 0;
}

if (pid == 0) { // Processo filho


 if (i == 1)

    execve("/usr/bin/ls", argv, envp);
if (i == 2)

    execve("/usr/bin/date", argv, envp);
if (i == 3)
    execve("/usr/bin/brave-browser", argv, envp);
}
else // Processo pai
    waitpid(pid, NULL, 0);
}

}