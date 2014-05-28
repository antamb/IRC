
NAME_C		= client

NAME_S		= serveur

INCLUDE		= ./includes

LIB		= ./libs

SRC		= ./sources

SRC_C		= $(SRC)/$(NAME_C)/ircc_nothing.c\
		$(SRC)/$(NAME_C)/ircc_client.c\
		$(SRC)/$(NAME_C)/ircc_cmd_exit.c\
		$(SRC)/$(NAME_C)/ircc_count.c\
		$(SRC)/$(NAME_C)/ircc_curr_chan.c\
		$(SRC)/$(NAME_C)/ircc_cut.c\
		$(SRC)/$(NAME_C)/ircc_disp_chan.c\
		$(SRC)/$(NAME_C)/ircc_extern.c\
		$(SRC)/$(NAME_C)/ircc_get_host.c\
		$(SRC)/$(NAME_C)/ircc_init.c\
		$(SRC)/$(NAME_C)/ircc_interface.c\
		$(SRC)/$(NAME_C)/ircc_join.c\
		$(SRC)/$(NAME_C)/ircc_list.c\
		$(SRC)/$(NAME_C)/ircc_loop.c\
		$(SRC)/$(NAME_C)/ircc_main.c\
		$(SRC)/$(NAME_C)/ircc_mesn.c\
		$(SRC)/$(NAME_C)/ircc_mess.c\
		$(SRC)/$(NAME_C)/ircc_nick.c\
		$(SRC)/$(NAME_C)/ircc_part.c\
		$(SRC)/$(NAME_C)/ircc_process.c\
		$(SRC)/$(NAME_C)/ircc_refresh.c\
		$(SRC)/$(NAME_C)/ircc_resize.c\
		$(SRC)/$(NAME_C)/ircc_show_mess.c\
		$(SRC)/$(NAME_C)/ircc_show_result.c\
		$(SRC)/$(NAME_C)/ircc_time.c\
		$(SRC)/$(NAME_C)/ircc_treat_chan.c\
		$(SRC)/$(NAME_C)/ircc_user.c\
		$(SRC)/$(NAME_C)/ircc_wait_connect.c\
		$(SRC)/$(NAME_C)/ircc_wmove.c\
		$(SRC)/$(NAME_C)/ircc_write.c\
		$(SRC)/$(NAME_C)/ircc_xchannel.c\
		$(SRC)/$(NAME_C)/ircc_xcontent.c\
		$(SRC)/$(NAME_C)/ircc_xdatetime.c\
		$(SRC)/$(NAME_C)/ircc_xinit.c\
		$(SRC)/$(NAME_C)/ircc_xseizure.c\
		$(SRC)/$(NAME_C)/ircc_xtitle.c\
		$(SRC)/$(NAME_C)/ircc_xusers.c

SRC_S		= $(SRC)/$(NAME_S)/ircs_main.c\
		$(SRC)/$(NAME_S)/ircs_cmd_nick.c\
		$(SRC)/$(NAME_S)/ircs_cmd_mess.c\
		$(SRC)/$(NAME_S)/ircs_cmd_mesn.c\
		$(SRC)/$(NAME_S)/ircs_cmd_join.c\
		$(SRC)/$(NAME_S)/ircs_cmd_part.c\
		$(SRC)/$(NAME_S)/ircs_cmd_list.c\
		$(SRC)/$(NAME_S)/ircs_cmd_user.c\
		$(SRC)/$(NAME_S)/ircs_cmd_addc.c\
		$(SRC)/$(NAME_S)/ircs_cmd_delc.c\
		$(SRC)/$(NAME_S)/ircs_cmd_exit.c\
		$(SRC)/$(NAME_S)/ircs_struct.c\
		$(SRC)/$(NAME_S)/ircs_signal.c\
		$(SRC)/$(NAME_S)/ircs_accept.c\
		$(SRC)/$(NAME_S)/ircs_work.c\
		$(SRC)/$(NAME_S)/ircs_free.c\
		$(SRC)/$(NAME_S)/ircs_talk.c\
		$(SRC)/$(NAME_S)/ircs_loop.c\
		$(SRC)/$(NAME_S)/ircs_init.c\
		$(SRC)/$(NAME_S)/ircs_chan.c\
		$(SRC)/$(NAME_S)/ircs_cut.c\
		$(SRC)/$(NAME_S)/ircs_io.c

OBJ_C		= $(SRC_C:.c=.o)

OBJ_S		= $(SRC_S:.c=.o)

CC		= $(CC_$(HOSTTYPE))

CC_FreeBSD	= gcc

CC_ia64-linux	= gcc

CC_powerpc	= gcc

CC_sun4		= /usr/sfw/bin/gcc

LDFLAGS		= -L$(LIB)\
		-lmy_list_`uname -m`-`uname -s` -lcurses -lpanel 

CFLAGS		= -I$(INCLUDE)\
		-ansi -pedantic -W -Wall -pipe -Wshadow -Wextra -Werror

RM		= rm -rf

all		: $(NAME_C) $(NAME_S)

$(NAME_C)	: $(OBJ_C)
		$(CC) -o $(NAME_C) $(OBJ_C) $(LDFLAGS)

$(NAME_S)	: $(OBJ_S)
		$(CC) -o $(NAME_S) $(OBJ_S) $(LDFLAGS)

.c.o		:
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

clean		:
		$(RM) \#* *~
		$(RM) $(LIB)/\#* $(LIB)/*~ $(LIB)/*.o
		$(RM) $(INCLUDE)/\#* $(INCLUDE)/*~ $(INCLUDE)/*.o
		$(RM) $(SRC)/$(NAME_C)/\#* $(SRC)/$(NAME_C)/*~\
		$(SRC)/$(NAME_C)/*.o
		$(RM) $(SRC)/$(NAME_S)/\#* $(SRC)/$(NAME_S)/*~\
		$(SRC)/$(NAME_S)/*.o

fclean		: clean
		$(RM) $(NAME_C)
		$(RM) $(NAME_S)

re		: fclean all

love		:
		@echo "... not war"

coffee		:
		@echo "... have a break
