
#include "head_serveur.h"

int	ircs_free_cli(void *elem)
{
  t_cli	*cli;

  cli = (t_cli *) elem;
  close(cli->cfd);
  free(cli->nick);
  free(cli);
  return (SUCCES);
}

int	ircs_free_ucli(void *elem)
{
  t_cli	*cli;

  cli = (t_cli *) elem;
  return (SUCCES);
}

int	ircs_free_ccli(t_lst **clis, t_cli *cli)
{
  t_lst	*lst;

  lst = *clis;
  while (lst && CLIENT)
    {
      if (CLIENT->cfd == cli->cfd)
	{
	  my_list_rmelem_data(&(*clis), ircs_free_ucli);
	  return (TRUE);
	}
      if (lst && lst->next)
	*clis = (*clis)->next;
      if (lst)
	lst = lst->next;
    }
  return (FALSE);
}

void	ircs_free_chas(t_lst *cha, t_cli *cli)
{
  t_lst	*lst;

  lst = cha;
  while (lst && CHANNEL)
    {
      my_list_gotobeg(&(CHANNEL->cli));
      if (ircs_free_ccli(&(CHANNEL->cli), cli) == TRUE)
	{
	  cli->temp = CHANNEL->name;
	  ircs_cpt_free(cli);
	}
      if (lst)
	lst = lst->next;
    }
}

void	ircs_killcli(t_cli *cli)
{
  t_irc	*irc;
  t_lst	*lst;

  irc = ircs_struct(IND_GET);
  my_list_gotobeg(&(irc->cli));
  my_list_gotobeg(&(irc->cha));
  ircs_free_chas(irc->cha, cli);
  lst = irc->cli;
  while (lst && CLIENT)
    {
      if (CLIENT->cfd == cli->cfd)
	{
	  my_list_rmelem_data(&(irc->cli), ircs_free_cli);
	  *((t_lst **)(irc->temp)) = irc->cli;
	  return ;
	}
      if (lst && lst->next)
	irc->cli = irc->cli->next;
      if (lst)
	lst = lst->next;
    }
}
