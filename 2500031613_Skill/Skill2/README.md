# Skill 2 – Interactive Command Loop

## Objective

To create an interactive command loop that displays a prompt, reads user input, processes commands, and handles the exit condition.

## Concepts Used

* `read()` system call
* `write()` system call
* Character/string buffer
* `while` loop
* Conditional statements
* String comparison using `strcmp()`

## Program Description

The program continuously displays the prompt `myshell>` and waits for the user to enter a command.

The entered command is stored in a character buffer using the `read()` system call.

If the user enters `exit`, the program terminates. Otherwise, it displays the entered command and shows the prompt again.

## How to Compile

```bash
gcc skill2.c -o skill2
```

## How to Run

```bash
./skill2
```

## Sample Output

```text
myshell> hello
You entered: hello

myshell> operating system
You entered: operating system

myshell> test
You entered: test

myshell> exit
Exiting...
```

## Conclusion

The program demonstrates the basic structure of an interactive command-line loop using Linux system calls such as `read()` and `write()`. It also demonstrates input buffering, command processing, and exit-condition handling.
