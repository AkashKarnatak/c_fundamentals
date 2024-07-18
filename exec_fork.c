#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int use_exec() {
  if (execl("ls", "ls", "-l", (char *) NULL) == -1) {
    perror("Unable to execute command");
    return 1;
  }
  return 0;
}

int use_fork() {
  pid_t child_pid = fork();
  if (child_pid == -1) { // error
    perror("Unable to fork process");
    return 1;
  } else if (child_pid == 0) { // child
    printf("From child process with PID: %d\n", getpid());
  } else { // parent
    printf("From parent process with PID: %d and child PID: %d\n", getpid(), child_pid);
    int wstatus = 0;
    sleep(1);
    pid_t child_pid = wait(&wstatus);
    if (child_pid == -1) {
      perror("wait() failed");
    } else {
      printf("Child with pid: %d exited\n", child_pid);
    }
  }
  printf("PID %d exiting\n", getpid());
  return 0;
}

int main(int argc, char *argv[])
{
  /* return use_exec(); */
  return use_fork();
}
