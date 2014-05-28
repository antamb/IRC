
#include "head_serveur.h"

int	ircs_start(char **av)
{
  t_irc	*irc;

  irc = ircs_struct(IND_SET);
  irc->prt = atoi(av[1]);
  if (ircs_init(av) == FAIL)
    return (FAIL + (int) ircs_struct(IND_CLR) * fprintf(stderr, ERR_INIT));
  if (ircs_chan(IND_DEFCHAN) == FAIL)
    return (FAIL + (int) ircs_struct(IND_CLR) * fprintf(stderr, ERR_LOOP));
  if (ircs_loop() == FAIL)
    return (FAIL + (int) ircs_struct(IND_CLR) * fprintf(stderr, ERR_LOOP));
  return (SUCCES);
}

int	main(int UNUSED ac, char UNUSED **av)
{
  if (ac < 2 || ac > 2)
    return (SUCCES + 0 * fprintf(stderr, ERR_USAGE));
  if (ircs_start(av) == FAIL)
    return (FAIL);
  return (SUCCES);
}
