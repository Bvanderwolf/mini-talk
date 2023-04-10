# SRCS: find ./srcs -iname "*.c"

# //= Variables =//

CLIENT_NAME	= client
SERVER_NAME	= server

LIBFT	= ./lib/libft
PRINTF	= ./lib/printf

ifdef SANITIZE
DFLAGS	= -g -fsanitize=address
else
DFLAGS	= 
endif

ifdef NOERROR
CFLAGS	= -Wunreachable-code -Ofast
else
CFLAGS	= -Wunreachable-code -Ofast -Wall -Werror -Wextra
endif

HEADERS	= -I ./includes -I ${LIBFT} -I ${PRINTF}
LIBS	= ${LIBFT}/libft.a ${PRINTF}/libftprintf.a

CLIENT_SRCS	= ${shell find ./srcs/client -iname "*.c"}
SERVER_SRCS	= ${shell find ./srcs/server -iname "*.c"}

CLIENT_OBJS	= ${CLIENT_SRCS:.c=.o}
SERVER_OBJS	= ${SERVER_SRCS:.c=.o}

BOLD	= \033[1m
BLACK	= \033[30;1m
RED		= \033[31;1m
GREEN	= \033[32;1m
YELLOW	= \033[33;1m
BLUE	= \033[34;1m
MAGENTA	= \033[35;1m
CYAN	= \033[36;1m
WHITE	= \033[37;1m
RESET	= \033[0m

# //= Recipes =//

all: libft printf ${CLIENT_NAME} ${SERVER_NAME}

printf:
	@${MAKE} -C ${PRINTF}

libft:
	@${MAKE} -C ${LIBFT}

%.o: %.c
	@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS} && printf "${GREEN}${BOLD}\rCompiling: ${notdir $<}\r\e[35C[OK]\n${RESET}"

${CLIENT_NAME}: ${CLIENT_OBJS}
	@${CC} ${DFLAGS} ${CLIENT_OBJS} ${LIBS} ${HEADERS} -o ${CLIENT_NAME}

${SERVER_NAME}: ${SERVER_OBJS}
	@${CC} ${DFLAGS} ${SERVER_OBJS} ${LIBS} ${HEADERS} -o ${SERVER_NAME}

clean:
	@rm -f ${CLIENT_OBJS} ${SERVER_OBJS}
	@${MAKE} -C ${LIBFT} clean

fclean: clean
	@rm -f ${CLIENT_NAME} ${SERVER_NAME}
	@${MAKE} -C ${LIBFT} fclean

re: clean all

.PHONY: all, client, server, clean, fclean, re, libft, printf