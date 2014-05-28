
#include	<stdlib.h>
#include	"head_client.h"

int		ircc_treat_mesn(char **tab)
{
  char		*hour;

  if (tab == NULL)
    return (-1);
  if (ircc_count(tab) == 3)
    {
      hour = ircc_time();
      wprintw(ircc.page.content, "%s ", hour);
      wattron(ircc.page.content, COLOR_PAIR(7));
      wprintw(ircc.page.content, "== <#private# from %s>", tab[1]);
      wattroff(ircc.page.content, COLOR_PAIR(7));
      wprintw(ircc.page.content, " : %s\n", tab[2]);
      wrefresh(ircc.page.content);
      free(hour);
    }
  return (0);
}

int		ircc_mesn(char **tab)
{
  int		i;
  char		c;

  c = IND_SEP;
  if (ircc_count(tab) >= 3)
    {
      ircc_write(ircc.s, CMD_MESN, strlen(CMD_MESN));
      ircc_write(ircc.s, &c, 1);
      ircc_write(ircc.s, tab[1], strlen(tab[1]));
      ircc_write(ircc.s, &c, 1);
      i = 2;
      while (tab[i] != NULL)
	{
	  ircc_write(ircc.s, tab[i], strlen(tab[i]));
	  if (tab[i + 1])
	    ircc_write(ircc.s, " ", 1);
	  i++;
	}
      ircc_write(ircc.s, S_NLINE, 1);
    }
  free(tab);
  return (0);
}
