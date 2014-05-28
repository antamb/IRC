
#include "head_serveur.h"

int	ircs_cpt_free(void *elem)
{
  char	*msg;
  t_cli	*cli;
  t_cha	*cha;
  t_lst	*lst;

  cli = (t_cli *) elem;
  cha = ircs_getchan(cli->temp);
  lst = cha->cli;
  my_list_gotobeg(&lst);
  while (lst && CLIENT)
    {
      if (CLIENT->cfd != cli->cfd)
	{
	  asprintf(&msg, "%s%c%s%c%s%s'\n", TRS_DECO);
	  ircs_write(CLIENT->cfd, msg, strlen(msg));
	  free(msg);
	}
      lst = lst->next;
    }
  return (SUCCES);
}

void	ircs_cpt_ext(t_cha *cha, t_cli *cli)
{
  t_lst	*lst;

  my_list_gotobeg(&(cha->cli));
  lst = cha->cli;
  while (lst && CLIENT)
    {
      if (CLIENT->cfd == cli->cfd)
	{
	  my_list_rmelem_data(&(cha->cli), ircs_cpt_free);
	  return ;
	}
      if (lst && lst->next)
	cha->cli = cha->cli->next;
      if (lst)
	lst = lst->next;
    }
}

void	ircs_cmd_part(t_cli *cli, char **tab)
{
  char	*msg;
  t_cha	*cha;

  if (ircs_nbr(tab) != 2)
    return ;
  if (IND_VERBOSE)
    fprintf(stdout, "%s%s\n\n", MSG_REQU, CMD_PART);
  if ((cha = ircs_getchan(tab[1])) == NULL)
    {
      asprintf(&msg, "%s%c%s\n", TRS_NOCHA);
      ircs_write(cli->cfd, msg, strlen(msg));
      free(msg);
      return ;
    }
  cli->temp = tab[1];
  ircs_cpt_ext(cha, cli);
}
