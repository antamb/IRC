
#include	"head_client.h"

int		ircc_chan_check(char *name)
{
  t_lst         *lst;

  lst = ircc.chan;
  my_list_gotobeg(&lst);
  while (lst != NULL && CHANNEL != NULL)
    {
      if (CHANNEL->name != NULL && strcmp(CHANNEL->name, name) == 0)
	return (1);
      lst = lst->next;
    }
  return (0);
}

static int	ircc_disp_chan_ext2(t_chan *chan)
{
  chan->flag = F_NCUR;
  hide_panel(chan->panel);
  return (0);
}

static int	ircc_disp_chan_ext3(void)
{
  ircc_xusers();
  ircc_xchannel();
  return (0);
}

int		ircc_disp_chan(t_chan *channel)
{
  t_lst         *lst;

  lst = ircc.chan;
  my_list_gotobeg(&lst);
  if (channel == NULL || lst == NULL || !ircc_chan_check(channel->name))
    return (-1);
  while (lst != NULL && CHANNEL != NULL)
    {
      if (CHANNEL->name != NULL && strcmp(CHANNEL->name, channel->name) == 0)
	{
	  CHANNEL->flag = F_CURR;
	  CHANNEL->isjoin = F_IS_JOIN;
	  show_panel(CHANNEL->panel);
	  ircc.page.content = CHANNEL->win;
	}
      else
	ircc_disp_chan_ext2(CHANNEL);
      lst = lst->next;
    }
  update_panels();
  doupdate();
  ircc_disp_chan_ext3();
  return (0);
}
