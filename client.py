import sys
import socket
from client_compiled import get_default_student_struct_as_bytes


HOST = 'localhost'
PORT = 50508


def handle_connection_error() -> None:
    ...


def send_bytes(data: bytes) -> int:
    '''Return zero on success
    '''
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as soc:
        try:
            soc.connect((HOST, PORT))
            soc.sendall(data)
        except ConnectionError as exc:
            print(f'sending error: {exc.__class__.__name__}')
            return 1
        r = soc.recv(64)
        print(r)
    print(f'send {data=} to the {HOST,PORT=} ')
    return 0


def main() -> None:
    # use this to set different group for the student to pass;
    # also it sets the timeout (processing time) for each connection,
    # so try to start 2 clients, one with group=10, other with group=2
    try:
        group_number = int(sys.argv[-1]) if len(sys.argv) > 1 else 1
    except ValueError as exc:
        print(f'argument error: {exc.__class__.__name__}')
        exit(1)

    struct: bytes = get_default_student_struct_as_bytes(group_number)
    if send_bytes(struct):  # do a walrus here, if returned code is needed
        handle_connection_error()
    print('finish')


if __name__ == '__main__':
    main()
