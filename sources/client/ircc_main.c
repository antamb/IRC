
#include	<signal.h>
#include	"head_client.h"

int		main(void)
{
  signal(SIGPIPE, ircc_nothing);
  signal(SIGWINCH, ircc_resize);
  ircc_init();
  ircc_wait_connect();
  return (0);
}
