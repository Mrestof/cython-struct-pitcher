#ifndef STUDENT_H_
#define STUDENT_H_

struct Student {
  char name[20];
  int age;
  int group;
};
struct Student get_default_student(void);

#endif
