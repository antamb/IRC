
#include	<stdlib.h>
#include	"head_client.h"

t_cmd		cmds[] = 
  {
    {0, C_NICK, ircc_nick},
    {1, C_LIST, ircc_list},
    {2, C_JOIN, ircc_join},
    {3, C_PART, ircc_part},
    {4, C_USER, ircc_user},
    {5, C_MESS, ircc_mesn},
    {6, NULL, NULL}
  };

int		ircc_process(char *cmd)
{
  int		i;
  char		*mess;
  char		**tab;

  i = 0;
  mess = strdup(cmd);
  tab = ircc_cut(cmd, ' ');
  if (tab == NULL)
    return (-1);
  while (cmds[i].cmd != NULL)
    {
      if (strcmp(tab[0], cmds[i].cmd) == 0)
	return (cmds[i].func(tab));
      i++;
    }
  ircc_mess(mess);
  free(tab);
  return (0);
}
