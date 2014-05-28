
#include	<curses.h>
#include	"head_client.h"

void		ircc_resize(int sig)
{
  (void)sig;
  ircc_interface();
  refresh();
}
