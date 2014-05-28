
#include                <stdio.h>
#include                <netdb.h>
#include                <sys/uio.h>
#include                <unistd.h>
#include                <sys/uio.h>
#include                <unistd.h>
#include                <stdlib.h>
#include		<arpa/inet.h>
#include                <sys/types.h>
#include                <netinet/in.h>
#include		"head_client.h"

char			*ircc_get_host(char *machin)
{
  struct hostent	*host;
  struct in_addr	addr;

  if (machin == NULL)
    return (NULL);
  if ((host = gethostbyname(machin)) == NULL)
    {
      ircc_show_error(ERR_UHOST, NULL);
      return (NULL);
    }
  bcopy(host->h_addr, &addr, sizeof(addr));
  return (inet_ntoa(addr));
}
