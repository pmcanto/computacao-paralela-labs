#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Quando o fork falha, pid retorna -1
        fprintf(stderr, "Fork falhou!\n");
        return 1;
    } else if (pid == 0) {
        // Este é o processo filho
        printf("Eu sou o filho! Meu PID e %d, meu pai e %d.\n", getpid(), getppid());
    } else {
        // Este é o processo pai
        printf("Eu sou o pai! Meu PID e %d, criei o filho %d.\n", getpid(), pid);

        // O pai espera o filho terminar
        wait(NULL);

        printf("Meu filho terminou, agora eu posso terminar.\n");
    }

    return 0;
}