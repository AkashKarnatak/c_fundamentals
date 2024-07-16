#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

// NOTE: both fgets and getline function stores newline character
// in the buffer
int add_using_fgets() {
  // objective: read two integers and return their sum

  // define variables to store input
  int a, b;

  // read input
  char buf[BUFFER_SIZE];
  if (fgets(buf, BUFFER_SIZE, stdin) == NULL) {
    fprintf(stderr, "Failed to read line\n");
    return -1;
  }

  // parse input
  if (sscanf(buf, "%d %d", &a, &b) != 2) {
    fprintf(stderr, "Unable to parse input\n");
    return -1;
  }

  printf("Sum of %d and %d is %d\n", a, b, a + b);

  return 0;
}

int add_using_getline() {
  // objective: read two integers and return their sum

  // define variables to store input
  int a, b;

  // read input
  char *line = NULL;
  size_t size = 0;
  ssize_t len = getline(&line, &size, stdin);

  if (len == -1) {
    fprintf(stderr, "Failed to read line\n");
    return -1;
  }

  // parse input
  if (sscanf(line, "%d %d", &a, &b) != 2) {
    fprintf(stderr, "Unable to parse input\n");
    free(line);
    return -1;
  }

  printf("Sum of %d and %d is %d\n", a, b, a + b);

  // clear memory
  free(line);

  return 0;
}

int main() {
  /* if (add_using_getline() == -1) { */
  /*   fprintf(stderr, "Add function failed\n"); */
  /*   return -1; */
  /* } */
  if (add_using_fgets() == -1) {
    fprintf(stderr, "Add function failed\n");
    return -1;
  }

  return 0;
}
