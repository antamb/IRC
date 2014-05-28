
#include "head_serveur.h"

int		ircs_free_lcli(void *elem)
{
  t_cli		*cli;

  cli = (t_cli *) elem;
  if (cli->cfd != NOT_SET)
    close(cli->cfd);
  free(cli->nick);
  free(cli);
  return (SUCCES);
}

int		ircs_free_fcli(void *elem)
{
  t_cli		*cli;

  cli = (t_cli *) elem;
  return (SUCCES);
}

int		ircs_free_lcha(void *elem)
{
  t_cha		*cha;

  cha = (t_cha *) elem;
  my_freelist_data(&(cha->cli), ircs_free_fcli);
  free(cha->name);
  free(cha);
  return (SUCCES);
}

t_irc		*ircs_struct(int flg)
{
  static t_irc	irc;

  if (flg == IND_SET)
    {
      bzero(&irc, sizeof(irc));
      irc.sfd = NOT_SET;
    }
  if (flg == IND_CLR)
    {
      if (irc.sfd != NOT_SET)
	close(irc.sfd);
      my_freelist_data(&irc.cli, ircs_free_lcli);
      my_freelist_data(&irc.cha, ircs_free_lcha);
      return ((t_irc *) SUCCES);
    }
  return (&irc);
}
