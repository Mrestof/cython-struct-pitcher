#ifndef STUDENT_H_
#define STUDENT_H_

typedef struct {
  char name[20];
  int age;
  int group;
} Student;
int init_default_student(Student *student);

#endif
