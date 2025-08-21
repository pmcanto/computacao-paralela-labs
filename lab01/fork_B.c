#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h> // Incluído para a função exit()

int main() {
    printf("Insira o número de filhos que você quer criar: ");
    int num;
    scanf("%d", &num);
    printf("\nEu sou o pai! Meu PID é %d. Criei %d filhos.\n", getpid(), num);
    for (int i = 0; i < num; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            // Se o fork falhar
            fprintf(stderr, "Erro ao criar o filho número %d!\n", i + 1);
            exit(1); // Encerra o programa com erro
        }
        else if (pid == 0) {
            // Este é o processo filho.
            printf("Eu sou o filho número %d! Meu PID é %d e meu pai é %d.\n", i + 1, getpid(), getppid());
            exit(0); // O filho termina sua execução aqui.
        }
    }
    // Este é o processo pai. Ele espera todos os filhos terminarem.
    
    for (int i = 0; i < num; i++) {
        wait(NULL);
    }
    printf("Todos os meus filhos terminaram. Agora eu posso terminar.\n");
    return 0; // O processo pai termina
}