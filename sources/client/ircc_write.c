
#include        <sys/types.h>
#include        <sys/uio.h>
#include        <unistd.h>
#include	"head_client.h"

int		ircc_write(int fd, char *str, size_t size)
{
  if (str == NULL)
    return (-1);
  if (write(fd, str, size) == -1)
    return (-1);
  return (0);
}
