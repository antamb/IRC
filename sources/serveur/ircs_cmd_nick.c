
#include "head_serveur.h"

void	ircs_cnk_ext(t_cli *cli, char **tab)
{
  char	*msg;

  free(cli->nick);
  asprintf(&(cli->nick), tab[1]);
  asprintf(&msg, "%s%c%s\n", TRS_IFNIC);
  ircs_write(cli->cfd, msg, strlen(msg));
  free(msg);
}

void	ircs_cmd_nick(t_cli *cli, char **tab)
{
  char	*msg;
  t_irc	*irc;
  t_lst	*lst;

  if (ircs_nbr(tab) != 2)
    return ;
  if (IND_VERBOSE)
    fprintf(stdout, "%s%s\n\n", MSG_REQU, CMD_NICK);
  irc = ircs_struct(IND_GET);
  lst = irc->cli;
  my_list_gotobeg(&lst);
  while (lst && CLIENT)
    {
      if (!strcmp(CLIENT->nick, tab[1]))
	{
	  asprintf(&msg, "%s%c%s\n", TRS_ALNIC);
	  ircs_write(cli->cfd, msg, strlen(msg));
	  free(msg);
	  return ;
	}
      lst = lst->next;
    }
  ircs_cnk_ext(cli, tab);
}
