# 🔗 Data Link Layer Error Detection Techniques using Socket Programming in C

This project demonstrates **various error detection techniques** implemented at the **Data Link Layer** of the **OSI Model**, using **Socket Programming in C**. The communication environment simulates two networked devices using **two separate terminals on the same computer**. The core techniques implemented include:

- Hamming Code
- CRC (Cyclic Redundancy Check)
- Parity Bit Method
- Checksum
- Chat Server (Simple Socket Communication)

---
#⚙️ Setup & Execution
🖥️ Requirements
GCC Compiler
----------------------------------
Linux Terminal (or WSL on Windows)
-----------------------------------------
Basic knowledge of C and socket programming
#How to run:--
1.Linux
🧪 Compilation
---------------------
You can compile each program using the following command:
gcc filename.c -o outputname
Example:
gcc hamming_code.c -o hamming
🔌 Running the Programs
----------------------
Open two terminal windows:
One as Server
One as Client
Example for hamming_code.c:
# Terminal 1 (Server)
./hamming server
# Terminal 2 (Client)
./hamming client
2.windows
A.for windows instead of arpa/inet.h you need to include 
#include <winsock2.h>
#include <ws2tcpip.h>
B.before using socket you need to write this lines:
WSADATA wsa;
WSAStartup(MAKEWORD(2,2), &wsa);
C.After using socket,at last you need to clean it up:
WSACleanup();
🧪 Compilation
---------------------
You can compile each program using the following command:
gcc filename.c -o outputname.exe -lws2_32
Example:
gcc hamming_code.c -o hamming.exe -lws2_32
🔌 Running the Programs
----------------------
Open two terminal windows:
One as Server
One as Client
Example for hamming_code.c:
# Terminal 1 (Server)
hamming server
# Terminal 2 (Client)
hamming client



