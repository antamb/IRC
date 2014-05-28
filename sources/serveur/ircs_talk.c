
#include "head_serveur.h"

t_tab	call[] = 
  {
    {CMD_NICK, ircs_cmd_nick},
    {CMD_LIST, ircs_cmd_list},
    {CMD_JOIN, ircs_cmd_join},
    {CMD_PART, ircs_cmd_part},
    {CMD_USER, ircs_cmd_user},
    {CMD_MESS, ircs_cmd_mess},
    {CMD_MESN, ircs_cmd_mesn},
    {0, 0}
  };

void	ircs_cmd(t_cli *cli, char **tab)
{
  int	i[2];

  bzero(i, sizeof(*i));
  while (call[i[0]].cmd)
    {
      if (!strcmp(call[i[0]].cmd, tab[0]))
	{
	  call[i[0]].fct(cli, tab);
	  i[1]++;
	}
      if (!call[i[0]].cmd && !i[1] && IND_VERBOSE)
	fprintf(stdout, MSG_INTRANS);
      i[0]++;
    }
}

void	ircs_talk(t_cli *cli)
{
  int	nrd;
  char	*dest;
  char	**tab;

  dest = cli->buff + cli->crd;
  if (!(nrd = ircs_read(cli->cfd, dest, IND_BUFFER - cli->crd)))
    {
      ircs_killcli(cli);
      return ;      
    }
  cli->crd += nrd;
  if (cli->buff[cli->crd - 1] != '\n')
    return ;
  cli->crd = 0;
  if (IND_VERBOSE)
    fprintf(stdout, MSG_INTRANS);
  if ((tab = ircs_cut(cli->buff, IND_SEP)) == NULL)
    return ;
  ircs_cmd(cli, tab);
  bzero(cli->buff, IND_BUFFER);
  free(tab);
}
