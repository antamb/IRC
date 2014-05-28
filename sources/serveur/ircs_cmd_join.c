
#include "head_serveur.h"

void	ircs_cjn_try(t_cli *cli, t_cha *cha)
{
  char	*msg;
  t_lst	*lst;

  my_list_gotobeg(&(cha->cli));
  lst = cha->cli;
  while (lst && CLIENT)
    {
      if (CLIENT->cfd == cli->cfd)
	{
	  asprintf(&msg, "%s%c%s\n", TRS_ALCON);
	  ircs_write(cli->cfd, msg, strlen(msg));
	  free(msg);
	  return ;
	}
      lst = lst->next;
    }
  lst = cha->cli;
  while (lst && CLIENT)
    {
      asprintf(&msg, "%s%c%s%c%s%s'\n", TRS_CONN);
      ircs_write(CLIENT->cfd, msg, strlen(msg));
      free(msg);
      lst = lst->next;
    }
}

void	ircs_cmd_join(t_cli *cli, char **tab)
{
  int	i;
  char	*msg;
  t_cha	*cha;

  i = 0;
  if (ircs_nbr(tab) != 2)
    return ;
  if (IND_VERBOSE)
    fprintf(stdout, "%s%s\n\n", MSG_REQU, CMD_JOIN);
  if ((cha = ircs_getchan(tab[1])) == NULL)
    {
      asprintf(&msg, "%s%c%s\n", TRS_NOCHA);
      ircs_write(cli->cfd, msg, strlen(msg));
      free(msg);
      return ;
    }
  ircs_cjn_try(cli, cha);
  my_list_putinend(&(cha->cli), &(*cli));
}
