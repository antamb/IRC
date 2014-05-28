
#include <sys/select.h>
#include "head_serveur.h"

int		ircs_fdset(fd_set *sset)
{
  int		max;
  t_irc		*irc;
  t_lst		*lst;

  max = NOT_SET;
  irc = ircs_struct(IND_GET);
  lst = irc->cli;
  FD_ZERO(sset);
  if (irc->sfd > max)
    max = irc->sfd;
  FD_SET(irc->sfd, sset);
  FD_SET(STDIN_FILENO, sset);
  my_list_gotobeg(&lst);
  while (lst && CLIENT)
    {
      if (CLIENT->cfd > max)
	max = CLIENT->cfd;
      FD_SET(CLIENT->cfd, sset);
      lst = lst->next;
    }
  return (max + 1);
}

void		ircs_loop_ext(t_irc *irc, fd_set *sset)
{
  t_lst		*lst;

  lst = irc->cli;
  my_list_gotobeg(&lst);
  while (lst && CLIENT)
    {
      irc->temp = (void *)&lst;
      if (FD_ISSET(CLIENT->cfd, sset))
	ircs_talk(lst->data);	
      if (lst)
	lst = lst->next;
    }
}

int		ircs_loop()
{
  int		max;
  t_irc		*irc;
  fd_set	sset;

  irc = ircs_struct(IND_GET);
  while ((max = ircs_fdset(&sset)) || 42)
    {
      ircs_write(STDOUT_FILENO, IND_PROMPT, strlen(IND_PROMPT));
      if (select(max, &sset, NULL, NULL, NULL) == FAIL)
	return (FAIL);
      ircs_write(STDOUT_FILENO, IND_RET, strlen(IND_RET));
      if (FD_ISSET(irc->sfd, &sset))
	ircs_client();
      if (FD_ISSET(STDIN_FILENO, &sset))
	ircs_work();
      ircs_loop_ext(irc, &sset);
    }
  return (SUCCES);
}
