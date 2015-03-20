/*
** serveur.c for my_ftp in /home/girard_x/GITREP/Squiq_myftp/Serveur
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Mon Mar 16 11:32:55 2015 ALEXIS GIRARDEY
** Last update Fri Mar 20 22:42:36 2015 ALEXIS GIRARDEY
*/

#include "serveur.h"

void			init_server(int port,struct s_server *srv)
{
  struct protoent	*pe;

  srv->user = my_malloc(sizeof(struct s_user));
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
  srv->home = my_malloc(sizeof(char) * 255);
  getcwd(srv->home, 255);
}

void			server(int port)
{
  int			n;
  struct s_server	srv;

  init_server(port, &srv);
  while (srv.stop == 0)
    {
      srv.socket_c = accept(srv.socket_srv, (struct sockaddr*)&(srv.c_sin), (socklen_t *)&(srv.c_len));
      if (fork() == 0)
	{
	  printf("[Server] New client connected..\n");
	  while (strncmp(srv.cmd, "quit", 4) != 0)
	    {
	      srv.cmd = my_malloc(sizeof(char) * 256);
	      n = read(srv.socket_c, srv.cmd, 255);
	      srv.cmd[n] = '\0';
	      printf("[%s] %s", srv.user->username == NULL ? "Client" : srv.user->username, srv.cmd);
	      if (strncmp(srv.cmd, "quit", 4) != 0 || srv.cmd != NULL)
		exec_cmd(srv);
	    }
	}
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
