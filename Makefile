

######################################
# COLOR
######################################

#----TEXT-----

RED = \033[031m
DEF = \033[0m
GREEN= \033[032m
Yellow= \033[33m
Blue= \033[034m
Purple= \033[035m

######################################
#		VARIABLES
######################################

SRCS = *.c

DATARACE = -fsanitize=thread
SILENT = --no-print-directory
MAKE_SILENT = @make ${SILENT} -C
COMPILE = cc ${SRCS} ${CFLAGS} -o
MAKE_MSG = @printf "\n\t    ${Purple}Makefile : ${RED}${NAME}${DEF}\n\n "

NAME = philo
DEBUG=  -fsanitize=address
CFLAGS = -L. -pthread -Wall -Werror -Wextra
 

${NAME} : ${SRCS}
	clear
	${COMPILE} ${NAME}
	${MAKE_MSG}

######################################
#		RULES	
######################################

all: ${NAME}
	
clean :	
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf ${NAME}
	@printf "\t\t${Yellow}CLEANED!\n"

re : fclean all

.PHONY: all re clean fclean