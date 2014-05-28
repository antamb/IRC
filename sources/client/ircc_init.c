
#include	<stdlib.h>
#include	"head_client.h"

int		ircc_init(void)
{
  ircc.chan = NULL;
  ircc.isset = F_NO_SET;
  ircc.page.users = NULL;
  ircc.page.title = NULL;
  ircc.page.chanel = NULL;
  ircc.page.content = NULL;
  ircc.page.seizure = NULL;
  ircc.page.datetime = NULL;
  memset(ircc.buffer, '\0', sizeof(ircc.buffer));
  return (0);
}
