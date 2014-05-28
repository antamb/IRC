
#include	<stdlib.h>
#include        <sys/types.h>
#include        <sys/uio.h>
#include        <unistd.h>
#include        <sys/ioctl.h>
#include        <sys/select.h>
#include	"head_client.h"

t_cmd            treat[] =
  {
    {0, CMD_LIST, ircc_treat_list},
    {1, CMD_USER, ircc_treat_user},
    {2, CMD_MESS, ircc_treat_mess},
    {3, CMD_MESN, ircc_treat_mesn},
    {4, CMD_ERRS, ircc_treat_errs},
    {5, CMD_INFO, ircc_treat_info},
    {6, CMD_ADDC, ircc_treat_addc},
    {7, CMD_DELC, ircc_treat_delc},
    {8, CMD_DECO, ircc_treat_deco},
    {9, NULL, NULL}
  };

int		ircc_treat_deco(char **tab)
{
  t_chan	*chan;

  if (ircc_count(tab) != 3)
    return (-1);
  chan = ircc_curr_chan();
  if (chan != NULL && strcmp(chan->name, tab[1]) == 0)
    ircc_show_info(tab[2], NULL);
  return (0);
}

int		ircc_treat_errs(char **tab)
{
  if (ircc_count(tab) == 2)
    ircc_show_error(tab[1], NULL);
  return (0);
}

int		ircc_treat_info(char **tab)
{
  if (ircc_count(tab) == 2)
    ircc_show_info(tab[1], NULL);
  return (0);
}

int		ircc_treat_result(void)
{
  int		i;
  char		*res;
  char		**tab;

  i = -1;
  res = strdup(ircc.buffer);
  memset(ircc.buffer, '\0', sizeof(ircc.buffer));
  if ((tab = ircc_cut(res, IND_SEP)) == NULL)
    {
      free(res);
      return (-1);
    }
  while (treat[++i].cmd != NULL)
    {
      if (strcmp(tab[0], treat[i].cmd) == 0)
	{
	  treat[i].func(tab);
	  free(res);
	  return (0);
	}
    }
  free(tab);
  free(res);
  return (0);
}

int		ircc_show_result(void)
{
  int		sizet;
  int		sizer;
  char		*strg;
  char		buf[BUFSIZ];

  (void)strg;
  sizet = 0;
  if (ioctl(ircc.s, FIONREAD, &sizet) == -1)
    return (-1);
  if ((sizer = read(ircc.s, buf, sizet)) == -1)
    return (-1);
  buf[sizer] = '\0';
  if (strlen(ircc.buffer) == 0)
    strcpy(ircc.buffer, buf);
  else
    strcat(ircc.buffer, buf);
  strg = strstr(ircc.buffer, S_NLINE);
  if (strg != NULL)
    ircc_treat_result();
  return (0);
}

