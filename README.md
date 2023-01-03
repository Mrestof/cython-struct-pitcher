# Cython C struct pitcher (client-server)

The main gole is to create C `struct`, wrap it in Python using Cython and send it with sockets to the server side, which is written entirely in C. Parse the `struct` on the server side and return its members.

> `python` version used in the entire project is `3.9`

## Quick start

Run the script to build and run both client and server part, \
saving logs in two separate files:\
`./run.sh`

## Building by yourself

If you want to build client and server parts separately for debug or smth else.
Run the server and client in different terminals: client first, then server.

### Server
  
1. Build the server:\
  `gcc server.c -o server`

2. Run the server:\
  `./server`

### Client

1. Build the client:\
  `python setup.py build_ext --inplace`

2. Run the client:\
  `python client.py`
