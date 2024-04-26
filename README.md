# mini_talk
A small data exchange program in the form of a client and a server using only UNIX signals. The client must send the string passed as a parameter to the server. Once the string has been received by the client , the server must print it pretty quickly. Only two signals are allowed: SIGUSR1 and SIGUSR2.
## What are Signals ?
It's a form of communication between processes. Signals can be defined as a message, an event or an interrupt.  When a process receives a signal, the process will stop what its doing and take some action.
To send a signal to a specific program, you'll need to specify the PID of that program. That can be achieved using the getpid() fuction. Keep in mind that the program's PID will most definitely have a value that's higher than 0. PIDs of 0 and less have are reserved for the system: 

**PID > 0**: PIDs greater than 0 are assigned to user-space processes.

**PID 0**: This PID is reserved for the "swapper" or "scheduler" process, which is the first process created by the kernel during system initialization. This kernel thread manages system-level tasks. It is not associated with any user-space process.

**PID < 0**: represents special process group IDs (PGID), not an actual process. Specifically, the PID **-1** is used to broadcast signals to all processes except for the sender, and PID **-n** refers to process group n.

## How can users send a signal from one process to another ?

The server will have to decrypt the message sent by the client so that it can be displayed. Alternatively, the client will have to encrypt the message typed from the console so that it can be sent to the server bit by bit. So, the terminal will have to receive a binary representation of the message that you wish to send. We'll need to figure out away to convert the ASCII representation of each character that form the message to binary code, then sending each binary one by one to the server and setting a sleep time between each transmission to avoid signal overlap. 

You can either use bitwise operators to shift each binary and extract them. ALternatively, you can allocate a tab pointer that will store the value of the 8 bits which make up one character. Then sending the content of the tab respecting the order of the bits.

