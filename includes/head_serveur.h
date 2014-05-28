
#ifndef _IRCSRV_H_
#define _IRCSRV_H_

/*
** INCLUDES
*/

#include <sys/uio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include "my_list.h"
#include "head_common.h"

/*
** DEFINES
*/

#define TRS(x)		(x), (char) IND_SEP

#define CLIENT		((t_cli *)(lst->data))
#define CHANNEL		((t_cha *)(lst->data))

#define ERR_USAGE	"Usage: ./serveur port\n"
#define ERR_INIT	"Fail to initialize server.\n"
#define ERR_LOOP	"Fail to process listening.\n"
#define ERR_SOCKET	"Fail to create server socket.\n"
#define ERR_BIND	"Fail to bind server.\n"
#define ERR_LISTEN	"Fail to set queue.\n"
#define ERR_ACCEPT	"Fail to accept a client.\n"
#define ERR_SIGNAL	"Fail to redirect signals.\n"
#define ERR_KCLI	"Fail to kill clients.\n"

#define MSG_CONNECT	"Connection form a client named '%s'\n", cli->nick
#define MSG_INTRANS	"Transmission from '%s'\n", cli->nick
#define MSG_SERVTYPE	"Invalid command ...\n"
#define MSG_REQU	"Request : "
#define MSG_CHANAL	"This channel already exists.\n"
#define MSG_CHAND	"This channel doesn't exist.\n"
#define MSG_SUCCAD	"Channel successfully added !\n"
#define MSG_SUCCDE	"Channel successfully deleted !\n"

#define TRS_YOUALC	"You are already include into this channel.\n"
#define TRS_NOSUER	"There is no such user.\n"
#define TRS_NOSCHA	"There is no such channel.\n"
#define TRS_NICKAL	"This pseudonym is already reserved !\n"
#define TRS_USRJOIN	"A new user joined the channel : '"
#define TRS_USRLEFT	"A user has just left the channel : '"
#define TRS_NOUSER	"No user named '%s'\n", nick
#define TRS_MESS	TRS(CMD_MESS), TRS(tab[1]), TRS(cli->nick), tab[2]
#define TRS_MESN	TRS(CMD_MESN), TRS(cli->nick), tab[2]
#define TRS_DECO	TRS(CMD_DECO), TRS(cha->name), TRS_USRLEFT, cli->nick
#define TRS_CONN	TRS(CMD_CONN), TRS(cha->name), TRS_USRJOIN, cli->nick
#define TRS_ALCON	TRS(CMD_INFO), TRS_YOUALC
#define TRS_NOCHA	TRS(CMD_ERRS), TRS_NOSCHA
#define TRS_NOUSE	TRS(CMD_ERRS), TRS_NOSUER
#define TRS_ALNIC	TRS(CMD_ERRS), TRS_NICKAL
#define TRS_IFNIC	TRS(CMD_NICK), cli->nick

#define ICMD_ADDC	"/add"
#define ICMD_DELC	"/del"
#define ICMD_EXIT	"/exit"
#define ICMD_QUIT	"/quit"

#define IND_SET		1
#define IND_GET		0
#define IND_CLR		-1
#define IND_QUEUE	42
#define IND_PROMPT	"=> "
#define IND_RET		"\r"
#define NOT_SET		-1

/*
** STRUCTURES
*/

typedef socklen_t		t_sle;
typedef struct sockaddr_in	t_sin;
typedef struct sockaddr		t_sad;
typedef struct timeval		t_val;

typedef struct			s_irc
{
  int				prt;
  int				sfd;
  char				buff[IND_BUFFER];
  void				*temp;
  t_sin				sin;
  t_lst				*cli;
  t_lst				*cha;
}				t_irc;

typedef struct			s_cli
{
  int				cfd;
  int				len;
  int				crd;
  char				buff[IND_BUFFER];
  char				*nick;
  void				*temp;
  t_sin				sin;
}				t_cli;

typedef struct			s_cha
{
  char				*name;
  t_lst				*cli;
}				t_cha;

typedef struct			s_tab
{
  char				*cmd;
  void				(* fct)();
}				t_tab;

/*
** PROTOTYPES
*/

int	ircs_start();
int	ircs_socket();
int	ircs_bind();
int	ircs_listen();
int	ircs_init();
int	ircs_loop();
int	ircs_nbr(char **tab);
int	ircs_chan(char *name);
int	ircs_fdset(fd_set *sset);
int	ircs_freedata(void *cli);
int	ircs_cpt_free(void *elem);
int	ircs_free_lcha(void *elem);
int	ircs_read(int fd, char *buff, int len);
int	ircs_write(int fd, char *str, int len);
int	ircs_accept(int sfd, t_sad *cli, t_sle *len);

void	ircs_client();
void	ircs_work();
void	ircs_talk(t_cli *cli);
void	ircs_killcli(t_cli *cli);
void	ircs_killirc(int UNUSED sig);
void	ircs_deadchild(int UNUSED sig);
void	ircs_cmd_addc(char **tab);
void	ircs_cmd_delc(char **tab);
void	ircs_cmd_exit(char **tab);
void	ircs_cmd_nick(t_cli *cli, char **tab);
void	ircs_cmd_list(t_cli *cli, char **tab);
void	ircs_cmd_join(t_cli *cli, char **tab);
void	ircs_cmd_part(t_cli *cli, char **tab);
void	ircs_cmd_user(t_cli *cli, char **tab);
void	ircs_cmd_mess(t_cli *cli, char **tab);
void	ircs_cmd_mesn(t_cli *cli, char **tab);

t_irc	*ircs_struct(int flg);
t_cha	*ircs_getchan(char *name);
char	**ircs_cut(char *str, char sep);

#endif /* !IRCSRV_H_ */
