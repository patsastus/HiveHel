# [philosophers]

*This project has been created as part of the 42 curriculum by nraatika.*

---
### Goal
This project is about discovering the challenges of **concurrent programming** in **multi-thread** or **multi-process** environments, explored via implementing the *dining philosophers problem* as 
- a multi-thread project, where every philosopher is in it's own thread
- a multi-process project, where every philosopher is it's own process

### Dining philosophers problem
This problem was set down by *E.W. Dijkstra*, and can be simplified as follows:
>$N$ philosophers are sitting around a round table, each with a bowl of food in front of them.
>They each have a fork to their right.
>A philosopher can either think, or eat
>To eat, they must use the for on their right *and* the one on their left (which is another philosophers 'right' fork)
>Design an algorithm that each philosopher can execute, that ensures every philosopher can eat regularly, without knowing the state of their neighboring philosophers

This [Wikipedia article](https://en.wikipedia.org/wiki/Dining_philosophers_problem) can expand the problem more.
For our version, we're actually asked to implement a third state philosophers can be in: sleeping. Each philosopher starts out thinking, then starts eating (when they can), and once finished eating, they sleep for some predetermined stretch of time, at which point they loop back to thinking. The problem is creating the internal logic that will ensure everyone can eat in orderly fashion, without getting accidentally deadlocked by their neighbors, when they're not allowed to know the state their neighbors are in.

### Compilation
To compile the project, run the following command in the  `philo` directory for the multi-thread version of the project, or in the `philo_bonus`directory for the multi-process version:

```bash
make
./philo 4 600 200 200 7
```

```bash
make
./philo_bonus 4 600 200 200 7
```

### Parameters
As the example above shows, the program expects some arguments, which are:
- the number of philosophers
- the time it takes for a philosopher to die (how long they can go between meals) (in milliseconds)
- the time a philosopher eats  (in milliseconds)
- the time a philosopher sleeps  (in milliseconds)
- \[an optional number of meals eaten by everyone that triggers the end of the simulation\]
We're asked to not test with values greater than 200 philosophers or times lower than 60 ms.

### Output
What the simulation outputs is a simple series of lines, each containing a timestamp (ms since the start of the simulation), and some information of a status change in a philosopher (the id, and what happened):
```
1 1 is thinking
1 1 has taken a fork
1 1 has taken a fork
1 1 is eating
1 2 is thinking
201 1 is sleeping
201 2 has taken a fork
201 2 has taken a fork
201 2 is eating
401 2 is sleeping
401 1 is thinking
```
The above example is the start of a simulation with 2 philosophers, where they eat for 200 ms and sleep for 200 ms.
### Multi-thread version
In this, I implemented a **philosophers' loop** function, that is run in it's own thread, and only has local knowledge of that philosopher: Timestamps regarding when the whole simulation started, when was the last time it ate, the current state (that cycles *thinking* $\to$ *eating* $\to$ *sleeping* $\to$ *thinking*...). It also needs to keep track of two shared resources: the forks on either side, each of which is shared with another philosopher.
The main thread runs a **monitor loop**, that checks that none of the philosophers have gone too long without eating (i.e. should have died by now). In order to do this, it has to check some variables in each philosophers' memory; this, and the shared forks, means that there is the possibility of **race conditions** (multiple threads accessing the same memory slot at the same time). To protect against this, I protect access with **mutexes**, so only one thread can have access at once, both for the monitor trying to read a philosophers' state when it's changing it, and two philosophers trying to use the same fork at the same time. 
There is actually also one more shared resource: each philosopher wants to write to standard out, and we don't want output to be garbled, so there is a mutex to protect write access as well.

### Multi-process version
In this, each philosopher runs in it's own **process**, so the problem changes slightly. We're no longer dealing with accessing shared memory; each process lives in it's own memory sandbox. This means no mutexes needed this time, rather we need some method for processes to communicate with each other. The solution is **semaphores**, a file-like construct that stores an unsigned integer, that each process has two ways to interact with:
- `sem_wait(semaphore_name)`: when a process calls this, the system checks the current state of that semaphore:
	- if it's greater than 0, it decreases by one, and the calling process can continue
	- if it's equal to 0, the calling process is inserted into a queue, and waits until the semaphore increases
- `sem_post(sempahore_name)`: the system increases the value of the semaphore by one. 
	- if the value was previously 0, the first process in the `waiting` queue un-hangs, and continues on from it's `wait` call, and the value goes back to 0.
There is one distinct difference in the problem setup from the multi-thread version: forks are no longer assigned to a philosopher; instead, they're in a shared pool. But there are still only the same number of forks as there are philosophers.
I use the semaphores in three different ways:
- as a counter of available resources (a *forks-semaphore*). Initialized to the number of philosophers being simulated.
- as an 'in-use' flag, so only one process writes to standard out at once (*write-semaphore* and *start-eating-semaphore*, the former quite analogous to the write-mutex in the multi-thread version, the latter to batch access to the forks; it does no good for multiple philosophers to grab one fork each, instead I only allow one at a time access to the forks-semaphore, so every philosopher gets 2 forks as quickly as is possible). Initialized to 1.
- as a 'signalling' flag, to pass some signal to each philosopher (*death-semaphore*, signalling that someone died and the simulation should stop.) Initialized to 0.
Each philosopher process runs three threads: 
- one running the main logic
- one monitor-thread to check that it shouldn't have died yet
- and one process that simply `waits` on the death-semaphore as a kill-switch, and if it ever returns from the `wait` call, it re-posts the semaphore to pass the message on to the other processes, and then exits the process.