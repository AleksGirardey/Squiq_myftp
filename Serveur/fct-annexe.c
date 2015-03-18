/*
** fct-annexe.c for my_ftp in /home/girard_x/GITREP/Squiq_myftp/Serveur
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Mon Mar 16 12:15:28 2015 ALEXIS GIRARDEY
** Last update Wed Mar 18 23:44:27 2015 ALEXIS GIRARDEY
*/

#include "serveur.h"

void			my_error(char *where, char *what)
{
  printf("[%s]%s\n", where, what);
  exit(-1);
}

void			*my_malloc(size_t t)
{
  void			*_malloc;

  _malloc = malloc(t);
  if (_malloc == NULL)
    my_error("Serveur", "[Malloc] Can't allocate memory");
  return (_malloc);
}

char			*remove_cmd(char *cmd)
{
  int			i;
  char			*_cmd;

  i = 0;
  _cmd = my_malloc(sizeof(char) * strlen(cmd));
  while (cmd[i])
    {
      if (cmd[i] == ' ' && cmd[i + 1] != ' ')
	{
	  _cmd = cmd + (i + 1);
	  break;
	}
      i = i + 1;
    }
  return (_cmd);
}

char			**get_args(struct s_server srv)
{
  int			i;
  int			k;
  int			l;
  char			**args;
  char			*cmd;

  i = 0;
  k = 0;
  l = 0;
  args = my_malloc(sizeof(char *) * 2);
  args[0] = my_malloc(sizeof(char) * 255);
  args[1] = my_malloc(sizeof(char) * 255);
  cmd = remove_cmd(srv.cmd);
  while (cmd[i] != '\0')
    {
      if (cmd[i] == ' ')
	{
	  args[k][i] = '\0';
	  k++;
	  l = 0;
	}
      else
	args[k][l] = cmd[i];
    }
  return (args);
}
