cdef extern from 'student.h':
    ctypedef struct Student:
        char[20] name
        int age
        int group
    int init_default_student(Student *student)


cpdef bytes get_default_student_struct_as_bytes():
    cdef unsigned char *student_ptr
    cdef Student student_struct

    init_default_student(&student_struct)
    student_ptr = <unsigned char *> &student_struct

    struct_student_size = sizeof(student_struct)
    student_arr = bytes([student_ptr[i] for i in range(struct_student_size)])

    return student_arr
