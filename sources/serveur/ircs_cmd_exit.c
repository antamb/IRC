
#include "head_serveur.h"

void	ircs_cmd_exit(char UNUSED **tab)
{
  t_irc	*irc;

  if (IND_VERBOSE)
    fprintf(stdout, "%s%s\n\n", MSG_REQU, CMD_EXIT);
  irc = ircs_struct(IND_GET);
  free(irc->temp);
  ircs_killirc(0);
  return ;
}
