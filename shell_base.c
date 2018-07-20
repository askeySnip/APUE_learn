#include "apue.h"
#include <sys/wait.h>

int
main(void)
{
  char buf[MAXLINE];
  pid_t pid;
  int status;

  printf("%% ");    /* print prompt (printf requires double % to print %) */
  while (fgets(buf, MAXLINE, stdin) != NULL) {
    if (buf[strlen(buf)-1] == '\n') {
      buf[strlen(buf)-1] = 0;    /* replace newline with null */
    }

    if ((pid = fork()) < 0) {
      printf("fork error");
      exit(1);
    } else if (pid == 0) {
      execlp(buf, buf, (char *)0);
      // err_ret("couldn't execute: %s", buf);
      exit(127);
    }

    if ((pid = waitpid(pid, &status, 0)) < 0) {
      printf("waitpid error");
      exit(1);
    }
    printf("%% ");
  }
  exit(0);
}
