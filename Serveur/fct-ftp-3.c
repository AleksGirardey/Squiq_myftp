/*
** fct-ftp-3.c for my_ftp in /home/girard_x/GITREP/Squiq_myftp/Serveur
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Wed Mar 18 22:32:43 2015 ALEXIS GIRARDEY
** Last update Fri Mar 20 22:20:11 2015 ALEXIS GIRARDEY
*/

#include "serveur.h"

void		ftp_user(struct s_server *srv)
{
  char		**args;
  char		msg[255];

  args = get_args(*srv, 5);
  bzero(msg, 254);
  printf("xxx%sxxx\n", args[1]);
  if (strlen(args[0]) == 0)
    {
      send_error("xxx - command fail\n", *srv);
      send_error("214 - [Usage] user _USERNAME_ (_PASSWORD_)\n", *srv);
      return;
    }
  else if (strcmp(args[0], "Anonymous") != 0 || strlen(args[1]) != 0)
    send_error("332 - Need account for login\n", *srv);
  else
    {
      srv->user->username = my_strcpy(args[0]);
      strcat(msg, "Welcome, ");
      strcat(msg, args[0]);
      strcat(msg, "\n");
      write(srv->socket_c, msg, strlen(msg));
      send_error("230 - User logged in, proceed\n", *srv);
    }
  free_args(args);
}

void	ftp_get(struct s_server srv)
{
  printf("[Client] %s\n", srv.cmd);
}
