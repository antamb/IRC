
#ifndef _IRCC_
# define _IRCC_

#include	<panel.h>
#include	<stdio.h>	
#include	<string.h>
#include	<curses.h>
#include	"my_list.h"
#include	"head_common.h"

/*Defines key*/
#define TAB		9
#define DEL		8
#define ENTER		10

/*Define flag*/
#define F_CURR		1
#define F_NCUR		0

#define F_NO_SET	-1
#define F_IS_SET	1

#define F_NO_JOIN	-1
#define F_IS_JOIN	1
/*Define access*/
#define CHANNEL	((t_chan *)(lst->data))

/*Define strings*/
#define S_PROMT		"=> "
#define S_NLINE		"\n"
#define S_SEPAR		"\t"

/*Defines messages*/
#define M_NCON		"Not connected."
#define M_CONN		"Connected to server."
#define M_WELC		"Welcome to the Piwi Internet Relay Chat Network."
#define M_INFO		"== Your host is %s[%s].\n\n"
#define M_CHAN		"[channel] => #%s"
#define M_FCON		"Connection failed."
#define M_TITL		"Piwi => Enhanced Environnement for Chat"
#define M_WAIT		"== Trying %s...\n"

/*Define commande*/
#define C_SERV		"/server"
#define C_NICK		"/nick"
#define C_LIST		"/list"
#define C_JOIN		"/join"
#define C_PART		"/part"
#define C_USER		"/users"
#define C_MESS		"/msg"
#define C_EXIT		"/exit"

/*Defines errors*/
#define	ERR_UHOST	"Hostname nor servname provided, or not known."

typedef struct  s_page{
  WINDOW        *title;
  WINDOW        *users;
  WINDOW        *chanel;
  WINDOW        *content;
  WINDOW        *seizure;
  WINDOW        *datetime;
}               t_page;

typedef struct  s_chan{
  int		flag;
  int		isjoin;
  char		*name;
  PANEL		*panel;
  WINDOW	*win;
}		t_chan;

typedef struct  s_ircc{
  int		s;
  int		isset;
  t_page	page;
  t_lst		*chan;
  char		buffer[BUFSIZ];
}		t_ircc;

typedef struct  s_cmd{
  int		num;
  const char	*cmd;
  int		(* func)();
}		t_cmd;

/*Extern*/
extern  t_ircc         ircc;

/*Define functions*/
int	ircc_xinit(void);
int	ircc_xtitle(void);
int	ircc_xusers(void);
int	ircc_xcontent(void);
int	ircc_xseizure(void);
int	ircc_xdatetime(void);
int	ircc_xchannel(void);

int	ircc_nick(char **tab);
int	ircc_list(char **tab);
int	ircc_user(char **tab);
int	ircc_part(char **tab);
int	ircc_join(char **tab);
int	ircc_mesn(char **tab);
int	ircc_mess(char *cmd);

int	ircc_show_result(void);
int	ircc_show_mess(char *mess);
int	ircc_show_info(char *mess, char *format);
int	ircc_show_error(char *mess, char *format);

int	ircc_treat_deco(char **tab);
int	ircc_treat_delc(char **tab);
int	ircc_treat_addc(char **tab);
int     ircc_treat_mess(char **tab);
int     ircc_treat_mesn(char **tab);
int     ircc_treat_user(char **tab);
int     ircc_treat_list(char **tab);
int     ircc_treat_nick(char **tab);
int     ircc_treat_join(char **tab);
int     ircc_treat_part(char **tab);
int	ircc_treat_errs(char **tab);
int	ircc_treat_info(char **tab);

int	ircc_init(void);
int	ircc_loop(void);
int	ircc_wmove(void);
int	ircc_select(void);
int	ircc_refresh(void);
int	ircc_cmd_exit(void);
int	ircc_interface(void);
int	ircc_count(char **tab);
int	ircc_switch_chan(void);	
int	ircc_wait_connect(void);
int	ircc_process(char *cmd);
int	ircc_client(char **info);
int	ircc_delete(char *cmd, int *i);
int	ircc_disp_chan(t_chan *channel);
int	ircc_write(int fd, char *str, size_t size);

void	ircc_resize(int sig);
void	ircc_nothing(int sig);

char	*ircc_time(void);
char	*ircc_get_host(char *machin);
char	**ircc_cut(char *str, char sep);

t_chan	*ircc_curr_chan(void);
#endif /*_IRCC_*/
