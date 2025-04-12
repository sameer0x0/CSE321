#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LEN 1024
#define MAX_ARG 64

// parser:
void parse_input(char *input, char **args) {
  int i = 0;
  char *token = strtok(input, " \t\n");

  while (token != NULL && i < MAX_ARG - 1) {
    args[i] = token;
    i++;
    token = strtok(NULL, " \t\n");
  }

  args[i] = NULL;
}

// executor:
void execute_commads(char **args) {
  if (args[0] == NULL) {
    return;
  }

  pid_t pid = fork();
  if (pid == 0) {
    execvp(args[0], args);
    perror("execvp failed");
    exit(1);
  } else if (pid > 0) {
    waitpid(pid, NULL, 0);
  } else {
    perror("fork failed");
  }
}

int main() {
  char input[MAX_LEN];
  char *args[MAX_ARG];

  while (1) {
    printf("sh> ");
    fflush(stdout);

    if (fgets(input, MAX_LEN, stdin) == NULL) {
      break;
    }
    input[strcspn(input, "\n")] = '\0';
    parse_input(input, args);
    execute_commads(args);
  }
  return 0;
}
