
#include	"head_client.h"

int             ircc_xdatetime(void)
{
  if ((ircc.page.datetime = newwin(1, COLS, LINES - 2, 0)) == NULL)
    return (-1);
  wbkgd(ircc.page.datetime, COLOR_PAIR(3));
  wrefresh(ircc.page.datetime);
  return (0);
}
