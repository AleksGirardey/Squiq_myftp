#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int			create_socket()
{
  struct protoent	*pe;
  int			s;

  pe = getprotobyname("TCP");
  s = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (s == -1)
    {
      printf("[Error] Socket\n");
      exit(-1);
    }
  return (s);
}

int			init_server(int socket, int port)
{
  struct sockaddr_in	sin;
  int			error;

  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = INADDR_ANY;
  error = bind(socket, (const struct sockaddr *)&sin, sizeof(sin));
  if (error == -1)
    {
      printf("[Serveur][Error] Bind\n");
      close(socket);
      exit(-1);
    }
  error = listen(socket, 4);
  if (error == -1)
    {
      printf("[Serveur][Error] Listen\n");
      close(socket);
      exit(-1);
    }
  return (1);
}

int			listen_to_client(int s)
{
  struct sockaddr_in	sin_client;
  int			client_length;
  int			cs;
  int			n;
  char			str[256];

  client_length = sizeof(sin_client);
  while ((cs = accept(s, (struct sockaddr *)&sin_client, (socklen_t *)&(client_length))) >= 0)
    {
      printf("[Server] s = %d\n", s);
      if (cs == -1)
	{
	  printf("[Server][Error] Accept\n");
	  close(cs);
	  close(s);
	  exit(-1);
	}
      n = read(cs, str, 256);
      str[n] = '\0';
      printf("[Client] %s", str);
    }
  close(cs);
  return (1);
}

void			listen_to_server(int s)
{
  int			n;
  char			str[256];

  n = 0;
  while (n >= 0)
    {
      n = read(1, str, 255);
      str[n] = '\0';
      if (strncmp(str, "shutdown", 8) == 0)
	{
	  printf("[Serveur] Shutdown...\n");
	  sleep(3);
	  close(s);
	  exit(1);
	}
      else
	printf("[Server] Unknown command\n");
    }
}

int			main(int ac, char **av)
{
  int			s;
  int			x;

  if (ac != 2)
    {
      printf("[Usage] ./serveur 'port'\n");
      exit(-1);
    }
  s = create_socket();
  init_server(s, atoi(av[1]));
  x = fork();
  if (x == 0)
    listen_to_client(s);
  if (x > 0)
    listen_to_server(s);
  close (s);
  printf("[Serveur] End of stream\n");
  return (1);
}
