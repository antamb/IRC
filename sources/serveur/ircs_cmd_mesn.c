
#include "head_serveur.h"

int	ircs_cmn_ext(t_lst *lst, t_cli *cli, char **tmp, int *i)
{
  char	*msg;

  if (!strcmp(CLIENT->nick, tmp[0]))
    {
      ircs_write(CLIENT->cfd, tmp[1], strlen(tmp[1]));
      (*i)++;
    }
  if (!lst->next && !(*i))
    {
      asprintf(&msg, "%s%c%s\n", TRS_ALNIC);
      ircs_write(cli->cfd, msg, strlen(msg));
      free(msg);
      return (FAIL);
    }
  return (SUCCES);
}

void	ircs_cmd_mesn(t_cli *cli, char **tab)
{
  int	i;
  char	*msg;
  char	*tmp[2];
  t_irc	*irc;
  t_lst	*lst;

  i = 0;
  if (ircs_nbr(tab) != 3)
    return ;
  if (IND_VERBOSE)
    fprintf(stdout, "%s%s\n\n", MSG_REQU, CMD_MESN);
  irc = ircs_struct(IND_GET);
  asprintf(&msg, "%s%c%s%c%s\n", TRS_MESN);
  tmp[0] = tab[1];
  tmp[1] = msg;
  lst = irc->cli;
  my_list_gotobeg(&lst);
  while (lst && CLIENT)
    {
      if (ircs_cmn_ext(lst, cli, tmp, &i) == FAIL)
	return ;
      lst = lst->next;
    }
  free(msg);
}
