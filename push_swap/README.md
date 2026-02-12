# [push_swap]

*This project has been created as part of the 42 curriculum by nraatika.*

---
### Goal
Write a program that sorts an input list of numbers using two stacks, and a limited selection of allowed actions:

| Action\Target  | Stack A | Stack B | Both  | Explanation                                             |
| :------------- | :------ | :------ | :---- | ------------------------------------------------------- |
| Swap           | `sa`    | `sb`    | `ss`  | Swap the top two elements of target stack               |
| Rotate         | `ra`    | `rb`    | `rr`  | Rotate target stack up, so first element becomes last   |
| Reverse rotate | `rra`   | `rrb`   | `rrr` | Rotate target stack down, so last element becomes first |
| Push           | `pa`    | `pb`    | -     | Push element into target stack from other stack         |
The exercise is graded based on the number of operations it took to reach a sorted stack.
### Compilation
To compile the project, run the following command in the root directory:

```bash
make
./push_swap 1 7 8 9 -2 #or any list of unique integers
```
This will output a set of instructions, that should result in a sorted stack. The provided `checker`program can be used to verify.
### Implementation details
The constraints of the exercise are such that you won't achieve full marks with any well-known sorting algorithms. Rather, you'd need something like a greedy look-ahead algorithm to choose the move that minimizes the number of operations. I instead chose to make a somewhat generalizable sorting algorithm, based on the **divide-and-conquer** approach: 

I first calculate cutoff points to split the input into some number of sub-problems, push all elements in that subproblem to stack b, and then use a greedy approach: check which of the following costs fewer moves, and execute that: 
- rotating stack b so the **smallest** remaining number is on top, push it to stack a and rotate stack a once
or
- rotating stack b so the **largest** remaining number is on top, push it to stack a.
This ensures the current subproblem ends up as a sorted section of stack a, and the final result is a fully sorted stack (making sure to rotate stack a to the correct spot between subproblems, and at the end).

### Useful links
[I found this site made by other students very useful in visualizing what's going on](https://push-swap42-visualizer.vercel.app/). You can use it to generate a set of random numbers, run them through your algorithm, and paste the output of your program into the instructions tab, and loop through a visualization of your algorithm at work.
