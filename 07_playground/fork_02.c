#include <stdio.h>   // Biblioteca para usar a função printf() é necessária para imprimir mensagens na tela.
#include <unistd.h>  // Biblioteca para usar a função fork() é necessária para criar um novo processo.
#include <sys/wait.h> // Biblioteca para usar a função waitpid() é necessária para aguardar o término do processo filho.

int main() {
int resultado, pid, ppid;
// Cria um novo processo usando a função fork(). O processo filho recebe um valor de retorno igual a 0,
// enquanto o processo pai recebe o PID do processo filho.

resultado = fork();

if (resultado < 0)
// Se o valor de retorno for negativo, significa que houve um erro na criação do processo filho.

printf("Algo deu errado!!!\n");

pid = getpid();

if (resultado == 0) {

ppid = getppid();
printf("Eu sou o processo filho, meu PID é %d e meu pai tem PID=%d.\n", pid, ppid);
}
if (resultado > 0) {
printf("Eu sou o processo pai, meu PID é %d e meu filho tem PID=%d.\n", pid, resultado);
waitpid(resultado, NULL, 0);
}

return 0;
}