#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
  
int main()
{
	int sockfd, connfd;
	struct sockaddr_in servaddr, cli;

	char buff[10] = "ABCDE";
  
   	// socket create and varification
    	sockfd = socket(AF_INET, SOCK_STREAM, 0);
    	if (sockfd == -1) {
		perror("socket() ");
		return -1;
    	}
    	else
    	bzero(&servaddr, sizeof(servaddr));
  
    	// assign IP, PORT
    	servaddr.sin_family = AF_INET;
    	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    	servaddr.sin_port = htons(9999);
  
    	// connect the client socket to server socket
    	if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
		perror("connect() ");
		return -1;
    	}
    	else

	/*
		Recv() & Send()
	*/
	write(sockfd, buff, sizeof(buff));

    	// close the socket
    	close(sockfd);


	return 0;
}
