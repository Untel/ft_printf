SRC_DIR			= ./srcs
TEST_DIR		= .test
LIBFT_DIR		= ./libft
LIBFT			= libft.a
LIBFT_PATH		= $(addprefix $(LIBFT_DIR)/, $(LIBFT))

INCLUDES		= -I $(LIBFT_DIR) -I ${SRC_DIR} -I ${SRC_DIR}

PARSE_FILES		= ft_parseint.c ft_parsechar.c ft_parsebase.c
PARSE			= $(addprefix parse/, $(PARSE_FILES))

UTILS_FILES		= ft_convert_base.c ft_printf_utils.c
UTILS			= $(addprefix utils/, $(UTILS_FILES))
SRC_FILES		= ft_printf.c ft_extract_flags.c ft_convert.c $(PARSE) $(UTILS)

TEST_FILES		= main.c

SRC				= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
TESTER			= $(addprefix $(TEST_DIR)/, $(TEST_FILES))
OBJS			= $(SRC:.c=.o)

TEST_OBJS		= $(TESTER:.c=.o)

CFLAGS			= -Werror -Wextra -Wall -w -g3 -fsanitize=address $(INCLUDES)

TEST_FLAGS		= 

CC				= gcc

AR				= ar rc

RM				= rm -f

NAME			= ft_printf.out

NAME_TEST		= a.out

LIBFT_MAKE		= ${MAKE} -C ${LIBFT_DIR}

LIBFT			= -L${LIBFT_DIR} -lft

TEST_1			= test1.test

TEST_2			= test2.test

DIFF			= diff --text --expand-tabs --left-column --side-by-side

$(NAME):		libft $(OBJS)
				cp ${LIBFT_PATH} ${NAME}
				${AR} ${NAME} ${OBJS}
				ranlib ${NAME}

all:			$(NAME)

test:			libft $(OBJS) $(TEST_OBJS) ${SRC_DIR}/ft_printf.h
				${CC} ${CFLAGS} ${TEST_FLAGS} ${OBJS} ${TEST_OBJS} ${LIBFT} -o ${NAME_TEST}

run/int:		test
				./${NAME_TEST} int

run/char:		test
				./${NAME_TEST} char

run/pointer:	test
				./${NAME_TEST} pointer


run/hex:		test
				./${NAME_TEST} hex
				
run/string:		test
				./${NAME_TEST} string

run/all:
				run/int
				run/string
				run/char
				run/pointer
				run/hex

compare:		test
				./${NAME_TEST}

				# ./${NAME_TEST} "1" > ${TEST_2}
				# $(DIFF) ${TEST_1} ${TEST_2}
				# $(RM) $(TEST_1) $(TEST_2)

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
				${LIBFT_MAKE} re

retest:			fclean test

.PHONY:			all clean fclean re libft retest run
