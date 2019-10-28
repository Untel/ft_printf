SRC_DIR			= ./srcs

INCLUDES_DIR	= ./includes

SRC_FILES		= ft_printf.c ft_printf_utils.c

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

$(NAME):		$(OBJS)
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:			$(NAME)

test:			$(OBJS) $(TEST_OBJS)
				${CC} ${CFLAGS} ${TEST_FLAGS} ${OBJS} ${TEST_OBJS} -o ${NAME_TEST}
				./${NAME_TEST}

clean:
				$(RM) $(OBJS) $(TEST_OBJS)

fclean:			clean
				$(RM) $(NAME) $(NAME_TEST)

re:				fclean all

retest:			fclean test

.PHONY:			all clean fclean re 
