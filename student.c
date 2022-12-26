#include <string.h>
#include "student.h"

struct Student get_default_student(void) {
  int age, group;
  char name[20];

  age = 23;
  group = 2;
  name = "Michael";

  struct Student default_student;
  default_student.age = age;
  default_student.group = group;
  strcpy(default_student.name, name)

  return default_student;
};
