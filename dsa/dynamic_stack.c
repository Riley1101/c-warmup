#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define INITIAL 5

struct dstack {
  int top;
  int *items;
  int size;
  int length;
};

typedef struct dstack dstack;

void create_empty(dstack *s) {
  s->size = INITIAL;
  s->top = -1;
  s->length = 0;
  s->items = (int *)malloc(INITIAL * sizeof(int));
}

bool is_full(dstack *s) {
  if (s->size == s->length) {
    return true;
  }
  return false;
}

bool is_empty(dstack *s) {
  if (s->length == 0) {
    return true;
  }
  return false;
}

void clear(dstack *s) {
  s->length = 0;
  s->top = -1;
  s->size = INITIAL;
  s->items = (int *)malloc(INITIAL * sizeof(int));
}

int _resize(dstack *s) {
  if (s->length == s->size) {
    s->size = s->size * 2;
    s->items = (int *)realloc(s->items, s->size * sizeof(int));
    return s->size;
  }
  return s->size;
}

int _free_unused(dstack *s) {
  if (s->length < s->size / 2) {
    s->size = s->size / 2;
    s->items = (int *)realloc(s->items, s->size * sizeof(int));
    return s->size;
  }
}

int push(dstack *s, int item) {
  if (is_full(s)) {
    _resize(s);
  }
  s->top++;
  s->length++;
  s->items[s->top] = item;
  return item;
}

int print_stack(dstack *s) {
  for (int i = 0; i < s->length; i++) {
    printf("%d\n", s->items[i]);
  }
  return 0;
}

void check_mem(dstack *s) {
  printf("-----------");
  printf("\n Size of dstack is %lx\n", sizeof(*s));
  printf("is_full: %u \n", is_full(s));
  printf("Size: %d\n", s->size);
  printf("Top: %d\n", s->top);
  printf("Length: %d\n", s->length);
  printf("-----------");
}

int pop(dstack *s) {
  if (is_empty(s)) {
    return 0;
  }
  int item = s->items[s->top];
  s->top--;
  return item;
}

int main(void) {
  dstack s;
  create_empty(&s);
  check_mem(&s);

  for (int i = 0; i < 1000; i++) {
    push(&s, i);
  }
  check_mem(&s);
  clear(&s);
  check_mem(&s);
}
