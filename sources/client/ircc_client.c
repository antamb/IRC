
#include		"head_client.h"
#include		<sys/select.h>
#include		<sys/socket.h>
#include		<sys/types.h>
#include		<netinet/in.h>
#include		<arpa/inet.h>
#include		<sys/time.h>
#include		<sys/uio.h>
#include		<stdlib.h>
#include		<unistd.h>

static int		ircc_welcome(char *machin, char *ip)
{
  char			*hour;

  ircc_show_info(M_CONN, NULL);
  ircc_show_info(M_WELC,NULL);
  if (machin != NULL || ip != NULL)
    {
      hour = ircc_time();
      wprintw(ircc.page.content, "%s ", hour);
      wattron(ircc.page.content, COLOR_PAIR(6));
      wprintw(ircc.page.content, M_INFO, machin, ip);
      wattroff(ircc.page.content, COLOR_PAIR(6));
      free(hour);
    }
  wrefresh(ircc.page.content);
  ircc_wmove();
  return (0);
}

static int		ircc_socket(int port, char *machin, \
				    struct sockaddr_in	*sin)
{
  int			s;
  socklen_t		len;

  (void)len;
  if ((s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    return (-1);
  sin->sin_port = htons(port);
  sin->sin_family = AF_INET;
  sin->sin_addr.s_addr = inet_addr(machin);
  return (s);
}

int			ircc_client(char **info)
{
  int			p;
  char			*m;
  struct sockaddr_in	sin;

  p = atoi(info[2]);
  if ((m = ircc_get_host(info[1])) == NULL)
    return (-1);
  if ((ircc.s = ircc_socket(p, m, &sin)) == -1)
    {
      free(info);
      return (ircc_show_error(M_FCON, NULL));
    }
  ircc_show_info(m, M_WAIT);
  if (connect(ircc.s, (struct sockaddr *)&sin, sizeof(sin)) == -1)
    {
      free(info);
      return (ircc_show_error(M_FCON, NULL));
    }
  ircc_welcome(info[1], m);
  free(info);
  ircc_loop();
  return (0);
}
