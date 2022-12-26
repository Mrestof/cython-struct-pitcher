cdef extern from 'student.h':
    cdef struct Student:
        char[20] name
        int age
        int group
    Student get_default_student()

def main() -> None:
    # print(type(Student))
    # ^- this won't work bc idunno why
    # TODO: understand what in the hell is the `Student`
    print('compile: ok')
    student = get_default_student()
    print(type(student))
