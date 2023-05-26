SRCS := main.cpp \
		ScalarConverter.cpp

OBJS := ${SRCS:.cpp=.o}

NAME := ScalarConverter

COMPILER ?= c++

RM		:= rm -f

CFLAGS 	:= -Wall -Werror -Wextra -g -std=c++98


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
