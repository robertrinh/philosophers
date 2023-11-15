# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qtrinh <qtrinh@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/01 15:08:12 by qtrinh        #+#    #+#                  #
#    Updated: 2023/11/15 16:53:10 by qtrinh        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := philo

CC := cc
CFLAGS := -Wall -Werror -Wextra -g #gflag for debug
HEADER := include/philosophers.h
INCLUDE := -I include
OBJDIR = objects

SRC := main.c \
		utils.c \

vpath %.c	src
OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

#COLORS SHOW
BOLD_GREEN=\033[1;92m
BOLD_RED=\033[1;91m
RED=\033[0;31m
PURPLE=\033[0;35m
YELLOW=\033[0;33m
GRAY=\033[0;37m
INTENSE_CYAN=\033[0;96m
END_COLOUR=\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(NAME)
	@echo "${RED}compiling? ${BOLD_GREEN}completed it mate ${END_COLOUR}"

$(OBJDIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJDIR)
	@echo "${RED} Socrates.. ${GRAY}Freud..${YELLOW}Davinci.. ${PURPLE}GETTING READY${INTENSE_CYAN}$< ${END_COLOUR}"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJDIR)
	@echo "${BOLD_RED}And so they have gone in their caves.. only to philosophise some more ${END_COLOUR}"

fclean: clean
	@rm -f $(NAME)
	@echo "${BOLD_GREEN}we out here ${END_COLOUR}"

re: fclean all

.PHONY: all clean fclean re