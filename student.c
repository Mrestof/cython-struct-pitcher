#include <string.h>
#include "student.h"

struct Student get_default_student (void) {
  struct Student default_student;
  default_student.age = 23;
  default_student.group = 2;
  strcpy(default_student.name, "Michael");

  return default_student;
}
