#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main (int argc, char *argv[])
{
	/* creating a socket */
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);
	/* specify an adress for the socket */
	struct sockaddr_in server_adress;
	server_adress.sin_family = AF_INET;
	server_adress.sin_port = htons(8888);
	/* INADDR_ANY default addres (0.0.0.0) */
	server_adress.sin_addr.s_addr = INADDR_ANY;

	int connection_status = connect(network_socket, (struct sockaddr *) &server_adress, sizeof(server_adress));
	if (connection_status == -1) { printf("Connection Error \n\n"); return -1; }
	printf("Connection Established \n\n");

	/* reciving data */
	char server_response[256];
	recv(network_socket, &server_response, sizeof(server_response), SOCK_CLOEXEC);

	printf("Recived: %s\n", server_response);

	close(network_socket);
	return 0;
}
