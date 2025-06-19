# 🔗 Data Link Layer Error Detection Techniques using Socket Programming in C

This project demonstrates **various error detection techniques** implemented at the **Data Link Layer** of the **OSI Model**, using **Socket Programming in C**. The communication environment simulates two networked devices using **two separate terminals on the same computer**. The core techniques implemented include:

- Hamming Code
- CRC (Cyclic Redundancy Check)
- Parity Bit Method
- Checksum
- Chat Server (Simple Socket Communication)

---
#⚙️ Setup & Execution<br>

🖥️ Requirements<br>

GCC Compiler<br>

----------------------------------
Linux Terminal (or WSL on Windows)<br>

-----------------------------------------
Basic knowledge of C and socket programming<br>

#How to run:--<br>

1.Linux<br>

🧪 Compilation<br>
---------------------
You can compile each program using the following command:<br>

gcc filename.c -o outputname<br>

Example:<br>

gcc hamming_code.c -o hamming<br>

🔌 Running the Programs<br>

----------------------
Open two terminal windows:<br>

One as Server<br>

One as Client<br>

Example for hamming_code.c:<br>

# Terminal 1 (Server)<br>

./hamming server<br>

# Terminal 2 (Client)<br>

./hamming client<br>

2.windows<br>

A.for windows instead of arpa/inet.h you need to include <br>

#include <winsock2.h><br>

#include <ws2tcpip.h><br>

B.before using socket you need to write this lines:<br>

WSADATA wsa;<br>

WSAStartup(MAKEWORD(2,2), &wsa);<br>

C.After using socket,at last you need to clean it up:<br>

WSACleanup();<br>

🧪 Compilation<br>

---------------------
You can compile each program using the following command:<br>

gcc filename.c -o outputname.exe -lws2_32<br>

Example:<br>

gcc hamming_code.c -o hamming.exe -lws2_32<br>

🔌 Running the Programs<br>

----------------------
Open two terminal windows:<br>

One as Server<br>

One as Client<br>

Example for hamming_code.c:<br>

# Terminal 1 (Server)<br>

hamming server<br>
# Terminal 2 (Client)<br>

hamming client<br>



