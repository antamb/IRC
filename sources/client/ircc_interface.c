
#include	"head_client.h"

int		ircc_interface(void)
{
  if (ircc_xinit() == -1)
    return (-1);
  if (ircc_xtitle() == -1)
    return (-1);
  if (ircc_xcontent() == -1)
    return (-1);
  if (ircc_xusers() == -1)
    return (-1);
  if (ircc_xchannel() == -1)
    return (-1);
  if (ircc_xdatetime() == -1)
    return (-1);
  if (ircc_xseizure() == -1)
    return (-1);
  return (0);
}

