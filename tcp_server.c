#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char **argv)
{
	int server_sock;
	int client_sock;

	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	socklen_t client_addr_size;

	server_sock = socket(PF_INET, SOCK_STREAM, 0);
	if(server_sock == -1)
	{
		perror("socket() ");
		return -1;
	}

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(atoi(argv[1]));

	if(bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr))==-1)
	{
		perror("bind() ");
		return -1;
	}

	if(listen(server_sock, 5) == -1)
	{
		perror("listen() ");
		return -1;
	}
	
	client_addr_size = sizeof(client_addr);
	client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_addr_size);
	if(client_sock == -1)
	{
		perror("accept() ");
		return -1;
	}

	/* 
		TCP Send or Recv 
	*/

	close(client_sock);
	close(server_sock);

	return 0;
}
