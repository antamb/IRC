
#include "head_serveur.h"

void	ircs_cdc_ext(char *str)
{
  char	c;
  t_lst	*lst;
  t_irc	*irc;

  c = IND_SEP;
  irc = ircs_struct(IND_GET);
  lst = irc->cli;
  my_list_gotobeg(&lst);
  while (lst && CLIENT)
    {
      ircs_write(CLIENT->cfd, CMD_DELC, strlen(CMD_DELC));
      ircs_write(CLIENT->cfd, &c, 1);
      ircs_write(CLIENT->cfd, str, strlen(str));
      ircs_write(CLIENT->cfd, "\n", 1);
      lst = lst->next;
    }
}

void	ircs_cmd_delc(char **tab)
{
  t_lst	*lst;
  t_irc	*irc;

  if (ircs_nbr(tab) != 2)
    return ;
  irc = ircs_struct(IND_GET);
  my_list_gotobeg(&(irc->cha));
  lst = irc->cha;
  while (lst && CHANNEL)
    {
      if (!strcmp(CHANNEL->name, tab[1]))
	{
	  my_list_rmelem_data(&(irc->cha), ircs_free_lcha);
	  ircs_cdc_ext(tab[1]);
	  ircs_write(STDOUT_FILENO, MSG_SUCCDE, strlen(MSG_SUCCDE));
	  return ;
	}
      if (lst && lst->next)
	irc->cha = irc->cha->next;
      if (lst)
	lst = lst->next;
    }
  ircs_write(STDOUT_FILENO, MSG_CHAND, strlen(MSG_CHAND));
}
