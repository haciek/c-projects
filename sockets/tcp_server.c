#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#include <netinet/in.h>



int main (int argc, char *argv[])
{
	char server_message[256] = "Server Message!";
	/* creating server socket */
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	/* define server addres */
	struct sockaddr_in server_addres;
	server_addres.sin_family = AF_INET;
	server_addres.sin_port = htons(8888);
	/* default addres */
	server_addres.sin_addr.s_addr = INADDR_ANY;

	int bind_status = bind(server_socket, (struct sockaddr *) &server_addres, sizeof(server_addres));
	if (bind_status == -1) { printf("Bind error\n\n"); return -1; }

	listen(server_socket, 5);

	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);

	send(client_socket, server_message, sizeof(server_message), SOCK_CLOEXEC);
	close(server_socket);

	return 0;
}
