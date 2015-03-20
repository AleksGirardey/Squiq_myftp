/*
** fct-ftp-2.c for my_ftp in /home/girard_x/GITREP/Squiq_myftp/Serveur
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Tue Mar 17 22:26:12 2015 ALEXIS GIRARDEY
** Last update Fri Mar 20 21:49:17 2015 ALEXIS GIRARDEY
*/

#include "serveur.h"

void	ftp_put(struct s_server srv)
{
  printf("[Client] %s\n", srv.cmd);
}

void	ftp_pwd(struct s_server srv)
{
  char	pwd[256];

  if (srv.user->username == NULL)
    {
      send_error("xxx - Must be logged before perform any commands\n", srv);
      return;
    }
  if (getcwd(pwd, 255) != NULL)
    {
      strcat(pwd, "\n");
      send_error("257 - \"PATHNAME\" created\n", srv);
      write(srv.socket_c, pwd, strlen(pwd));
    }
  else
    send_error("xxx - Pwd failed\n", srv);
}

void	ftp_quit(struct s_server *srv)
{
  if (srv->user->username != NULL)
    printf("[%s] Disconnected\n", srv->user->username);
  else
    printf("[Client] Disconnected\n");
  write(srv->socket_c, "exit", 4);
  send_error("221 - Logged out\n", *srv);
  close(srv->socket_c);
  free(srv->user->username);
  free(srv->user->password);
  free(srv->user);
}

void	send_error(char *msg, struct s_server srv)
{
  write(srv.socket_c, msg, strlen(msg));
}
