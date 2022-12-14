# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucimart <lucimart@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 23:50:14 by lucimart          #+#    #+#              #
#    Updated: 2022/10/11 23:36:31 by lucimart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $@ stands for the target
# $< stands for the first dependency
# $^ is similar to $<, but $^ stands for all the dependencies
# while $< will only get the first one.

NAME =			push_swap

CC =			gcc
S =				./src/
I = 			./inc/
O =				./obj/
CFLAGS =		-g
# CFLAGS +=		-g -Wall -Werror -Wextra -I$I
LIBFT_DIR =		./libft/
LIBFT =			$(LIBFT_DIR)libft.a
REG_SRCS =		$Smain.c \
				$Sutils.c \
				$Sparse.c \
				$Ssort.c \
				$Soperations/push.c \
				$Soperations/reverse_rotate.c \
				$Soperations/rotate.c \
				$Soperations/swap.c \
				$Soperations/utils.c
BONUS_SRCS =
RM = /bin/rm -f
RMDIR = /bin/rmdir

# ifdef does not expand variable references; it just sees if something is defined at all
# You can text replace at the end of each space seperated word using $(var:a=b)
ifdef WITH_BONUS
	OBJ = $(REG_SRCS:$S%=$O%.o) $(BONUS_SRCS:%=$O%.o)
else
	OBJ = $(REG_SRCS:$S%=$O%.o)
endif

# The all rule itself has no special meaning.
# Make simply runs the first rule when no rule is specified.
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "\033[33m[Compiling push_swap...]"
	@$(CC) $(CFLAGS) -o $@ $^

$(LIBFT):
	@echo "\033[33m[Compiling Libft...]"
	@$(MAKE) -s bonus -C $(LIBFT_DIR)

# The @ at the beginning of the line prevents make
# from displaying the line before executing it
$O:
	@mkdir -p $@
	@mkdir -p $@/operations

$(OBJ): | $O

# If the object file doesn???t exist or if the source file is newer
# than the object file, the contents of the rule will be executed.
$O%.o: $S%
	$(CC) -c $(CFLAGS) -O0 $< -o $@

cleanobj:
	@$(RM) $(wildcard $(OBJ))

cleanobjdir: cleanobj
	@$(RMDIR) $O/operations
	@$(RMDIR) $O

cleanlibft:
	@$(MAKE) -s clean -C $(LIBFT_DIR)

# @ makes it silent.
# - in front of the command makes sure that make ignores a non-zero return code
clean: cleanlibft cleanobjdir
	@echo "\033[33m[Erasing object files...]"

fclean: clean
	@echo "\033[33m[Erasing generated files...]"
	@$(MAKE) -s fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)

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
.PHONY: all clean fclean re bonus libft cleanlibft cleanobj cleanobjdir

# https://noahloomans.com/tutorials/makefile/
# https://makefiletutorial.com/
# https://www.gnu.org/software/make/manual/make.html
