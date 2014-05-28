
#include	"head_client.h"

int             ircc_xtitle(void)
{
  if ((ircc.page.title = newwin(1, COLS, 0, 0)) == NULL)
    return (-1);
  wbkgd(ircc.page.title, COLOR_PAIR(2));
  waddstr(ircc.page.title, M_TITL);
  wrefresh(ircc.page.title);
  return (0);
}
