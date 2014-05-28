
#include	<unistd.h>	
#include	<stdlib.h>
#include	"head_client.h"

int		ircc_cmd_exit(void)
{
  t_lst		*tmp;
  t_lst		*lst;

  lst = ircc.chan;
  my_list_gotobeg(&lst);
  while (lst != NULL && CHANNEL)
    {
      tmp = lst;
      free(CHANNEL->name);
      del_panel(CHANNEL->panel);
      delwin(CHANNEL->win);
      free(CHANNEL);
      free(tmp);
      lst = lst->next;
    }
  delwin(ircc.page.seizure);
  delwin(ircc.page.datetime);
  delwin(ircc.page.chanel);
  delwin(ircc.page.title);
  delwin(ircc.page.users);
  endwin();
  close(ircc.s);
  exit(0);
  return (-1);
}
