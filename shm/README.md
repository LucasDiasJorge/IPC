# Projeto: Memória Compartilhada em C

Este projeto demonstra o uso de memória compartilhada em C para permitir a comunicação entre processos. O código cria um segmento de memória compartilhada, usa um processo filho para escrever dados nesse segmento e permite que o processo pai leia os dados. 

## Índice
- [Descrição](#descrição)
- [Funcionamento do Código](#funcionamento-do-código)
- [Como Compilar e Executar](#como-compilar-e-executar)
- [Referências](#referências)

---

## Descrição

Este projeto utiliza funções de memória compartilhada para comunicação interprocessos. O código inclui:

- Criação e anexação de um segmento de memória compartilhada.
- Uso de `fork()` para criar um processo filho que escreve dados na memória compartilhada.
- O processo pai lê os dados e então remove o segmento de memória.

## Funcionamento do Código

1. **Geração da Chave**:
   - `key_t key = ftok("shmfile", 65);`: Gera uma chave única para identificar o segmento de memória compartilhada.

2. **Criação do Segmento de Memória Compartilhada**:
   - `int shmid = shmget(key, 1024, 0666|IPC_CREAT);`: Cria um segmento de memória compartilhada de 1024 bytes.

3. **Anexação do Segmento de Memória**:
   - `char *str = (char*) shmat(shmid, (void*)0, 0);`: Anexa o segmento de memória ao espaço de endereço do processo.

4. **Processo Filho**:
   - `strcpy(str, "Olá do filho!");`: Escreve uma mensagem na memória compartilhada.
   - `shmdt(str);`: Desanexa o segmento de memória.

5. **Processo Pai**:
   - `wait(NULL);`: Espera o processo filho terminar.
   - `printf("Pai leu: %s\n", str);`: Lê e exibe a mensagem da memória compartilhada.
   - `shmdt(str);`: Desanexa o segmento de memória.
   - `shmctl(shmid, IPC_RMID, NULL);`: Remove o segmento de memória compartilhada.

## Como Compilar e Executar

Para compilar e executar o código, siga os passos abaixo:

1. **Compilar**:
   ```bash
   gcc -o shared_memory shared_memory.c
   ```

2. **Executar**:
   ```bash
   ./shared_memory
   ```

## Referências

Para uma implementação mais completa e detalhada de memória compartilhada em C, consulte o projeto [Shared-Memory](https://github.com/LucasDiasJorge/Shared-Memory). Este projeto inclui exemplos adicionais e explicações mais detalhadas sobre o uso de memória compartilhada.