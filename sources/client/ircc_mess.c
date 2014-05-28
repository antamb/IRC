
#include	<stdlib.h>
#include	"head_client.h"

WINDOW		*ircc_right_chan(char **tab)
{
  t_lst		*lst;

  lst = ircc.chan;
  my_list_gotobeg(&lst);
  while (lst != NULL && CHANNEL != NULL)
    {
      if (CHANNEL->name != NULL && strcmp(CHANNEL->name, tab[1]) == 0)
	return (CHANNEL->win);
      lst = lst->next;
    }
  return (NULL);
}

int		ircc_treat_mess(char **tab)
{
  char		*hour;

  if (tab == NULL)
    return (-1);
  if (ircc_count(tab) == 4)
    {
      hour = ircc_time();
      wprintw(ircc.page.content, "%s ", hour);
      wattron(ircc.page.content, COLOR_PAIR(7));
      wprintw(ircc.page.content, "== <%s>", tab[2]);
      wattroff(ircc.page.content, COLOR_PAIR(7));
      wprintw(ircc.page.content, " : %s\n", tab[3]);
      wrefresh(ircc.page.content);
      free(hour);
    }
  return (0);
}

int		ircc_mess(char *mess)
{
  char		c;

  c = IND_SEP;
  ircc_write(ircc.s, CMD_MESS, strlen(CMD_MESS));
  ircc_write(ircc.s, &c, 1);
  ircc_write(ircc.s, IND_DEFCHAN, strlen(IND_DEFCHAN));
  ircc_write(ircc.s, &c, 1);
  ircc_write(ircc.s, mess, strlen(mess));
  ircc_write(ircc.s, S_NLINE, 1);
  free(mess);
  return (0);
}
