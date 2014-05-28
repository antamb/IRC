
#include <signal.h>
#include "head_serveur.h"

int	ircs_signal()
{
  if (signal(SIGPIPE, SIG_IGN) == SIG_ERR)
    return (FAIL);
  if (signal(SIGINT, ircs_killirc) == SIG_ERR)
    return (FAIL);
  return (SUCCES);
}

int	ircs_socket()
{
  t_irc	*irc;

  irc = ircs_struct(IND_GET);
  if ((irc->sfd = socket(PF_INET, SOCK_STREAM, 0)) == FAIL)
    return (FAIL);
  return (SUCCES);
}

int	ircs_bind()
{
  t_irc	*irc;

  irc = ircs_struct(IND_GET);
  irc->sin.sin_family = AF_INET;
  irc->sin.sin_port = htons(irc->prt);
  irc->sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(irc->sfd, (t_sad *) &(irc->sin), sizeof(irc->sin)) == FAIL)
    return (FAIL);
  return (SUCCES);
}

int	ircs_listen()
{
  t_irc	*irc;

  irc = ircs_struct(IND_GET);
  if (listen(irc->sfd, IND_QUEUE) == FAIL)
    return (FAIL);
  return (SUCCES);
}

int	ircs_init()
{
  if (ircs_signal() == FAIL)
    return (FAIL + 0 * fprintf(stderr, ERR_SIGNAL));
  if (ircs_socket() == FAIL)
    return (FAIL + 0 * fprintf(stderr, ERR_SOCKET));
  if (ircs_bind() == FAIL)
    return (FAIL + 0 * fprintf(stderr, ERR_BIND));
  if (ircs_listen() == FAIL)
    return (FAIL + 0 * fprintf(stderr, ERR_LISTEN));
  return (SUCCES);
}
