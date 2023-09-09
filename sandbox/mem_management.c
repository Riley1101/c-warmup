#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mall() {
  char *s = malloc(10);
  strcpy(s, "hello");
  printf("%s\n", s);
  int n;
  printf("Enter length of message \n");
  scanf("%d", &n);

  char *ptr = malloc(sizeof(char) * n);
  scanf("%s", ptr);
  printf("Message = %s \n", ptr);

  printf("Relloc the length of message \n");
  scanf("%d", &n);
  ptr = realloc(ptr, sizeof(char) * n);
  printf("Enter  message \n");

  scanf("%s", ptr);
  printf("Message = %s \n", ptr);
}

void reall() {
  char *s = malloc(6);
  strcpy(s, "hello");
  s = realloc(s, 11);
  strcat(s, " world");
  printf("%s\n", s);

  int *nums = malloc(sizeof(int) * 5);
  for (int i = 0; i < 5; ++i) {
    nums[i] = i + 1;
  }
  for (int i = 0; i < 5; ++i) {
    printf("%d, ", nums[i]);
  }
  free(nums);
}

void copy_move() {
  char *s = "System";
  char *s2 = malloc(8);
  memcpy(s2, s, 8);
  printf("%s\n", s2);

  char *c = malloc(1);
  free(c);
  c = NULL;
}

int main(void) { copy_move(); }
