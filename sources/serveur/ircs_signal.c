
#include "head_serveur.h"

void	ircs_killirc(int UNUSED sig)
{
  t_irc	*irc;

  irc = ircs_struct(IND_CLR);
  fclose(stdout);
  fclose(stderr);
  fclose(stdin);
  exit(SUCCES);
  return ;
}
