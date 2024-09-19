#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd); // Cria o pipe

    if (fork() == 0) { // Processo filho
        close(fd[0]); // Fecha a leitura
        char msg[] = "Olá do filho!";
        write(fd[1], msg, sizeof(msg)); // Envia a mensagem pelo pipe
        close(fd[1]);
    } else { // Processo pai
        close(fd[1]); // Fecha a escrita
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer)); // Lê a mensagem do pipe
        printf("Pai recebeu: %s\n", buffer);
        close(fd[0]);
    }

    return 0;
}
