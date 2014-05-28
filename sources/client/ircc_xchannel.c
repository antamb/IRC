
#include	"head_client.h"

int             ircc_xchannel(void)
{
  t_chan	*chan;

  chan = ircc_curr_chan();
  if ((ircc.page.chanel = newwin(1, COLS, LINES - 3, 0)) == NULL)
    return (-1);
  wbkgd(ircc.page.chanel, COLOR_PAIR(2));
  if (chan && chan->name && ircc.isset == F_IS_SET)
    wprintw(ircc.page.chanel, M_CHAN, chan->name);
  wrefresh(ircc.page.chanel);
  return (0);
}
