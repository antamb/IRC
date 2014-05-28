
#include "head_serveur.h"

int	ircs_cms_ctrl(t_cha *cha, t_cli *cli)
{
  t_lst	*lst;

  lst = cha->cli;
  my_list_gotobeg(&lst);
  while (lst && CLIENT)
    {
      if (!strcmp(CLIENT->nick, cli->nick))
	return (SUCCES);
      lst = lst->next;
    }  
  return (FAIL);
}

void	ircs_cms_ext(t_cha *cha, t_cli *cli, char **tab)
{
  char	*msg;
  t_lst	*lst;

  asprintf(&msg, "%s%c%s%c%s%c%s\n", TRS_MESS);
  lst = cha->cli;
  my_list_gotobeg(&lst);
  while (lst && CLIENT)
    {
      ircs_write(CLIENT->cfd, msg, strlen(msg));
      lst = lst->next;
    }
  free(msg);
}

void	ircs_cmd_mess(t_cli *cli, char **tab)
{
  char	*msg;
  t_cha	*cha;

  if (ircs_nbr(tab) != 3)
    return ;
  if (IND_VERBOSE)
    fprintf(stdout, "%s%s\n\n", MSG_REQU, CMD_MESS);
  if ((cha = ircs_getchan(tab[1])) == NULL)
    {
      asprintf(&msg, "%s%c%s\n", TRS_NOCHA);
      ircs_write(cli->cfd, msg, strlen(msg));
      free(msg);
      return ;
    }
  if (ircs_cms_ctrl(cha, cli) == FAIL)
    return ;
  ircs_cms_ext(cha, cli, tab);
}
