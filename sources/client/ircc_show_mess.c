
#include	<stdlib.h>
#include	"head_client.h"

int		ircc_show_mess(char *mess)
{
  char		*hour;

  if (mess == NULL)
    return (-1);
  hour = ircc_time();
  wprintw(ircc.page.content, "%s ", hour);
  wattron(ircc.page.content, COLOR_PAIR(7));
  wprintw(ircc.page.content, "== ");
  wattroff(ircc.page.content, COLOR_PAIR(7));
  wprintw(ircc.page.content, "%s\n", mess);
  wrefresh(ircc.page.content);
  free(hour);
  return (-1);
}

int             ircc_show_error(char *mess, char *format)
{
  char		*hour;

  if (mess == NULL)
    return (-1);
  hour = ircc_time();
  wprintw(ircc.page.content, "%s ", hour);
  wattron(ircc.page.content, COLOR_PAIR(5));
  if (format == NULL)
    wprintw(ircc.page.content, "== %s\n", mess);
  else
    wprintw(ircc.page.content, format, mess);
  wattroff(ircc.page.content, COLOR_PAIR(5));
  wrefresh(ircc.page.content);
  free(hour);
  return (0);
}

int             ircc_show_info(char *mess, char *format)
{
  char		*hour;

  if (mess == NULL)
    return (-1);
  hour = ircc_time();
  wprintw(ircc.page.content, "%s ", hour);
  wattron(ircc.page.content, COLOR_PAIR(6));
  if (format == NULL)
    wprintw(ircc.page.content, "== %s\n", mess);
  else
    wprintw(ircc.page.content, format, mess);
  wattroff(ircc.page.content, COLOR_PAIR(6));
  wrefresh(ircc.page.content);
  free(hour);
  return (0);
}
