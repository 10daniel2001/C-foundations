#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

// This program demonstrates the use of fork() to create a child process.
// The child process will print its own PID and the parent's PID.

// Este programa demonstra o uso de fork() para criar um processo filho.
// O processo filho imprimirá seu próprio PID e o PID do pai.
int main(int arg, char* argv[]){

    pid_t pid = fork(); // Create a new process
    // Criando um novo processo

    if (pid < 0) { // Error occurred
        perror("Fork failed");
        // Verificar se ocorreu um erro
        // se Pid for menor que 0, significa que ocorreu um erro na criação do processo filho
        return 1;
    } else if (pid == 0) { // Child process
        // Processo filho
        // The child process will print its own PID and the parent's PID

        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else { // Parent process
        // Processo pai
        // The parent process will print its own PID and the child's PID
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}