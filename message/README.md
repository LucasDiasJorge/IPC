### Estrutura do Projeto

- **Arquivo 1:** `sender.c` (Envia mensagens para a fila)
- **Arquivo 2:** `receiver.c` (Recebe mensagens da fila)

### Explicação do Código

1. **Estrutura da Mensagem (`msg_buffer`):**
   - A mensagem é composta por um `msg_type` (tipo de mensagem) e um campo `msg_text` (o texto da mensagem).
   - O `msg_type` permite que diferentes tipos de mensagens sejam enviadas e recebidas, mas neste exemplo, utilizamos apenas o tipo `1`.

2. **Chave (`key_t key`):**
   - A chave é gerada usando a função `ftok()` para garantir que ambos os programas (envio e recepção) usem a mesma fila de mensagens.

3. **Criação da Fila de Mensagens (`msgget`):**
   - O `msgget()` cria ou acessa a fila de mensagens usando a chave gerada.

4. **Envio da Mensagem (`msgsnd`):**
   - O `msgsnd()` envia a mensagem para a fila de mensagens, especificando o tipo da mensagem.

5. **Recepção da Mensagem (`msgrcv`):**
   - O `msgrcv()` recebe a mensagem da fila, e pode ser filtrada pelo `msg_type`.

6. **Destruição da Fila de Mensagens:**
   - Após receber a mensagem, o `receiver.c` destrói a fila de mensagens usando `msgctl()` com o comando `IPC_RMID`.

### Como Compilar e Executar

1. Compile os arquivos:
   ```bash
   gcc sender.c -o sender
   gcc receiver.c -o receiver
   ```

2. Execute o programa de envio de mensagem (`sender`):
   ```bash
   ./sender
   ```

3. Em outro terminal, execute o programa de recepção de mensagem (`receiver`):
   ```bash
   ./receiver
   ```

### Exemplo de Saída

- No terminal de envio (sender):
  ```
  Digite uma mensagem: Olá, mundo!
  Mensagem enviada: Olá, mundo!
  ```

- No terminal de recepção (receiver):
  ```
  Mensagem recebida: Olá, mundo!
  ```