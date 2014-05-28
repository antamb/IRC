
#include <errno.h>
#include "head_serveur.h"

int	ircs_read(int fd, char *buff, int len)
{
  int	nbr;

  nbr = read(fd, buff, len);
  buff[nbr] = '\0';
  return (nbr);
}

int	ircs_write(int fd, char *str, int len)
{
  int	nbr;

  nbr = write(fd, str, len);
  return (nbr);
}
