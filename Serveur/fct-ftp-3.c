/*
** fct-ftp-3.c for my_ftp in /home/girard_x/GITREP/Squiq_myftp/Serveur
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Wed Mar 18 22:32:43 2015 ALEXIS GIRARDEY
** Last update Wed Mar 18 23:48:36 2015 ALEXIS GIRARDEY
*/

#include "serveur.h"

void		ftp_user(struct s_server srv)
{
  char		**args;

  args = get_args(srv);
  if (args[0] == NULL)
    {
      send_error("[Usage] user _USERNAME_ (_PASSWORD_)\n", srv);
      return;
    }
  srv.user.username = args[0];
  if (args[1] != NULL)
    srv.user.password = args[1];
  printf("[%s] Now log as %s\n", srv.user.username, srv.user.username);
}

void	ftp_get(struct s_server srv)
{
  printf("[Client] %s\n", srv.cmd);
}
