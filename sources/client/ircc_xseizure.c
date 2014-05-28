
#include	"head_client.h"

int             ircc_xseizure(void)
{
  int           len;

  len = strlen(S_PROMT);
  if ((ircc.page.seizure = newwin(1, COLS, LINES - 1, 0)) == NULL)
    return (-1);
  wbkgd(ircc.page.seizure, COLOR_PAIR(1));
  wrefresh(ircc.page.seizure);
  return (0);
}

