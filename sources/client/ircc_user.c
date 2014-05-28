
#include	<stdlib.h>
#include	"head_client.h"

int		ircc_treat_user(char **tab)
{
  int		i;

  i = 1;
  if (tab == NULL)
    return (-1);
  werase(ircc.page.users);
  while (tab[i] != NULL)
    {
      wprintw(ircc.page.users, "  %s\n", tab[i]);
      i++;
    }
  wrefresh(ircc.page.users);
  return (0);
}

int		ircc_user(char **tab)
{
  char		c;
  t_chan	*chan;

  c = IND_SEP;
  chan = ircc_curr_chan();
  if (chan != NULL && chan->name != NULL)
    {
      ircc_write(ircc.s, CMD_USER, strlen(CMD_USER));
      ircc_write(ircc.s, &c, 1);
      ircc_write(ircc.s, chan->name, strlen(chan->name));
      ircc_write(ircc.s, S_NLINE, 1);
    }
  if (tab)
    free(tab);
  return (0);
}
