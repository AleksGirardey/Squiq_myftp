/*
** fct-ftp-2.c for my_ftp in /home/girard_x/GITREP/Squiq_myftp/Serveur
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Tue Mar 17 22:26:12 2015 ALEXIS GIRARDEY
** Last update Wed Mar 18 23:47:54 2015 ALEXIS GIRARDEY
*/

#include "serveur.h"

void	ftp_put(struct s_server srv)
{
  printf("[Client] %s\n", srv.cmd);
}

void	ftp_pwd(struct s_server srv)
{
  char	pwd[256];

  if (srv.user.username == NULL)
    {
      send_error("Must be logged before perform any commands\n", srv);
      return;
    }
  if (getcwd(pwd, 255) != NULL)
    write(srv.socket_c, pwd, strlen(pwd));
  else
    send_error("Pwd failed\n", srv);
}

void	ftp_quit(struct s_server srv)
{
  if (srv.user.username != NULL)
    printf("[%s] Disconnected\n", srv.user.username);
  else
    printf("[Client] Disconnecter\n");
  write(srv.socket_c, "exit", 4);
  close(srv.socket_c);
}

void	send_error(char *msg, struct s_server srv)
{
  write(srv.socket_c, msg, strlen(msg));
}
