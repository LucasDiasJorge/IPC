#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Definição da estrutura da mensagem
struct msg_buffer {
    long msg_type;
    char msg_text[100];
} message;

int main() {
    key_t key;
    int msgid;

    // Gerando uma chave única
    key = ftok("progfile", 65);

    // Acessando a fila de mensagens
    msgid = msgget(key, 0666 | IPC_CREAT);

    // Recebendo a mensagem da fila
    msgrcv(msgid, &message, sizeof(message), 1, 0);

    // Exibindo a mensagem recebida
    printf("Mensagem recebida: %s\n", message.msg_text);

    // Destruindo a fila de mensagens
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
