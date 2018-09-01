# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syamada <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/06 21:25:07 by syamada           #+#    #+#              #
#    Updated: 2018/09/01 16:31:57 by syamada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra
DEBUG		:= -g
SANITIZER	:= -fsanitize=address

LIB			:= libft.a
LIBDIR		:= libft

SRCDIR		:= srcs
INCDIR		:= includes

SSL			:= ft_ssl
SSLSRC		:= $(addprefix $(SRCDIR)/, ft_ssl.c \
					process_stdio_cmd.c error_cmd.c \
					dispatch_funcs.c option_checker.c error_exit.c)

#colors
COM_COLOR	:= \033[0;34m
OK_COLOR	:= \033[0;32m
EXEC_COLOR	:= \033[1;32m
DEBUG_COLOR	:= \033[0;33m
NO_COLOR	:= \033[m

.PHONY: all
all: $(SSL)

$(SSL): $(LIBDIR) $(LIBDIR)/$(LIB)
	@printf "%b" "$(NO_COLOR)Creating $(EXEC_COLOR)$@"
	@$(CC) -o $@ $(CFLAG) $(SSLSRC) -I$(INCDIR) -L$< -lft
	@printf "%b" " ✔\n"

$(LIBDIR)/$(LIB):
	@make -C $(LIBDIR)

.PHONY: clean
clean:
	@make -C $(LIBDIR) clean

.PHONY: fclean
fclean:
	@make -C $(LIBDIR) fclean
	@printf "%b" "$(NO_COLOR)Removing $(SSL)...\n"
	@rm -f $(SSL)
	@printf "%b" "$(OK_COLOR)[OK]: $(NO_COLOR)$(SSL) were successfully removed\n"

.PHONY: re
re: fclean all

.PHONY: debug
debug:
	@rm -f d$(SSL)
	@make d$(SSL)

d$(SSL): $(LIBDIR) $(LIBDIR)/$(LIB)
	@printf "%b" "$(DEBUG_COLOR)[DEBUG MODE] $(NO_COLOR)Creating $(EXEC_COLOR)$@"
	@$(CC) -o $@ $(CFLAG) $(DEBUG) $(SSLSRC) -I$(INCDIR) -L$< -lft
	@printf "%b" " ✔\n"

.PHONY: cleandebug
cleandebug:
	@rm -rf d$(SSL).dSYM
	@rm -f d$(SSL)

.PHONY: quick
quick:
	@printf "%b" "Quick recompile for $(CHECKER)\n"
	@rm -f $(SSL)
	@make $(SSL)
