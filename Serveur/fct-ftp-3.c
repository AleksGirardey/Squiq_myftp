/*
** fct-ftp-3.c for my_ftp in /home/girard_x/GITREP/Squiq_myftp/Serveur
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Wed Mar 18 22:32:43 2015 ALEXIS GIRARDEY
** Last update Fri Mar 20 13:54:35 2015 ALEXIS GIRARDEY
*/

#include "serveur.h"

void		ftp_user(struct s_server srv)
{
  char		**args;
  char		msg[255];

  args = get_args(srv, 5);
  printf("%s\n", args[0]);
  if (strlen(args[0]) == 0)
    {
      send_error("[Usage] user _USERNAME_ (_PASSWORD_)\n", srv);
      return;
    }
  my_strcpy(srv.user.username, args[0]);
  if (strlen(args[1]) > 0)
    my_strcpy(srv.user.password, args[1]);
  strcat(msg, "Welcome, ");
  strcat(msg, args[0]);
  strcat(msg, "\n");
  write(srv.socket_c, msg, strlen(msg));
  printf("[%s] Now log as %s\n", srv.user.username, srv.user.username);
  free_args(args);
}

void	ftp_get(struct s_server srv)
{
  printf("[Client] %s\n", srv.cmd);
}
