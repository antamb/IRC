
#include	<unistd.h>
#include	<sys/select.h>
#include	"head_client.h"

static int      ircc_get_seizure(char *cmd, int *i)
{
  cmd[*i] = '\0';
  if (strncmp(cmd, C_EXIT, strlen(C_EXIT)) == 0)
    return (ircc_cmd_exit());
  ircc_wmove();
  ircc_process(cmd);
  *i = 0;
  return (0);
}

int		ircc_edition(char *cmd, int *i)
{
  char		c;

  c = wgetch(ircc.page.seizure);
  cmd[(*i)++] = c;
  if (c == ENTER)
    ircc_get_seizure(cmd, i);
  else if (c == TAB)
    ircc_switch_chan();
  else
    wprintw(ircc.page.seizure, "%c", c);
  return (0);
}

int             ircc_loop(void)
{
  int		i;
  fd_set	readf;
  char		cmd[BUFSIZ];

  i = 0;
  while (1)
    {
      FD_ZERO(&readf);
      FD_SET(STDIN_FILENO, &readf);
      FD_SET(ircc.s, &readf);
      if (select(ircc.s + 1, &readf, NULL, NULL, NULL) == -1)
        return (-1);
      if (FD_ISSET(ircc.s, &readf))
	ircc_show_result();
      if (FD_ISSET(STDIN_FILENO, &readf))
	ircc_edition(cmd, &i);
      ircc_refresh();
    }
  return (0);
}
