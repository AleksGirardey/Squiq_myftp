/*
** fct-annexe.c for my_ftp in /home/girard_x/GITREP/Squiq_myftp/Serveur
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Mon Mar 16 12:15:28 2015 ALEXIS GIRARDEY
** Last update Fri Mar 20 14:01:14 2015 ALEXIS GIRARDEY
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

char		*my_strcpy(char *str)
{
  char	*dest;

  dest = my_malloc(sizeof(char) * (strlen(str) + 1));
  strcpy(dest, str);
  return (dest);
}
