#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct stack {
  int top;
  int items[MAX];
};

typedef struct stack stack;

void create_empty(stack *s) { s->top = -1; }

int is_full(stack *s) {
  if (s->top == MAX - 1) {
    return 1;
  } else {
    return 0;
  }
}

int is_empty(stack *s) {
  if (s->top == -1) {
    return 1;
  } else {
    return 0;
  }
}

int push(stack *s, int new_item) {
  if (is_full(s)) {
    printf("Stack is full");
    exit(0);
  };
  s->top++;
  s->items[s->top] = new_item;
  return new_item;
}

int pop(stack *s) {
  if (is_empty(s)) {
    printf("Stack is empty");
    exit(0);
  }
  int item = s->items[s->top];
  s->top--;
  return item;
}

void print_stack(stack *s) {
  for (int i = 0; i < s->top + 1; i++) {
    printf(" item => %d", s->items[i]);
  }
}

int main(void) {
  int ch;
  stack *s = (stack *)malloc(sizeof(stack));
  create_empty(s);
  push(s, 1);
  push(s, 2);
  push(s, 3);
  push(s, 4);
  print_stack(s);
}
