
#ifndef LIST_H_
# define LIST_H_

#ifndef		NULL
# define	NULL	(void *)0
#endif

/*
** STRUCTURES
*/

typedef struct	s_lst
{
  void		*data;
  struct s_lst	*prev;
  struct s_lst	*next;
}		t_lst;

/*
** PROTOTYPES
*/

int	my_list_len(t_lst *list);
int	my_list_printer(t_lst *list);
int	my_list_printer_data(t_lst *list, int (*c)(void *), int (*p)(void *));
int	my_list_gotobeg(t_lst **list);
int	my_list_gotoend(t_lst **list);
int	my_list_putinbeg(t_lst **list, void *data);
int	my_list_putinend(t_lst **list, void *data);

int     my_list_rmelem(t_lst **lst);
int     my_list_rmelem_data(t_lst **lst, int (*e)(void *));

int     my_list_rmfrom(t_lst **lst, int (*f)(void *));
int     my_list_rmfrom_data(t_lst **lst, int (*f)(void *), int (*e)(void *));

int	my_freelist(t_lst **list);
int	my_freelist_data(t_lst **list, int (* func)(void *));

#endif /* !LIST_H */
