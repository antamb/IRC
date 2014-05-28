
#include	<time.h>
#include	"head_client.h"

char		*ircc_time(void)
{
  time_t	tt;
  struct tm	*tm;
  char		buf[10];

  tt = time(NULL);
  tm = localtime(&tt);
  if (tm != NULL)
    strftime(buf, 10, "[%H:%M]", tm);
  return (strdup(buf));
}
