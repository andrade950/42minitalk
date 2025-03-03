# minitalk

[Leia em Português](README.pt.md)

An implementation of interprocess communication using UNIX signals.

- **Objective**: Create a communication program between a client and a server using UNIX signals.

- **Functionality**:
  - The **server** must be started first and display its PID upon initialization.
  - The **client** receives the server's PID and the string to be sent as parameters.
  - The client sends the string to the server using only the `SIGUSR1` and `SIGUSR2` signals.
  - The server receives the string and quickly prints it to the standard output.
  - The server must be able to handle multiple clients without needing to restart.

- **Implementation Details**:
  - The **server** listens for incoming signals and reconstructs the message bit by bit.
  - The **client** converts each character of the message into an 8-bit binary sequence and transmits it using signals.
  - A global state structure (`t_state`) is used to manage incoming bits and reconstruct the message.
  - A cleanup function ensures proper memory management and prevents memory leaks.
  - The project handles **SIGINT** (`Ctrl + C`) gracefully by freeing memory before exiting.

- **Allowed Functions**:  
  | Function       | Description |
  |--------------|-------------|
  | `write`      | Writes to the standard output |
  | `ft_printf`  | Prints formatted messages |
  | `signal`     | Defines a signal handler |
  | `sigemptyset` | Initializes an empty signal set |
  | `sigaddset`  | Adds a signal to the set |
  | `sigaction`  | Defines actions for signals |
  | `kill`       | Sends signals to processes |
  | `getpid`     | Retrieves the current process PID |
  | `malloc`     | Allocates memory dynamically |
  | `free`       | Frees allocated memory |
  | `pause`      | Pauses the process until a signal is received |
  | `sleep`      | Suspends execution for a specified time |
  | `usleep`     | Suspends execution for a specified time in microseconds |
  | `exit`       | Terminates the program |

- **Project Guidelines**:
  - The code strictly follows the 42 **norminette** standard.
  - No memory leaks are allowed.
  - The client and server must be compiled separately and named `client` and `server`.
  - A `Makefile` must be provided to compile the files without relinking.

- **Makefile**:
  - Automates the compilation process for `minitalk`.
  - **Rules**:
    - `make` or `make all`: Compiles `client` and `server`.
    - `make clean`: Removes object files (`.o`).
    - `make fclean`: Removes compiled files and executables.
    - `make re`: Recompiles the project from scratch.

- **Usage Example**:
  ```bash
  # Start the server
  ./server
  # The server will display its PID, for example: 43523

  # Run the client to send a message to the server
  ./client 43523 "Vski, rei dos ceus!"
  ```

- **Challenges and Learning Outcomes**:
  - Understanding UNIX signals and IPC (Inter-Process Communication).
  - Implementing a robust and reliable communication protocol.
  - Ensuring data integrity during transmission without losses.
  - Efficiently handling processes and signals in C.
  - Managing dynamic memory and preventing leaks.
  - Handling asynchronous signal reception and process synchronization.


---
