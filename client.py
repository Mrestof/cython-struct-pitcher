import socket
from typing import Optional
from client_compiled import get_default_student_struct_as_bytes


HOST = 'localhost'
PORT = 50508


def handle_connection_error() -> None:
    ...


def send_bytes(data: bytes) -> Optional[int]:
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        try:
            s.connect((HOST, PORT))
            s.sendall(data)
        except ConnectionError as ce:
            print(f'sending error: {ce.__class__.__name__}')
            return 1
    print(f'send {data=} to the {HOST,PORT=} ')


def main() -> None:
    struct: bytes = get_default_student_struct_as_bytes()
    status = send_bytes(struct)
    if status:
        handle_connection_error()
    print('finish')


if __name__ == '__main__':
    main()
