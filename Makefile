SRC_DIR			= ./srcs

TEST_DIR		= ./.test

LIBFT_DIR		= ./libft

LIBFT			= libft.a

INCLUDES		= -I $(LIBFT_DIR) -I ${SRC_DIR} -I ${SRC_DIR}

SRC_FILES		= ft_printf.c ft_printf_utils.c

TEST_FILES		= main.c

SRC				= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

TESTER			= $(addprefix $(TEST_DIR)/, $(TEST_FILES))

OBJS			= $(SRC:.c=.o)

TEST_OBJS		= $(TESTER:.c=.o)

CFLAGS			= -Wall -Wextra -Werror $(INCLUDES)

TEST_FLAGS		= -g3 -fsanitize=address

CC				= gcc

AR				= ar rc

RM				= rm -f

NAME			= ft_printf.out

NAME_TEST		= .ft_printf_test.out

LIBFT_MAKE		= ${MAKE} -C ${LIBFT_DIR}

LIBFT			= -L${LIBFT_DIR} -lft

TEST_1			= test1.txt

TEST_2			= test2.txt

$(NAME):		libft $(OBJS)
				${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

all:			$(NAME)

test:			libft $(OBJS) $(TEST_OBJS)
				${CC} ${CFLAGS} ${TEST_FLAGS} ${OBJS} ${TEST_OBJS} ${LIBFT} -o ${NAME_TEST}

run:			test
				./${NAME_TEST}

compare:		test
				${RM} ${TEST_1} ${TEST_2}
				./${NAME_TEST} >> ${TEST_1}
				${RM} ${NAME_TEST}
				${CC} ${CFLAGS} ${TEST_FLAGS} -D ORIGIN_PRINTF=1 ${OBJS} ${TEST_OBJS} ${LIBFT} -o ${NAME_TEST}
				./${NAME_TEST} >> ${TEST_2}
				diff --text --side-by-side ${TEST_1} ${TEST_2} > diff.txt
				${RM} ${TEST_1} ${TEST_2}

libft:			
				git submodule init
				git submodule update
				${LIBFT_MAKE}

clean:
				$(RM) $(OBJS) $(TEST_OBJS)

fclean:			clean
				$(RM) $(NAME) $(NAME_TEST)
				${LIBFT_MAKE} fclean

re:				fclean all

retest:			fclean test

.PHONY:			all clean fclean re libft retest run
