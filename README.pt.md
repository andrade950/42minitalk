<div align="center">

# 📡 minitalk

**Comunicação entre processos via sinais UNIX, em C**

[![Linguagem](https://img.shields.io/badge/Linguagem-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![IPC](https://img.shields.io/badge/IPC-Sinais%20UNIX-orange.svg)](#como-funciona)
[![Norm](https://img.shields.io/badge/42-Norminette-brightgreen.svg)](#regras)

[Read in English](README.md)

</div>

---

## 📌 Visão Geral

`minitalk` implementa um sistema de comunicação cliente-servidor usando apenas dois sinais UNIX — `SIGUSR1` e `SIGUSR2`. Cada caractere da mensagem é decomposto na sua representação binária de 8 bits e transmitido sinal a sinal, sendo depois reconstruído do lado do servidor.

---

## 🔁 Como Funciona

```
CLIENTE                             SERVIDOR
  │                                   │
  │  ./client <PID> "olá"             │  ./server  →  imprime PID
  │                                   │
  │  'o' = 0b01101111                 │
  │  ──── SIGUSR1/SIGUSR2 ──────────► │  reconstrói bit a bit
  │  ──── SIGUSR1/SIGUSR2 ──────────► │  reconstrói bit a bit
  │  ──── ... (8 sinais/char) ──────► │
  │                                   │  imprime mensagem completa
  │  ◄─────────── SIGUSR1 ───────────  │  (confirmação de receção)
```

1. O **servidor** arranca primeiro, imprime o seu PID e fica à espera de sinais
2. O **cliente** recebe o PID do servidor e a mensagem como argumentos
3. Cada caractere é codificado em 8 bits — `SIGUSR2` para `1`, `SIGUSR1` para `0`
4. O servidor reconstrói cada caractere bit a bit e imprime a mensagem completa
5. O servidor envia um sinal de confirmação para que o cliente possa continuar em segurança
6. O servidor permanece ativo para receber novos clientes sem necessitar de reiniciar

---

## 🛠️ Funções Permitidas

| Função | Descrição |
|--------|-----------|
| `write` | Escreve na saída padrão |
| `ft_printf` | Imprime mensagens formatadas |
| `signal` | Regista um handler de sinal |
| `sigemptyset` | Inicializa um conjunto de sinais vazio |
| `sigaddset` | Adiciona um sinal a um conjunto |
| `sigaction` | Define ações detalhadas para sinais |
| `kill` | Envia um sinal para um processo |
| `getpid` | Obtém o PID do processo atual |
| `malloc` | Aloca memória dinamicamente |
| `free` | Liberta memória alocada |
| `pause` | Suspende até receber um sinal |
| `sleep` | Suspende a execução por um tempo definido |
| `usleep` | Suspende a execução por um tempo em microssegundos |
| `exit` | Termina o programa |

---

## 🚀 Utilização

```bash
# Terminal 1 — iniciar o servidor
./server
# Output: PID: 76435

# Terminal 2 — enviar uma mensagem
./client 76435 "Vski, rei dos céus!"
```

---

## 🔧 Makefile

```bash
make          # Compila client e server
make clean    # Remove ficheiros objeto (.o)
make fclean   # Remove ficheiros objeto e executáveis
make re       # Recompilação completa do zero
```

---

## 📐 Regras

- Segue estritamente a norma **norminette** da 42
- Zero fugas de memória — uma função de limpeza trata de todas as alocações ao sair, incluindo em `SIGINT`
- `client` e `server` são compilados como binários separados
- Sem relink — o `Makefile` recompila apenas o que foi alterado

---

## 🧠 Conceitos-Chave

- Sinais UNIX e IPC (Inter-Process Communication)
- Codificação binária e transmissão de dados ao nível do bit
- Tratamento assíncrono de sinais e sincronização de processos
- Desenho de um protocolo fiável sem perda de dados
- Gestão dinâmica de memória em C

---
