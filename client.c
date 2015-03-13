#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

extern int errno;

int			create_socket()
{
  struct protoent	*pe;
  int			s;

  pe = getprotobyname("TCP");
  s = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (s == -1)
    {
      perror("[Error] socket");
      exit(-1);
    }
  return (s);
}

int			init_client(int port, char *addr)
{
  struct sockaddr_in	sin;
  int			s;

  s = create_socket();
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(addr);
  if ((connect(s, (const struct sockaddr *)&sin, (socklen_t)sizeof(sin))) == -1)
    {
      perror("[Client][Error]");
      return (-1);
    }
  return (s);
}

int			main(int ac, char **av)
{
  int			s;
  int			n;
  char			str[255];

  if (ac != 3)
    exit(-1);
  while ((s = init_client(atoi(av[2]), av[1])) >= 0)
    {
      n = read(1, str, 256);
      str[n] = '\0';
      if (strncmp(str, "exit", 4) == 0)
	{
	  printf("[Client] Disconneted from %s\n", av[1]);
	  close(s);
	  break;
	}
      write(s, str, strlen(str));
      close(s);
    }
  return (1);
}
