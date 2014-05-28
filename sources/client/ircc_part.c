
#include	<stdlib.h>
#include	"head_client.h"

int             ircc_treat_part(char **tab)
{
  t_lst         *lst;

  if (ircc_count(tab) != 2)
    return (-1);
  lst = ircc.chan;
  my_list_gotobeg(&lst);
  while (lst != NULL && CHANNEL != NULL)
    {
      if (strcmp(CHANNEL->name, tab[1]) == 0 && CHANNEL->isjoin == F_IS_JOIN)
	{
	  CHANNEL->isjoin = F_NO_JOIN;
	  return (ircc_switch_chan());
	}
      lst = lst->next;
    }
  return (0);
}

int		ircc_part(char **tab)
{
  char		c;

  c = IND_SEP;
  ircc_treat_part(tab);
  if (ircc_count(tab) == 2)
    {
      ircc_write(ircc.s, CMD_PART, strlen(CMD_PART));
      ircc_write(ircc.s, &c, 1);
      ircc_write(ircc.s, tab[1], strlen(tab[1]));
      ircc_write(ircc.s, S_NLINE, 1);
    }
  free(tab);
  return (0);
}
