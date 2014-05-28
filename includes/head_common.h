
#ifndef _IRCCOM_H_
#define _IRCCOM_H_

/*
** DEFINES
*/

#define FAIL		-1
#define SUCCES		0
#define TRUE		1
#define FALSE		0
#define UNUSED		__attribute__((unused))

#define CMD_NICK	"NICK"
#define CMD_LIST	"LIST"
#define CMD_JOIN	"JOIN"
#define CMD_PART	"PART"
#define CMD_USER	"USER"
#define CMD_MESS	"MESS"
#define CMD_MESN	"MESN"
#define CMD_ADDC	"ADDC"
#define CMD_DELC	"DELC"
#define CMD_EXIT	"EXIT"
#define CMD_QUIT	"QUIT"
#define CMD_ERRS	"ERRS"
#define CMD_INFO	"INFO"
#define CMD_DECO	"DECO"
#define CMD_CONN	"CONN"

#define IND_SEP		'\t'
#define IND_BUFFER	1024
#define IND_UNKNOW	"Unknown_"
#define IND_DEFCHAN	"Home"
#define IND_VERBOSE	0

#endif /* !IRCCOM_H_ */
