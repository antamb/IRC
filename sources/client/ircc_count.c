
#include	"head_client.h"

int		ircc_count(char **tab)
{
  int		i;
  
  i = 0;
  if (tab == NULL)
    return (i);
  while (tab[i] != NULL)
    i++;
  return (i);
}
