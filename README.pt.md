# minitalk

[Read in English](README.md)

Uma implementação de comunicação entre processos utilizando sinais UNIX.

- **Objetivo**: Criar um programa de comunicação entre um cliente e um servidor utilizando sinais UNIX.

- **Funcionalidade**:
  - O **servidor** deve ser iniciado primeiro e exibir seu PID ao iniciar.
  - O **cliente** recebe como parâmetros o PID do servidor e a string a ser enviada.
  - O cliente envia a string ao servidor utilizando apenas os sinais `SIGUSR1` e `SIGUSR2`.
  - O servidor recebe a string e a imprime rapidamente na saída padrão.
  - O servidor deve conseguir lidar com múltiplos clientes sem precisar ser reiniciado.

- **Detalhes da Implementação**:
  - O **servidor** escuta sinais recebidos e reconstrói a mensagem bit a bit.
  - O **cliente** converte cada caractere da mensagem em uma sequência binária de 8 bits e transmite utilizando sinais.
  - Uma estrutura global (`t_state`) é utilizada para gerir os bits recebidos e reconstruir a mensagem.
  - Uma função de limpeza garante a gestão adequada da memória e evita vazamentos.
  - O projeto lida com **SIGINT** (`Ctrl + C`) de forma adequada, garantindo que a memória seja libertada antes de sair.

- **Funções Permitidas**:  
  | Função       | Descrição |
  |--------------|-------------|
  | `write`      | Escreve na saída padrão |
  | `ft_printf`  | Imprime mensagens formatadas |
  | `signal`     | Define um manipulador de sinais |
  | `sigemptyset` | Inicializa um conjunto de sinais vazio |
  | `sigaddset`  | Adiciona um sinal ao conjunto |
  | `sigaction`  | Define ações para sinais |
  | `kill`       | Envia sinais para processos |
  | `getpid`     | Obtém o PID do processo atual |
  | `malloc`     | Aloca memória dinamicamente |
  | `free`       | Liberta memória alocada |
  | `pause`      | Pausa o processo até receber um sinal |
  | `sleep`      | Suspende a execução por um tempo especificado |
  | `usleep`     | Suspende a execução por um tempo em microssegundos |
  | `exit`       | Termina o programa |

- **Regras do Projeto**:
  - O código segue estritamente a norma **norminette** da 42.
  - Nenhum vazamento de memória é permitido.
  - O cliente e o servidor devem ser compilados separadamente e nomeados `client` e `server`.
  - Um `Makefile` deve ser fornecido para compilar os arquivos sem relink.

- **Makefile**:
  - Automatiza o processo de compilação do `minitalk`.
  - **Regras**:
    - `make` ou `make all`: Compila `client` e `server`.
    - `make clean`: Remove ficheiros objeto (`.o`).
    - `make fclean`: Remove ficheiros compilados e executáveis.
    - `make re`: Recompila o projeto do zero.

- **Exemplo de Uso**:
  ```bash
  # Iniciar o servidor
  ./server
  # O servidor exibirá seu PID, por exemplo: 76435

  # Executar o cliente para enviar uma mensagem ao servidor
  ./client 76435 "Vski, king of heaven!"
  ```

- **Desafios e Aprendizagem**:
  - Compreensão de sinais UNIX e IPC (Inter-Process Communication).
  - Implementação de um protocolo de comunicação robusto e fiável.
  - Garantia da integridade dos dados durante a transmissão sem perdas.
  - Manipulação eficiente de processos e sinais em C.
  - Gestão dinâmica de memória e prevenção de vazamentos.
  - Tratamento assíncrono da receção de sinais e sincronização de processos.

---
