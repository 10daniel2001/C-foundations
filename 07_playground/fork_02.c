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
// Obtém o PID do processo atual usando a função getpid().

if (resultado == 0) {
// Se o valor de retorno for igual a 0, significa que estamos no processo filho.
ppid = getppid();
// Obtém o PID do processo pai usando a função getppid().
printf("Eu sou o processo filho, meu PID é %d e meu pai tem PID=%d.\n", pid, ppid);
}
if (resultado > 0) {
// Se o valor de retorno for maior que 0, significa que estamos no processo pai.
printf("Eu sou o processo pai, meu PID é %d e meu filho tem PID=%d.\n", pid, resultado);
waitpid(resultado, NULL, 0);
// Aguarda o término do processo filho usando a função waitpid(). O primeiro argumento é o PID do processo filho, o segundo argumento é um ponteiro para uma variável que armazenará o status de término do processo filho (neste caso, NULL), e o terceiro argumento é um conjunto de opções (neste caso, 0).
}

return 0;
}