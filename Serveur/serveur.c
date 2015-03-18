/*
** serveur.c for my_ftp in /home/girard_x/GITREP/Squiq_myftp/Serveur
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Mon Mar 16 11:32:55 2015 ALEXIS GIRARDEY
** Last update Wed Mar 18 22:45:28 2015 ALEXIS GIRARDEY
*/

#include "serveur.h"

void			init_server(int port,struct s_server *srv)
{
  struct protoent	*pe;

  srv->stop = 0;
  pe = getprotobyname("TCP");
  srv->socket_srv = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (srv->socket_srv < 0)
    my_error("Server", "[Error] Can't established socket..");
  srv->sin.sin_family = AF_INET;
  srv->sin.sin_port = htons(port);
  srv->sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(srv->socket_srv, (struct sockaddr *)&(srv->sin), sizeof(srv->sin)) < 0)
    my_error("Server", "[Error] Can't bind the socket..");
  if (listen(srv->socket_srv, 4) < 0)
    my_error("Server", "[Error] Can't listen the socket..");
  srv->c_len = sizeof(srv->c_sin);
}

void			server(int port)
{
  int			n;
  int			f;
  struct s_server	srv;

  init_server(port, &srv);
  while (srv.stop == 0)
    {
      srv.socket_c = accept(srv.socket_srv, (struct sockaddr*)&(srv.c_sin), (socklen_t *)&(srv.c_len));
      f = fork();
      if (f == 0)
	{
	  printf("[Server] New client connected..\n");
	  while (strcmp(srv.cmd, "exit") != 0)
	    {
	      memset(srv.cmd, 0, 256);
	      n = read(srv.socket_c, srv.cmd, 255);
	      srv.cmd[n] = '\0';
	      printf("[Client] %s\n", srv.cmd);
	      if (strcmp(srv.cmd, "exit") != 0 || srv.cmd != NULL)
		exec_cmd(srv);
	    }
	}
      if (f > 0)
	close(srv.socket_c);
    }
}

int			main(int ac, char **av)
{
  if (ac != 2)
    my_error("Usage", "./server PORT");
  server(atoi(av[1]));
  return (1);
}
