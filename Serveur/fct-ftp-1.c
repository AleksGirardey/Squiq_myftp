/*
** fct-ftp-1.c for my_ftp in /home/girard_x/GITREP/Squiq_myftp/Serveur
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Tue Mar 17 22:21:43 2015 ALEXIS GIRARDEY
** Last update Sat Mar 21 00:33:01 2015 ALEXIS GIRARDEY
*/

#include "serveur.h"

void		ftp_ls(struct s_server srv)
{
  if (srv.user->username == NULL)
    {
      send_error("xxx - Must be logged before using any commands\n", srv);
      send_error("214 - User command needed\n", srv);
      return;
    }
  else
    semi_ls(srv);
}

void		semi_ls(struct s_server srv)
{
  struct dirent	*s_dir;
  DIR		*dir;
  char		*ls;
  int		length;

  length = 0;
  if ((dir = opendir(".")) != 0)
    {
      while ((s_dir = readdir(dir)))
	length = 1 + length + strlen(s_dir->d_name);
      ls = my_malloc(sizeof(char) * (length + 1));
      closedir(dir);
      dir = opendir(".");
      ls[0] = '\0';
      while ((s_dir = readdir(dir)))
	{
	  strcat(ls, s_dir->d_name);
	  strcat(ls, "\n");
	}
      closedir(dir);
      write(srv.socket_c, ls, strlen(ls));
      send_error("200 - command okay\n", srv);
      free(ls);
    }
}

void		ftp_cd(struct s_server srv)
{
  char		**args;
  char		current_dir[256];

  args = get_args(srv, 3);
  if (srv.user->username == NULL)
    {
      send_error("xxx - Must be logged before using any commands.\n", srv);
      send_error("214 - User command needed\n", srv);
      return;
    }
  if (can_go(args[0], srv) == -1 || chdir(args[0]) == -1)
    {
      send_error("xxx - No such directory\n", srv);
      send_error("214 - Please indicate a valid path\n", srv);      
    }
  else
    {
      getcwd(current_dir, 255);
      send_error("150 - File status ok; about to open data connection.\n", srv);
      semi_cd(args[0], current_dir, srv);
    }
}

void		semi_cd(char *path, char *current_path, struct s_server srv)
{
  int		nb_slash;
  int		i;

  i = 0;
  nb_slash = 0;
  while (path[i])
    {
      if (path[i] == '/')
	nb_slash = nb_slash + 1;
      i++;
    }
  i = 0;
  while (current_path[i])
    {
      if (current_path[i] == '/')
	nb_slash = nb_slash - 1;
      i++;
    }
  if (nb_slash > 0)
    {
      send_error("No such directory - 2\n", srv);
      return;
    }
  else
    write(srv.socket_c, "226 - file action successful - Dir changed\n", 43);
}
