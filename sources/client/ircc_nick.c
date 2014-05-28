
#include	<stdlib.h>
#include	"head_client.h"

int		ircc_treat_nick(char **tab)
{
  (void)tab;
  return (0);
}

int		ircc_nick(char **tab)
{
  char		c;
  char		cmd[BUFSIZ];

  c = IND_SEP;
  bzero(cmd, sizeof(cmd));
  if (ircc_count(tab) != 2)
    return (-1);
  ircc_write(ircc.s, CMD_NICK, strlen(CMD_NICK));
  ircc_write(ircc.s, &c, 1);
  ircc_write(ircc.s, tab[1], strlen(tab[1]));
  ircc_write(ircc.s, S_NLINE, 1);
  free(tab);
  return (0);
}
