
#include	"head_client.h"

int		ircc_refresh(void)
{
  wrefresh(ircc.page.title);
  wrefresh(ircc.page.chanel);
  wrefresh(ircc.page.users);
  wrefresh(ircc.page.content);
  wrefresh(ircc.page.seizure);
  wrefresh(ircc.page.datetime);
  refresh();
  return (0);
}
