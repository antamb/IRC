
#include	<stdlib.h>
#include	"head_client.h"

int             ircc_xcontent(void)
{
  int           w;
  t_chan	*chan;

  w = COLS / 4;
  if ((chan = malloc(sizeof(*chan))) == NULL)
    return (-1);
  bzero(chan , sizeof(*chan));
  chan->flag = F_CURR;
  chan->isjoin = F_IS_JOIN;
  chan->name = strdup(IND_DEFCHAN);
  chan->win = newwin(LINES - 4, COLS - w, 1, 0);
  if (chan->win)
    ircc.page.content = chan->win;
  else
    return (-1);
  chan->panel = new_panel(chan->win);
  scrollok(chan->win, true);
  wbkgd(ircc.page.content, COLOR_PAIR(1));
  show_panel(chan->panel);
  update_panels();
  my_list_putinbeg(&(ircc.chan), chan);
  return (0);
}
