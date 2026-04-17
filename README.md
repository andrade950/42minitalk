<div align="center">

# 📡 minitalk

**Interprocess communication over UNIX signals, in C**

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![IPC](https://img.shields.io/badge/IPC-UNIX%20Signals-orange.svg)](#how-it-works)
[![Norm](https://img.shields.io/badge/42-Norminette-brightgreen.svg)](#guidelines)

[Leia em Português](README.pt.md)

</div>

---

## 📌 Overview

`minitalk` implements a client-server communication system using only two UNIX signals — `SIGUSR1` and `SIGUSR2`. Each character of a message is broken down into its 8-bit binary representation and transmitted signal by signal, then reconstructed on the server side.

---

## 🔁 How It Works

```
CLIENT                              SERVER
  │                                   │
  │  ./client <PID> "hello"           │  ./server  →  prints PID
  │                                   │
  │  'h' = 0b01101000                 │
  │  ──── SIGUSR1/SIGUSR2 ──────────► │  reconstruct bit by bit
  │  ──── SIGUSR1/SIGUSR2 ──────────► │  reconstruct bit by bit
  │  ──── ... (8 signals/char) ─────► │
  │                                   │  prints full message
  │  ◄─────────── SIGUSR1 ───────────  │  (acknowledgement)
```

1. The **server** starts first, prints its PID, and waits for incoming signals
2. The **client** takes the server PID and message as arguments
3. Each character is encoded as 8 bits — `SIGUSR2` for `1`, `SIGUSR1` for `0`
4. The server reconstructs each character bit by bit and prints the full message
5. The server sends back an acknowledgement signal so the client can proceed safely
6. The server stays alive to handle further clients without restarting

---

## 🛠️ Allowed Functions

| Function | Description |
|----------|-------------|
| `write` | Write to standard output |
| `ft_printf` | Print formatted messages |
| `signal` | Register a signal handler |
| `sigemptyset` | Initialise an empty signal set |
| `sigaddset` | Add a signal to a set |
| `sigaction` | Define fine-grained signal actions |
| `kill` | Send a signal to a process |
| `getpid` | Get the current process PID |
| `malloc` | Allocate memory dynamically |
| `free` | Free allocated memory |
| `pause` | Suspend until a signal is received |
| `sleep` | Suspend execution for a given time |
| `usleep` | Suspend execution for a given time (microseconds) |
| `exit` | Terminate the program |

---

## 🚀 Usage

```bash
# Terminal 1 — start the server
./server
# Output: PID: 43523

# Terminal 2 — send a message
./client 43523 "Vski, rei dos ceus!"
```

---

## 🔧 Makefile

```bash
make          # Compile client and server
make clean    # Remove object files (.o)
make fclean   # Remove object files and executables
make re       # Full recompilation from scratch
```

---

## 📐 Guidelines

- Follows the 42 **norminette** coding standard strictly
- Zero memory leaks — a cleanup function handles all allocations on exit, including `SIGINT`
- `client` and `server` are compiled as separate binaries
- No relinking — the `Makefile` only recompiles what has changed

---

## 🧠 Key Concepts

- UNIX signals and IPC (Inter-Process Communication)
- Binary encoding and bit-level data transmission
- Asynchronous signal handling and process synchronisation
- Reliable protocol design without data loss
- Dynamic memory management in C

---
