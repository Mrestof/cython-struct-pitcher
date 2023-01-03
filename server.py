import socket
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind(('', 50508))
    s.listen(1)
    conn, addr = s.accept()
    with conn:
        print('conned by', addr)
        while True:
            data = conn.recv(64)
            if not data: break
            print('recvd data', data)
