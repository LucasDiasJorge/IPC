#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    // Criando a fila de mensagens e retornando o ID
    msgid = msgget(key, 0666 | IPC_CREAT);
    
    // Configurando a mensagem
    message.msg_type = 1;

    printf("Digite uma mensagem: ");
    fgets(message.msg_text, 100, stdin);

    // Enviando a mensagem para a fila
    msgsnd(msgid, &message, sizeof(message), 0);

    printf("Mensagem enviada: %s\n", message.msg_text);

    return 0;
}
