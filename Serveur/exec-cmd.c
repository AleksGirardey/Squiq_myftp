/*
** exec-cmd.c for my_ftp in /home/girard_x/GITREP/Squiq_myftp/Serveur
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Tue Mar 17 17:46:47 2015 ALEXIS GIRARDEY
** Last update Wed Mar 18 23:52:18 2015 ALEXIS GIRARDEY
*/

#include "serveur.h"

char		cmds[7][4] = {"user", "ls", "cd", "get", "put", "pwd", "quit"};
cmd_fonction	fcts[7] = {ftp_user, ftp_ls, ftp_cd, ftp_get, ftp_put, ftp_pwd, ftp_quit};

struct s_cmd	*new_cmd(char *cmd, cmd_fonction f)
{
  struct s_cmd	*newcmd;

  newcmd = my_malloc(sizeof(struct s_cmd));
  newcmd->cmd = cmd;
  newcmd->fonction = f;
  newcmd->next = NULL;
  return (newcmd);
}

struct s_cmd	*init_cmd()
{
  int		i;
  struct s_cmd	*cmd;
  struct s_cmd	*tmp;

  i = 1;
  cmd = new_cmd(cmds[0], fcts[0]);
  tmp = cmd;
  while (i < 7)
    {
      tmp->next = new_cmd(cmds[i], fcts[i]);
      tmp = tmp->next;
      i++;
    }
  return (cmd);
}

void		free_struct(struct s_cmd *cmd)
{
  while (cmd->next != NULL)
    cmd = cmd->next;
  free(cmd);
}

void		exec_cmd(struct s_server srv)
{
  struct s_cmd	*my_cmds;
  struct s_cmd	*tmp;
  int		a;

  a = 0;
  my_cmds = init_cmd();
  tmp = my_cmds;
  while (tmp->next != NULL)
    {
      if (strncmp(srv.cmd, tmp->cmd, strlen(tmp->cmd)) == 0)
	{
	  tmp->fonction(srv);
	  a = 1;
	}
      tmp = tmp->next;
    }
  if (a == 0)
    send_error("Unknown command.\n", srv);
  free_struct(my_cmds);
}