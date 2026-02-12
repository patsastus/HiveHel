# [minishell]

*This project has been created as part of the 42 curriculum by nraatika, [zfarah](https://github.com/zakaria552).*

---
### Goal
Create a functional UNIX shell. 
### Compilation
To compile the project, run the following command in the root directory:

```bash
make
./minishell
```
### Implementation details.
This was a large step up in complexity in the curriculum: making a fully functional (if limited in scope) shell. We were required to implement executing arbitrary commands, including input and output redirects, pipes, and variable expansions, as well as some basic built-in functions that other shells have such as `cd`and `echo`. Overall, the project splits into two clear parts: **parsing** and **execution**. The program is essentially in an infinite loop of 
- reading an input line from the user (the **readline**-loop)
- parsing that command (and checking it for syntax errors)
- executing that command (while checking for runtime errors and signals that would interrupt)
### Parsing
This was my main workload. I split the work into two sections here: first **tokenizing** the input, and then **parsing** the input into structured commands that could be passed to the execution part of the program. 
#### Tokenizing
This is the process of splitting the input into discrete chunks, and detecting what type of chunk we're dealing with. So the command
```
echo "Hello "World'!' -n >hello.txt|ls $PATH
```
first gets cut into a vector of chunks:

| Type                 | content   | tag           |
| -------------------- | --------- | ------------- |
| String               | echo      | string-type   |
| Empty                |           |               |
| Double-quoted string | "Hello "  | string-type   |
| String               | World     | string-type   |
| Single-quoted string | '!'       | string-type   |
| Empty                |           |               |
| String               | -n        | string-type   |
| Empty                |           |               |
| Output redirect      | >         | redirect-type |
| String               | hello.txt | string-type   |
| Pipe                 | \|        |               |
| String               | ls        |               |
| Empty                |           |               |
| Variable             | $PATH     | string-type   |
This array gets passed to 
#### Parsing
Here is where the main logic of Parsing is implemented, which aims to build a **command struct** from the command (or multiple ones if pipes are involved):
> **`command struct`**
>
> | variable  | type     |
> | --------- | ------- |
> | command   | char* |
> | arguments | vector* |
> | redirect  | vector* |
 
If the resultant struct passes checks, it gets added to a vector of command structs 
#### Syntax errors
There are many syntax rules associated with building those structs, the main error cases are:
- unmatched single or double quotes 
- empty redirects (so redirects without an accompanying string-type token)
- empty pipes (a section between two pipes without anything getting parsed into the command variable)
#### Commands, arguments and redirects
We use the *empty* tokens to split the token vector, and in essence the first 'string-type' variable is stored in the command variable, any further string types get appended to the arguments vector, any redirect type searches for the next string type, has that attached to itself and gets added to the redirect vector. If a pipe is encountered, that means a command struct is finalized, and another is created, and the process starts over.
Some of the rules for manipulating string-type tokens:
- any *Variable* type gets transformed into a string by looking at a variable expansion array, or an entry string if the name isn't found
- any double- or single-quoted strings have their outer quotes stripped
	- double-quoted strings are scanned for *variable* type substrings to expand
- any sequence of string-type tokens get concatenated
### Execution
Execution gets a vector of command structs, and does a few things:
- goes through the whole vector of commands to check for *Here-docs* (`<<` tokens) in the redirect list
	- runs a function to collect and write some input into a temporary file
- if there are redirects, finds the last input and last output redirect
- checks if the command is in the list of built-in commands
	- if not, reformats the command and arguments to the format the `execve` command expects
Once that preprocessing is done, it goes in a loop of creating a child process, and executing a command in that process (after doing the necessary pipe gymnastics to ensure proper chaining of command input and output). It also checks the exit status each child process returns, so it can correctly update the status variable `$?`.
### Signal handling
All along, we register some signal handlers to listen to Ctrl-C  (`SIGINT`) or Ctrl-\ (`SIGQUIT`) input, while the readline-loop handles inputs of Ctrl-D, which acts as an EOF passed to the current input.

### Memory management
For this project, we implemented a **memory arena**, a chunk of storage allocated at the start of every loop our shell, and freed once it concludes. This allowed us to not spend too much time worrying about memory leaks, and while it did mean rewriting many functions that we had created earlier in our studies, that seemed a good choice still.