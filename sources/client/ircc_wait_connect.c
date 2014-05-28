
#include	<stdlib.h>
#include	"head_client.h"

int		ircc_get_cmd(char *cmd)
{
  char		**tab;

  tab = ircc_cut(cmd, ' ');
  if (tab != NULL && ircc_count(tab) == 3 && strcmp(tab[0], C_SERV) == 0)
    ircc_client(tab);
  else if (tab != NULL && strcmp(tab[0], C_EXIT) == 0)
    {
      free (tab);
      ircc_cmd_exit();
    }
  else
    {
      free(tab);
      ircc_show_error(M_NCON, NULL);
    }
  return (0);
}

int		ircc_wait_connect(void)
{
  int		i;
  char		c;
  char		cmd[BUFSIZ];

  i = 0;
  ircc_interface();
  ircc_show_error(M_NCON, NULL);
  waddstr(ircc.page.seizure, S_PROMT);
  while (1)
    {
      c = wgetch(ircc.page.seizure);
      cmd[i++] = c;
      if (c == ENTER)
	{
	  cmd[i] = '\0';
	  ircc_get_cmd(cmd);
	  wclear(ircc.page.seizure);
	  waddstr(ircc.page.seizure, S_PROMT);
	  i = 0;
	}
      else
	wprintw(ircc.page.seizure, "%c", c);
    }
  return (0);
}
