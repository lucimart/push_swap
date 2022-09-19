# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucimart <lucimart@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 23:50:14 by lucimart          #+#    #+#              #
#    Updated: 2022/09/19 18:52:56 by lucimart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $@ stands for the target
# $< stands for the first dependency
# $^ is similar to $<, but $^ stands for all the dependencies
# while $< will only get the first one.

NAME =			push_swap

CC =			gcc
# CFLAGS =		-g
CFLAGS =		-g -Wall -Werror -Wextra
LIBFT_DIR =		./libft/
LIBFT =			$(LIBFT_DIR)libft.a
HEADERS_DIR = 	-Iinclude
REG_SRCS =		src/main.c \
				src/utils.c
BONUS_SRCS =

# ifdef does not expand variable references; it just sees if something is defined at all
# You can text replace at the end of each space seperated word using $(var:a=b)
ifdef WITH_BONUS
	OBJS = $(REG_SRCS:.c=.o) $(BONUS_SRCS:.c=.o)
else
	OBJS = $(REG_SRCS:.c=.o)
endif

# The all rule itself has no special meaning.
# Make simply runs the first rule when no rule is specified.
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "\033[33m[Compiling push_swap...]"
	@$(CC) -g -o $@ $^ $(HEADERS_DIR)

$(LIBFT):
	@echo "\033[33m[Compiling Libft...]"
	@$(MAKE) -s bonus -C $(LIBFT_DIR)
# If the object file doesn’t exist or if the source file is newer
# than the object file, the contents of the rule will be executed.
%.o: %.c
	@$(CC) -c $(CFLAGS) $(HEADERS_DIR) -O0 -o $@ $<

# @ makes it silent.
# - in front of the command makes sure that make ignores a non-zero return code
clean:
	@echo "\033[33m[Erasing object files...]"
	@$(MAKE) -s clean -C $(LIBFT_DIR)
	@rm -f $(OBJS)

fclean: clean
	@echo "\033[33m[Erasing generated files...]"
	@$(MAKE) -s fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

# Instead of having fclean and all as dependencies we will recursively
# call make twice. The $(MAKE) rule will expand to a make with all of
# the flags used to call the parent make pre-set.
re:
	@$(MAKE) -s fclean
	@$(MAKE) -s all

bonus:
	@echo "\033[33m[Compiling with bonus sources...]"
	@$(MAKE) WITH_BONUS=1 all
#.PHONY line means that all of these rules should be treated like commands, not
# outputs. So even if there exists a file called clean, clean will still run.
.PHONY: all clean fclean re bonus libft

# https://noahloomans.com/tutorials/makefile/
# https://makefiletutorial.com/
# https://www.gnu.org/software/make/manual/make.html
