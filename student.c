#include <string.h>
#include "student.h"

int init_default_student (Student *student) {
  student->age = 23;
  student->group = 2;
  strcpy(student->name, "Michael");
  return 0;
}
