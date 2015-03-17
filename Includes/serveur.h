/*
** serveur.h for my_ftp in /home/girard_x/GITREP/Squiq_myftp/Serveur
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Mon Mar 16 12:16:28 2015 ALEXIS GIRARDEY
** Last update Mon Mar 16 16:52:54 2015 ALEXIS GIRARDEY
*/

#ifndef SERVEUR_H_
# define SERVEUR_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct			s_server
{
  int			socket_c;
  int			socket_srv;
  int			stop;
  char			*cmd;
  size_t		c_len;
  struct sockaddr_in	sin;
  struct sockaddr_in	c_sin;
};

void	init_server(int port,struct s_server *srv);
void	server(int port);
void	*my_malloc(size_t t);
void	my_error(char *where, char *what);

#endif /* SERVEUR_H_ */
