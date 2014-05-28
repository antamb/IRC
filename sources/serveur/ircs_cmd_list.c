
#include "head_serveur.h"

void	ircs_cmd_list(t_cli *cli, char UNUSED **tab)
{
  char	c;
  t_irc	*irc;
  t_lst	*lst;

  c = IND_SEP;
  if (IND_VERBOSE)
    fprintf(stdout, "%s%s\n\n", MSG_REQU, CMD_LIST);
  irc = ircs_struct(IND_GET);
  lst = irc->cha;
  my_list_gotobeg(&lst);
  ircs_write(cli->cfd, CMD_LIST, strlen(CMD_LIST));
  ircs_write(cli->cfd, &c, 1);
  while (lst && CHANNEL)
    {
      ircs_write(cli->cfd, CHANNEL->name, strlen(CHANNEL->name));
      ircs_write(cli->cfd, &c, 1);
      lst = lst->next;
    }
  ircs_write(cli->cfd, "\n", 1);
}
