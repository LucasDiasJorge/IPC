# Comunicação entre Processos

## Visão Geral

Este projeto explora vários mecanismos de Comunicação entre Processos (IPC) utilizando a linguagem de programação C. A IPC permite que processos se comuniquem e sincronizem suas ações, o que é essencial para o desenvolvimento de aplicações multiprocessadas.

## Introdução

A Comunicação entre Processos é um aspecto crucial da programação de sistemas, permitindo que processos compartilhem dados e sincronizem operações de forma eficiente. Este projeto implementa vários métodos de IPC, demonstrando seu uso e funcionalidade em C.

## Mecanismos de IPC Abordados

### Pipes

Pipes permitem que os dados fluam em uma direção entre processos. Esta seção inclui exemplos de pipes não nomeados e nomeados, mostrando como criá-los e usá-los para comunicação.

### Filas de Mensagens

Filas de mensagens fornecem uma maneira para os processos trocarem mensagens em uma ordem FIFO. Esta seção detalha como criar e manipular filas de mensagens usando chamadas de sistema.

### Memória Compartilhada

Segmentos de memória compartilhada permitem que vários processos acessem uma área comum de memória, facilitando o compartilhamento rápido de dados. Esta seção aborda a criação, anexação e desanexação de memória compartilhada.

### Semáforos

Semáforos são ferramentas de sincronização usadas para gerenciar o acesso a recursos compartilhados. Esta seção explora como implementar semáforos em C para evitar condições de corrida.
