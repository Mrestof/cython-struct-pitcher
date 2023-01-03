#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include "student.h"

int main () {
  int sockfd, newsockfd, portno, clilen;
  unsigned char buffer[64];
  struct sockaddr_in serv_addr, cli_addr;
  int n;

  // Initialize socket structure
  bzero((char *) &serv_addr, sizeof(serv_addr));
  portno = 50508;

  // create socket and get file descriptor
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  clilen = sizeof(cli_addr);

  // bind the host address using bind() call
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
      perror("ERROR on binding\n");
      exit(1);
  }

  // start listening for the clients,
  // accept actual connection from the client,
  // process will go in sleep mode and will wait for the incoming connection.
  printf("start listening\n");
  listen(sockfd, 1);
  newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

  bzero(buffer, 64);
  n = read(newsockfd, buffer, 63);

  if (n < 0){
    perror("ERROR in reading from socket");
    exit(1);
  }

  Student *student_ptr = (Student *) &buffer;
  printf("name: %s, ", student_ptr->name);
  printf("age: %d, ", student_ptr->age);
  printf("group: %d\n", student_ptr->group);

  return 0;
}
