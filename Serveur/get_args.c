/*
** get_args.c for my_ftp in /home/girard_x/GITREP/Squiq_myftp
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Fri Mar 20 11:04:52 2015 ALEXIS GIRARDEY
** Last update Fri Mar 20 11:45:42 2015 ALEXIS GIRARDEY
*/

#include "serveur.h"

char		**malloc_args()
{
  int		i;
  char		**args;

  i = 0;
  args = my_malloc(sizeof(char *) * 4);
  while (i < 4)
    {
      args[i] = my_malloc(sizeof(char) * 255);
      i++;
    }
  return (args);
}

void		free_args(char	**args)
{
  int		i;

  i = 0;
  while (i < 4)
    {
      free(args[i]);
      i++;
    }
  free(args);
}

char		**get_args(struct s_server srv, int i)
{
  int		k;
  int		l;
  char		**args;

  k = 0;
  l = 0;
  args = malloc_args();
  args[0][0] = '\0';
  args[1][0] = '\0';
  while (srv.cmd[i] != '\0' && srv.cmd[i] != '\n')
    {
      if (srv.cmd[i] == ' ')
	{
	  args[k][l] = '\0';
	  k++;
	  l = 0;
	}
      else
	{
	  args[k][l] = srv.cmd[i];
	  l++;
	}
      i++;
    }
  return (args);
}
