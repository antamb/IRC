
#include	<stdlib.h>
#include	"head_client.h"

int		ircc_size(void)
{
  int		i;
  t_lst		*lst;

  i = 0;
  lst = ircc.chan;
  my_list_gotobeg(&lst);
  while (lst != NULL && CHANNEL != NULL)
    {
      i++;
      lst = lst->next;
    }
  return (i);
}

int		ircc_switch_chan(void)
{
  int		flag;
  t_lst		*lst;

  flag = 0;
  if (ircc_size() == 1)
    return (-1);
  lst = ircc.chan;
  my_list_gotobeg(&lst);
  while (lst != NULL && CHANNEL != NULL)
    {
      if (flag == 1 && CHANNEL->isjoin == F_IS_JOIN)
	return (ircc_disp_chan(CHANNEL));
      if (CHANNEL->flag == F_CURR)
	flag = 1;
      lst = lst->next;
    }
  lst = ircc.chan;
  my_list_gotobeg(&lst);
  while (lst != NULL && CHANNEL != NULL)
    {
      if (CHANNEL->flag != F_CURR && CHANNEL->isjoin == F_IS_JOIN)
	return (ircc_disp_chan(CHANNEL));
      lst = lst->next;
    }
  return (0);
}

int		ircc_treat_addc(char **tab)
{
  t_chan	*chan;

  if (ircc_count(tab) != 2)
    {
      free(tab);
      return (-1);
    }
  if ((chan = malloc(sizeof(*chan))) == NULL)
    {
      free(tab);
      return (-1);
    }
  bzero(chan , sizeof(*chan));
  chan->flag = F_NCUR;
  chan->isjoin = F_NO_JOIN;
  chan->name = strdup(tab[1]);
  chan->win = newwin(LINES - 4, COLS - (COLS / 4), 1, 0);
  wrefresh(chan->win);
  chan->panel = new_panel(chan->win);
  hide_panel(chan->panel);
  scrollok(chan->win, true);
  wbkgd(chan->win, COLOR_PAIR(1));
  update_panels();
  doupdate();
  my_list_putinbeg(&(ircc.chan), chan);
  free(tab);
  return (0);
}

int		ircc_delc(void *elem)
{
  t_chan	*chan;

  if (elem == NULL)
    return (-1);
  chan = (t_chan *)elem;
  free(chan->name);
  del_panel(chan->panel);
  delwin(chan->win);
  free(chan);
  return (0);
}

int		ircc_treat_delc(char **tab)
{
  t_lst		*lst;

  if (ircc_count(tab) != 2)
    {
      free(tab);
      return (-1);
    }
  my_list_gotobeg(&(ircc.chan));
  lst = ircc.chan;
  while (lst != NULL && CHANNEL != NULL)
    {
      if (strcmp(CHANNEL->name, tab[1]) == 0)
	{
	  my_list_rmelem_data(&(ircc.chan), ircc_delc);
	  free(tab);
	  return (0);
	}
      if (lst)
	{
	  lst = lst->next;
	  ircc.chan = ircc.chan->next;
	}
    }
  free(tab);
  return (0);
}
