#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_name() {
  int *p_name;
  int n;
  char i[20];
  p_name = (int *)malloc(sizeof(int) * n);
}

void print_nums() {
  int *ptr;
  int n, i;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  ptr = (int *)malloc(sizeof(int) * n);
  if (ptr == NULL) {
    printf("Error! memory not allocated.");
    exit(0);
  } else {
    for (i = 0; i < n; ++i) {
      ptr[i] = i + 1;
    }
    for (i = 0; i < n; ++i) {
      printf("%d, ", ptr[i]);
    }
  }
}

void malloc_names() {
  // which is the amount of bytes that is required to
  // store 5 int values.

  // The memory allocated by calloc will be
  // zero-initialized, but the memory allocated with
  // malloc will be uninitialized so reading it would be
  // undefined behavior.
  //
  int *allocated_with_malloc = malloc(5 * sizeof(int));
  int *allocated_with_calloc = calloc(5, sizeof(int));

  // As you can see, all of the values are initialized to
  // zero.
  printf("Values of allocated_with_calloc: ");
  for (size_t i = 0; i < 5; ++i) {
    printf("%d ", allocated_with_calloc[i]);
  }
  putchar('\n');

  // This malloc requests 1 terabyte of dynamic memory,
  // which is unavailable in this case, and so the
  // allocation fails and returns NULL.
  int *failed_malloc = malloc(1000000000000);
  if (failed_malloc == NULL) {
    printf("The allocation failed, the value of "
           "failed_malloc is: %p",
           (void *)failed_malloc);
  }

  // Remember to always free dynamically allocated memory.
  free(allocated_with_malloc);
  free(allocated_with_calloc);
}

int main(void) {
  malloc_names();
  /* print_nums();
  print_name(); */
  return 0;
}
