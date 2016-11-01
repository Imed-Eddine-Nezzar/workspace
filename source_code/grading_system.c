#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


void swap_ptr(void** fst, void** snd) {
  void* tmp = *fst;
  *fst = *snd;
  *snd = tmp;
}

void* memdupl(void* addr, size_t n) {
  void* dupl = malloc(n);
  memcpy(dupl, addr, size);
  return dupl;
}

char* readline(char* dest, size_t n, FILE* stream) {
  char c;
  while((c = fgetc(stream)) != EOF && c != '\n' && --n)
    *dest++ = c;
  dest = '\0';
  return dest;
}


typedef struct student {
  char* name;
  float* grades;
  float avrg;
  uint8_t ngrades;
} student_s, * student_ptr;


void student_init(
    student_ptr s,
    char* name,
    float* grades,
    uint8_t ngrades)
{
  s->name = (char*) memdupl(name, strlen(name) + 1);
  s->grades = (float*) memdupl(grades, ngrades * sizeof(float));
  s->ngrades = ngrades;
}

void student_destroy(student_ptr s) {
  free(s->name);
  free(s->grades);
}

void student_swap(student_ptr fst, student_ptr snd) {
  swap_ptr(fst->name, snd->name, sizeof(char*));
  swap_ptr(fst->grades, snd->grades);
}

void student_print(student_ptr s, char** labels) {
}

