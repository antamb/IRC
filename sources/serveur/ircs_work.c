
#include "head_serveur.h"

t_tab	inte[] = 
  {
    {ICMD_ADDC, ircs_cmd_addc},
    {ICMD_DELC, ircs_cmd_delc},
    {ICMD_EXIT, ircs_cmd_exit},
    {ICMD_QUIT, ircs_cmd_exit},
    {0, 0}
  };

void	ircs_int(char **tab)
{
  int	i[2];

  i[0] = 0;
  i[1] = 0;
  while (inte[i[0]].cmd)
    {
      if (!strcmp(inte[i[0]].cmd, tab[0]))
	{
	  inte[i[0]].fct(tab);
	  i[1]++;
	}
      if (!(inte[i[0]].cmd) && !i[1] && IND_VERBOSE)
	fprintf(stdout, MSG_SERVTYPE);
      i[0]++;
    }
}

void	ircs_work()
{
  t_irc *irc;
  char	**tab;

  irc = ircs_struct(IND_GET);
  ircs_read(STDIN_FILENO, irc->buff, IND_BUFFER);
  if ((tab = ircs_cut(irc->buff, ' ')) == NULL)
    return ;
  irc->temp = tab;
  ircs_int(tab);
  free(tab);
}
