SRC_DIR			= srcs
TEST_DIR		= .test
LIBFT_DIR		= ./libft

LIBFT_NAME		= libft.a
LIBFT_PATH		= $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

INCLUDES		= -I $(LIBFT_DIR) -I ${SRC_DIR}

PARSE_FILES		= ft_parseint.c ft_parsechar.c ft_parsebase.c ft_parsefloat.c
PARSE			= $(addprefix parse/, $(PARSE_FILES))

UTILS_FILES		= ft_convert_base.c ft_printf_utils.c
UTILS			= $(addprefix utils/, $(UTILS_FILES))

FLAGS_FILES		= ft_extract_flags.c ft_convert.c
FLAGS			= $(addprefix flags/, $(FLAGS_FILES))

SRC_FILES		= ft_printf.c $(PARSE) $(UTILS) $(FLAGS)

TEST_FILES		= main.c

SRC				= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
TESTER			= $(addprefix $(TEST_DIR)/, $(TEST_FILES))
OBJS			= $(SRC:.c=.o)

TEST_OBJS		= $(TESTER:.c=.o)

CFLAGS			= -g -Werror -Wextra -Wall -w $(INCLUDES) #-g3 -fsanitize=address 

TEST_FLAGS		= $(INCLUDES)

CC				= clang

AR				= ar rcs

RM				= rm -f

LIB_OUTPUT		= libftprintf.a

TEST_OUTPUT		= a.out

LIBFT_MAKE		= ${MAKE} -C ${LIBFT_DIR}

LIBFT			= -L${LIBFT_DIR} -lft

LIBFTPRINTF		= -L. -lftprintf

TEST_1			= test1.test

TEST_2			= test2.test

ARGS			= int uint char string pointer hex float exp gfloat leaks other

$(NAME):		libft $(OBJS) ./srcs/ft_printf.h
				cp ${LIBFT_PATH} ${LIB_OUTPUT}
				${AR} ${LIB_OUTPUT} ${OBJS}
				ranlib ${LIB_OUTPUT}

all:			$(NAME)

test:			all $(TEST_OBJS) ${SRC_DIR}/ft_printf.h
				${CC} ${TEST_FLAGS} ${TEST_OBJS} ${LIBFTPRINTF} -o ${TEST_OUTPUT}

run:			test
				./${TEST_OUTPUT} ${ARGS}

libft:			
				git submodule init
				${LIBFT_MAKE}

clean:
				$(RM) $(OBJS) $(TEST_OBJS)

fclean:			clean
				$(RM) $(NAME) $(TEST_OUTPUT)

re:				fclean all

retest:			fclean test

.PHONY:			all clean fclean re libft retest run
