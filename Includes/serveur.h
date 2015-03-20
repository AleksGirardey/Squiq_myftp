/*
** serveur.h for my_ftp in /home/girard_x/GITREP/Squiq_myftp/Serveur
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Mon Mar 16 12:16:28 2015 ALEXIS GIRARDEY
** Last update Sat Mar 21 00:28:04 2015 ALEXIS GIRARDEY
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
#include <dirent.h>

struct			s_user
{
  char			*username;
  char			*password;
};

struct			s_cmd;

struct			s_server
{
  int			socket_c;
  int			socket_srv;
  int			stop;
  char			*cmd;
  char			*home;
  size_t		c_len;
  struct sockaddr_in	sin;
  struct sockaddr_in	c_sin;
  struct s_user		*user;
};

typedef			int (*cmd_fonction)(struct s_server);

extern cmd_fonction fcts[7];

struct			s_cmd
{
  char			*cmd;
  cmd_fonction		fonction;
  struct s_cmd		*next;
};

int		can_go(char *path, struct s_server srv);
void		ftp_user(struct s_server *srv);
void		ftp_ls(struct s_server srv);
void		semi_ls(struct s_server srv);
void		ftp_cd(struct s_server srv);
void		semi_cd(char *path, char *current_path, struct s_server srv);
void		ftp_get(struct s_server srv);
void		ftp_put(struct s_server srv);
void		ftp_pwd(struct s_server srv);
void		ftp_quit(struct s_server *srv);
void		send_error(char *msg, struct s_server srv);
void		init_server(int port,struct s_server *srv);
void		server(int port);
void		*my_malloc(size_t t);
void		my_error(char *where, char *what);
void		exec_cmd(struct s_server srv);
//void		free_struct(struct s_cmd *cmd);
void		free_args(char **args);
char		*my_strcpy(char *str);
char		**get_args(struct s_server srv, int i);
//struct s_cmd	*init_cmd();
//struct s_cmd	*new_cmd(char *cmd, cmd_fonction f);

#endif /* SERVEUR_H_ */
