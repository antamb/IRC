
#include	"head_client.h"

int		ircc_wmove(void)
{
  werase(ircc.page.seizure);
  waddstr(ircc.page.seizure, S_PROMT);
  wmove(ircc.page.seizure, 0, strlen(S_PROMT));
  wrefresh(ircc.page.seizure);
  return (0);
}
