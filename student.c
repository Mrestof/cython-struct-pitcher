#include <string.h>
#include "student.h"

int init_default_student (Student *student, int group_in) {
  student->age = 23;
  student->group = group_in;
  strcpy(student->name, "Michael");
  return 0;
}
