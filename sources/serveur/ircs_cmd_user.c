
#include "head_serveur.h"

void	ircs_cur_list(t_cha *cha, t_cli *cli)
{
  char	c;
  t_lst	*lst;

  c = IND_SEP;
  lst = cha->cli;
  my_list_gotobeg(&lst);
  ircs_write(cli->cfd, CMD_USER, strlen(CMD_USER));
  ircs_write(cli->cfd, &c, 1);
  while (lst && CLIENT)
    {
      ircs_write(cli->cfd, CLIENT->nick, strlen(CLIENT->nick));
      ircs_write(cli->cfd, &c, 1);
      lst = lst->next;
    }
  ircs_write(cli->cfd, "\n", 1);
}

void	ircs_cmd_user(t_cli *cli, char **tab)
{
  char	*msg;
  t_cha	*cha;

  if (ircs_nbr(tab) != 2)
    return ;
  if (IND_VERBOSE)
    fprintf(stdout, "%s%s\n\n", MSG_REQU, CMD_USER);
  if ((cha = ircs_getchan(tab[1])) == NULL)
    {
      asprintf(&msg, "%s%c%s\n", TRS_NOCHA);
      ircs_write(cli->cfd, msg, strlen(msg));
      free(msg);
      return ;
    }
  ircs_cur_list(cha, cli);
}
