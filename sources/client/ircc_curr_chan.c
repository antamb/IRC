
#include	"head_client.h"

t_chan		*ircc_curr_chan(void)
{
  t_lst		*lst;

  lst = ircc.chan;
  my_list_gotobeg(&lst);
  while (lst && CHANNEL)
    {
      if (CHANNEL->flag == 1)
	return (CHANNEL);
      lst = lst->next;
    }
  return (NULL);
}
