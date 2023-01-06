#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include "student.h"

int main () {
  int sockfd_server, sockfd_client, portno, clilen, pid, option = 1;
  unsigned char buffer[64];
  struct sockaddr_in serv_addr, cli_addr;
  int n;
  char end_msg[] = "transmission end";

  // Initialize socket structure
  bzero((char *) &serv_addr, sizeof(serv_addr));
  portno = 50508;

  // create socket and get file descriptor, make it reusable right after closing
  sockfd_server = socket(AF_INET, SOCK_STREAM, 0);
  setsockopt(sockfd_server, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  clilen = sizeof(cli_addr);

  // bind the host address using bind() call
  if (bind(sockfd_server, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
      perror("ERROR on binding\n");
      exit(1);
  }

  // start listening for the clients,
  printf("start listening\n");
  listen(sockfd_server, 3);

  // start communicating
  while (1) {
    // accept actual connection from the client,
    // process will go in sleep mode and will wait for the incoming connection.
    sockfd_client = accept(sockfd_server, (struct sockaddr *)&cli_addr, &clilen);
    pid = fork();
    if (pid != 0) {
      close(sockfd_client);
      continue;
    }

    close(sockfd_server);
    bzero(buffer, 64);
    n = read(sockfd_client, buffer, 63);
    if (n < 0) {
      perror("ERROR in reading from socket");
      exit(1);
    }

    Student *student_ptr = (Student *) &buffer;

    // use this to check the simultaneity of the processes
    sleep(student_ptr->group);

    n = write(sockfd_client, end_msg, sizeof(end_msg));
    if (n <0) {
      perror("ERROR in writing to socket");
      exit(1);
    }
    close(sockfd_client);

    printf("name: %s, ", student_ptr->name);
    printf("age: %d, ", student_ptr->age);
    printf("group: %d\n", student_ptr->group);

    return 0;
  }
  // end communicating

  return 0;
}
