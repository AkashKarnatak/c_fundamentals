#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Vec {
  int *p;
  size_t capacity;
  size_t len;
};

struct Vec vec_new() {
  struct Vec vec;
  vec.p = (int *)malloc(sizeof(int));
  vec.capacity = 1;
  vec.len = 0;
  return vec;
}

bool vec_push(struct Vec *vec, int x) {
  if (vec == NULL || vec->p == NULL)
    return false;

  if (vec->len == vec->capacity) {
    int *new_p = (int *)realloc(vec->p, 2 * vec->capacity * sizeof(int));

    if (new_p == NULL)
      return false;

    vec->capacity *= 2;
    vec->p = new_p;
  }
  vec->p[vec->len++] = x;

  return true;
}

bool vec_pop(struct Vec *vec, int *value) {
  if (vec == NULL || vec->p == NULL || vec->len == 0 || value == NULL)
    return false;

  --vec->len;
  *value = vec->p[vec->len];

  return true;
}

void free_vec(struct Vec *vec) {
  if (vec != NULL || vec->p != NULL) {
    free(vec->p);
    vec->p = NULL;
    vec->capacity = 0;
    vec->len = 0;
  }
}

void vec_print(struct Vec *vec) {
  if (vec == NULL || vec->p == NULL) return;

  printf("[");
  for (size_t i = 0; i < vec->len; ++i) {
    printf(" %d,", vec->p[i]);
  }
  if (vec->len != 0)
    printf("\b ");
  printf("]\n");
}

int main() {
  struct Vec vec = vec_new();

  vec_print(&vec);

  vec_push(&vec, 1);
  vec_push(&vec, 2);
  vec_push(&vec, 3);
  vec_push(&vec, 4);

  vec_print(&vec);

  int value = 0;
  vec_pop(&vec, &value);
  printf("Popped %d\n", value);
  vec_pop(&vec, &value);
  printf("Popped %d\n", value);
  vec_pop(&vec, &value);
  printf("Popped %d\n", value);

  vec_print(&vec);

  free_vec(&vec);
  return 0;
}
