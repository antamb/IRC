
#include "head_serveur.h"

int	ircs_accept(int sfd, t_sad *cli, t_sle *len)
{
  int	cfd;

  if ((cfd = accept(sfd, cli, len)) == FAIL && errno != EINTR)
    return (FAIL + 0 * fprintf(stderr, ERR_ACCEPT));
  if (errno == EINTR)
    cfd = ircs_accept(sfd, cli, len);
  return (cfd);
}

int	ircs_nsh_valid(char *nick)
{
  t_irc	*irc;
  t_lst	*lst;

  irc = ircs_struct(IND_GET);
  lst = irc->cli;
  my_list_gotobeg(&lst);
  while (lst && CLIENT)
    {
      if (!strcmp(CLIENT->nick, nick))
	return (FAIL);
      lst = lst->next;
    }
  return (SUCCES);
}

void	ircs_nick_search(t_cli *cli)
{
  int	i;
  char	*nick;

  i = 0;
  while (TRUE)
    {
      asprintf(&nick, "%s%d", IND_UNKNOW, i);
      if (ircs_nsh_valid(nick) == SUCCES)
	{
	  asprintf(&(cli->nick), "%s", nick);
	  free(nick);
	  return ;
	}
      free(nick);
      i++;
    }
}

void	ircs_client()
{
  char	c;
  char	**tab;
  t_cli	*cli;
  t_sad	*sin;
  t_cha	*cha;
  t_irc	*irc;

  c = IND_SEP;
  irc = ircs_struct(IND_GET);
  if ((cha = ircs_getchan(IND_DEFCHAN)) == NULL)
    return ;
  if ((cli = malloc(sizeof(*cli))) == NULL)
    return ;
  bzero(cli, sizeof(*cli));
  sin = (t_sad *) &(cli->sin);
  if ((cli->cfd = ircs_accept(irc->sfd, sin, (t_sle *) &(cli->len))) == FAIL)
    return ;
  ircs_nick_search(cli);
  if (IND_VERBOSE)
    fprintf(stdout, MSG_CONNECT);
  my_list_putinend(&(cha->cli), cli);
  my_list_putinend(&(irc->cli), cli);
  ircs_cmd_list(cli, tab);
}
