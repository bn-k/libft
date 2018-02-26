##########################################################################
##########################################################################
##########################################################################
##########################################################################

.PHONY: clean $(NAME) re fclean all
.SILENT:

NAME = libftprintf.a

# compilation
CC = clang
FLAGS = # -Wall -Werror -Wextra

# dir
D_SRC = srcs
D_INC = includes
D_OBJ = objs

# sources
SRC =\
	 strings/ft_strncat.c \
	 strings/ft_strnstr.c \
	 strings/ft_putstr_fd.c \
	 strings/ft_strequ.c \
	 strings/ft_strlen.c \
	 strings/ft_strclr.c \
	 strings/ft_strsplit.c \
	 strings/ft_strnlen.c \
	 strings/ft_strchr.c \
	 strings/ft_striteri.c \
	 strings/ft_strjoin.c \
	 strings/ft_strstr.c \
	 strings/ft_putendl.c \
	 strings/ft_strcat.c \
	 strings/ft_putendl_fd.c \
	 strings/ft_strdel.c \
	 strings/ft_strnequ.c \
	 strings/ft_strrchr.c \
	 strings/ft_strmap.c \
	 strings/ft_strncmp.c \
	 strings/ft_strcpy.c \
	 strings/ft_strmapi.c \
	 strings/ft_strtrim.c \
	 strings/ft_strnew.c \
	 strings/ft_putstr.c \
	 strings/ft_strlcat.c \
	 strings/ft_strdup.c \
	 strings/ft_striter.c \
	 strings/ft_strsub.c \
	 strings/ft_strncpy.c \
	 strings/ft_strcmp.c \
	 numbers/ft_putnbr.c \
	 numbers/ft_putnbr_base.c \
	 numbers/ft_putnbr_ill.c \
	 numbers/ft_putnuminfo.c \
	 numbers/ft_putnbr_fd.c \
	 numbers/ft_atoi.c \
	 numbers/ft_itoa.c \
	 numbers/ft_nbrlen.c \
	 numbers/ft_print_adress.c \
	 memory/ft_memcmp.c \
	 memory/ft_bzero.c \
	 memory/ft_memcpy.c \
	 memory/ft_memalloc.c \
	 memory/ft_memccpy.c \
	 memory/ft_memchr.c \
	 memory/ft_memset.c \
	 memory/ft_memdel.c \
	 memory/ft_memmove.c \
	 file/ft_display_file.c \
	 chars/ft_isdigit.c \
	 chars/ft_isascii.c \
	 chars/ft_isprint.c \
	 chars/ft_toupper.c \
	 chars/ft_putchar.c \
	 chars/ft_isalpha.c \
	 chars/ft_putchar_fd.c \
	 chars/ft_isalnum.c \
	 chars/ft_tolower.c \
	 lst/ft_lstadd.c \
	 lst/ft_list_push_params.c \
	 lst/ft_lstnew.c \
	 lst/ft_list_push_back.c \
	 lst/ft_list_push_front.c \
	 lst/ft_lstmap.c \
	 lst/ft_lstdel.c \
	 lst/ft_lstdelone.c \
	 utf8/ft_putchar_utf8.c \
	 utf8/ft_putstr_utf8.c \
	 utf8/ft_strlen_utf8.c \
	 printf/ft_printf.c \
	 printf/test_1.c \
	 printf/parser.c \
	 printf/modifier.c \
	 printf/flags.c \
	 printf/pad.c \
	 printf/mark.c \
	 printf/s_spec.c \
	 printf/c_spec.c \
	 printf/p_spec.c \
	 printf/ss_spec.c \
	 printf/d_spec.c \
	 printf/o_spec.c \
	 printf/no_spec.c \
	 printf/x_spec.c \
	 printf/dd_spec.c \
	 printf/u_spec.c \
	 printf/pourcent_spec.c \
	 printf/s_display.c \
	 printf/c_display.c \
	 printf/d_display.c \
	 printf/x_display.c \
	 printf/o_display.c \
	 printf/u_display.c \
	 printf/ss_display.c \
	 printf/no_display.c \


# SPECIAL CHARS

LOG_CLEAR		= \033[2K
LOG_UP 			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BLACK		= \033[1;30m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_CYAN		= \033[1;36m
LOG_WHITE		= \033[1;37m


SRCS = $(addprefix $(D_SRC)/, $(SRC))
OBJS = $(addprefix $(D_OBJ)/, $(addsuffix .o, $(basename $(SRC))))
F_INC = $(addsuffix $(D_INC), $(basename -I))
OBJS_DIRS = $(sort $(dir $(OBJS)))

all: $(NAME)


$(NAME): build $(OBJS)
	echo "$(LOG_CLEAR)Create obj $(LOG_CYAN)$(LOG_NOCOLOR)$(LOG_UP)"
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	echo "$(LOG_BLACK)Compiling $(LOG_GREEN)done $(LOG_GREEN)✓$(LOG_NOCOLOR)"

build:
	mkdir -p $(D_OBJ)
	mkdir -p $(OBJS_DIRS)


clean:
	rm -f $(LIBS)
	rm -Rf $(OBJS_DIRS)
	rm -Rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: clean all

$(D_OBJ)/%.o: $(D_SRC)/%.c
	echo "$(LOG_NOCOLOR)Create obj $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	$(CC) -c -o $@ $< $(F_INC) $(FLAGS)


##########################################################################
##########################################################################
##########################################################################
##########################################################################
