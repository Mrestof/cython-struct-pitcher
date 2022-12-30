cdef extern from 'student.h':
    struct Student:
        char[20] name
        int age
        int group
    Student get_default_student()


cpdef bytes get_default_student_struct_as_bytes():
    cdef unsigned char *student_ptr
    cdef Student student_struct = get_default_student()
    student_ptr = <unsigned char *> &student_struct

    # TODO: ask why the line below doesn't work
    #       student_arr = <bytes>student_ptr
    struct_student_size = sizeof(student_struct)
    student_arr = bytes([student_ptr[i] for i in range(struct_student_size)])

    return student_arr
