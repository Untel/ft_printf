SRC_DIR			= ./srcs

TEST_DIR		= ./.test

LIBFT_DIR		= ./libft

LIBFT			= libft.a

INCLUDES_DIR	= ${SRC_DIR}

SRC_FILES		= *.c

TEST_FILES		= .main.c

SRC				= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJS			= $(SRC:.c=.o)

TEST_OBJS		= $(TEST_FILES:.c=.o)

CFLAGS			= -Wall -Wextra -Werror -I $(INCLUDES_DIR)

TEST_FLAGS		= -g3 -fsanitize=address

CC				= gcc

AR				= ar rc

RM				= rm -f

NAME			= ft_printf.out

NAME_TEST		= .ft_printf_test.out

LIBFT_MAKE		= ${MAKE} -C ${LIBFT_DIR}

LIBFT			= -L${LIBFT_DIR} -lft

$(NAME):		$(OBJS)
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:			$(NAME)

test:			libft $(OBJS) $(TEST_OBJS)
				${CC} ${CFLAGS} ${TEST_FLAGS} ${OBJS} ${TEST_OBJS} ${LIBFT} -o ${NAME_TEST}
				./${NAME_TEST}					

libft:			
				git submodule init
				git submodule update
				${LIBFT_MAKE}

clean:
				$(RM) $(OBJS) $(TEST_OBJS)

fclean:			clean
				$(RM) $(NAME) $(NAME_TEST)

re:				fclean all

retest:			${LIBFT_MAKE} re fclean test

.PHONY:			all clean fclean re libft retest
