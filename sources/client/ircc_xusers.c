
#include	"head_client.h"

int             ircc_xusers(void)
{
  int           x;
  int           w;

  w = COLS / 4;
  x = COLS - w;
  if ((ircc.page.users = newwin(LINES - 4, w, 1, x)) == NULL)
    return (-1);
  wbkgd(ircc.page.users, COLOR_PAIR(4));
  scrollok(ircc.page.users, true);
  wrefresh(ircc.page.users);
  return (0);
}
