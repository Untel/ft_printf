SRC_DIR			= ./srcs
TEST_DIR		= .test
LIBFT_DIR		= ./libft
LIBFT			= libft.a
LIBFT_PATH		= $(addprefix $(LIBFT_DIR)/, $(LIBFT))

INCLUDES		= -I $(LIBFT_DIR) -I ${SRC_DIR} -I ${SRC_DIR}

PARSE_FILES		= ft_parseint.c ft_parsechar.c ft_parsebase.c ft_parsefloat.c
PARSE			= $(addprefix parse/, $(PARSE_FILES))

UTILS_FILES		= ft_convert_base.c ft_printf_utils.c
UTILS			= $(addprefix utils/, $(UTILS_FILES))
SRC_FILES		= ft_printf.c ft_extract_flags.c ft_convert.c $(PARSE) $(UTILS)

TEST_FILES		= main.c

SRC				= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
TESTER			= $(addprefix $(TEST_DIR)/, $(TEST_FILES))
OBJS			= $(SRC:.c=.o)

TEST_OBJS		= $(TESTER:.c=.o)

CFLAGS			= -Werror -Wextra -Wall -w $(INCLUDES) #-g3 -fsanitize=address 

TEST_FLAGS		= 

CC				= clang

AR				= ar rc

RM				= rm -f

NAME			= ft_printf.out

NAME_TEST		= a.out

LIBFT_MAKE		= ${MAKE} -C ${LIBFT_DIR}

LIBFT			= -L${LIBFT_DIR} -lft

TEST_1			= test1.test

TEST_2			= test2.test

DIFF			= diff --text --expand-tabs --left-column --side-by-side

ARGS			= int uint char string pointer hex float exp other

$(NAME):		libft $(OBJS) ./srcs/ft_printf.h
				cp ${LIBFT_PATH} ${NAME}
				${AR} ${NAME} ${OBJS}
				ranlib ${NAME}

all:			$(NAME)

test:			libft $(OBJS) $(TEST_OBJS) ${SRC_DIR}/ft_printf.h
				${CC} ${CFLAGS} ${TEST_FLAGS} ${OBJS} ${TEST_OBJS} ${LIBFT} -o ${NAME_TEST}

run:			test
				./${NAME_TEST} ${ARGS}

compare:		test
				./${NAME_TEST} 

				# ./${NAME_TEST} "1" > ${TEST_2}
				# $(DIFF) ${TEST_1} ${TEST_2}
				# $(RM) $(TEST_1) $(TEST_2)

libft:			
				git submodule init
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
