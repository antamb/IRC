
#include "head_serveur.h"

void	ircs_cac_ext(char *str)
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
      ircs_write(CLIENT->cfd, CMD_ADDC, strlen(CMD_ADDC));
      ircs_write(CLIENT->cfd, &c, 1);
      ircs_write(CLIENT->cfd, str, strlen(str));
      ircs_write(CLIENT->cfd, "\n", 1);
      lst = lst->next;
    }
}

void	ircs_cmd_addc(char **tab)
{
  char	c;
  t_lst	*lst;
  t_irc	*irc;

  c = IND_SEP;
  if (ircs_nbr(tab) != 2)
    return ;
  irc = ircs_struct(IND_GET);
  my_list_gotobeg(&(irc->cha));
  lst = irc->cha;
  while (lst && CHANNEL)
    {
      if (!strcmp(CHANNEL->name, tab[1]))
	{
	  ircs_write(STDERR_FILENO, MSG_CHANAL, strlen(MSG_CHANAL));
	  return ;
	}
      lst = lst->next;
    }
  ircs_chan(tab[1]);
  ircs_cac_ext(tab[1]);
  ircs_write(STDOUT_FILENO, MSG_SUCCAD, strlen(MSG_SUCCAD));
}
