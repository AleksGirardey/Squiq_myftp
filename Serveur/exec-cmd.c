/*
** exec-cmd.c for my_ftp in /home/girard_x/GITREP/Squiq_myftp/Serveur
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Tue Mar 17 17:46:47 2015 ALEXIS GIRARDEY
** Last update Fri Mar 20 14:38:14 2015 ALEXIS GIRARDEY
*/

#include "serveur.h"

void		exec_cmd(struct s_server srv)
{
  if (strncmp(srv.cmd, "user", 4) == 0)
    ftp_user(&srv);
  else if (strncmp(srv.cmd, "ls", 2) == 0)
    ftp_ls(srv);
  else if (strncmp(srv.cmd, "cd", 2) == 0)
    ftp_cd(srv);
  else if (strncmp(srv.cmd, "get", 3) == 0)
    ftp_get(srv);
  else if (strncmp(srv.cmd, "put", 3) == 0)
    ftp_put(srv);
  else if (strncmp(srv.cmd, "pwd", 3) == 0)
    ftp_pwd(srv);
  else if (strncmp(srv.cmd, "quit", 4) == 0)
    ftp_quit(&srv);
  else
    send_error("Unknown command.\n", srv);
}
