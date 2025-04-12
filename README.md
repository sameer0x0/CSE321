# CSE321

### Introduction:
In this assignment you have to implement a UNIX shell using C. Your shell will be able to run basic linux commands, I/O redirections and handle errors.

### Specifications

[X] The shell must implement the following core features:
  Display a command prompt (e.g., sh> ) and read user input.
  Parse and execute system commands.
  For example, running “pwd” will output the absolute path of the directory that your shell is working on.
  Hint: Use “fork” and “exec” system call
  
[] Support input (<) and output (> and >>) redirection.
  Hint: Use “dup” and “dup2”
  
[] Support command piping (|). Your shell should support any number of piping.
  For example, “command1 | command2 | command3 | command4” should work
[] Support multiple commands in-line separated by semicolon (;)
[] Support multiple command in sequence using (&&)
[] Support history of executed commands
[] Support signal handling. Pressing CTRL+C should terminate the currently running command inside your shell, not your shell.
  Hint: Use “signal” and “sigaction”
