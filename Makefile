SRC_DIR			= srcs
LIBFT_DIR		= ./libft
LIBFT_NAME		= libft.a
LIBFT_PATH		= $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

INCLUDES		= -I $(LIBFT_DIR) -I $(SRC_DIR) -I.

PARSE_FILES		= ft_parseint.c ft_parsechar.c ft_parsebase.c ft_parsefloat.c ft_parseexp.c
PARSE			= $(addprefix parse/, $(PARSE_FILES))

UTILS_FILES		= ft_convert_base.c ft_printf_utils.c
UTILS			= $(addprefix utils/, $(UTILS_FILES))

FLAGS_FILES		= ft_extract_flags.c ft_convert.c
FLAGS			= $(addprefix flags/, $(FLAGS_FILES))

SRC_FILES		= ft_printf.c $(PARSE) $(UTILS) $(FLAGS)

SRC				= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS			= $(SRC:.c=.o)

CFLAGS			= -Werror -Wextra -Wall $(INCLUDES)
CC				= clang
AR				= ar rc
RM				= rm -f

NAME			= libftprintf.a

LIBFT_MAKE		= $(MAKE) -C $(LIBFT_DIR)

all:			$(NAME)

$(NAME):		$(OBJS) libft ./srcs/ft_printf_internal.h
				cp $(LIBFT_PATH) $(NAME)
				$(AR) $(NAME) $(OBJS)
				ranlib $(NAME)

bonus:			all

libft:
				$(LIBFT_MAKE)

norme:
				$(LIBFT_MAKE) norme
				norminette $(SRC) ft_printf.h ./srcs/ft_printf_internal.h

clean:
				$(RM) $(OBJS)
				$(LIBFT_MAKE) clean

fclean:
				$(RM) $(OBJS) $(NAME)
				$(LIBFT_MAKE) fclean

re:				fclean all

.PHONY:			all clean fclean re libft norme
