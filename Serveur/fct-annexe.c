/*
** fct-annexe.c for my_ftp in /home/girard_x/GITREP/Squiq_myftp/Serveur
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Mon Mar 16 12:15:28 2015 ALEXIS GIRARDEY
** Last update Fri Mar 20 12:06:47 2015 ALEXIS GIRARDEY
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

void			my_strcpy(char	*dest, char *str)
{
  dest = my_malloc(sizeof(char) * (strlen(str) + 1));
  strcpy(dest, str);
}
