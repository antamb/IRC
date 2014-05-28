
#include	<stdlib.h>
#include	"head_client.h"

void		ircc_init_chan_ext(t_chan *chan, char *name)
{
  int		w;

  w = COLS / 4;
  chan->flag = F_NCUR;
  chan->isjoin = F_NO_JOIN;
  chan->name = strdup(name);
  chan->win = newwin(LINES - 4, COLS - w, 1, 0);
  chan->panel = new_panel(chan->win);
  scrollok(chan->win, true);
  wbkgd(chan->win, COLOR_PAIR(1));
  hide_panel(chan->panel);
  wrefresh(chan->win);
}

int             ircc_init_chan(char **tab)
{
  int		i;
  t_chan        *chan;

  i = 1;
  ircc.isset = F_IS_SET;
  ircc_xchannel();
  while (tab[i] != NULL)
    {
      if ((chan = malloc(sizeof(*chan))) == NULL)
	return (-1);
      bzero(chan , sizeof(*chan));
      if (strcmp(tab[i], IND_DEFCHAN) != 0)
	{
	  ircc_init_chan_ext(chan, tab[i]);
	  my_list_putinbeg(&(ircc.chan), chan);
	}
      i++;
    }
  update_panels();
  doupdate();
  free(tab);
  return (0);
}


int		ircc_treat_list(char **tab)
{
  int		i;
  char		*hour;

  i = 1;
  if (tab == NULL)
    return (-1);
  if (ircc.isset == F_NO_SET)
    {
      ircc_init_chan(tab);
      return (0);
    }
  hour = ircc_time();
  while (tab[i] != NULL)
    {
      wprintw(ircc.page.content, "%s ", hour);
      wattron(ircc.page.content, COLOR_PAIR(6));
      wprintw(ircc.page.content, "== [channel %i] -> #%s\n", i, tab[i]);
      wattroff(ircc.page.content, COLOR_PAIR(6));
      wrefresh(ircc.page.content);
      i++;
    }
  free(hour);
  return (0);
}

int		ircc_list(char **tab)
{
  char		c;

  c = IND_SEP;
  ircc_write(ircc.s, CMD_LIST, strlen(CMD_LIST));
  if (tab[1] != NULL)
    {
      ircc_write(ircc.s, &c, 1);
      ircc_write(ircc.s, tab[1], strlen(tab[1]));
    }
  ircc_write(ircc.s, S_NLINE, 1);
  free(tab);
  return (0);
}
