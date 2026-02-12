# [minitalk]

*This project has been created as part of the 42 curriculum by nraatika.*

---
### Goal
Create two separate programs (`client` and `server`), that communicate via two `UNIX`signals to send an arbitrary length text from client to server.
### Compilation
To compile the project, run the following command in the root directory:

```bash
make
make bonus
```
### Usage
in one terminal, run
```
./server
```
this will print out the PID of the server, so the client knows which process it's sending signals to. then, in another terminal, run:
```
./client PID "The message to be sent"
```

To use the bonus version, which includes the server acknowledging a received message, go into the `bonus_obj`directory, and repeat the above
