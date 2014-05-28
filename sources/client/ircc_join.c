
#include	<stdlib.h>
#include	"head_client.h"

int		ircc_treat_join(char **tab)
{
  t_lst		*lst;

  if (ircc_count(tab) != 2)
    return (-1);
  lst = ircc.chan;
  my_list_gotobeg(&lst);
  while (lst != NULL && CHANNEL != NULL)
    {
      if (strcmp(CHANNEL->name, tab[1]) == 0 \
	  && CHANNEL->isjoin == F_NO_JOIN && CHANNEL->flag == F_NCUR)
	return (ircc_disp_chan(CHANNEL));
      lst = lst->next;
    }
  return (0);
}

int		ircc_join(char **tab)
{
  char		c;

  c = IND_SEP;
  if (ircc_count(tab) == 2)
    {
      ircc_write(ircc.s, CMD_JOIN, strlen(CMD_JOIN));
      ircc_write(ircc.s, &c, 1);
      ircc_write(ircc.s, tab[1], strlen(tab[1]));
      ircc_write(ircc.s, S_NLINE, 1);
    }
  ircc_treat_join(tab);
  free(tab);
  return (0);
}
