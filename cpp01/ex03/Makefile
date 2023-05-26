SRCS := main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp \

OBJS := ${SRCS:.cpp=.o}

NAME := fight_club

COMPILER ?= c++

RM		:= rm -f

CFLAGS 	:= -Wall -Werror -Wextra -std=c++98


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
