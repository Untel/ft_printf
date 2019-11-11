PRINTF_PATH			= ..
TEST_DIR			= .
TEST_FILES			= main.c
TESTER				= $(addprefix $(TEST_DIR)/, $(TEST_FILES))
INCLUDES			= -I . -I $(PRINTF_PATH)/srcs -I $(PRINTF_PATH)/libft
CFLAGS				= -w -g $(INCLUDES)
LIBFTPRINTF_MAKE	= $(MAKE) -C $(PRINTF_PATH)
# $(TEST_FILES)/%.o: $(TEST_FILES)/%.c
# 				$(CC) $(TEST_FLAGS) -I. -o $@ -c $<
TEST_OBJS			= $(TESTER:.c=.o)
CC					= clang
NAME				= a.out
LIBFTPRINTF			= -L$(PRINTF_PATH) -lftprintf
ARGS				= int uint char string pointer hex float exp gfloat leaks other

all:				$(TEST_OBJS) test.h
					$(LIBFTPRINTF_MAKE)
					$(CC) $(TEST_OBJS) $(LIBFTPRINTF) -o $(NAME)

run:				all
					./$(NAME) $(ARGS)

clean:
					$(RM) $(OBJS) $(TEST_OBJS)
					$(LIBFT_MAKE) clean
fclean:
					$(RM) $(OBJS) $(TEST_OBJS)
					$(RM) $(NAME) $(TEST_OUTPUT)
					$(LIBFT_MAKE) fclean

re:					fclean all

.PHONY:				all clean fclean re libft retest run