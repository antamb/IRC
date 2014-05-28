
#include	<ctype.h>
#include	<stdlib.h>
#include	"head_client.h"

static int	ircc_nbr(char *str, char sep)
{
  int		i;

  i = 0;
  while (*str)
    {
      while (*str && *str == sep)
	str++;
      if (*str)
	i++;
      while (*str && *str != sep)
	str++;
    }
  return (i);
}

char	**ircc_cut(char *str, char sep)
{
  int	pos;
  char	*sav;
  char	**tab;

  sav = str + strlen(str);
  while (sav >= str && (!*sav || isspace(*sav)))
    *(sav--) = '\0';
  if (!(pos = ircc_nbr(str, sep)))
    return NULL;
  if ((tab = malloc((pos + 1) * sizeof(*tab))) == NULL)
    return (NULL);
  tab[pos] = NULL;
  pos = 0;
  while (*str)
    {
      while (*str && *str == sep)
	str++;
      if (*str)
	tab[pos++] = str;
      while (*str && *str != sep)
	str++;
      if (*str)
	*(str++) = '\0';
    }
  return (tab);
}
