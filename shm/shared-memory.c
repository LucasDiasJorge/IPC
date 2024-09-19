#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

int main() {
    key_t key = ftok("shmfile", 65); // Gera uma chave única
    int shmid = shmget(key, 1024, 0666|IPC_CREAT); // Cria um segmento de memória compartilhada
    char *str = (char*) shmat(shmid, (void*)0, 0); // Anexa o segmento de memória ao espaço de endereço

    if (fork() == 0) { // Processo filho
        strcpy(str, "Olá do filho!"); // Escreve na memória compartilhada
        shmdt(str); // Desanexa o segmento de memória
    } else { // Processo pai
        wait(NULL); // Espera o processo filho terminar
        printf("Pai leu: %s\n", str); // Lê da memória compartilhada
        shmdt(str); // Desanexa o segmento de memória
        shmctl(shmid, IPC_RMID, NULL); // Destroi o segmento de memória
    }

    return 0;
}
