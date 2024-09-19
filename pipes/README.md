# Projeto: Comunicação entre Processos com Pipes em C

Este projeto demonstra como utilizar pipes e processos em C para realizar comunicação entre um processo pai e um processo filho. O código cria um pipe, faz um fork para gerar um processo filho, e utiliza o pipe para transmitir uma mensagem do processo filho para o processo pai.

## Índice
- [Descrição](#descrição)
- [Funcionamento do Código](#funcionamento-do-código)
- [Como Compilar e Executar](#como-compilar-e-executar)
- [Exemplo de Saída](#exemplo-de-saída)
- [Explicação do Código](#explicação-do-código)
- [Referências](#referências)

---

## Descrição

Este projeto utiliza a funcionalidade de pipes e a chamada `fork()` em C para permitir a comunicação entre processos. O pipe é utilizado como um canal de comunicação unidirecional entre o processo pai e o processo filho.

## Funcionamento do Código

1. **Criação do Pipe**: A função `pipe(fd)` cria um pipe e armazena seus descritores em `fd`. O descritor `fd[0]` é usado para leitura e `fd[1]` é usado para escrita.

2. **Fork**: A chamada `fork()` cria um novo processo. O processo criado é chamado de processo filho e o processo original é o processo pai.

3. **Processo Filho**:
   - Fecha o descritor de leitura (`fd[0]`) do pipe.
   - Envia uma mensagem para o pipe usando o descritor de escrita (`fd[1]`).
   - Fecha o descritor de escrita após a operação.

4. **Processo Pai**:
   - Fecha o descritor de escrita (`fd[1]`) do pipe.
   - Lê a mensagem enviada pelo processo filho usando o descritor de leitura (`fd[0]`).
   - Exibe a mensagem recebida e fecha o descritor de leitura.

## Como Compilar e Executar

Para compilar e executar o código, siga os passos abaixo:

1. **Compilar**:
   ```bash
   gcc -o pipe pipe.c
   ```

2. **Executar**:
   ```bash
   ./pipe
   ```

## Exemplo de Saída

Ao executar o programa, você deverá ver uma saída similar a esta:

```
Pai recebeu: Olá do filho!
```

## Explicação do Código

1. **Inclusão de Bibliotecas**:
   - `#include <stdio.h>`: Para funções de entrada e saída.
   - `#include <unistd.h>`: Para funções relacionadas a processos e pipes.

2. **Criação do Pipe**:
   - `pipe(fd)`: Cria o pipe. `fd[0]` é para leitura e `fd[1]` é para escrita.

3. **Criação do Processo Filho**:
   - `fork()`: Cria um novo processo. Retorna 0 no processo filho e o PID do filho no processo pai.

4. **Comunicação**:
   - O processo filho escreve uma mensagem no pipe.
   - O processo pai lê a mensagem do pipe e a exibe.

## Referências

- [Documentação do Pipe](https://man7.org/linux/man-pages/man2/pipe.2.html)
- [Documentação do Fork](https://man7.org/linux/man-pages/man2/fork.2.html)
- [Programação de Processos em C](https://www.gnu.org/software/libc/manual/html_node/Creating-Processes.html)