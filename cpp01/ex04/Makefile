SRCS := main.cpp 

OBJS := ${SRCS:.cpp=.o}

NAME := sed_is_for_loser

COMPILER ?= c++

RM		:= rm -f

CFLAGS 	:= -Wall -Werror -Wextra -std=c++98 -g


.cpp.o:		${OBJS}
			${COMPILER} ${CFLAGS} -c $< -o ${<:.cpp=.o}

all: 		${NAME}

${NAME}:	${OBJS}
			${COMPILER} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re:
			make fclean
			make

.PHONY: 	all clean fclean re
