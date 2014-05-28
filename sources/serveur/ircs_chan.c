
#include "head_serveur.h"

int	ircs_chan(char *name)
{
  t_irc	*irc;
  t_lst	*lst;
  t_cha	*cha;

  irc = ircs_struct(IND_GET);
  lst = irc->cha;
  my_list_gotobeg(&lst);
  while (lst && CHANNEL)
    {
      if (!strcmp(CHANNEL->name, name))
	return (FAIL);
      lst = lst->next;
    }
  if ((cha = malloc(sizeof(*cha))) == NULL)
    return (FAIL);
  bzero(cha, sizeof(*cha));
  asprintf(&(cha->name), name);
  my_list_putinend(&(irc->cha), cha);
  return (SUCCES);
}

t_cha	*ircs_getchan(char *name)
{
  t_irc	*irc;
  t_lst	*lst;

  irc = ircs_struct(IND_GET);
  lst = irc->cha;
  my_list_gotobeg(&lst);
  while (lst && CHANNEL)
    {
      if (!strcmp(CHANNEL->name, name))
	return (CHANNEL);
      lst = lst->next;
    }
  return (NULL);  
}
