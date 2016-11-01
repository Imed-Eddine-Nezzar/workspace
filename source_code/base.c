#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void readline(char* dest, FILE* src) {
    char c;
    while((c = fgetc(src)) != EOF && c != '\n')
        *dest++ = c;
    *dest = '\0';
}

typedef struct student {
  char* name;
  float avrg;
  float* points;
  size_t npoints;
} student_s, *student_ptr;


void student_init(student_ptr s, char* name, float* points, size_t npoints) {

  s->name = (char*)malloc(strlen(name) * sizeof(char));
  strcpy(s->name, name);

  s->points = (float*) malloc(npoints * sizeof(float));
  memcpy(s->points, points, npoints * sizeof(float));

  s->npoints = npoints;

  float sum = 0.0;
  for (int i = 0; i < npoints; ++i)
    sum += points[i];
  s->avrg = sum / npoints;
}


void student_print(student_ptr s) {
  printf("name: %s\n", s->name);

  printf("score: \n");
  for (int i = 0; i < s->npoints; ++i)
    printf("%.1f ", s->points[i]);
  putchar('\n');

  printf("average: %.1f\n", s->avrg);
}


void student_delete(student_ptr s) {
  free(s->name);
  free(s->points);
}


void read_student(student_ptr s, size_t n) {
  printf("Enter student name [max 40 letters]: ");
  char buf[40];
  readline(buf, stdin);

  printf("Enter points: ");
  float points[n];
  for (int i = 0; i < n; ++i)
    scanf("%f", &points[i]);
  student_init(s, buf, points, n);
}

int main() {
  student_s st;
  /* float points[] = {1, 2, 3}; */
  read_student(&st, 3);
  /* student_init(&st, "imad", points, sizeof(points) / sizeof(float)); */
  student_print(&st);
  student_delete(&st);
}
