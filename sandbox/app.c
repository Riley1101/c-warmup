#include <stdio.h>
#include <string.h>

struct Cords {
  int x;
  int y;
};

typedef struct Cords Point;

struct base {
  struct child {
    int x;
  } child;
};

struct movie {
  char title[30];
  char director[30];
  int year;
  int duration;
  struct category {
    char genre[30];
    char rating[30];
  } category;
};

struct Books {
  char title[30];
  char author[40];
  char subject[100];
  int book_id;
};

union Data {
  int i;
  float d;
  char str[20];
};

void print_movie(struct movie movie) {
  printf("Title: %s\n", movie.title);
  printf("Director: %s\n", movie.director);
  printf("Year: %d\n", movie.year);
  printf("Duration: %d\n", movie.duration);
  printf("Genre: %s\n", movie.category.genre);
  printf("Rating: %s\n", movie.category.rating);
}

void print_cords(Point point) {
  printf("x: %d\n", point.x);
  printf("y: %d\n", point.y);
}

void print_union(union Data data) {
  printf("data.i : %d\n", data.i);
  printf("data.i : %f\n", data.d);
  printf("data.i : %s\n", data.str);
}

void print_books(struct Books book) {
  printf("Book 1 title : %s\n", book.title);
  printf("Book 1 author : %s\n", book.author);
  printf("Book 1 subject : %s\n", book.subject);
  printf("Book 1 book_id : %d\n", book.book_id);
}

void pointer_arithematics() {
  int arr[4] = {1, 2, 3, 4};
  int *ptr = arr;
  for (int i = 0; i < 4; i++) {
    if (i == 2) {
      *ptr = 10;
    }
    printf("arr[%d] = %d\n", i, *ptr++);
  }
}

void passed_by_ref(int *num) {
  *num = 10;
  printf("Value of num is: %d\n", *num);
}

void swap(int *x, int *y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

void autoStorageClass() {
  printf("autoStorageClass\n");
  auto int a = 21;
  printf("Value of a is automatically created a = %d\n", a);
}

void externStorageClass() { printf("externStorageClass\n"); }

void staticStorageClass() {
  int i = 0;

  printf("\nDemonstrating static class\n\n");

  // using a static variable 'y'
  printf("Declaring 'y' as static inside the loop.\n"
         "But this declaration will occur only"
         " once as 'y' is static.\n"
         "If not, then every time the value of 'y' "
         "will be the declared value 5"
         " as in the case of variable 'p'\n");

  printf("\nLoop started:\n");

  for (i = 1; i < 5; i++) {

    // Declaring the static variable 'y'
    static int y = 5;

    // Declare a non-static variable 'p'
    int p = 10;

    // Incrementing the value of y and p by 1
    y++;
    p++;

    // printing value of y at each iteration
    printf("\nThe value of 'y', "
           "declared as static, in %d "
           "iteration is %d\n",
           i, y);

    // printing value of p at each iteration
    printf("The value of non-static variable 'p', "
           "in %d iteration is %d\n",
           i, p);
  }

  printf("\nLoop ended:\n");

  printf("--------------------------------");
}

void register_check() {
  int i = 12;
  register int *a = &i;
  printf("\n %d \n", *a);
}

void pointer_check() {
  int x = 12;
  int *pX = &x;
  int **pY = &pX;
  int ***pZ = &pY;
  int bloom = ***pZ;
  int y = *pX;
  printf("\n y - %d \n", y);
  printf("\n bloom - %d \n", bloom);
}

struct Person {
  int age;
  char name[20];
};

typedef struct Person Person;

void updatePerson(Person *person) {
  person->age = 20;
  strcpy(person->name, "John Doe");
}

void print_person() {
  struct Person person;
  strcpy(person.name, "John");
  person.age = 12;
  updatePerson(&person);

  printf("\n %s \n", person.name);
  printf("\n %u \f", person.age);
}

struct User {
  char name[64];
  int age;
};

void pointer_math() {
  struct User user[100];
  struct User *p_user = user;
  for (int i = 0; i < 100; i++) {
    // print age
    printf("%d\n", p_user->age);
    p_user->age = 0;
    p_user += 1;
  }
}

int main() {
  pointer_math();
  print_person();
  pointer_check();
  register_check();
  staticStorageClass();
  autoStorageClass();
  externStorageClass();
  struct Books Book1;
  union Data data;
  data.i = 10;
  data.d = 220.5;
  strcpy(data.str, "C Programming");
  Book1.book_id = 6495407;
  strcpy(Book1.title, "C Programming");
  strcpy(Book1.author, "Nuha Ali");
  strcpy(Book1.subject, "C Programming Tutorial");
  print_books(Book1);
  print_union(data);
  pointer_arithematics();
  int num = 5;
  passed_by_ref(&num);
  int x = 12;
  int y = 13;
  swap(&x, &y);
  printf("x = %d, y = %d \n", x, y);
  Point point;
  point.x = 10;
  point.y = 20;
  print_cords(point);
  struct base base;
  base.child.x = 10;
  struct movie movie;
  movie = (struct movie){
      "The Dark Knight", "Christopher Nolan", 2008, 152, {"Action", "PG-13"}};
  print_movie(movie);
}
